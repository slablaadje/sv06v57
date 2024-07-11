//===========================================================================
//========================== KnightShade settings ===========================
//===========================================================================

// Version History
// 1-6 Tests for SV06
// 7 SV06+
// 8 PID settings for SV06+
// 9 Versioning
// 10 Homing current
// 11 Testing diff filesize
// 12 BTT + fans
// 13 fan fix + 75 X stall
// 14 pwn scale test
// 15 fast pwm
// 16 hardware pwm
// 17 pwm and invert axes
// 18 stall sens, pwm
// 19 invert E0
// 20 currents, stall
// 21 homing speed, minor many tweaks
// 22 homing
// 23 quick home and menu changes
// 24 menu fix
// 25 homing current higher
// 26 pid
// 27 z currents
// 28 quick home disable
// 29 z 1050 -> 1000, pid i 2.2 -> 2, d 43.1->42
// 30 remove duplicate STEALTHCHOP defines from adv, bug: wouldn't use spreadcycle for Z and E
// 31 UBL gridpoints per axis 8->11
// 32 cos 31 failed with Chinese SD card

#define SV06                            1      // Set to 0 for SV06+
#define KS_BTT                          1      // Set to 0 for stock Sovol board
#define KS_VERSION                      "32"

#define KS_MARLIN_TITLE                 "Marlin ~~ )»<(((°>-"
#define KS_CUSTOM_MACHINE_NAME          TERN(SV06,  "SV06 KS", "SV06+ KS")
#define KS_SHORT_BUILD_VERSION          "2.1.2." TERN(KS_BTT, "BTT.", "") TERN(SV06, "", "+.") KS_VERSION


// Space Savers
//#define ASSISTED_TRAMMING             // G35
#define SDCARD_READONLY                 // Read-only SD card (to save over 2K of flash)
#define DISABLE_M503                    // Saves ~2700 bytes of flash. Disable for release!
#if ENABLED(KS_BTT)
  #define EEPROM_CHITCHAT               // Give feedback on EEPROM commands. Disable to save PROGMEM.
  #define CANCEL_OBJECTS
  #define MECHANICAL_GANTRY_CALIBRATION // G34
  #define ARC_SUPPORT                   // Requires ~3226 bytes
#else

#endif

#define INPUT_SHAPING_X
#define INPUT_SHAPING_Y
#if EITHER(INPUT_SHAPING_X, INPUT_SHAPING_Y)
  #define SHAPING_MENU                // Add a menu to the LCD to set shaping parameters.
#endif

#define KS_M92_Report
#define KS_M603_Report
#define KS_M420_Report

#define M114_DETAIL                   // Detail

#define PIDTEMP                       // Moved define, moved to be able to reference it below:
#if ANY(PIDTEMP, PIDTEMPBED, PIDTEMPCHAMBER)
  #define PID_EDIT_MENU               // Add PID editing to the "Advanced Settings" menu. (~700 bytes of flash)
  #define PID_AUTOTUNE_MENU           // Add PID auto-tuning to the "Advanced Settings" menu. (~250 bytes of flash)
#endif


// Features & Settings
#define NO_SD_DETECT

// Physical                                         SV06    +
#define KS_X_BED_SIZE                   TERN(SV06,  222,    300)
#define KS_Y_BED_SIZE                   TERN(SV06,  224,    300)
#define KS_Z_MAX_POS                    TERN(SV06,  250,    340)
#define KS_X_MIN_POS                    -2
#define KS_Y_MIN_POS                    -5
#define KS_INVERT_X_DIR                 TERN(KS_BTT, false, true)
#define KS_INVERT_Y_DIR                 TERN(KS_BTT, true, false)
#define KS_INVERT_Z_DIR                 TERN(KS_BTT, false, true)
#define KS_INVERT_E0_DIR                TERN(KS_BTT, false, true)


// Safety
#define KS_WATCH_TEMP_PERIOD_NOZZLE     20              // Seconds
#define KS_WATCH_TEMP_INCREASE_NOZZLE   4               // Degrees Celsius
#define KS_WATCH_BED_TEMP_PERIOD        60              // Seconds
#define KS_WATCH_BED_TEMP_INCREASE      3               // Degrees Celsius

// Fans
#define KS_E0_AUTO_FAN_PIN              -1 //TERN(KS_BTT, FAN2_PIN, -1)  // Fan2 pin is easier to reach on BTT for hotend cable
#define KS_EXTRUDER_AUTO_FAN_TEMP       35
#define KS_EXTRUDER_AUTO_FAN_SPEED      200             // 255 == full speed

// For now don't use controller fans
/*#if ENABLED(KS_BTT)
  #define USE_CONTROLLER_FAN
  #if ENABLED(USE_CONTROLLER_FAN)
  #define CONTROLLER_FAN_PIN            FAN1_PIN        // Fan1 pin is easier to reach on BTT
  #define KS_CONTROLLERFAN_SPEED_ACTIVE 255 
  #define KS_CONTROLLERFAN_SPEED_IDLE   255
  #endif
#endif*/

//#define NUM_M106_FANS 1                    // :[1,2,3,4,5,6,7,8] Set number of user-controlled fans. Disable to use all board-defined fans.
//#define FAN_SOFT_PWM                     // This uses a very low frequency
//#define SOFT_PWM_SCALE                  6                  // [0,1,2,3,4,5,6,7] Incrementing this by 1 will double the software PWM frequency,
//#define FAST_PWM_FAN                       // Increase the fan PWM frequency. Removes the PWM noise but increases heating in the FET/Arduino
#define FAST_PWM_FAN_FREQUENCY          200    // Define here to override the defaults below

// Leveling & Probing                               SV06                            +
#define KS_Z_PROBE_END_SCRIPT           TERN(SV06,  "G1 Z10 F3000\nG1 X110 Y110",   "G1 Z10 F3000\nG1 X150 Y150")
#define KS_GRID_POINTS_PER_AXIS         11
#define KS_PROBING_MARGIN               8

// Motion                                           SV06    +
#define KS_SHAPING_FREQ_X               TERN(SV06,  36.4,   30)
#define KS_SHAPING_ZETA_X               TERN(SV06,  0.18f,  0.15f)
#define KS_SHAPING_FREQ_Y               TERN(SV06,  39.5,   35)
#define KS_SHAPING_ZETA_Y               TERN(SV06,  0.12f,  0.15f)
#define KS_DEFAULT_MAX_ACCELERATION     { 1500, 1500, 100, 5000 } // Axes
#define KS_DEFAULT_ACCELERATION         1500    // For printing moves
#define KS_DEFAULT_RETRACT_ACCELERATION 1500    // E acceleration for retracts
#define KS_DEFAULT_TRAVEL_ACCELERATION  1500    // X, Y, Z acceleration for travel (non printing) moves
#define KS_XY_PROBE_FEEDRATE            (80*60) // mm/min (feedrates are in mm/min by default)
#define KS_HOMING_FEEDRATE_MM_MIN       { (30*60), (30*60), (4*60) }
//#define QUICK_HOME                              // If G28 contains XY do a diagonal move first

// Stepper Motors                                   SV06    +
#define KS_X_STALL_SENSITIVITY          TERN(SV06,  105,    105)
#define KS_Y_STALL_SENSITIVITY          TERN(SV06,  105,    105)

#define STEALTHCHOP_XY
//#define STEALTHCHOP_Z
//#define STEALTHCHOP_E

#define KS_MOTOR_STEPS_PER_UNIT         { 160, 160, 800, 691.5 }
#define KS_MOTOR_HOLD_MULTIPLIER        1
#define KS_MOTOR_XY_HOLD_MULTIPLIER     0.8
#define KS_MOTOR_XY_RUN_CURRENT         800
#define KS_MOTOR_X_HOME_CURRENT         400
#define KS_MOTOR_Y_HOME_CURRENT         400     // when home == run; home will be set to always use run current
#define KS_MOTOR_XY_RSENSE              0.14    // 0.21 -> 1A, 0.18 -> 1.15A, 0.15 -> 1.35A, 0.12 -> 1.64A, 0.1 -> 1.92A

#define KS_MOTOR_Z_RUN_CURRENT          1000
#define KS_MOTOR_Z_HOME_CURRENT         1000     // when home == run; home will be set to always use run current
#define KS_MOTOR_Z_HOLD_MULTIPLIER      0.75
#define KS_MOTOR_Z_RSENSE               0.15

#define KS_MOTOR_E_RUN_CURRENT          530
#define KS_MOTOR_E_HOLD_MULTIPLIER      0.7
#define KS_MOTOR_E_RSENSE               0.15


// PID                                              SV06    +
#define KS_DEFAULT_bedKp                TERN(SV06,  153.9,  197.8) 
#define KS_DEFAULT_bedKi                TERN(SV06,  24,     35.77) 
#define KS_DEFAULT_bedKd                TERN(SV06,  657.6,  729.1)
#define KS_MAX_BED_POWER                255     // 0-255

#define KS_PID_FUNCTIONAL_RANGE         22      // Default 10

#define KS_BANG_MAX                     220     // Limits current to nozzle while in bang-bang mode; 255=full current
#define KS_PID_MAX                      120     // Limits current to nozzle while PID is active (see PID_FUNCTIONAL_RANGE below); 255=full current
#define KS_PID_K1                       0.95    // Smoothing, 1 = no kd, don't get this one

#define KS_DEFAULT_Kp                   21
#define KS_DEFAULT_Ki                   1.5
#define KS_DEFAULT_Kd                   40       // 42