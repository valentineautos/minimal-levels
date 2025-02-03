#include "GaugeMinimal.h"
#include <ESP_Panel_Library.h>
#include "lvgl_port_v8.h"
#include "fonts/ubuntu_24.h"
#include "fonts/ubuntu_60.h"
#include "fonts/ubuntu_100.h"
#include "fonts/font_awesome_icons_small.h"
#include "splash_0.h"
#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>
#include <Preferences.h>

// Initialise memory
Preferences prefs;

// ESPNow structures
typedef struct struct_time_date {
  uint8_t flag;
  uint8_t time_hour;
  uint8_t time_minute;
  uint8_t date_day;
  uint8_t date_month;
  uint16_t date_year;
} struct_time_date;

typedef struct struct_levels {
  uint8_t flag;
  float battery_volts;
  int8_t water_temp;
} struct_levels;

typedef struct struct_oil_press {
   uint8_t flag;
   int8_t oil_press;
} struct_oil_press;

struct_time_date TimeDateData;
struct_levels LevelsData;
struct_buttons ButtonData;
struct_oil_press OilPressData;

// Global components

// Screens
lv_obj_t *startup_scr;                // Black startup screen
lv_obj_t *splash_scr;                 // Splash screen
lv_obj_t *daily_scr;                  // Daily screen
lv_obj_t *track_scr;                  // Track screen
lv_obj_t *dimmer;                     // Dimmer overlay

// Daily screen
lv_obj_t *oil_meter;                  // Daily oil meter
lv_obj_t *water_meter;                // Daily water meter
lv_obj_t *battery_arc;                // Battery arc

lv_meter_indicator_t *oil_indic;      // Oil meter moving part
lv_meter_indicator_t *water_indic;    // Water meter moving part
lv_meter_indicator_t *battery_indic;  // Battery arc moving part

lv_obj_t *battery_icon;               // Battery icon
lv_obj_t *battery_label;              // Battery label
lv_obj_t *water_icon;                 // Water icon
lv_obj_t *water_label;                // Water label
lv_obj_t *oil_icon;                   // Oil icon
lv_obj_t *oil_label;                  // Battery label

lv_obj_t *time_label;                 // Time label
lv_obj_t *date_label;                 // Date label

// Track screen
lv_obj_t *track_oil_arc;              // Track oil arc
lv_obj_t *track_oil_label;            // Track oil value
lv_obj_t *track_oil_icon;             // Track oil icon
lv_obj_t *track_water_arc;            // Track water arc
lv_obj_t *track_water_label;          // Track water value

// Global styles
static lv_style_t style_unit_text;
static lv_style_t style_track_value_text;
static lv_style_t style_icon;

// Font Awesome symbols
#define BATTERY_SYMBOL "\xEF\x97\x9F"
#define OIL_SYMBOL "\xEF\x98\x93"
#define WATER_SYMBOL "\xEF\x98\x94"

// ESPNow checks
volatile bool data_ready = false;
volatile bool time_ready = false;
volatile bool oil_ready = false;
volatile bool button_pressed = false;
bool startup_ready = false;
bool startup_complete = false;

// LVGL Timer 
hw_timer_t *timer = nullptr;

// Lookup
const char *months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

// Icons using the above structure.
// Positions are for the single icon only - labels will be calculated automatically
// Structure: horz_pos, vert_pos, vert_offset, alert, warning, flag_when
struct_icon_parts OilData = {-165, 0, 5, 0, 120, -1, -1, BELOW, "psi"};
struct_icon_parts WaterData = {165, 0, 0, 0, 160, 120, 140, ABOVE, "°C"};
struct_icon_parts BatteryData = {0, 180, 5, 10, 16, 12.2, 11.8, BELOW, "V"};

// ------------------------------------------------------------
// Various initialisations for the ESP32-S3 LCD Driver Board &
// ST7701 LCD Screen featured in the project videos.
//
// Only change if you know what you're doing
// ------------------------------------------------------------
void scr_init() {
  ESP_Panel *panel = new ESP_Panel();
  panel->init();

  #if LVGL_PORT_AVOID_TEAR
    ESP_PanelBus_RGB *rgb_bus = static_cast<ESP_PanelBus_RGB *>(panel->getLcd()->getBus());
    rgb_bus->configRgbFrameBufferNumber(LVGL_PORT_DISP_BUFFER_NUM);
    rgb_bus->configRgbBounceBufferSize(LVGL_PORT_RGB_BOUNCE_BUFFER_SIZE);
  #endif
  panel->begin();

  lvgl_port_init(panel->getLcd(), panel->getTouch());

  startup_scr = lv_scr_act(); // Make startup screen active
  lv_obj_set_style_bg_color(startup_scr, PALETTE_BLACK, 0);
  lv_obj_set_style_bg_opa(startup_scr, LV_OPA_COVER, 0); 
}

void wifi_init() {
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv));
}

void IRAM_ATTR onTimer() {
  lv_tick_inc(1);
}

void timer_init() {
  const uint32_t lv_tick_frequency = 1000;  // 1 kHz = 1ms period

  timer = timerBegin(lv_tick_frequency);  // Configure the timer with 1kHz frequency
  if (!timer) {
    Serial.println("Failed to configure timer!");
    while (1)
      ;  // Halt execution on failure
  }

  timerAttachInterrupt(timer, &onTimer);  // Attach the ISR to the timer
  Serial.println("Timer initialized for LVGL tick");
}

// Global styles
void make_styles(void) {
  lv_style_init(&style_unit_text);
  lv_style_set_text_font(&style_unit_text, &ubuntu_24);
  lv_style_set_text_color(&style_unit_text, PALETTE_WHITE);

  lv_style_init(&style_track_value_text);
  lv_style_set_text_font(&style_track_value_text, &ubuntu_100);
  lv_style_set_text_color(&style_track_value_text, PALETTE_WHITE);

  lv_style_init(&style_icon);
  lv_style_set_text_font(&style_icon, &font_awesome_icons_small);
  lv_style_set_text_color(&style_icon, PALETTE_GREY);
}

// ESPNow received
void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
  // Write to the correct structure based on ESPNow flag
  switch (incomingData[0]) {
    case (FLAG_SET_CHANNEL): {
      int8_t new_channel = incomingData[1];
      esp_wifi_set_channel(new_channel, WIFI_SECOND_CHAN_NONE);
      break;
    }
    case (FLAG_STARTUP):
      startup_ready = true;
      break;
    case (FLAG_BUTTONS):
      memcpy(&ButtonData, incomingData, sizeof(ButtonData));
      button_pressed = true;
      break;
    case (FLAG_CANBUS):
      memcpy(&LevelsData, incomingData, sizeof(LevelsData));
      data_ready = true;
      break;
    case (FLAG_GPS):
      memcpy(&TimeDateData, incomingData, sizeof(TimeDateData));
      time_ready = true;
      break;
    case (FLAG_OIL_PRESSURE):
      memcpy(&OilPressData, incomingData, sizeof(OilPressData));
      oil_ready = true;
      break;
  }
}

// Return date suffix, eg th, st, rd
String get_date_suffix(int day) {
  if (day < 1 || day > 31) {
    return "";
  }

  if (day >= 11 && day <= 13) {
    return "th";
  }

  switch (day % 10) {
    case 1:
      return "st";
    case 2:
      return "nd";
    case 3:
      return "rd";
    default:
      return "th";
  }
}

// Check and update colors
void update_alert_colors(void) {
  lv_obj_set_style_text_color(oil_icon, get_state_color(OilData, OilPressData.oil_press, true), 0);
  lv_obj_set_style_arc_color(track_oil_arc, get_state_color(OilData, OilPressData.oil_press, false), LV_PART_INDICATOR);

  lv_obj_set_style_text_color(water_icon, get_state_color(WaterData, LevelsData.water_temp, true), 0);
  lv_obj_set_style_arc_color(track_water_arc, get_state_color(WaterData, LevelsData.water_temp, false), LV_PART_INDICATOR);

  lv_obj_set_style_text_color(battery_icon, get_state_color(BatteryData, LevelsData.battery_volts, true), 0);
  lv_obj_set_style_arc_color(battery_arc, get_state_color(BatteryData, LevelsData.battery_volts, false), LV_PART_INDICATOR);
}

// Move icons and set opacities
void update_show_num(void) {
    // Set oil icon position
    lv_obj_align(oil_icon, LV_ALIGN_CENTER, OilData.horz_pos, OilData.vert_pos - (is_show_num ? (ICON_MOVEMENT - OilData.vert_offset) : 0));
    lv_obj_set_style_opa(oil_label, (is_show_num ? LV_OPA_COVER : LV_OPA_TRANSP), 0);

    // Set water icon position
    lv_obj_align(water_icon, LV_ALIGN_CENTER, WaterData.horz_pos, WaterData.vert_pos - (is_show_num ? (ICON_MOVEMENT - WaterData.vert_offset ): 0));
    lv_obj_set_style_opa(water_label, (is_show_num) ? LV_OPA_COVER : LV_OPA_TRANSP, 0);

    // Set battery icon position
    lv_obj_align(battery_icon, LV_ALIGN_CENTER, BatteryData.horz_pos, BatteryData.vert_pos - (is_show_num ? (ICON_MOVEMENT - BatteryData.vert_offset) : 0));
    lv_obj_set_style_opa(battery_label, (is_show_num) ? LV_OPA_COVER : LV_OPA_TRANSP, 0);

  update_alert_colors();
}

// Switch between screens
void update_mode(void) {
  if (is_track_mode) {
    lv_scr_load_anim(track_scr, LV_SCR_LOAD_ANIM_MOVE_TOP, 1000, 0, false);
  } else {
    lv_scr_load_anim(daily_scr, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 1000, 0, false);
  }
}

// Update oil pressure
void update_oil_pressure(int new_oil_pressure = OilPressData.oil_press) {
  // check for -1 initialisation
  if (new_oil_pressure == -1) {
    lv_label_set_text(oil_label, DEFAULT_LABEL); // Icon label with unit
    lv_meter_set_indicator_value(oil_meter, oil_indic, OilData.min); // Meter position

    lv_label_set_text(track_oil_label, DEFAULT_LABEL);  // Track label without unit
    lv_arc_set_value(track_oil_arc, OilData.min); // Arc position

    return;
  }

  // Convert to text for labels
  char oil_text[4];       // Without unit
  char oil_text_unit[7];  // With unit

  // Convert to strings and add unit
  sprintf(oil_text, "%d", new_oil_pressure);
  sprintf(oil_text_unit, "%d%s", new_oil_pressure, OilData.unit);

  // Daily screen
  lv_label_set_text(oil_label, oil_text_unit);   // Icon label with unit
  lv_meter_set_indicator_value(oil_meter, oil_indic, new_oil_pressure); // Meter position
  
  // Track screen
  lv_label_set_text(track_oil_label, oil_text);  // Track label without unit
  lv_arc_set_value(track_oil_arc, new_oil_pressure); // Arc position
}

void update_water_temp(int new_water_temp = LevelsData.water_temp) {
  // check for -1 initialisation
  if (new_water_temp == -1) {
    lv_label_set_text(water_label, DEFAULT_LABEL);   // Icon label with unit
    lv_meter_set_indicator_value(water_meter, water_indic, WaterData.min); // Meter position

    lv_label_set_text(track_water_label, DEFAULT_LABEL);  // Track label without unit
    lv_arc_set_value(track_water_arc, WaterData.min); // Arc position

    return;
  }

  // Convert to text for labels
  char water_text[4];       // Without unit
  char water_text_unit[7];  // With unit

  // Convert to strings and add unit
  sprintf(water_text, "%d", new_water_temp);
  sprintf(water_text_unit, "%d%s", new_water_temp, WaterData.unit);

  // Daily screen
  lv_label_set_text(water_label, water_text_unit);   // Icon label with unit
  lv_meter_set_indicator_value(water_meter, water_indic, new_water_temp); // Meter position
  
  // Track screen
  lv_label_set_text(track_water_label, water_text);  // Track label without unit
  lv_arc_set_value(track_water_arc, new_water_temp); // Arc position
}

void update_battery(float new_battery_volts = LevelsData.battery_volts) {
  if (new_battery_volts == -1) {
    lv_label_set_text(battery_label, DEFAULT_LABEL);
    lv_arc_set_value(battery_arc, BatteryData.min);

    return;
  }

  // Convert to text for labels 
  char battery_text_unit[6];  // With unit

  // Convert to strings and add unit
  sprintf(battery_text_unit, "%.1f%s", new_battery_volts, BatteryData.unit);

  // Daily screen
  lv_label_set_text(battery_label, battery_text_unit);   // Icon label with unit
  lv_arc_set_value(battery_arc, new_battery_volts);      // Arc position
}

void update_date_time(void) {
  if (TimeDateData.date_day > 0) {
    // Format - 18:22
    char new_time[6];
    snprintf(new_time, sizeof(new_time), "%02d:%02d", TimeDateData.time_hour, TimeDateData.time_minute);
    lv_label_set_text(time_label, new_time);

    // Format - 15th Dec, 2024
    char new_date[15];
    snprintf(new_date, sizeof(new_date), "%d%s %s, %02d", TimeDateData.date_day, get_date_suffix(TimeDateData.date_day), months[TimeDateData.date_month - 1], TimeDateData.date_year);
    lv_label_set_text(date_label, new_date);
  }
}

void update_levels(void) {
  update_water_temp();
  update_battery();

  // Check and adjust colors
  update_alert_colors();
}

void update_brightness(void) {
  // convert from 0-11 to 0-198
  uint8_t dimmed_perc = dimmer_lv * 22;
  lv_obj_set_style_bg_opa(dimmer, dimmed_perc, 0);
}


// Save states to memory
void save_mode(bool new_mode) {
  is_track_mode = new_mode;
  prefs.putBool("is_track_mode", new_mode);

  update_mode();
}

void save_show_num(bool new_show) {
  is_show_num = new_show;
  prefs.putBool("is_show_num", new_show);

  // update display after save
  update_show_num();
}

void save_brightness() {
  prefs.putInt("dimmer_lv", dimmer_lv);

  // update brightness after save
  update_brightness();
}

// Button press handling
void handle_button_press(void) {

  // 350z - Top left button
  if (ButtonData.button == BUTTON_SETTING) {
    switch (ButtonData.press_type) {
      case CLICK_EVENT_CLICK:
        // Show minimal design
        save_show_num(false);
        break;
      case CLICK_EVENT_HOLD:
        // Show daily mode
        save_mode(false);
        break;
    }
  }

  // 350z - Bottom left button
  if (ButtonData.button == BUTTON_MODE) {
    switch (ButtonData.press_type) {
      case CLICK_EVENT_CLICK:
        // Show values display mode
        save_show_num(true);
        break;
      case CLICK_EVENT_HOLD:
        // Show track mode
        save_mode(true);
        break;
    }
  }

  // 350z - Top right button
  if (ButtonData.button == BUTTON_BRIGHTNESS_UP) {
    switch (ButtonData.press_type) {
      case CLICK_EVENT_CLICK:
        // Increase brightness / lower overlay opacity
        if (dimmer_lv > 0) {
          dimmer_lv--;
          save_brightness();
        }
        break;
    }
  }

  // 350z - Bottom right button
  if (ButtonData.button == BUTTON_BRIGHTNESS_DOWN) {
    switch (ButtonData.press_type) {
      case CLICK_EVENT_CLICK:
      // Lower brightness / increase overlay opacity
        if (dimmer_lv < 9) {
          dimmer_lv++;
          save_brightness();
        }
        break;
    }
  }
}

void make_oil_meter(void) {
  // Make the meter
  oil_meter = lv_meter_create(daily_scr);
  lv_obj_set_size(oil_meter, 460, 460);
  lv_obj_set_style_bg_opa(oil_meter, LV_OPA_TRANSP, 0);
  lv_obj_set_style_border_width(oil_meter, 0, 0);
  lv_obj_center(oil_meter);
  lv_obj_set_style_text_font(oil_meter, &ubuntu_24, LV_PART_TICKS);
  lv_obj_set_style_text_color(oil_meter, PALETTE_WHITE, LV_PART_TICKS);

  // Add the scale
  lv_meter_scale_t *oil_scale = lv_meter_add_scale(oil_meter);
  lv_meter_set_scale_ticks(oil_meter, oil_scale, HALF_METER_TICKS, TICK_WIDTH, TICK_LENGTH, PALETTE_WHITE);
  lv_meter_set_scale_major_ticks(oil_meter, oil_scale, HALF_METER_TICKS - 1, TICK_WIDTH, TICK_LENGTH, PALETTE_WHITE, TICK_TEXT_OFFSET);
  lv_meter_set_scale_range(oil_meter, oil_scale, OilData.min, OilData.max, 90, 135);

  lv_meter_indicator_t *outline = lv_meter_add_arc(oil_meter, oil_scale, OUTLINE_WIDTH, PALETTE_WHITE, OUTLINE_WIDTH);
  lv_meter_set_indicator_start_value(oil_meter, outline, OilData.min);
  lv_meter_set_indicator_end_value(oil_meter, outline, OilData.max);

  oil_indic = lv_meter_add_needle_line(oil_meter, oil_scale, NEEDLE_WIDTH, NEEDLE_COLOR, NEEDLE_OFFSET);
}

void make_water_meter(void) {
  // Make the meter
  water_meter = lv_meter_create(daily_scr);
  lv_obj_set_size(water_meter, 460, 460);
  lv_obj_set_style_bg_opa(water_meter, LV_OPA_TRANSP, 0);
  lv_obj_set_style_border_width(water_meter, 0, 0);
  lv_obj_center(water_meter);
  lv_obj_set_style_text_font(water_meter, &ubuntu_24, LV_PART_TICKS);
  lv_obj_set_style_text_color(water_meter, PALETTE_WHITE, LV_PART_TICKS);

  // Add the scale
  lv_meter_scale_t *water_scale = lv_meter_add_scale(water_meter);
  lv_meter_set_scale_ticks(water_meter, water_scale, HALF_METER_TICKS, TICK_WIDTH, TICK_LENGTH, PALETTE_WHITE);
  lv_meter_set_scale_major_ticks(water_meter, water_scale, HALF_METER_TICKS - 1, TICK_WIDTH, TICK_LENGTH, PALETTE_WHITE, TICK_TEXT_OFFSET);
  lv_meter_set_scale_range(water_meter, water_scale, WaterData.max, WaterData.min, 90, 315);

  lv_meter_indicator_t *outline = lv_meter_add_arc(water_meter, water_scale, 2, PALETTE_WHITE, OUTLINE_WIDTH);
  lv_meter_set_indicator_start_value(water_meter, outline,  WaterData.max);
  lv_meter_set_indicator_end_value(water_meter, outline, WaterData.min);

  water_indic = lv_meter_add_needle_line(water_meter, water_scale, NEEDLE_WIDTH, NEEDLE_COLOR, NEEDLE_OFFSET);
}

void make_battery_arc(void) {
  battery_arc = lv_arc_create(daily_scr);
  lv_obj_set_size(battery_arc, 446, 446);
  lv_arc_set_rotation(battery_arc, 65);
  lv_arc_set_bg_angles(battery_arc, 0, 50);
  lv_arc_set_range(battery_arc, BatteryData.min, BatteryData.max);
  lv_obj_center(battery_arc);
  lv_arc_set_mode(battery_arc, LV_ARC_MODE_REVERSE);

  lv_obj_set_style_arc_color(battery_arc, PALETTE_WHITE, LV_PART_INDICATOR);
  lv_obj_set_style_arc_color(battery_arc, PALETTE_DARK_GREY, LV_PART_MAIN);
  lv_obj_set_style_arc_rounded(battery_arc, false, LV_PART_MAIN);
  lv_obj_set_style_arc_rounded(battery_arc, false, LV_PART_INDICATOR);
  lv_obj_set_style_arc_width(battery_arc, 4, LV_PART_MAIN);
  lv_obj_set_style_arc_width(battery_arc, 4, LV_PART_INDICATOR);
  lv_obj_remove_style(battery_arc, NULL, LV_PART_KNOB);

  lv_arc_set_value(battery_arc, BatteryData.max);
}

void make_inner_circle(void) {
  lv_obj_t *inner_circle = lv_obj_create(daily_scr);
  lv_obj_set_size(inner_circle, 312, 312);
  lv_obj_center(inner_circle);
  lv_obj_set_style_bg_color(inner_circle, PALETTE_BLACK, 0);
  lv_obj_set_style_bg_opa(inner_circle, LV_OPA_COVER, 0);
  lv_obj_set_style_radius(inner_circle, LV_RADIUS_CIRCLE, 0);
  lv_obj_set_style_border_width(inner_circle, 0, 0);
}

void make_icons(void) {
  oil_icon = lv_label_create(daily_scr);
  lv_label_set_text(oil_icon, OIL_SYMBOL);
  lv_obj_add_style(oil_icon, &style_icon, 0);

  oil_label = lv_label_create(daily_scr);
  lv_label_set_text(oil_label, "---");
  lv_obj_add_style(oil_label, &style_unit_text, 0);
  lv_obj_align(oil_label, LV_ALIGN_CENTER, OilData.horz_pos, OilData.vert_pos + LABEL_LOWER);

  water_icon = lv_label_create(daily_scr);
  lv_label_set_text(water_icon, WATER_SYMBOL);
  lv_obj_add_style(water_icon, &style_icon, 0);

  water_label = lv_label_create(daily_scr);
  lv_label_set_text(water_label, "---");
  lv_obj_add_style(water_label, &style_unit_text, 0);
  lv_obj_align(water_label, LV_ALIGN_CENTER, WaterData.horz_pos, WaterData.vert_pos + LABEL_LOWER);

  battery_icon = lv_label_create(daily_scr);
  lv_label_set_text(battery_icon, BATTERY_SYMBOL);
  lv_obj_add_style(battery_icon, &style_icon, 0);

  battery_label = lv_label_create(daily_scr);
  lv_label_set_text(battery_label, "---");
  lv_obj_add_style(battery_label, &style_unit_text, 0);
  lv_obj_align(battery_label, LV_ALIGN_CENTER, BatteryData.horz_pos, BatteryData.vert_pos + LABEL_LOWER);
}

void make_time_date(void) {
  static lv_style_t style_time_text;
  lv_style_init(&style_time_text);
  lv_style_set_text_font(&style_time_text, &ubuntu_60);
  lv_style_set_text_color(&style_time_text, PALETTE_WHITE);

  time_label = lv_label_create(daily_scr);
  lv_label_set_text(time_label, "");
  lv_obj_add_style(time_label, &style_time_text, 0);
  lv_obj_align(time_label, LV_ALIGN_CENTER, 0, -5);

  date_label = lv_label_create(daily_scr);
  lv_label_set_text(date_label, "");
  lv_obj_add_style(date_label, &style_unit_text, 0);
  lv_obj_align(date_label, LV_ALIGN_CENTER, 0, 35);
}

void make_track_water() {
  track_water_arc = lv_arc_create(track_scr);
  lv_obj_set_size(track_water_arc, 400, 400);
  lv_arc_set_rotation(track_water_arc, 300);
  lv_arc_set_range(track_water_arc, WaterData.min, WaterData.max);
  lv_arc_set_bg_angles(track_water_arc, 0, 120);
  lv_obj_center(track_water_arc);
  lv_obj_set_style_arc_color(track_water_arc, PALETTE_GREY, LV_PART_MAIN);
  lv_obj_set_style_arc_color(track_water_arc, PALETTE_WHITE, LV_PART_INDICATOR);
  lv_obj_set_style_arc_width(track_water_arc, 20, LV_PART_MAIN);
  lv_obj_set_style_arc_width(track_water_arc, 20, LV_PART_INDICATOR);
  lv_arc_set_mode(track_water_arc, LV_ARC_MODE_REVERSE);
  lv_obj_remove_style(track_water_arc, NULL, LV_PART_KNOB);

  track_water_label = lv_label_create(track_scr);
  lv_label_set_text(track_water_label, "0");
  lv_obj_add_style(track_water_label, &style_track_value_text, 0);
  lv_obj_align(track_water_label, LV_ALIGN_CENTER, 80, 4);

  lv_obj_t *track_water_icon = lv_label_create(track_scr);
  lv_label_set_text(track_water_icon, WATER_SYMBOL);
  lv_obj_add_style(track_water_icon, &style_icon, 0);
  lv_obj_set_style_text_color(track_water_icon, PALETTE_WHITE, 0);
  lv_obj_align(track_water_icon, LV_ALIGN_CENTER, 80, -60);

  lv_obj_t *track_water_unit = lv_label_create(track_scr);
  lv_label_set_text(track_water_unit, WaterData.unit);
  lv_obj_add_style(track_water_unit, &style_unit_text, 0);
  lv_obj_set_style_text_color(track_water_unit, PALETTE_WHITE, 0);
  lv_obj_align(track_water_unit, LV_ALIGN_CENTER, 80, 60);
}

void make_track_oil() {
  track_oil_arc = lv_arc_create(track_scr);
  lv_obj_set_size(track_oil_arc, 400, 400);
  lv_arc_set_rotation(track_oil_arc, 120);
  lv_arc_set_range(track_oil_arc, OilData.min, OilData.max);
  lv_arc_set_bg_angles(track_oil_arc, 0, 120);
  lv_obj_center(track_oil_arc);
  lv_obj_set_style_arc_color(track_oil_arc, PALETTE_GREY, LV_PART_MAIN);
  lv_obj_set_style_arc_color(track_oil_arc, PALETTE_WHITE, LV_PART_INDICATOR);
  lv_obj_set_style_arc_width(track_oil_arc, 20, LV_PART_MAIN);
  lv_obj_set_style_arc_width(track_oil_arc, 20, LV_PART_INDICATOR);

  lv_obj_remove_style(track_oil_arc, NULL, LV_PART_KNOB);

  track_oil_icon = lv_label_create(track_scr);
  lv_label_set_text(track_oil_icon, OIL_SYMBOL);
  lv_obj_add_style(track_oil_icon, &style_icon, 0);
  lv_obj_set_style_text_color(track_oil_icon, PALETTE_WHITE, 0);
  lv_obj_align(track_oil_icon, LV_ALIGN_CENTER, -80, -60);

  track_oil_label = lv_label_create(track_scr);
  lv_label_set_text(track_oil_label, "0");
  lv_obj_add_style(track_oil_label, &style_track_value_text, 0);
  lv_obj_align(track_oil_label, LV_ALIGN_CENTER, -80, 4);

  lv_obj_t *track_oil_unit = lv_label_create(track_scr);
  lv_label_set_text(track_oil_unit, OilData.unit);
  lv_obj_add_style(track_oil_unit, &style_unit_text, 0);
  lv_obj_set_style_text_color(track_oil_unit, PALETTE_WHITE, 0);
  lv_obj_align(track_oil_unit, LV_ALIGN_CENTER, -80, 60);
}

void make_splash_screen(void) {
  splash_scr = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(splash_scr, PALETTE_BLACK, 0);

  lv_obj_t *icon_zero = lv_img_create(splash_scr);
  lv_img_set_src(icon_zero, &splash_0);
  lv_obj_align(icon_zero, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_style_img_recolor(icon_zero, PALETTE_WHITE, 0);
  lv_obj_set_style_img_recolor_opa(icon_zero, LV_OPA_COVER, 0);
}

void make_daily_screen(void) {
  daily_scr = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(daily_scr, PALETTE_BLACK, 0);

  make_oil_meter();
  make_water_meter();
  make_battery_arc();
  make_inner_circle();
  make_icons();
  make_time_date();
}

void make_track_screen(void) {
  track_scr = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(track_scr, PALETTE_BLACK, 0);

  make_track_oil();
  make_track_water();
}

void make_dimmer(void) {
  dimmer = lv_layer_top();

  lv_obj_set_size(dimmer, 480, 480);
  lv_obj_center(dimmer);
  lv_obj_set_style_bg_color(dimmer, PALETTE_BLACK, 0);

  update_brightness();
}

// Initialise startup values
void init_values() {
  OilPressData.oil_press = -1;
  LevelsData.water_temp = -1;
  LevelsData.battery_volts = -1;

  update_show_num(); // Initialise show num
  update_oil_pressure(); // Initialise oil pressure
  update_levels(); // Intialise CAN sent levels
}

// Two step managed 
bool complete = false; // flag for screen changes to prevent recurssion

void change_loading_scr(lv_timer_t *timer) {
  lv_obj_t *next_scr = (lv_obj_t *)timer->user_data;
  lv_scr_load_anim(next_scr, LV_SCR_LOAD_ANIM_FADE_IN, 1000, 0, true); // delete startup on exit

  if (!complete) {
    lv_timer_t *exit_timer = lv_timer_create(change_loading_scr, 2000, (is_track_mode) ? track_scr : daily_scr); // back to blank
    lv_timer_set_repeat_count(exit_timer, 1);
    complete = true;
  }
}

// if no startup message received, start anyway
void force_splash(lv_timer_t *timer) {
  // avoid refire if complete
  if (!startup_complete) {
    start_splash();
    startup_complete = true;
  }
}

void start_splash() {
  lv_scr_load_anim(splash_scr, LV_SCR_LOAD_ANIM_FADE_IN, 1000, 0, false);

  lv_timer_t *exit_timer = lv_timer_create(change_loading_scr, 3500, startup_scr); // back to blank
  lv_timer_set_repeat_count(exit_timer, 1);
}

void make_ui(void) {
  make_styles();

  make_daily_screen();
  make_track_screen();
  make_dimmer();

  make_splash_screen();

  init_values();

  start_splash();
}

void setup() {
  Serial.begin(115200);

  prefs.begin("levels_store", false);
  is_track_mode = prefs.getBool("is_track_mode", false);
  is_show_num = prefs.getBool("is_show_num", false);
  dimmer_lv = prefs.getInt("dimmer_lv", 0);

  scr_init();
  wifi_init();

  make_ui();

  timer_init();

    lv_timer_t *startup_timer = lv_timer_create(force_splash, STARTUP_OVERRIDE_TIMER, startup_scr); // back to blank
  lv_timer_set_repeat_count(startup_timer, 1);
}

void loop() {
  lv_timer_handler();

  if (startup_ready && !startup_complete) {
    delay(120);
    start_splash();
    startup_ready = false;
  }
  
  if (data_ready) {
    update_levels();
    data_ready = false;
  }

  if (oil_ready) {
    update_oil_pressure();
    oil_ready = false;
  }

  if (time_ready) {
    update_date_time();
    time_ready = false;
  }

  if (button_pressed) {
    handle_button_press();
    button_pressed = false;
  }
}