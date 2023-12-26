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
struct MpAlarmXHistory
{	struct MpComIdentType(* MpLink);
	plcstring(* DeviceName)[51];
	plcstring(* Language)[21];
	signed long StatusID;
	MpAlarmXInfoType Info;
	MpComInternalDataType Internal;
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Export;
	plcbit Active;
	plcbit Error;
	plcbit CommandBusy;
	plcbit CommandDone;
};
_BUR_PUBLIC void MpAlarmXHistory(struct MpAlarmXHistory* inst);
_BUR_LOCAL struct MpAlarmXHistory iFb_AlarmHistory;
_BUR_LOCAL struct MpAlarmXCore iFb_AlarmX;
