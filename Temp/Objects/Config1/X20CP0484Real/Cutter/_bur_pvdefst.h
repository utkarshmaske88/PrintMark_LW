#ifndef __AS__TYPE_Joglim_enum
#define __AS__TYPE_Joglim_enum
typedef enum Joglim_enum
{	enCHECKVEL = 0,
	enADDVEL = 1,
	enUPPERPOS = 2,
	enLOWERPOS = 3,
	enUPDATE = 4,
	enRESET = 5,
} Joglim_enum;
#endif

#ifndef __AS__TYPE_AxStep_enum
#define __AS__TYPE_AxStep_enum
typedef enum AxStep_enum
{	enINITA = 0,
	enSTARTA = 1,
	enNEEGHOMEMOVE = 2,
	enPOWER_ONA = 3,
	enPOSHOMINGSEC = 4,
	enPOSHOMING = 5,
	enNEGHOMING = 6,
	enHOMEA = 7,
	enOPERATIONA = 8,
	enERRORA = 9,
	enMANUAL = 10,
	enAUTOMATIC = 11,
	enJOGPOSITIVE = 12,
	enJOGNEGATIVE = 13,
	enCUTTINGZONE = 14,
} AxStep_enum;
#endif

#ifndef __AS__TYPE_AxisCmd_typ
#define __AS__TYPE_AxisCmd_typ
typedef struct AxisCmd_typ
{	plcbit Start;
	plcbit Stop;
	plcbit PrintMark;
	plcbit ErrorReset;
	plcbit AutoMode;
	plcbit JogFwd;
	plcbit JogBack;
	plcbit Home;
	plcbit SingleCutter;
} AxisCmd_typ;
#endif

#ifndef __AS__TYPE_AxisPara_typ
#define __AS__TYPE_AxisPara_typ
typedef struct AxisPara_typ
{	unsigned short Speed;
} AxisPara_typ;
#endif

#ifndef __AS__TYPE_AxisStatus_typ
#define __AS__TYPE_AxisStatus_typ
typedef struct AxisStatus_typ
{	plcbit JogNegReady;
	plcbit JogPosReady;
} AxisStatus_typ;
#endif

#ifndef __AS__TYPE_AxisCtrl_typ
#define __AS__TYPE_AxisCtrl_typ
typedef struct AxisCtrl_typ
{	AxisCmd_typ Cmd;
	AxisPara_typ Para;
	AxisStatus_typ Status;
} AxisCtrl_typ;
#endif

#ifndef __AS__TYPE_MpAxisMoveDirectionEnum
#define __AS__TYPE_MpAxisMoveDirectionEnum
typedef enum MpAxisMoveDirectionEnum
{	mpAXIS_DIR_POSITIVE = 0,
	mpAXIS_DIR_NEGATIVE = 1,
	mpAXIS_DIR_CURRENT = 2,
	mpAXIS_DIR_SHORTEST_WAY = 3,
	mpAXIS_DIR_EXCEED_PERIOD = 8,
} MpAxisMoveDirectionEnum;
#endif

#ifndef __AS__TYPE_MpAxisHomeModeEnum
#define __AS__TYPE_MpAxisHomeModeEnum
typedef enum MpAxisHomeModeEnum
{	mpAXIS_HOME_MODE_DEFAULT = 0,
	mpAXIS_HOME_MODE_ABS_SWITCH = 2,
	mpAXIS_HOME_MODE_SWITCH_GATE = 8,
	mpAXIS_HOME_MODE_LIMIT_SWITCH = 3,
	mpAXIS_HOME_MODE_REF_PULSE = 5,
	mpAXIS_HOME_MODE_DIRECT = 1,
	mpAXIS_HOME_MODE_ABSOLUTE = 4,
	mpAXIS_HOME_MODE_ABSOLUTE_CORR = 6,
	mpAXIS_HOME_MODE_DCM = 9,
	mpAXIS_HOME_MODE_DCM_CORR = 10,
	mpAXIS_HOME_MODE_RESTORE_POS = 11,
	mpAXIS_HOME_MODE_AXIS_REF = 12,
	mpAXIS_HOME_MODE_BLOCK_TORQUE = 13,
	mpAXIS_HOME_MODE_BLOCK_DS = 14,
} MpAxisHomeModeEnum;
#endif

#ifndef __AS__TYPE_MpAxisHomeMoveDirectionEnum
#define __AS__TYPE_MpAxisHomeMoveDirectionEnum
typedef enum MpAxisHomeMoveDirectionEnum
{	mpAXIS_HOME_DIR_POSITIVE = 0,
	mpAXIS_HOME_DIR_NEGATIVE = 1,
} MpAxisHomeMoveDirectionEnum;
#endif

#ifndef __AS__TYPE_MpAxisHomeOptionEnum
#define __AS__TYPE_MpAxisHomeOptionEnum
typedef enum MpAxisHomeOptionEnum
{	mpAXIS_HOME_OPTION_OFF = 0,
	mpAXIS_HOME_OPTION_ON = 1,
} MpAxisHomeOptionEnum;
#endif

#ifndef __AS__TYPE_MpAxisHomingType
#define __AS__TYPE_MpAxisHomingType
typedef struct MpAxisHomingType
{	MpAxisHomeModeEnum Mode;
	double Position;
	float StartVelocity;
	float HomingVelocity;
	double SensorOffset;
	float Acceleration;
	MpAxisHomeMoveDirectionEnum StartDirection;
	MpAxisHomeMoveDirectionEnum HomingDirection;
	MpAxisHomeOptionEnum NoDirectionChange;
	MpAxisHomeMoveDirectionEnum SwitchEdge;
	MpAxisHomeOptionEnum ReferencePulse;
	double ReferencePulseBlockingDistance;
	float TorqueLimit;
	double BlockDetectionPositionError;
	double PositionErrorStopLimit;
	unsigned long EndlessPositionDataRef;
} MpAxisHomingType;
#endif

#ifndef __AS__TYPE_MpAxisJogType
#define __AS__TYPE_MpAxisJogType
typedef struct MpAxisJogType
{	float Acceleration;
	float Deceleration;
	float Velocity;
	double LowerLimit;
	double UpperLimit;
} MpAxisJogType;
#endif

#ifndef __AS__TYPE_MpAxisStopType
#define __AS__TYPE_MpAxisStopType
typedef struct MpAxisStopType
{	float Deceleration;
	plcbit StopInPhase;
	double Phase;
} MpAxisStopType;
#endif

#ifndef __AS__TYPE_MpAxisTriggerSourceEnum
#define __AS__TYPE_MpAxisTriggerSourceEnum
typedef enum MpAxisTriggerSourceEnum
{	mpAXIS_TRIGGER1 = 20,
	mpAXIS_TRIGGER2 = 22,
} MpAxisTriggerSourceEnum;
#endif

#ifndef __AS__TYPE_MpAxisTriggerEdgeEnum
#define __AS__TYPE_MpAxisTriggerEdgeEnum
typedef enum MpAxisTriggerEdgeEnum
{	mpAXIS_TRIGGER_EDGE_POS = 0,
	mpAXIS_TRIGGER_EDGE_NEG = 1,
} MpAxisTriggerEdgeEnum;
#endif

#ifndef __AS__TYPE_MpAxisStopAfterTriggerType
#define __AS__TYPE_MpAxisStopAfterTriggerType
typedef struct MpAxisStopAfterTriggerType
{	plcbit Enable;
	double TriggerDistance;
	plcbit ForceTriggerDistance;
	MpAxisTriggerSourceEnum Source;
	MpAxisTriggerEdgeEnum Edge;
} MpAxisStopAfterTriggerType;
#endif

#ifndef __AS__TYPE_MpAxisTorqueLimitType
#define __AS__TYPE_MpAxisTorqueLimitType
typedef struct MpAxisTorqueLimitType
{	float Limit;
	float Window;
} MpAxisTorqueLimitType;
#endif

#ifndef __AS__TYPE_MpAxisReadInfoModeEnum
#define __AS__TYPE_MpAxisReadInfoModeEnum
typedef enum MpAxisReadInfoModeEnum
{	mpAXIS_READ_OFF = 0,
	mpAXIS_READ_CYCLIC = 1,
	mpAXIS_READ_MULTIPLEXED = 2,
	mpAXIS_READ_POLLING_1s = 3,
	mpAXIS_READ_POLLING_5s = 4,
} MpAxisReadInfoModeEnum;
#endif

#ifndef __AS__TYPE_MpAxisCyclicReadSetupType
#define __AS__TYPE_MpAxisCyclicReadSetupType
typedef struct MpAxisCyclicReadSetupType
{	MpAxisReadInfoModeEnum TorqueMode;
	MpAxisReadInfoModeEnum LagErrorMode;
	MpAxisReadInfoModeEnum MotorTempMode;
	MpAxisReadInfoModeEnum UserChannelMode;
} MpAxisCyclicReadSetupType;
#endif

#ifndef __AS__TYPE_MpAxisAutotuneModeEnum
#define __AS__TYPE_MpAxisAutotuneModeEnum
typedef enum MpAxisAutotuneModeEnum
{	mpAXIS_TUNE_AUTOMATIC = 0,
	mpAXIS_TUNE_SPEED = 2,
	mpAXIS_TUNE_POSITION = 1,
	mpAXIS_TUNE_TEST = 31,
	mpAXIS_TUNE_SPEED_ISQ_F1 = 130,
	mpAXIS_TUNE_SPEED_T_FLTR = 66,
	mpAXIS_TUNE_SPEED_T_FLTR_ISQ_F1 = 194,
	mpAXIS_TUNE_SPEED_FLTR = 6,
	mpAXIS_TUNE_ISQ_F1 = 128,
	mpAXIS_TUNE_ISQ_F1_F2 = 384,
	mpAXIS_TUNE_ISQ_F1_F2_F3 = 896,
	mpAXIS_TUNE_FF = 32,
	mpAXIS_TUNE_FF_ONLY_POS = 33,
	mpAXIS_TUNE_FF_ONLY_NEG = 34,
} MpAxisAutotuneModeEnum;
#endif

#ifndef __AS__TYPE_MpAxisFeedForwardModeEnum
#define __AS__TYPE_MpAxisFeedForwardModeEnum
typedef enum MpAxisFeedForwardModeEnum
{	mpAXIS_FF_DISABLED = 0,
	mpAXIS_FF_BOTH = 1,
	mpAXIS_FF_ONLY_POS = 2,
	mpAXIS_FF_ONLY_NEG = 3,
} MpAxisFeedForwardModeEnum;
#endif

#ifndef __AS__TYPE_MpAxisAutotuneType
#define __AS__TYPE_MpAxisAutotuneType
typedef struct MpAxisAutotuneType
{	MpAxisAutotuneModeEnum Mode;
	MpAxisFeedForwardModeEnum FeedForward;
	plcbit Vertical;
	float MaxCurrentPercent;
	float MaxSpeedPercent;
	double MaxDistance;
	float ProportionalAmplification;
} MpAxisAutotuneType;
#endif

#ifndef __AS__TYPE_MpAxisBasicParType
#define __AS__TYPE_MpAxisBasicParType
typedef struct MpAxisBasicParType
{	float Acceleration;
	float Deceleration;
	float Velocity;
	double Position;
	double Distance;
	MpAxisMoveDirectionEnum Direction;
	MpAxisHomingType Home;
	MpAxisJogType Jog;
	MpAxisStopType Stop;
	MpAxisStopAfterTriggerType StopAfterTrigger;
	MpAxisTorqueLimitType Torque;
	MpAxisCyclicReadSetupType CyclicRead;
	MpAxisAutotuneType Autotune;
} MpAxisBasicParType;
#endif

#ifndef __AS__TYPE_MpAxisCyclicReadValueType
#define __AS__TYPE_MpAxisCyclicReadValueType
typedef struct MpAxisCyclicReadValueType
{	plcbit Valid;
	double Value;
} MpAxisCyclicReadValueType;
#endif

#ifndef __AS__TYPE_MpAxisCyclicReadType
#define __AS__TYPE_MpAxisCyclicReadType
typedef struct MpAxisCyclicReadType
{	MpAxisCyclicReadValueType Torque;
	MpAxisCyclicReadValueType LagError;
	MpAxisCyclicReadValueType MotorTemperature;
	MpAxisCyclicReadValueType UserChannelParameterID;
} MpAxisCyclicReadType;
#endif

#ifndef __AS__TYPE_MpAxisBootPhaseEnum
#define __AS__TYPE_MpAxisBootPhaseEnum
typedef enum MpAxisBootPhaseEnum
{	mpAXIS_BLP_NETWORK_INACTIVE = 0,
	mpAXIS_BLP_NETWORK_INIT_STARTED = 1,
	mpAXIS_BLP_WAIT_INIT_HIGH_PRIO = 5,
	mpAXIS_BLP_HW_WAIT = 9,
	mpAXIS_BLP_HW_LINKED = 10,
	mpAXIS_BLP_HW_START = 20,
	mpAXIS_BLP_HW_UPDATE = 30,
	mpAXIS_BLP_HW_UPDATE_OTHER_DRV = 31,
	mpAXIS_BLP_FW_UPDATE = 40,
	mpAXIS_BLP_FW_UPDATE_OTHER_DRV = 41,
	mpAXIS_BLP_FW_START = 50,
	mpAXIS_BLP_WAIT_INIT_LOW_PRIO = 55,
	mpAXIS_BLP_DOWNLOAD_DEF_PARAMS = 60,
	mpAXIS_BLP_DOWNLOAD_INI_PARAMS = 70,
	mpAXIS_BLP_HW_INFO_FROM_DRIVE = 80,
	mpAXIS_BLP_DONE = 90,
} MpAxisBootPhaseEnum;
#endif

#ifndef __AS__TYPE_MpAxisPlcOpenStateEnum
#define __AS__TYPE_MpAxisPlcOpenStateEnum
typedef enum MpAxisPlcOpenStateEnum
{	mpAXIS_DISABLED = 0,
	mpAXIS_STANDSTILL = 1,
	mpAXIS_ERRORSTOP = 10,
	mpAXIS_STOPPING = 9,
	mpAXIS_DISCRETE_MOTION = 2,
	mpAXIS_CONTINUOUS_MOTION = 3,
	mpAXIS_SYNCHRONIZED_MOTION = 4,
	mpAXIS_HOMING = 5,
} MpAxisPlcOpenStateEnum;
#endif

#ifndef __AS__TYPE_MpAxisDigitalIOStatusType
#define __AS__TYPE_MpAxisDigitalIOStatusType
typedef struct MpAxisDigitalIOStatusType
{	plcbit DriveEnable;
	plcbit HomeSwitch;
	plcbit PositiveLimitSwitch;
	plcbit NegativeLimitSwitch;
	plcbit Trigger1;
	plcbit Trigger2;
} MpAxisDigitalIOStatusType;
#endif

#ifndef __AS__TYPE_MpAxisNetworkTypeEnum
#define __AS__TYPE_MpAxisNetworkTypeEnum
typedef enum MpAxisNetworkTypeEnum
{	mpAXIS_CAN_NETWORK = 0,
	mpAXIS_PLK_NETWORK = 1,
	mpAXIS_SDC_NETWORK = 129,
} MpAxisNetworkTypeEnum;
#endif

#ifndef __AS__TYPE_MpAxisDeviceTypeEnum
#define __AS__TYPE_MpAxisDeviceTypeEnum
typedef enum MpAxisDeviceTypeEnum
{	mpAXIS_DEVICE_UNKNOWN = 0,
	mpAXIS_ACOPOS = 1,
	mpAXIS_VIRTUAL = 3,
	mpAXIS_ACOPOSmulti65m = 4,
	mpAXIS_ACOPOSmulti = 5,
	mpAXIS_ACOPOSmulti_PPS = 6,
	mpAXIS_ACOPOSmulti_PS = 2,
	mpAXIS_ACOPOSmicro = 7,
	mpAXIS_ACOPOSmulti65 = 8,
	mpAXIS_ACOPOS_P3 = 12,
	mpAXIS_ACOPOS_SDC = 128,
	mpAXIS_ACOPOS_SIM = 129,
} MpAxisDeviceTypeEnum;
#endif

#ifndef __AS__TYPE_MpAxisAddInfoHardwareType
#define __AS__TYPE_MpAxisAddInfoHardwareType
typedef struct MpAxisAddInfoHardwareType
{	unsigned short NodeID;
	unsigned char Channel;
	MpAxisNetworkTypeEnum NetworkType;
	MpAxisDeviceTypeEnum DeviceType;
} MpAxisAddInfoHardwareType;
#endif

#ifndef __AS__TYPE_MpAxisErrorEnum
#define __AS__TYPE_MpAxisErrorEnum
typedef enum MpAxisErrorEnum
{	mpAXIS_NO_ERROR = 0,
	mpAXIS_ERR_ACTIVATION = -1064239103,
	mpAXIS_ERR_MPLINK_NULL = -1064239102,
	mpAXIS_ERR_MPLINK_INVALID = -1064239101,
	mpAXIS_ERR_MPLINK_CHANGED = -1064239100,
	mpAXIS_ERR_MPLINK_CORRUPT = -1064239099,
	mpAXIS_ERR_MPLINK_IN_USE = -1064239098,
	mpAXIS_ERR_PAR_NULL = -1064239097,
	mpAXIS_ERR_CONFIG_NULL = -1064239096,
	mpAXIS_ERR_CONFIG_NO_PV = -1064239095,
	mpAXIS_ERR_CONFIG_LOAD = -1064239094,
	mpAXIS_WRN_CONFIG_LOAD = -2137980917,
	mpAXIS_ERR_CONFIG_SAVE = -1064239092,
	mpAXIS_ERR_CONFIG_INVALID = -1064239091,
	mpAXIS_ERR_AXIS_HANDLE_NULL = -1064074752,
	mpAXIS_WRN_ERROR_TABLE_MISSING = -2137816575,
	mpAXIS_WRN_CFG_WAIT_ERROR_RESET = -2137816574,
	mpAXIS_WRN_CFG_WAIT_POWER_OFF = -2137816573,
	mpAXIS_WRN_CFG_WAIT_STANDSTILL = -2137816572,
	mpAXIS_ERR_PLC_OPEN = -1064074747,
	mpAXIS_WRN_PLC_OPEN = -2137816570,
	mpAXIS_WRN_READ_TORQUE_OFF = -2137816569,
	mpAXIS_ERR_MAX_TORQUE_REACHED = -1064074744,
	mpAXIS_ERR_SLAVE_NOT_FOUND = -1064074732,
	mpAXIS_ERR_MASTER_NOT_FOUND = -1064074731,
	mpAXIS_ERR_WRONG_DENOMINATOR = -1064074730,
	mpAXIS_ERR_WRONG_NUMERATOR = -1064074729,
	mpAXIS_ERR_NO_CAM_NAME = -1064074728,
	mpAXIS_WRN_SLAVE_NOT_READY = -2137816551,
	mpAXIS_ERR_CHECK_SLAVE_STATUS = -1064074726,
	mpAXIS_ERR_CMD_WRONG_AXISTYPE = -1064074725,
	mpAXIS_WRN_PARAMETER_LIMITED = -2137816548,
	mpAXIS_WRN_MULTIPLE_COMMAND = -2137816547,
	mpAXIS_ERR_CAM_PARAMETER = -1064074722,
	mpAXIS_ERR_RECOVERY_NOT_ALLOWED = -1064074721,
} MpAxisErrorEnum;
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

#ifndef __AS__TYPE_MpAxisStatusIDType
#define __AS__TYPE_MpAxisStatusIDType
typedef struct MpAxisStatusIDType
{	MpAxisErrorEnum ID;
	MpComSeveritiesEnum Severity;
	unsigned short Code;
} MpAxisStatusIDType;
#endif

#ifndef __AS__TYPE_MpComFacilitiesEnum
#define __AS__TYPE_MpComFacilitiesEnum
typedef enum MpComFacilitiesEnum
{	mpCOM_FAC_UNDEFINED = -1,
	mpCOM_FAC_ARCORE = 0,
	mpCOM_FAC_SAFETY1 = 1,
	mpCOM_FAC_SAFETY2 = 2,
	mpCOM_FAC_GMC1 = 96,
	mpCOM_FAC_GMC2 = 97,
	mpCOM_FAC_GMCAXIS = 98,
	mpCOM_FAC_GMCAXESGROUP = 99,
	mpCOM_FAC_GMCARNCGROUP = 103,
	mpCOM_FAC_TRF = 105,
	mpCOM_FAC_MAPP_INTERNAL = 144,
	mpCOM_FAC_MAPP_CORE = 145,
	mpCOM_FAC_MAPP_INFRASTRUCTURE = 146,
	mpCOM_FAC_MAPP_MECHATRONIC = 147,
	mpCOM_FAC_MAPP_INDUSTRY = 148,
} MpComFacilitiesEnum;
#endif

#ifndef __AS__TYPE_MpAxisInternalType
#define __AS__TYPE_MpAxisInternalType
typedef struct MpAxisInternalType
{	signed long ID;
	MpComSeveritiesEnum Severity;
	MpComFacilitiesEnum Facility;
	unsigned short Code;
} MpAxisInternalType;
#endif

#ifndef __AS__TYPE_MpAxisExecutingCmdEnum
#define __AS__TYPE_MpAxisExecutingCmdEnum
typedef enum MpAxisExecutingCmdEnum
{	mpAXIS_CMD_IDLE = 0,
	mpAXIS_CMD_INIT = 1,
	mpAXIS_CMD_HOMING = 2,
	mpAXIS_CMD_STOP = 3,
	mpAXIS_CMD_HALT = 4,
	mpAXIS_CMD_MOVE_VELOCITY = 5,
	mpAXIS_CMD_MOVE_ABSOLUTE = 6,
	mpAXIS_CMD_GEAR_IN = 7,
	mpAXIS_CMD_GEAR_OUT = 8,
	mpAXIS_CMD_CAM_IN = 9,
	mpAXIS_CMD_CAM_OUT = 10,
	mpAXIS_CMD_DOWNLOAD_CAMS = 11,
	mpAXIS_CMD_MOVE_ADDITIVE = 12,
	mpAXIS_CMD_JOG_POSITIVE = 13,
	mpAXIS_CMD_JOG_NEGATIVE = 14,
	mpAXIS_CMD_STOP_PHASED = 15,
	mpAXIS_CMD_AUTOTUNE = 16,
	mpAXIS_CMD_REMOTE_CONTROL = 17,
	mpAXIS_CMD_MOVE_VEL_TRG_STOP = 18,
	mpAXIS_CMD_MOVE_ABS_TRG_STOP = 19,
	mpAXIS_CMD_MOVE_ADD_TRG_STOP = 20,
	mpAXIS_CMD_CAM_SEQUENCER = 50,
	mpAXIS_COUPLING_IDLE = 100,
	mpAXIS_CMD_PHASING = 101,
	mpAXIS_CMD_OFFSET = 102,
	mpAXIS_CMD_ABORT = 103,
	mpAXIS_CMD_UPDATE_GEAR = 104,
	mpAXIS_CMD_UPDATE_CAM = 105,
	mpAXIS_CMD_RECOVERY = 106,
	mpAXIS_CYCLIC_REF_IDLE = 200,
	mpAXIS_CMD_CYC_POSITION = 201,
	mpAXIS_CMD_CYC_VELOCITY = 202,
	mpAXIS_CMD_CYC_TORQUE = 203,
	mpAXIS_CMD_CYC_POSITION_UPDATE = 204,
	mpAXIS_CMD_CYC_VELOCITY_UPDATE = 205,
	mpAXIS_CMD_CYC_TORQUE_UPDATE = 206,
} MpAxisExecutingCmdEnum;
#endif

#ifndef __AS__TYPE_MpAxisDiagExtType
#define __AS__TYPE_MpAxisDiagExtType
typedef struct MpAxisDiagExtType
{	MpAxisStatusIDType StatusID;
	MpAxisInternalType Internal;
	MpAxisExecutingCmdEnum ExecutingCommand;
} MpAxisDiagExtType;
#endif

#ifndef __AS__TYPE_MpAxisBasicInfoType
#define __AS__TYPE_MpAxisBasicInfoType
typedef struct MpAxisBasicInfoType
{	plcbit AxisInitialized;
	plcbit ReadyToPowerOn;
	plcbit JogLimited;
	plcbit TorqueLimitActive;
	plcbit DriveRestarted;
	MpAxisCyclicReadType CyclicRead;
	MpAxisBootPhaseEnum BootState;
	MpAxisPlcOpenStateEnum PLCopenState;
	MpAxisDigitalIOStatusType DigitalInputsStatus;
	MpAxisAddInfoHardwareType HardwareInfo;
	MpAxisDiagExtType Diag;
	plcbit MoveDone;
} MpAxisBasicInfoType;
#endif

#ifndef __AS__TYPE_MpAxisShiftModeEnum
#define __AS__TYPE_MpAxisShiftModeEnum
typedef enum MpAxisShiftModeEnum
{	mpAXIS_SHIFT_MODE_ABS = 0,
	mpAXIS_SHIFT_MODE_REL = 1,
	mpAXIS_SHIFT_MODE_ABS_NO_RESET = 2,
	mpAXIS_SHIFT_MODE_REL_NO_RESET = 3,
} MpAxisShiftModeEnum;
#endif

#ifndef __AS__TYPE_MpAxisApplyModeEnum
#define __AS__TYPE_MpAxisApplyModeEnum
typedef enum MpAxisApplyModeEnum
{	mpAXIS_SHIFT_TIME_BASE = 1,
	mpAXIS_SHIFT_MSTR_POS_BASE = 2,
	mpAXIS_SHIFT_MSTR_DIST_BASE = 3,
	mpAXIS_SHIFT_VEL_CTRL = 4,
	mpAXIS_OFFS_TIME_MSTR = 257,
	mpAXIS_OFFS_MSTR_POS_BASE_MSTR = 258,
	mpAXIS_OFFS_MSTR_DIS_BASE_MSTR = 259,
	mpAXIS_OFFS_VEL_CTRL_MSTR = 260,
} MpAxisApplyModeEnum;
#endif

#ifndef __AS__TYPE_MpAxisProfileBasisEnum
#define __AS__TYPE_MpAxisProfileBasisEnum
typedef enum MpAxisProfileBasisEnum
{	mpAXIS_PROFILE_BASIS_SLAVE = 0,
	mpAXIS_PROFILE_BASIS_MASTER = 256,
} MpAxisProfileBasisEnum;
#endif

#ifndef __AS__TYPE_MpAxisOffsetInZoneType
#define __AS__TYPE_MpAxisOffsetInZoneType
typedef struct MpAxisOffsetInZoneType
{	plcbit Enable;
	double ZoneStartPosition;
	double ZoneEndPosition;
	double Period;
	MpAxisProfileBasisEnum ProfileBasis;
} MpAxisOffsetInZoneType;
#endif

#ifndef __AS__TYPE_MpAxisOffsetType
#define __AS__TYPE_MpAxisOffsetType
typedef struct MpAxisOffsetType
{	MpAxisShiftModeEnum Mode;
	double Distance;
	float Velocity;
	float Acceleration;
	MpAxisApplyModeEnum ApplicationMode;
	plcbit EnableVelocityControl;
	double ApplicationDistance;
	unsigned short CyclicParID;
	MpAxisOffsetInZoneType WithinZone;
} MpAxisOffsetType;
#endif

#ifndef __AS__TYPE_MpAxisRecoveryModeEnum
#define __AS__TYPE_MpAxisRecoveryModeEnum
typedef enum MpAxisRecoveryModeEnum
{	mpAXIS_RECOVERY_FORWARD = 0,
	mpAXIS_RECOVERY_BACKWARD = 2,
	mpAXIS_RECOVERY_SHORTEST_WAY = 3,
	mpAXIS_RECOVERY_FORWARD_WINDOW = 100,
	mpAXIS_RECOVERY_BACKWARD_WINDOW = 101,
	mpAXIS_RECOVERY_GET_POSITION = 102,
} MpAxisRecoveryModeEnum;
#endif

#ifndef __AS__TYPE_MpAxisRecoveryType
#define __AS__TYPE_MpAxisRecoveryType
typedef struct MpAxisRecoveryType
{	MpAxisRecoveryModeEnum Mode;
	float Velocity;
	float Acceleration;
	double ToleranceWindow;
	double PhaseShift;
	double OffsetShift;
} MpAxisRecoveryType;
#endif

#ifndef __AS__TYPE_MpAxisPhasingType
#define __AS__TYPE_MpAxisPhasingType
typedef struct MpAxisPhasingType
{	MpAxisShiftModeEnum Mode;
	double Distance;
	float Velocity;
	float Acceleration;
	MpAxisApplyModeEnum ApplicationMode;
	plcbit EnableVelocityControl;
	double ApplicationDistance;
	unsigned short CyclicParID;
} MpAxisPhasingType;
#endif

#ifndef __AS__TYPE_MC_AUTDATA_EVENT_TYP
#define __AS__TYPE_MC_AUTDATA_EVENT_TYP
typedef struct MC_AUTDATA_EVENT_TYP
{	unsigned char Type;
	unsigned char Attribute;
	unsigned long Action;
	unsigned char NextState;
} MC_AUTDATA_EVENT_TYP;
#endif

#ifndef __AS__TYPE_MC_AUTDATA_STATE_TYP
#define __AS__TYPE_MC_AUTDATA_STATE_TYP
typedef struct MC_AUTDATA_STATE_TYP
{	unsigned char DisableStateInit;
	unsigned short CamProfileIndex;
	signed long MasterFactor;
	signed long SlaveFactor;
	unsigned char CompMode;
	float MasterCompDistance;
	float SlaveCompDistance;
	unsigned short RepeatCounterInit;
	unsigned short RepeatCounterSet;
	float MasterCamLeadIn;
	unsigned short ExtendedCompLimits;
	float MinMasterCompDistance;
	float MinSlaveCompDistance;
	float MaxSlaveCompDistance;
	float MinSlaveCompVelocity;
	float MaxSlaveCompVelocity;
	float MaxSlaveAccelComp1;
	float MaxSlaveAccelComp2;
	float SlaveCompJoltTime;
	unsigned short MasterParID;
	struct MC_AUTDATA_EVENT_TYP Event[5];
} MC_AUTDATA_STATE_TYP;
#endif

#ifndef __AS__TYPE_MC_AUTDATA_TYP
#define __AS__TYPE_MC_AUTDATA_TYP
typedef struct MC_AUTDATA_TYP
{	unsigned long Master;
	float StartPosition;
	signed long StartPositionDINT;
	float StartInterval;
	float EventStartPositionInInterval[5];
	unsigned char StartState;
	float StartMaRelPos;
	unsigned char MasterStartPosMode;
	float MaxMasterVelocity;
	unsigned short MasterParID;
	unsigned short AddMasterParID;
	unsigned short AddSlaveParID;
	unsigned short SlaveFactorParID;
	unsigned short EventParID;
	unsigned short EventParID2;
	unsigned short EventParID3;
	unsigned short EventParID4;
	unsigned short SlaveLatchParID;
	struct MC_AUTDATA_STATE_TYP State[15];
} MC_AUTDATA_TYP;
#endif

#ifndef __AS__TYPE_MpAxisCamSequencerParType
#define __AS__TYPE_MpAxisCamSequencerParType
typedef struct MpAxisCamSequencerParType
{	MC_AUTDATA_TYP Configuration;
	float Deceleration;
	unsigned char ParLock;
	unsigned char MaxStatePerCycle;
	plcstring CamTable[14][13];
	MpAxisRecoveryType Recovery;
	MpAxisOffsetType OffsetShift;
	MpAxisPhasingType PhaseShift;
} MpAxisCamSequencerParType;
#endif

#ifndef __AS__TYPE_MpAxisCamSequencerInfoType
#define __AS__TYPE_MpAxisCamSequencerInfoType
typedef struct MpAxisCamSequencerInfoType
{	plcbit MasterReady;
	plcbit SlaveReady;
	plcbit ActiveSignal1;
	plcbit ActiveSignal2;
	plcbit ActiveSignal3;
	plcbit ActiveSignal4;
	float ActualOffsetValue;
	float ActualPhasingValue;
	MpAxisDiagExtType Diag;
	double RecoveryPosition;
} MpAxisCamSequencerInfoType;
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

#ifndef __AS__TYPE_MC_BR_CFG_RM2_REF
#define __AS__TYPE_MC_BR_CFG_RM2_REF
typedef struct MC_BR_CFG_RM2_REF
{	float ProductLength;
	float RegMarkPosition;
	float RegMarkOffset;
	float DistanceToSensor;
} MC_BR_CFG_RM2_REF;
#endif

#ifndef __AS__TYPE_MC_BR_ADV_RM2_REF
#define __AS__TYPE_MC_BR_ADV_RM2_REF
typedef struct MC_BR_ADV_RM2_REF
{	unsigned short Mode;
	unsigned short EventSourceParID;
	unsigned char Edge;
	float MinWidth;
	float MaxWidth;
	float WindowNeg;
	float WindowPos;
	signed long SensorDelay;
	plcbit CorrectCurrentCycle;
	float CorrectionValueLimitNeg;
	float CorrectionValueLimitPos;
	plcbit DisableWidthEvaluationAtStart;
} MC_BR_ADV_RM2_REF;
#endif

#ifndef __AS__TYPE_MC_BR_ADDINFO_RM2_REF
#define __AS__TYPE_MC_BR_ADDINFO_RM2_REF
typedef struct MC_BR_ADDINFO_RM2_REF
{	float ActLength;
	float AverageProductLength;
	float CutLength;
	unsigned short QueueElements;
	plcbit LimitNegActive;
	plcbit LimitPosActive;
	float ActualCorrectionValue;
} MC_BR_ADDINFO_RM2_REF;
#endif

#ifndef __AS__TYPE_MC_BR_RM2_IMG_REF
#define __AS__TYPE_MC_BR_RM2_IMG_REF
typedef struct MC_BR_RM2_IMG_REF
{	unsigned short EventSourceParID;
	unsigned char Edge;
	unsigned char Reserve;
	signed long MinWidth;
	signed long MaxWidth;
	signed long WindowNeg;
	signed long WindowPos;
	signed long LatchTDelay;
	signed long LatchIV;
	signed long LatchIVL;
	float SPTDelay;
} MC_BR_RM2_IMG_REF;
#endif

#ifndef __AS__TYPE_MC_RMC002_FIFO_TYP
#define __AS__TYPE_MC_RMC002_FIFO_TYP
typedef struct MC_RMC002_FIFO_TYP
{	unsigned short QueueElements;
	unsigned char IdxWriteIn;
	unsigned char IdxReadOut;
	signed long BufferRM[256];
	signed long BufferPL[256];
} MC_RMC002_FIFO_TYP;
#endif

#ifndef __AS__TYPE_MC_0117_IS_TYP
#define __AS__TYPE_MC_0117_IS_TYP
typedef struct MC_0117_IS_TYP
{	plcbit SearchRM;
	plcbit IgnoreSearchRM;
	plcbit InitData;
	unsigned char Reserve1;
	signed long CutPosition;
	signed long oldFBCutPosition;
	signed long oldFBCutPositionCL;
	signed long ProductLength;
	signed long ProductLengthAtCut;
	signed long RegMarkPosition;
	signed long RegMarkOffset;
	signed long DistanceToSensor;
	unsigned short Mode;
	unsigned short EventSourceParID;
	unsigned char Edge;
	plcbit DisableWidthEvaluationAtStart;
	unsigned short Reserve2;
	signed long MinWidth;
	signed long MaxWidth;
	signed long WindowNeg;
	signed long WindowPos;
	signed long SensorDelay;
	signed long CorrectionValueLimitNeg;
	signed long CorrectionValueLimitPos;
	plcbit CorrectCurrentCycle;
	plcbit Active;
	plcbit Valid;
	plcbit Busy;
	unsigned char Reserve3;
	plcbit Error;
	unsigned short ErrorID;
	plcbit DataInitialized;
	plcbit SearchDone;
	unsigned short ProductsWithoutRM;
	unsigned long ValidRMs;
	signed long CorrectionValue;
	signed long CorrectionValueUnlimited;
	signed long ActLength;
	signed long AverageProductLength;
	signed long ArrayProductLength[50];
	unsigned char idxProductLengths;
	unsigned char cntAverage;
	plcbit LimitNegActive;
	plcbit LimitPosActive;
	signed long CutLength;
	MC_BR_RM2_IMG_REF IMG;
	unsigned char state;
	unsigned char LastState;
	unsigned char NextState;
	unsigned char Reserve4;
	unsigned short BitCompInfo;
	unsigned short BitIndex;
	unsigned short BitOffset;
	unsigned short LatchIndex;
	unsigned short DelayIndex;
	unsigned short Reserve8;
	unsigned char BitRecIndex;
	unsigned char LockID;
	unsigned char LockIDPar;
	plcbit IgnoreLatchErrorCountOnce;
	signed long LatchPos;
	signed long oldLatchPos;
	unsigned short LatchPosOffset;
	unsigned char LatchPosRecIndex;
	unsigned char LatchErrCount;
	unsigned char oldLatchErrCount;
	unsigned char LatchStatusCount;
	plcbit LatchReconfiguredtoSearch;
	unsigned char SavedFrDrvCnt;
	unsigned char WaitForTelegrams;
	plcbit PerformLengthCalculation;
	plcbit ModeAcceptAllTrigger;
	plcbit ModeSignalWidth;
	unsigned char ProductCntToStart;
	plcbit PerformLimitation;
	plcbit FiFoUsed;
	plcbit RMOccuredOnce;
	MC_RMC002_FIFO_TYP FIFOBuffer;
	signed long MasterAxisPositionAtBeginning;
	signed long DelayTime;
	float SPTDelayTime;
	signed long LatchTime;
} MC_0117_IS_TYP;
#endif

struct MpAxisBasic
{	struct MpComIdentType(* MpLink);
	struct MpAxisBasicParType(* Parameters);
	unsigned long Axis;
	signed long StatusID;
	double Position;
	float Velocity;
	MpAxisBasicInfoType Info;
	MpComInternalDataType Internal;
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Update;
	plcbit Power;
	plcbit Home;
	plcbit MoveVelocity;
	plcbit MoveAbsolute;
	plcbit MoveAdditive;
	plcbit Stop;
	plcbit JogPositive;
	plcbit JogNegative;
	plcbit Autotune;
	plcbit Simulate;
	plcbit TorqueLimit;
	plcbit ReleaseBrake;
	plcbit Active;
	plcbit Error;
	plcbit UpdateDone;
	plcbit CommandBusy;
	plcbit CommandAborted;
	plcbit PowerOn;
	plcbit IsHomed;
	plcbit InVelocity;
	plcbit InPosition;
	plcbit MoveActive;
	plcbit Stopped;
	plcbit TuningDone;
	plcbit Simulation;
	plcbit TorqueLimited;
	plcbit BrakeReleased;
};
_BUR_PUBLIC void MpAxisBasic(struct MpAxisBasic* inst);
struct MpAxisCamSequencer
{	struct MpComIdentType(* MpLink);
	struct MpAxisCamSequencerParType(* Parameters);
	struct MpComIdentType(* MpLinkMaster);
	signed long StatusID;
	unsigned char ActualStateIndex;
	unsigned short ActualStateCamIndex;
	MpAxisCamSequencerInfoType Info;
	MpComInternalDataType Internal;
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Update;
	plcbit Signal1;
	plcbit Signal2;
	plcbit Signal3;
	plcbit Signal4;
	plcbit StartSequence;
	plcbit Continue;
	plcbit EndSequence;
	plcbit Recovery;
	plcbit OffsetShift;
	plcbit PhaseShift;
	plcbit Active;
	plcbit Error;
	plcbit UpdateDone;
	plcbit Standby;
	plcbit CommandBusy;
	plcbit CommandAborted;
	plcbit InCompensation;
	plcbit InSync;
	plcbit RecoveryDone;
	plcbit OffsetDone;
	plcbit PhasingDone;
};
_BUR_PUBLIC void MpAxisCamSequencer(struct MpAxisCamSequencer* inst);
struct MC_MoveVelocity
{	unsigned long Axis;
	float Velocity;
	float Acceleration;
	float Deceleration;
	unsigned char Direction;
	unsigned short ErrorID;
	unsigned long C_Axis;
	float C_Velocity;
	float C_Acceleration;
	float C_Deceleration;
	unsigned char C_Direction;
	unsigned char LockIDPar;
	unsigned short C_ErrorID;
	unsigned char state;
	unsigned char MoveID;
	plcbit Execute;
	plcbit InVelocity;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
	plcbit C_Execute;
	plcbit cmdExecute;
	plcbit C_InVelocity;
	plcbit C_CommandAborted;
	plcbit C_Error;
};
_BUR_PUBLIC void MC_MoveVelocity(struct MC_MoveVelocity* inst);
struct MC_BR_RegMarkCapture002
{	unsigned long Master;
	unsigned long Axis;
	signed long CutPosition;
	MC_BR_CFG_RM2_REF Configuration;
	MC_BR_ADV_RM2_REF AdvancedParameters;
	unsigned short ErrorID;
	unsigned long ValidRMs;
	unsigned short ProductsWithoutRM;
	float CorrectionValue;
	MC_BR_ADDINFO_RM2_REF AdditionalInfo;
	MC_0117_IS_TYP IS;
	unsigned long C_Master;
	unsigned long C_Axis;
	plcbit Enable;
	plcbit SearchRM;
	plcbit InitData;
	plcbit Active;
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
	plcbit DataInitialized;
	plcbit SearchDone;
};
_BUR_PUBLIC void MC_BR_RegMarkCapture002(struct MC_BR_RegMarkCapture002* inst);
_BUR_LOCAL float iVl_OldAcc;
_BUR_LOCAL plcbit iMi_LogoNegDir;
_BUR_LOCAL plcbit icmdUpdate;
_BUR_LOCAL plcbit icmdPower;
_BUR_LOCAL plcbit icmdHome;
_BUR_LOCAL_RETAIN plcbit icmdMoveVelocity;
_BUR_LOCAL plcbit icmdMoveAdditive;
_BUR_LOCAL_RETAIN plcbit icmdStop;
_BUR_LOCAL float iVl_OldAccNeg;
_BUR_LOCAL plcbit icmdErrorReset;
_BUR_LOCAL float iVl_OldVelocity;
_BUR_LOCAL struct MC_MoveVelocity iFb_MC_MoveVelocity_0;
_BUR_LOCAL struct MpAxisBasic iFb_SlaveAx;
_BUR_LOCAL MpAxisBasicParType iBasicParSlave;
_BUR_LOCAL MpAxisBasicParType iParaSlave;
_BUR_LOCAL AxisCtrl_typ iCutCtrl;
_BUR_LOCAL MpAxisBasicParType iParamMaster;
_BUR_LOCAL MpAxisCamSequencerParType iAx_CamSequence;
_BUR_LOCAL Joglim_enum iJogLimState;
_BUR_LOCAL AxStep_enum iAxStep_enum;
_BUR_LOCAL struct MpAxisBasic iFb_AxisSlave;
_BUR_LOCAL struct MpAxisBasic iFb_AxisMater;
_BUR_LOCAL struct MpAxisCamSequencer iFb_CamSequ;
_BUR_LOCAL struct MC_BR_RegMarkCapture002 iFb_RegCap;
_BUR_LOCAL MC_BR_ADV_RM2_REF iRegCapAdvPar;
_BUR_LOCAL MC_BR_CFG_RM2_REF iRegCapConfig;
_BUR_LOCAL double iAbsVal;
_BUR_LOCAL plcbit icmdMoveAbsoulte;
_BUR_LOCAL float HOMING_VEL;
_BUR_LOCAL float HOFFSET_SINGLE;
_BUR_LOCAL float SPEED;
_BUR_LOCAL float ZEROSPD;
_BUR_LOCAL float SCALSPEEDTEN;
_BUR_LOCAL float START_VEL;
_BUR_LOCAL float INIT_FIHNRD;
_BUR_LOCAL float INIT_FTHOUSAND;
_BUR_LOCAL float INIT_THOUSAND;
_BUR_LOCAL float UPPER_CUT_POS;
_BUR_LOCAL float HOFFSET_DUAL;
_BUR_LOCAL float LOWER_CUT_POS;
_BUR_LOCAL double HOFFSET_NEGDUAL;
_BUR_LOCAL double FIRST_CUT_UPPER;
_BUR_LOCAL double HOME_POS;
_BUR_LOCAL double SEC_CUT_UPPER;
_BUR_LOCAL double FIRST_CUT_LOWER;
_BUR_LOCAL double MAX_POS_AXIS;
_BUR_LOCAL double SEC_CUT_LOWER;
_BUR_LOCAL double HOME_OFFSET;
_BUR_LOCAL double LOWER_BUFER;
_BUR_LOCAL double ZERO;
_BUR_LOCAL float PRODUCT_LENGTH;
_BUR_LOCAL float PER_SEC;
_BUR_LOCAL float iMI_CutSetJogAcc;
_BUR_LOCAL float iMI_CutSetJogDeacc;
_BUR_LOCAL float iMI_CutActSpeed;
_BUR_LOCAL float iMI_CutSetJogVel;
