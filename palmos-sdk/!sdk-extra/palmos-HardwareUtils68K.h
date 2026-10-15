/******************************************************************************
 *
 * Copyright (c) 2000-2002 Palm, Inc. or its subsidiaries.
 * All rights reserved.
 *
 * File: HardwareUtils68K.h
 *
 * Description:
 *      public API of HardwareUtils library used by 68K applications
 *
 *****************************************************************************/

#ifndef __HWUTILS68K_H__
#define	__HWUTILS68K_H__

#include <PalmTypes.h>

// To Define when building the library
#if (defined BUILDING_HWR68K_LIB)
	#define HWR68K_LIB_TRAP(trapNum)
#else
	#include <LibTraps.h>
	#define HWR68K_LIB_TRAP(trapNum) SYS_TRAP(trapNum)
#endif

#define kHWUtilsType					sysFileTLibrary
#define kHWUtilsCreator					'HWut'
#define kHWUtilsName					"HardwareUtils"	

#define kHWUtilsTrapOpen				sysLibTrapOpen
#define kHWUtilsTrapClose				sysLibTrapClose

#define kHWUtilsTrapBlinkLED			(sysLibTrapCustom + 0)
#define kHWUtilsTrapSetBlinkRate		(sysLibTrapCustom + 1)
#define kHWUtilsTrapEnableDisplay		(sysLibTrapCustom + 2)
#define	kHWUtilsTrapGetDisplayState		(sysLibTrapCustom + 3)

#ifdef __cplusplus
extern "C" {
#endif

Err HWUOpen(UInt16 refnum)
			HWR68K_LIB_TRAP(sysLibTrapOpen);

Err HWUClose(UInt16 refnum)
			HWR68K_LIB_TRAP(sysLibTrapClose);

Err HWUSleep(UInt16 refnum)
			HWR68K_LIB_TRAP(sysLibTrapSleep);

Err HWUWake(UInt16 refnum)
			HWR68K_LIB_TRAP(sysLibTrapWake);

Err HWUClose(UInt16 refnum)
			HWR68K_LIB_TRAP(kHWUtilsTrapClose);

Err HWUBlinkLED(UInt16 refnum, Boolean b)
			HWR68K_LIB_TRAP(kHWUtilsTrapBlinkLED);

Err HWUSetBlinkRate(UInt16 refnum, UInt16 rate)
			HWR68K_LIB_TRAP(kHWUtilsTrapSetBlinkRate);

Err	HWUEnableDisplay(UInt16 refnum, Boolean on)
			HWR68K_LIB_TRAP(kHWUtilsTrapEnableDisplay);

Boolean HWUGetDisplayState(UInt16 refnum)
			HWR68K_LIB_TRAP(kHWUtilsTrapGetDisplayState);

#ifdef __cplusplus 
}
#endif

#endif 	//__HWUTILS68K_H__

