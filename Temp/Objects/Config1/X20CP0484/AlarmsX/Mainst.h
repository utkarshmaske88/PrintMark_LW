#ifndef __AS__TYPE_
#define __AS__TYPE_
typedef struct {
	unsigned char bit0  : 1;
	unsigned char bit1  : 1;
	unsigned char bit2  : 1;
	unsigned char bit3  : 1;
	unsigned char bit4  : 1;
	unsigned char bit5  : 1;
	unsigned char bit6  : 1;
	unsigned char bit7  : 1;
} _1byte_bit_field_;

typedef struct {
	unsigned short bit0  : 1;
	unsigned short bit1  : 1;
	unsigned short bit2  : 1;
	unsigned short bit3  : 1;
	unsigned short bit4  : 1;
	unsigned short bit5  : 1;
	unsigned short bit6  : 1;
	unsigned short bit7  : 1;
	unsigned short bit8  : 1;
	unsigned short bit9  : 1;
	unsigned short bit10 : 1;
	unsigned short bit11 : 1;
	unsigned short bit12 : 1;
	unsigned short bit13 : 1;
	unsigned short bit14 : 1;
	unsigned short bit15 : 1;
} _2byte_bit_field_;

typedef struct {
	unsigned long bit0  : 1;
	unsigned long bit1  : 1;
	unsigned long bit2  : 1;
	unsigned long bit3  : 1;
	unsigned long bit4  : 1;
	unsigned long bit5  : 1;
	unsigned long bit6  : 1;
	unsigned long bit7  : 1;
	unsigned long bit8  : 1;
	unsigned long bit9  : 1;
	unsigned long bit10 : 1;
	unsigned long bit11 : 1;
	unsigned long bit12 : 1;
	unsigned long bit13 : 1;
	unsigned long bit14 : 1;
	unsigned long bit15 : 1;
	unsigned long bit16 : 1;
	unsigned long bit17 : 1;
	unsigned long bit18 : 1;
	unsigned long bit19 : 1;
	unsigned long bit20 : 1;
	unsigned long bit21 : 1;
	unsigned long bit22 : 1;
	unsigned long bit23 : 1;
	unsigned long bit24 : 1;
	unsigned long bit25 : 1;
	unsigned long bit26 : 1;
	unsigned long bit27 : 1;
	unsigned long bit28 : 1;
	unsigned long bit29 : 1;
	unsigned long bit30 : 1;
	unsigned long bit31 : 1;
} _4byte_bit_field_;
#endif

#ifndef __AS__TYPE_MpComSeveritiesEnum
#define __AS__TYPE_MpComSeveritiesEnum
typedef enum MpComSeveritiesEnum
{	mpCOM_SEV_SUCCESS = 0,
	mpCOM_SEV_INFORMATIONAL = 1,
	mpCOM_SEV_WARNING = 2,
	mpCOM_SEV_ERROR = 3,
} MpComSeveritiesEnum;
#endif

#ifndef __AS__TYPE_MpComIdentType
#define __AS__TYPE_MpComIdentType
typedef struct MpComIdentType
{	unsigned long Internal[2];
} MpComIdentType;
#endif

#ifndef __AS__TYPE_MpComInternalDataType
#define __AS__TYPE_MpComInternalDataType
typedef struct MpComInternalDataType
{	unsigned long pObject;
	unsigned long State;
} MpComInternalDataType;
#endif

#ifndef __AS__TYPE_MpAlarmXErrorEnum
#define __AS__TYPE_MpAlarmXErrorEnum
typedef enum MpAlarmXErrorEnum
{	mpALARMX_NO_ERROR = 0,
	mpALARMX_ERR_ACTIVATION = -1064239103,
	mpALARMX_ERR_MPLINK_NULL = -1064239102,
	mpALARMX_ERR_MPLINK_INVALID = -1064239101,
	mpALARMX_ERR_MPLINK_CHANGED = -1064239100,
	mpALARMX_ERR_MPLINK_CORRUPT = -1064239099,
	mpALARMX_ERR_MPLINK_IN_USE = -1064239098,
	mpALARMX_ERR_CONFIG_NULL = -1064239096,
	mpALARMX_ERR_CONFIG_NO_PV = -1064239095,
	mpALARMX_ERR_CONFIG_INVALID = -1064239091,
	mpALARMX_ERR_NAME_NULL = -1064116224,
	mpALARMX_ERR_NAME_EMPTY = -1064116223,
	mpALARMX_WRN_MISSING_UICONNECT = -2137858045,
	mpALARMX_ERR_ALARM_NOT_ACTIVE = -1064116220,
	mpALARMX_ERR_ALARM_NOT_SELECTED = -1064116219,
	mpALARMX_ERR_ACK_NOT_ALLOWED = -1064116218,
	mpALARMX_ERR_INVALID_FILE_DEV = -1064116217,
	mpALARMX_INF_WAIT_CORE_FB = 1083367432,
	mpALARMX_ERR_CORE_INST_EXISTS = -1064116215,
	mpALARMX_ERR_MEMORY_INIT = -1064116214,
	mpALARMX_ERR_WRITE_EXPORT_FILE = -1064116213,
	mpALARMX_ERR_NAME_NOT_FOUND = -1064116212,
	mpALARMX_ERR_QUERY_NOT_FOUND = -1064116211,
	mpALARMX_INF_QUERY_NO_DATA = 1083367438,
	mpALARMX_WRN_QUERY_INCONSISTENT = -2137858033,
} MpAlarmXErrorEnum;
#endif

#ifndef __AS__TYPE_MpAlarmXStatusIDType
#define __AS__TYPE_MpAlarmXStatusIDType
typedef struct MpAlarmXStatusIDType
{	MpAlarmXErrorEnum ID;
	MpComSeveritiesEnum Severity;
	unsigned short Code;
} MpAlarmXStatusIDType;
#endif

#ifndef __AS__TYPE_MpAlarmXDiagType
#define __AS__TYPE_MpAlarmXDiagType
typedef struct MpAlarmXDiagType
{	MpAlarmXStatusIDType StatusID;
} MpAlarmXDiagType;
#endif

#ifndef __AS__TYPE_MpAlarmXInfoType
#define __AS__TYPE_MpAlarmXInfoType
typedef struct MpAlarmXInfoType
{	MpAlarmXDiagType Diag;
} MpAlarmXInfoType;
#endif

struct MpAlarmXCore
{	struct MpComIdentType(* MpLink);
	signed long StatusID;
	unsigned long ActiveAlarms;
	unsigned long PendingAlarms;
	MpAlarmXInfoType Info;
	MpComInternalDataType Internal;
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Active;
	plcbit Error;
};
_BUR_PUBLIC void MpAlarmXCore(struct MpAlarmXCore* inst);
_BUR_LOCAL struct MpAlarmXCore iFb_AlarmX;
_GLOBAL MpComIdentType gAlarmXCore;
