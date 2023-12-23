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

#ifndef __AS__TYPE_MpDataRecorderHeaderType
#define __AS__TYPE_MpDataRecorderHeaderType
typedef struct MpDataRecorderHeaderType
{	plcstring Name[101];
	plcstring Description[256];
} MpDataRecorderHeaderType;
#endif

#ifndef __AS__TYPE_MpDataErrorEnum
#define __AS__TYPE_MpDataErrorEnum
typedef enum MpDataErrorEnum
{	mpDATA_NO_ERROR = 0,
	mpDATA_ERR_ACTIVATION = -1064239103,
	mpDATA_ERR_MPLINK_NULL = -1064239102,
	mpDATA_ERR_MPLINK_INVALID = -1064239101,
	mpDATA_ERR_MPLINK_CHANGED = -1064239100,
	mpDATA_ERR_MPLINK_CORRUPT = -1064239099,
	mpDATA_ERR_MPLINK_IN_USE = -1064239098,
	mpDATA_ERR_CONFIG_NULL = -1064239096,
	mpDATA_ERR_CONFIG_NO_PV = -1064239095,
	mpDATA_ERR_CONFIG_LOAD = -1064239094,
	mpDATA_WRN_CONFIG_LOAD = -2137980917,
	mpDATA_ERR_CONFIG_SAVE = -1064239092,
	mpDATA_ERR_CONFIG_INVALID = -1064239091,
	mpDATA_ERR_REGISTERING_PV = -1064124416,
	mpDATA_ERR_NO_PV_REGISTERED = -1064124415,
	mpDATA_ERR_INVALID_PV_NAME = -1064124414,
	mpDATA_ERR_PV_NAME_NULL = -1064124413,
	mpDATA_ERR_PV_REGISTERED = -1064124412,
	mpDATA_ERR_FILE_SYSTEM = -1064124411,
	mpDATA_WRN_SAMPLING_TIME = -2137866234,
	mpDATA_ERR_INVALID_FILE_DEV = -1064124409,
	mpDATA_ERR_DATAREC_NOT_FOUND = -1064124408,
	mpDATA_WRN_SAVE_INTERVAL = -2137866231,
	mpDATA_ERR_RECORD_FAILURE = -1064124406,
	mpDATA_WRN_SAMPLING_TIME_MULTIP = -2137866229,
	mpDATA_INF_WAIT_RECORDER_FB = 1083359244,
	mpDATA_ERR_MISSING_UICONNECT = -1064124403,
	mpDATA_WRN_TOO_MANY_FILENAMES = -2137866226,
	mpDATA_ERR_INVALID_LIMITS = -1064124399,
} MpDataErrorEnum;
#endif

#ifndef __AS__TYPE_MpDataStatusIDType
#define __AS__TYPE_MpDataStatusIDType
typedef struct MpDataStatusIDType
{	MpDataErrorEnum ID;
	MpComSeveritiesEnum Severity;
	unsigned short Code;
} MpDataStatusIDType;
#endif

#ifndef __AS__TYPE_MpDataDiagType
#define __AS__TYPE_MpDataDiagType
typedef struct MpDataDiagType
{	MpDataStatusIDType StatusID;
} MpDataDiagType;
#endif

#ifndef __AS__TYPE_MpDataInfoType
#define __AS__TYPE_MpDataInfoType
typedef struct MpDataInfoType
{	MpDataDiagType Diag;
} MpDataInfoType;
#endif

#ifndef __AS__TYPE_MpDataRecorderInfoType
#define __AS__TYPE_MpDataRecorderInfoType
typedef struct MpDataRecorderInfoType
{	unsigned short FileCount;
	plcstring CurrentFileName[51];
	unsigned long CurrentFileSize;
	unsigned short CurrentBufferSize;
	unsigned short RegisteredPVCount;
	unsigned long TotalSamples;
	plcbit ValueOutsideLimits;
	MpDataDiagType Diag;
} MpDataRecorderInfoType;
#endif

#ifndef __AS__TYPE_MpDataRecordModeEnum
#define __AS__TYPE_MpDataRecordModeEnum
typedef enum MpDataRecordModeEnum
{	mpDATA_RECORD_MODE_TIME = 0,
	mpDATA_RECORD_MODE_TRIGGER = 1,
	mpDATA_RECORD_MODE_VALUE = 2,
	mpDATA_RECORD_MODE_TIME_TRIGGER = 3,
	mpDATA_RECORD_MODE_TIME_VALUE = 4,
	mpDATA_RECORD_MODE_TRIGGER_VALUE = 5,
	mpDATA_RECORD_MODE_TIME_TRIG_VAL = 6,
} MpDataRecordModeEnum;
#endif

struct MpDataRecorder
{	struct MpComIdentType(* MpLink);
	struct MpDataRecorderHeaderType(* Header);
	plcstring(* DeviceName)[51];
	plctime SamplingTime;
	MpDataRecordModeEnum RecordMode;
	signed long StatusID;
	MpDataRecorderInfoType Info;
	MpComInternalDataType Internal;
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Record;
	plcbit Trigger;
	plcbit SnapShot;
	plcbit Active;
	plcbit Error;
	plcbit CommandBusy;
	plcbit Recording;
	plcbit RecordDone;
	plcbit SnapShotDone;
};
_BUR_PUBLIC void MpDataRecorder(struct MpDataRecorder* inst);
struct MpDataRegPar
{	struct MpComIdentType(* MpLink);
	plcstring(* PVName)[101];
	plcstring(* Unit)[21];
	plcstring(* Description)[51];
	float ScaleFactor;
	signed long StatusID;
	MpDataInfoType Info;
	MpComInternalDataType Internal;
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Active;
	plcbit Error;
};
_BUR_PUBLIC void MpDataRegPar(struct MpDataRegPar* inst);
_BUR_LOCAL struct MpDataRecorder iFB_DataR;
_BUR_LOCAL struct MpDataRegPar iFB_DataRegPar;
_GLOBAL MpComIdentType gDataRecorder;
