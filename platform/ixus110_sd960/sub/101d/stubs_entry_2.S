#include "stubs_asm.h"
#define NULL_SUB 0xFF810950 //ixus110

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(LogCameraEvent,                   0xFF86C85C) //ixus110
NHSTUB(MakeAFScan,                  0xFF924900) //ixus110
NHSTUB(ScreenLock,                  0xFF9B7774) //ixus110
