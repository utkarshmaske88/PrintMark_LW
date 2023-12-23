/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1703356586_8_
#define _BUR_1703356586_8_

#include <bur/plctypes.h>

/* Constants */
#ifdef _REPLACE_CONST
 #define LOWER_CUT_POS 2653.0f
 #define UPPER_CUT_POS 3013.0f
 #define LIMIT_ERROR_PRODUCT 5
 #define TEN 10.0f
#else
 _LOCAL_CONST float LOWER_CUT_POS;
 _LOCAL_CONST float UPPER_CUT_POS;
 _LOCAL_CONST signed short LIMIT_ERROR_PRODUCT;
 _LOCAL_CONST float TEN;
#endif


/* Variables */
_BUR_LOCAL float iMI_AvgBagLen;
_BUR_LOCAL float iMI_LastBagLen;
_BUR_LOCAL plcwstring iMi_SelectedMode[81];
_BUR_LOCAL plcwstring iMi_StatusTxt[81];
_BUR_LOCAL plcbit iMi_CutModeSelected;
_BUR_LOCAL struct AutoCtrl_typ iAutoCtrl;
_BUR_LOCAL enum Reset_enum iResetState;
_BUR_LOCAL enum AutoCtrl_enum iAutoCtrlState;
_BUR_LOCAL unsigned long MasterAx;
_BUR_LOCAL unsigned long SlaveSize;
_BUR_LOCAL unsigned long MasterSize;
_BUR_LOCAL unsigned long SlaveAx;
_BUR_LOCAL unsigned short iStatus_MasterAx;
_BUR_LOCAL unsigned long iStatus_SlaveAx;
_BUR_LOCAL unsigned long SizeCam;
_BUR_LOCAL unsigned long CamAdd;
_BUR_LOCAL unsigned short iStatus_RegCapt;
_BUR_LOCAL unsigned short iStatus_CamSeq;
_BUR_LOCAL unsigned short iStatus_ConvCtrl;
_BUR_LOCAL unsigned long SizeCutter;
_BUR_LOCAL unsigned long SizeConv;
_BUR_LOCAL unsigned long ConvAdd;
_BUR_LOCAL unsigned long RegSize;
_BUR_LOCAL unsigned long RegAdd;
_BUR_LOCAL unsigned long CutterAdd;
_BUR_LOCAL unsigned short iStatus_CutCtrl;
_BUR_LOCAL struct MpAxisBasic *pSlaveAx;
_BUR_LOCAL struct MpAxisCamSequencer *pAx_CamSeq;
_BUR_LOCAL struct MpAxisBasic *pMasterAx;
_BUR_LOCAL struct AxisCtrl_typ *pConvCtrl;
_BUR_LOCAL struct MC_BR_RegMarkCapture002 *pRegCapture;
_BUR_LOCAL struct AxisCtrl_typ *pCutterCtrl;





__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/AutoCtrl/AutoCtrl/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpAxis/MpAxis.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MC_RegMa/MC_RegMa.fun\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1703356586_8_ */

