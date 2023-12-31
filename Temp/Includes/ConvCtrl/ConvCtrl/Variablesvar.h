/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1703598611_10_
#define _BUR_1703598611_10_

#include <bur/plctypes.h>

/* Constants */
#ifdef _REPLACE_CONST
 #define K_ZERO 0.0
 #define LOWER_CUT_POS 2653.0
 #define PRINT_MARK_LIMIT 300.0
 #define SCALSPEEDTEN 10000.0f
 #define SPEED 0.25f
 #define INIT_FIHNRD 500.0f
 #define INIT_FTHOUSAND 5000.0f
 #define PER_SEC 60.0f
 #define PRODUCT_LENGTH 700.0f
 #define INIT_THOUSAND 1000.0f
 #define START_VEL 145.0f
 #define UPPER_CUT_POS 3013.0
 #define ZEROSPD 0.0f
 #define HOFFSET_SINGLE 1033.0f
 #define HOMING_VEL 500.0f
#else
 _LOCAL_CONST double K_ZERO;
 _LOCAL_CONST double LOWER_CUT_POS;
 _LOCAL_CONST double PRINT_MARK_LIMIT;
 _LOCAL_CONST float SCALSPEEDTEN;
 _LOCAL_CONST float SPEED;
 _LOCAL_CONST float INIT_FIHNRD;
 _LOCAL_CONST float INIT_FTHOUSAND;
 _LOCAL_CONST float PER_SEC;
 _LOCAL_CONST float PRODUCT_LENGTH;
 _LOCAL_CONST float INIT_THOUSAND;
 _LOCAL_CONST float START_VEL;
 _LOCAL_CONST double UPPER_CUT_POS;
 _LOCAL_CONST float ZEROSPD;
 _LOCAL_CONST float HOFFSET_SINGLE;
 _LOCAL_CONST float HOMING_VEL;
#endif


/* Variables */
_BUR_LOCAL float iMI_ConSetJogVel;
_BUR_LOCAL float iMI_ConSetJogDeacc;
_BUR_LOCAL float iMI_ConSetJogAcc;
_BUR_LOCAL float iMI_ConActSpeed;
_BUR_LOCAL float iMI_ConSetSpeed;
_BUR_LOCAL double HOFFSET_DUAL;
_BUR_LOCAL enum AxStep_enum iAxStepMaster;
_BUR_LOCAL struct MpAxisCamSequencer iFb_CamSequ;
_BUR_LOCAL struct MpAxisBasic iFb_MasterAx;
_BUR_LOCAL struct MC_MoveVelocity iFb_MC_MoveVelocity_0;
_BUR_LOCAL struct MC_BR_CFG_RM2_REF iRegCapConfig;
_BUR_LOCAL struct MC_BR_SetHardwareInputs iVa_MasterInputs;
_BUR_LOCAL struct MC_BR_RegMarkCapture002 iFb_RegCap;
_BUR_LOCAL struct MpAxisCamSequencerParType iAx_CamSequence;
_BUR_LOCAL struct MpAxisBasicParType iParaSlave;
_BUR_LOCAL struct MpAxisBasicInfoType iFb_BasicInfo;
_BUR_LOCAL struct AxisCtrl_typ iConCtrl;
_BUR_LOCAL struct ACP10APNWCPA_typ iRegCapAdvPar;
_BUR_LOCAL struct MpAxisBasicParType iParamMaster;
_BUR_LOCAL struct MpAxisBasicParType iBasicParamMaster;
_BUR_LOCAL plcbit icmdErrorReset;
_BUR_LOCAL plcbit icmdHome;
_BUR_LOCAL plcbit icmdMoveAdditive;
_BUR_LOCAL_RETAIN plcbit icmdMoveVelocity;
_BUR_LOCAL plcbit icmdPower;
_BUR_LOCAL_RETAIN plcbit icmdStop;
_BUR_LOCAL plcbit icmdUpdate;
_BUR_LOCAL plcbit iMi_LogoNegDir;
_BUR_LOCAL double iVa_OldRecPosition;
_BUR_LOCAL float iVl_OldAcc;
_BUR_LOCAL float iVl_OldAccNeg;
_BUR_LOCAL double iVl_OldVelocity;





__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/ConvCtrl/ConvCtrl/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpAxis/MpAxis.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Acp10_MC/acp10_mc.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MC_RegMa/MC_RegMa.fun\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1703598611_10_ */

