//===========================================================================
//========================== KnightShade settings ===========================
//===========================================================================

// Version History
// 1-6 Tests for SV06, 7 SV06+, 8 PID settings for SV06+, 9 Versioning

#define SV06                            0       // Set to 0 for SV06+

// NOZZLE_TO_PROBE_OFFSET

#define KS_VERSION                      "9"
#define KS_MARLIN_TITLE                 "Marlin ~~ )»<(((°>-"
#define KS_CUSTOM_MACHINE_NAME          TERN(SV06,  "SV06 KS", "SV06+ KS")
#define KS_SHORT_BUILD_VERSION          "2.1.2.57" TERN(SV06, "", ".+") KS_VERSION

// Space Savers
#define INPUT_SHAPING_X
#define INPUT_SHAPING_Y
#if EITHER(INPUT_SHAPING_X, INPUT_SHAPING_Y)
  #define SHAPING_MENU                // Add a menu to the LCD to set shaping parameters.
#endif

// #define M114_DETAIL                // Detail removed

#define PIDTEMP                       // Moved define, moved to be able to reference it below:
#if ANY(PIDTEMP, PIDTEMPBED, PIDTEMPCHAMBER)
  //#define PID_EDIT_MENU         // Add PID editing to the "Advanced Settings" menu. (~700 bytes of flash)
  //#define PID_AUTOTUNE_MENU     // Add PID auto-tuning to the "Advanced Settings" menu. (~250 bytes of flash)
#endif

// Physical                                         SV06   +
#define KS_X_BED_SIZE                   TERN(SV06,  222,   300)
#define KS_Y_BED_SIZE                   TERN(SV06,  224,   300)
#define KS_Z_MAX_POS                    TERN(SV06,  250,   340)
#define KS_X_MIN_POS                    -2
#define KS_Y_MIN_POS                    -5

// Safety
#define KS_WATCH_TEMP_PERIOD_NOZZLE     20              // Seconds
#define KS_WATCH_TEMP_INCREASE_NOZZLE   4               // Degrees Celsius
#define KS_WATCH_BED_TEMP_PERIOD        60              // Seconds
#define KS_WATCH_BED_TEMP_INCREASE      3               // Degrees Celsius

// Leveling & Probing                               SV06                            +
#define KS_Z_PROBE_END_SCRIPT           TERN(SV06,  "G1 Z10 F3000\nG1 X110 Y110",   "G1 Z10 F3000\nG1 X150 Y150")
#define KS_GRID_POINTS_PER_AXIS         8

// Motion                                           SV06   +
#define KS_SHAPING_FREQ_X               TERN(SV06,  36.4,   30)
#define KS_SHAPING_ZETA_X               TERN(SV06,  0.18f,  0.15f)
#define KS_SHAPING_FREQ_Y               TERN(SV06,  39.5,   35)
#define KS_SHAPING_ZETA_Y               TERN(SV06,  0.12f,  0.15f)
#define KS_DEFAULT_MAX_ACCELERATION     { 1500, 1500, 100, 5000 } // Axes
#define KS_DEFAULT_ACCELERATION         1500    // For printing moves
#define KS_DEFAULT_RETRACT_ACCELERATION 1500    // E acceleration for retracts
#define KS_DEFAULT_TRAVEL_ACCELERATION  1500    // X, Y, Z acceleration for travel (non printing) moves
#define KS_XY_PROBE_FEEDRATE            (80*60) // mm/min (feedrates are in mm/min by default)
#define KS_HOMING_FEEDRATE_MM_MIN       { (50*60), (50*60), (4*60) }


// Stepper Motors                                   SV06   +
#define KS_X_STALL_SENSITIVITY          TERN(SV06,  68,    80)
#define KS_Y_STALL_SENSITIVITY          TERN(SV06,  62,    80)

#define KS_MOTOR_STEPS_PER_UNIT         { 160, 160, 800, 691.5 }
#define KS_MOTOR_HOLD_MULTIPLIER        1
#define KS_MOTOR_XY_HOLD_MULTIPLIER     0.8
#define KS_MOTOR_XY_RUN_CURRENT         675
#define KS_MOTOR_XY_HOME_CURRENT        675     // when home == run; home will be set to always use run current
#define KS_MOTOR_XY_RSENSE              0.21

#define KS_MOTOR_Z_RUN_CURRENT          900
#define KS_MOTOR_Z_HOME_CURRENT         900     // when home == run; home will be set to always use run current
#define KS_MOTOR_Z_HOLD_MULTIPLIER      0.66
#define KS_MOTOR_Z_RSENSE               0.15

#define KS_MOTOR_E_RUN_CURRENT          550
#define KS_MOTOR_E_HOLD_MULTIPLIER      0.7
#define KS_MOTOR_E_RSENSE               0.15

// PID                                              SV06    +
#define KS_DEFAULT_bedKp                TERN(SV06,  153.9,  197.8) 
#define KS_DEFAULT_bedKi                TERN(SV06,  24,     35.77) 
#define KS_DEFAULT_bedKd                TERN(SV06,  657.6,  729.1)
#define KS_MAX_BED_POWER                255     // 0-255

#define KS_PID_FUNCTIONAL_RANGE         22      // Default 10

#define KS_BANG_MAX                     230     // Limits current to nozzle while in bang-bang mode; 255=full current
#define KS_PID_MAX                      200     // Limits current to nozzle while PID is active (see PID_FUNCTIONAL_RANGE below); 255=full current
#define KS_PID_K1                       0.95    // Smoothing, don't get this one

#define KS_DEFAULT_Kp                   20.9
#define KS_DEFAULT_Ki                   2.53
#define KS_DEFAULT_Kd                   43.1