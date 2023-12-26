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

#ifndef __AS__TYPE_MpAlarmXListUIStatusEnum
#define __AS__TYPE_MpAlarmXListUIStatusEnum
typedef enum MpAlarmXListUIStatusEnum
{	mpALARMX_LIST_UI_STATUS_IDLE = 0,
	mpALARMX_LIST_UI_STATUS_ERROR = 99,
} MpAlarmXListUIStatusEnum;
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

#ifndef __AS__TYPE_MpAlarmXListUIBacktraceType
#define __AS__TYPE_MpAlarmXListUIBacktraceType
typedef struct MpAlarmXListUIBacktraceType
{	unsigned long RecordID[5];
	plcstring LogbookName[5][101];
	signed long EventID[5];
	plcstring Description[5][256];
} MpAlarmXListUIBacktraceType;
#endif

#ifndef __AS__TYPE_MpAlarmXListUIAlarmListType
#define __AS__TYPE_MpAlarmXListUIAlarmListType
typedef struct MpAlarmXListUIAlarmListType
{	unsigned long Severity[50];
	unsigned long Code[50];
	plcwstring Message[50][256];
	plcwstring AdditionalInformation1[50][256];
	plcwstring AdditionalInformation2[50][256];
	unsigned long InstanceID[50];
	plcstring Scope[50][256];
	plcstring Name[50][256];
	plcbit StateActive[50];
	plcbit StateAcknowledged[50];
	plcstring Timestamp[50][51];
	unsigned short SelectedIndex;
	unsigned short MaxSelection;
	plcbit PageUp;
	plcbit PageDown;
	plcbit StepUp;
	plcbit StepDown;
	float RangeStart;
	float RangeEnd;
} MpAlarmXListUIAlarmListType;
#endif

#ifndef __AS__TYPE_MpAlarmXListUIDetailsType
#define __AS__TYPE_MpAlarmXListUIDetailsType
typedef struct MpAlarmXListUIDetailsType
{	unsigned long Severity;
	unsigned long Code;
	plcwstring Message[256];
	plcwstring AdditionalInformation1[256];
	plcwstring AdditionalInformation2[256];
	unsigned long InstanceID;
	plcstring Scope[256];
	plcstring Name[256];
	plcbit StateActive;
	plcbit StateAcknowledged;
	plcstring Timestamp[51];
	MpAlarmXListUIBacktraceType Backtrace;
} MpAlarmXListUIDetailsType;
#endif

#ifndef __AS__TYPE_MpAlarmXListUIConnectType
#define __AS__TYPE_MpAlarmXListUIConnectType
typedef struct MpAlarmXListUIConnectType
{	MpAlarmXListUIStatusEnum Status;
	MpAlarmXListUIAlarmListType AlarmList;
	plcbit Acknowledge;
	plcbit AcknowledgeAll;
	MpAlarmXListUIDetailsType Details;
	plcstring Language[21];
	unsigned long AcknowledgeID;
} MpAlarmXListUIConnectType;
#endif

#ifndef __AS__TYPE_MpAlarmXListUISetupType
#define __AS__TYPE_MpAlarmXListUISetupType
typedef struct MpAlarmXListUISetupType
{	unsigned short AlarmListSize;
	unsigned char AlarmListScrollWindow;
	plcstring TimeStampPattern[51];
} MpAlarmXListUISetupType;
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
struct MpAlarmXListUI
{	struct MpComIdentType(* MpLink);
	MpAlarmXListUISetupType UISetup;
	struct MpAlarmXListUIConnectType(* UIConnect);
	signed long StatusID;
	MpAlarmXInfoType Info;
	MpComInternalDataType Internal;
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Active;
	plcbit Error;
};
_BUR_PUBLIC void MpAlarmXListUI(struct MpAlarmXListUI* inst);
_BUR_LOCAL struct MpAlarmXCore iFb_AlarmX;
_BUR_LOCAL struct MpAlarmXListUI iFb_AlarmUI;
_BUR_LOCAL MpAlarmXListUIConnectType iUIConnectCore;
_GLOBAL MpComIdentType gAlarmXCore;
