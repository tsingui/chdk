// Camera - sx230hs - platform_camera.h

// This file contains the various settings values specific to the SX230HS camera.
// This file is referenced via the 'include/camera.h' file and should not be loaded directly.

// If adding a new settings value put a suitable default in 'include/camera.h',
// along with documentation on what the setting does and how to determine the correct value.
// If the setting should not have a default value then add it in 'include/camera.h'
// using the '#undef' directive along with appropriate documentation.

// Override any default values with your camera specific values in this file. Try and avoid
// having override values that are the same as the default value.

// When overriding a setting value there are two cases:
// 1. If removing the value, because it does not apply to your camera, use the '#undef' directive.
// 2. If changing the value it is best to use an '#undef' directive to remove the default value
//    followed by a '#define' to set the new value.

// When porting CHDK to a new camera, check the documentation in 'include/camera.h'
// for information on each setting. If the default values are correct for your camera then
// don't override them again in here.

    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE   1
    #define DNG_VERT_RLE_BADPIXELS          1
    #define CAM_AV_OVERRIDE_IRIS_FIX        1
    #define CAM_KEY_CLICK_DELAY             150
    #define CAM_ADJUSTABLE_ALT_BUTTON       1
    #define CAM_ALT_BUTTON_NAMES            { "Playback", "Video", "Display" }
    #define CAM_ALT_BUTTON_OPTIONS          { KEY_PRINT, KEY_VIDEO, KEY_DISPLAY }
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1

    #define CAM_DRYOS_2_3_R39               1
    #define CAM_DRYOS_2_3_R47               1
    #define CAM_PROPSET                     4
    #define CAM_DATE_FOLDER_NAMING          1
    #define CAM_DRYOS                       1
    #define CAM_RAW_ROWPIX                  4168
    #define CAM_RAW_ROWS                    3060

    #define CAM_HAS_CMOS                    1

    #define CAM_HAS_ND_FILTER               1

    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_HAS_VIDEO_BUTTON            1
    #define CAM_VIDEO_QUALITY_ONLY          1

    #undef  CAM_VIDEO_CONTROL
   
    #define CAM_HAS_JOGDIAL                 1
    #undef  CAM_USE_ZOOM_FOR_MF

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000

    #define CAM_DNG_LENS_INFO               { 50,10, 700,10, 31,10, 59,10 } // See comments in camera.h
    #define cam_CFAPattern                  0x02010100

    #define CAM_COLORMATRIX1                            \
    544808, 1000000, -174047, 1000000, -80399, 1000000, \
    -75055, 1000000,  440444, 1000000,  11367, 1000000, \
     -5801, 1000000,   71589, 1000000, 118914, 1000000

    #define cam_CalibrationIlluminant1      17

    #define CAM_JPEG_WIDTH                  4000
    #define CAM_JPEG_HEIGHT                 3000

    #define CAM_ACTIVE_AREA_X1              96
    #define CAM_ACTIVE_AREA_Y1              24
    #define CAM_ACTIVE_AREA_X2              4168
    #define CAM_ACTIVE_AREA_Y2              3060

    #define PARAM_CAMERA_NAME               4
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #define CAM_EXT_TV_RANGE                1
    
    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE              13
    #define CAM_LOAD_CUSTOM_COLORS          1           // Enable loading CHDK colors into the camera palette memory
    #define CHDK_COLOR_BASE                 0xA8        // Start color index for CHDK colors loaded into camera palette.

    #undef  CAM_HAS_ERASE_BUTTON
    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1

    #define CAM_HAS_VARIABLE_ASPECT         1
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1
    #undef  CAM_SCREEN_WIDTH
    #undef  CAM_BITMAP_WIDTH
    #undef  CAM_BITMAP_HEIGHT
    #define CAM_SCREEN_WIDTH                480 // Width of bitmap screen in CHDK co-ordinates
    #define CAM_BITMAP_WIDTH                960 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT               270 // Actual height of bitmap screen in rows

    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN                    10


    #define CAM_ZEBRA_ASPECT_ADJUST         1
    #define CAM_ZEBRA_NOBUF                 1

    #define CAM_QUALITY_OVERRIDE            1
    
    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX 1

    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                 99     // Override min subject distance

    #define CAM_HAS_GPS                     1

    #define CAM_CHDK_HAS_EXT_VIDEO_TIME     1

    #define USE_REAL_AUTOISO                1
    #define OVEREXP_COMPENSATE_OVERALL      1
    
    #define CAM_USE_ALT_SET_ZOOM_POINT      1   // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt 1  // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()

    #define REMOTE_SYNC_STATUS_LED          0xC0220130  // specifies an LED that turns on while camera waits for USB remote to sync

    #define CAM_HAS_MOVIE_DIGEST_MODE       1 
//----------------------------------------------------------
