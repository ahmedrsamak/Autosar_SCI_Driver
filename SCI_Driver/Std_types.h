/*
 * Std_types.h
 *
 * Created: 8/6/2018 10:17:18 PM
 *  Author: ahmed
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include "Platform_types.h"
#include "Compiler.h"

#define ENABLE 1
#define DISABLE 0

#define E_OK 1
#define E_NOT_OK 0

typedef u8 Std_ReturnType; //return E_ok or E_NOT_OK


typedef struct
{
	u16 vendorID;
	u16 moduleID;
	u8 sw_major_version;
	u8 sw_minor_version;
	u8 sw_patch_version;
}Std_VersionInfoType;




#endif /* STD_TYPES_H_ */