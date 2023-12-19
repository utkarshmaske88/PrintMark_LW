#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Temp/Objects/Config1/X20CP0484/Cutter/Mainst.h"
#line 1 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.nodebug"
#line 2 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{


}}
#line 5 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.nodebug"
#line 7 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{





((*(unsigned long*)&(iFb_AxisMater.MpLink))=((unsigned long)(&gAxisMaster)));
(iFb_AxisMater.Enable=1);
((*(unsigned long*)&(iFb_AxisMater.Parameters))=((unsigned long)(&iParamMaster)));
(iFb_AxisMater.Axis=((unsigned long)(&gAxMaster)));
MpAxisBasic(&iFb_AxisMater);

((*(unsigned long*)&(iFb_AxisSlave.MpLink))=((unsigned long)(&gAxisSlave)));
(iFb_AxisSlave.Enable=1);
((*(unsigned long*)&(iFb_AxisSlave.Parameters))=((unsigned long)(&iParaSlave)));
(iFb_AxisSlave.Axis=((unsigned long)(&gAxSlave)));
MpAxisBasic(&iFb_AxisSlave);

__AS__Action__CamSingle();

((*(unsigned long*)&(iFb_CamSequ.MpLink))=((unsigned long)(&gAxisSlave)));
(iFb_CamSequ.Enable=1);
((*(unsigned long*)&(iFb_CamSequ.Parameters))=((unsigned long)(&iAx_CamSequence)));
((*(unsigned long*)&(iFb_CamSequ.MpLinkMaster))=((unsigned long)(&gAxisMaster)));
(iFb_CamSequ.StartSequence=(iFb_CamSequ.Info.MasterReady&iFb_CamSequ.Info.SlaveReady));
MpAxisCamSequencer(&iFb_CamSequ);

}}
#line 34 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.nodebug"
#line 36 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{

(iFb_CamSequ.Enable=0);
(iFb_AxisSlave.Enable=0);
(iFb_AxisMater.Enable=0);
MpAxisBasic(&iFb_AxisMater);
MpAxisBasic(&iFb_AxisSlave);
MpAxisCamSequencer(&iFb_CamSequ);
(iFb_SlaveAx.Enable=0);
MpAxisBasic(&iFb_SlaveAx);
}}
#line 46 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.nodebug"
#line 22 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/CamAutoSingle.st"
static void __AS__Action__CamSingle(void){
{(iAx_CamSequence.Configuration.Master=((unsigned long)(&gAxMaster)));
(iAx_CamSequence.Configuration.MasterParID=ACP10PAR_PCTRL_S_ACT);


(iAx_CamSequence.Configuration.State[0].Event[0].Type=ncST_END);
(iAx_CamSequence.Configuration.State[0].Event[0].Attribute=ncST_END);
(iAx_CamSequence.Configuration.State[0].Event[0].NextState=1);




(iAx_CamSequence.Configuration.State[1].CamProfileIndex=65534);
(iAx_CamSequence.Configuration.State[1].MasterFactor=400);
(iAx_CamSequence.Configuration.State[1].SlaveFactor=(-900));

(iAx_CamSequence.Configuration.State[1].CompMode=ncONLYCOMP);
(iAx_CamSequence.Configuration.State[1].MasterCompDistance=900);
(iAx_CamSequence.Configuration.State[1].SlaveCompDistance=(-450));

(iAx_CamSequence.Configuration.State[1].Event[0].Type=ncST_END);
(iAx_CamSequence.Configuration.State[1].Event[0].Attribute=ncST_END);
(iAx_CamSequence.Configuration.State[1].Event[0].NextState=2);


(iAx_CamSequence.Configuration.State[2].CamProfileIndex=65535);
(iAx_CamSequence.Configuration.State[2].MasterFactor=400);
(iAx_CamSequence.Configuration.State[2].SlaveFactor=(-900));

(iAx_CamSequence.Configuration.State[2].Event[0].Type=ncST_END);
(iAx_CamSequence.Configuration.State[2].Event[0].Attribute=ncST_END);
(iAx_CamSequence.Configuration.State[2].Event[0].NextState=3);


(iAx_CamSequence.Configuration.State[3].CamProfileIndex=65534);
(iAx_CamSequence.Configuration.State[3].MasterFactor=400);
(iAx_CamSequence.Configuration.State[3].SlaveFactor=(-900));

(iAx_CamSequence.Configuration.State[3].CompMode=ncONLYCOMP);
(iAx_CamSequence.Configuration.State[3].MasterCompDistance=400);
(iAx_CamSequence.Configuration.State[3].SlaveCompDistance=(-2250));

(iAx_CamSequence.Configuration.State[3].Event[0].Type=ncST_END);
(iAx_CamSequence.Configuration.State[3].Event[0].Attribute=ncST_END);
(iAx_CamSequence.Configuration.State[3].Event[0].NextState=1);
}}
#line 48 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.nodebug"

void __AS__ImplInitMain_st(void){__BUR__ENTRY_INIT_FUNCT__();}

__asm__(".section \".plc\"");
__asm__(".ascii \"iecfile \\\"Logical/Global.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Acp10man/Acp10man.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/NcGlobal/NcGlobal.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpAxis/MpAxis.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpAxis/MpAxisError.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpAxis/MpAxisAlarm.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Acp10_MC/acp10_mc.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpBase/MpBase.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpCom/MpCom.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpCom/MpComError.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/sys_lib/sys_lib.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/brsystem/brsystem.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/NcGlobal/NcGlobal.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpAxis/MpAxis.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Acp10_MC/acp10_mc.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpBase/MpBase.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpCom/MpCom.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/sys_lib/sys_lib.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/brsystem/brsystem.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Global.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Temp/Includes/AS_TempDecl/Config1/GlobalComponents/MpComponents.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Acp10par/Acp10par.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/NcGlobal/NcGlobal.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Acp10_MC/acp10_mc.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpBase/MpBase.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpCom/MpCom.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/sys_lib/sys_lib.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/brsystem/brsystem.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Cutter/Cutter/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Cutter/Cutter/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Temp/Objects/Config1/X20CP0484/Cutter/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Temp/Objects/Config1/X20CP0484/Cutter/Main.st.c\\\" \\\"C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.st\\\"\\n\"");
__asm__(".previous");

__asm__(".section \".plciec\"");
__asm__(".ascii \"plcdata_const 'ACP10PAR_PCTRL_S_ACT'\\n\"");
__asm__(".ascii \"plcdata_const 'ncONLYCOMP'\\n\"");
__asm__(".ascii \"plcdata_const 'ncST_END'\\n\"");
__asm__(".previous");
