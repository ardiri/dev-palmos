/******************************************************************************
 *
 * Copyright (c) 2003 Palm, Inc. or its subsidiaries.
 * All rights reserved.
 *
 * File: PalmDisplayExtent.h
 *
 * Description:
 *      Public API for the Display Extent Library
 *
 * History:
 *		Version 1.0		- Intial Revision (03/03/03)
 *
 *****************************************************************************/

#ifndef __PALMDISPLAYEXTENT_H__
#define __PALMDISPLAYEXTENT_H__

#include <PalmTypes.h>
#include <LibTraps.h>

/********************************************************************
 * Library type and creator
 ********************************************************************/
#define dexLibName			"rotmgr"
#define dexLibCreator		'rotM'
#define dexLibType			sysFileTLibrary
#define dexFtrNumVersion	(0)

/********************************************************************
 * Rotation Library Notifications
 ********************************************************************/
#define sysNotifyDexRotationChangingEvent	'Rchg'
#define sysNotifyDexRotationEvent			'RChg'
#define sysNotifyDexHandednessEvent			'Hchg'

/********************************************************************
 * Library Traps
 ********************************************************************/
#define kDexLibTrapOpen						sysLibTrapOpen
#define kDexLibTrapClose					sysLibTrapClose
#define kDexLibTrapDexSetRotation			(sysLibTrapCustom)
#define kDexLibTrapDexGetRotation			(sysLibTrapCustom + 1)
#define kDexLibTrapDexSetHandedness			(sysLibTrapCustom + 2)
#define kDexLibTrapDexGetHandedness			(sysLibTrapCustom + 3)
#define kDexLibTrapDexGetDisplayAddress		(sysLibTrapCustom + 4)
#define kDexLibTrapDexGetDisplayDimensions	(sysLibTrapCustom + 5)

/********************************************************************
 * Rotation types and events
 ********************************************************************/
typedef enum RotationTypeTag
{
    dexRotation0   = 0,
    dexRotation90  = 90,
    dexRotation180 = 180,
    dexRotation270 = 270
} DexRotationType;

typedef struct
{
    UInt16 newRotation;
    UInt16 oldRotation;
} DexRotationChangedEventDataType;

/********************************************************************
 * Handedness types and events
 ********************************************************************/
typedef enum HandednessTypeTag
{
    dexHandednessRight = 0,
    dexHandednessLeft = 1
} DexHandednessType;

typedef struct
{
    UInt8 newHandedness;
    UInt8 oldHandedness;
} DexHandednessChangedEventDataType;     


/********************************************************************
 * Prototypes
 ********************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

Err DexLibOpen(UInt16 refnum)
				SYS_TRAP(kDexLibTrapOpen);
				
Err DexLibClose(UInt16 refnum)
				SYS_TRAP(kDexLibTrapClose);
				
DexRotationType DexSetRotation(UInt16 refnum, DexRotationType rotation)
				SYS_TRAP(kDexLibTrapDexSetRotation);
				
DexRotationType DexGetRotation(UInt16 refnum)
				SYS_TRAP(kDexLibTrapDexGetRotation);
				
DexHandednessType DexSetHandedness(UInt16 refnum, DexHandednessType handedness)
				SYS_TRAP(kDexLibTrapDexSetHandedness);
				
DexHandednessType DexGetHandedness(UInt16 refnum)
				SYS_TRAP(kDexLibTrapDexGetHandedness);

void *DexGetDisplayAddress(UInt16 refnum)                                       
				SYS_TRAP(kDexLibTrapDexGetDisplayAddress);

void DexGetDisplayDimensions(UInt16 refnum, Coord *width, Coord *height, UInt16 *rowBytes)     
				SYS_TRAP(kDexLibTrapDexGetDisplayDimensions);

#ifdef __cplusplus
}
#endif

#endif