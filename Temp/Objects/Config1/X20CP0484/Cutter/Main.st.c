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

__AS__Action__SingleCutter();



((*(unsigned long*)&(iFb_AxisMater.MpLink))=((unsigned long)(&gmlMaster)));
(iFb_AxisMater.Enable=1);
((*(unsigned long*)&(iFb_AxisMater.Parameters))=((unsigned long)(&iParamMaster)));
(iFb_AxisMater.Axis=((unsigned long)(&gAxMaster)));
MpAxisBasic(&iFb_AxisMater);


__AS__Action__CamSingle();

((*(unsigned long*)&(iFb_CamSequ.MpLink))=((unsigned long)(&gmlSlave)));
(iFb_CamSequ.Enable=1);
((*(unsigned long*)&(iFb_CamSequ.Parameters))=((unsigned long)(&iAx_CamSequence)));
((*(unsigned long*)&(iFb_CamSequ.MpLinkMaster))=((unsigned long)(&gmlMaster)));
(iFb_CamSequ.StartSequence=(iFb_CamSequ.Info.MasterReady&iFb_CamSequ.Info.SlaveReady));
MpAxisCamSequencer(&iFb_CamSequ);

}}
#line 29 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.nodebug"
#line 31 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{

(iFb_CamSequ.Enable=0);
(iFb_AxisMater.Enable=0);
(iFb_AxisMater.Enable=0);
MpAxisBasic(&iFb_AxisMater);
MpAxisBasic(&iFb_AxisMater);
MpAxisCamSequencer(&iFb_CamSequ);
(iFb_SlaveAx.Enable=0);
MpAxisBasic(&iFb_SlaveAx);
}}
#line 41 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.nodebug"
#line 16 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/SingCutter.st"
static void __AS__Action__SingleCutter(void){
{
(iFb_SlaveAx.Enable=1);
((*(unsigned long*)&(iFb_SlaveAx.MpLink))=((unsigned long)(&gmlSlave)));
(iFb_SlaveAx.Axis=((unsigned long)(&gAxSlave)));

((*(unsigned long*)&(iFb_SlaveAx.Parameters))=((unsigned long)(&iBasicParameters)));
MpAxisBasic(&iFb_SlaveAx);






























(iBasicParameters.Torque.Limit=(8.00000011920928955078E-01));


if((((unsigned long)(unsigned char)icmdStop==(unsigned long)(unsigned char)1))){
(iFb_SlaveAx.Stop=1);
if((((unsigned long)(unsigned char)iFb_SlaveAx.Stopped==(unsigned long)(unsigned char)1))){
(iFb_SlaveAx.Stop=0);
(icmdStop=0);
}
}


if((((unsigned long)(unsigned char)iFb_SlaveAx.Error==(unsigned long)(unsigned char)1))){
(iAxStep_enum=9);
}


switch(iAxStep_enum){


case 0:{
(iAxStep_enum=1);


}break;case 1:{
if((((unsigned long)(unsigned char)iFb_SlaveAx.Info.ReadyToPowerOn==(unsigned long)(unsigned char)1))){
(iAxStep_enum=3);
}


}break;case 3:{
(icmdPower=1);
if((((unsigned long)(unsigned char)iFb_SlaveAx.PowerOn==(unsigned long)(unsigned char)1))){
if((iFb_SlaveAx.PowerOn&((iFb_SlaveAx.Position<LOWER_CUT_POS)))){
(icmdUpdate=1);
if((((unsigned long)(unsigned char)iFb_SlaveAx.UpdateDone==(unsigned long)(unsigned char)1))){
(iAxStep_enum=6);
(icmdUpdate=0);
}
}
if((iFb_SlaveAx.PowerOn&((iFb_SlaveAx.Position>UPPER_CUT_POS)))){
(icmdUpdate=1);
if((((unsigned long)(unsigned char)iFb_SlaveAx.UpdateDone==(unsigned long)(unsigned char)1))){
(iAxStep_enum=5);
(icmdUpdate=0);
}
}
}


}break;case 6:{
(iBasicParameters.Home.Mode=5);
(iBasicParameters.Home.HomingDirection=1);
(iBasicParameters.Home.SensorOffset=HOFFSET_SINGLE);
(iBasicParameters.Home.HomingVelocity=HOMING_VEL);
(iBasicParameters.Home.StartVelocity=START_VEL);

(icmdHome=1);
}break;case 5:{
(iBasicParameters.Home.Mode=5);
(iBasicParameters.Home.HomingDirection=0);
(iBasicParameters.Home.SensorOffset=HOFFSET_SINGLE);
(iBasicParameters.Home.HomingVelocity=HOMING_VEL);
(iBasicParameters.Home.StartVelocity=START_VEL);


(icmdHome=1);

}break;case 8:{

if((((unsigned long)(unsigned char)iFb_SlaveAx.IsHomed==(unsigned long)(unsigned char)1))){
(icmdHome=0);
(iAxStep_enum=8);
}

if((((unsigned long)(unsigned char)iFb_SlaveAx.Error==(unsigned long)(unsigned char)1))){
(iAxStep_enum=9);
}
if((((unsigned long)(unsigned char)icmdMoveAdditive==(unsigned long)(unsigned char)1))){
(iFb_SlaveAx.MoveAdditive=1);
(icmdMoveAdditive=0);
(icmdHome=0);
}


}break;case 9:{
(icmdPower=0);
(icmdMoveVelocity=0);
(icmdStop=0);

(icmdErrorReset=1);
if((((unsigned long)(unsigned char)iFb_SlaveAx.Error==(unsigned long)(unsigned char)0))){
(iAxStep_enum=1);
(icmdErrorReset=0);
}
}break;}
(iFb_SlaveAx.Update=icmdUpdate);
(iFb_SlaveAx.Home=icmdHome);
}}
#line 43 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.nodebug"
#line 22 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/CamAutoSingle.st"
static void __AS__Action__CamSingle(void){
{(iAx_CamSequence.Configuration.Master=((unsigned long)(&gAxMaster)));
(iAx_CamSequence.Configuration.MasterParID=ACP10PAR_PCTRL_S_ACT);


(iAx_CamSequence.Configuration.State[0].Event[0].Type=ncST_END);
(iAx_CamSequence.Configuration.State[0].Event[0].Attribute=ncAT_ONCE);
(iAx_CamSequence.Configuration.State[0].Event[0].NextState=4);








































(iAx_CamSequence.Configuration.State[2].CamProfileIndex=65535);
(iAx_CamSequence.Configuration.State[2].MasterFactor=300);
(iAx_CamSequence.Configuration.State[2].SlaveFactor=(-400));

(iAx_CamSequence.Configuration.State[2].Event[0].Type=ncST_END);
(iAx_CamSequence.Configuration.State[2].Event[0].Attribute=ncST_END);
(iAx_CamSequence.Configuration.State[2].Event[0].NextState=1);



(iAx_CamSequence.Configuration.State[1].CamProfileIndex=65534);
(iAx_CamSequence.Configuration.State[1].MasterFactor=400);
(iAx_CamSequence.Configuration.State[1].SlaveFactor=(-900));

(iAx_CamSequence.Configuration.State[1].CompMode=ncONLYCOMP);
(iAx_CamSequence.Configuration.State[1].MasterCompDistance=400);
(iAx_CamSequence.Configuration.State[1].SlaveCompDistance=(-3200));

(iAx_CamSequence.Configuration.State[1].Event[0].Type=ncST_END);
(iAx_CamSequence.Configuration.State[1].Event[0].Attribute=ncST_END);
(iAx_CamSequence.Configuration.State[1].Event[0].NextState=2);




(iAx_CamSequence.Configuration.State[4].CamProfileIndex=65534);
(iAx_CamSequence.Configuration.State[4].MasterFactor=300);
(iAx_CamSequence.Configuration.State[4].SlaveFactor=(-400));

(iAx_CamSequence.Configuration.State[4].CompMode=ncONLYCOMP);
(iAx_CamSequence.Configuration.State[4].MasterCompDistance=100);
(iAx_CamSequence.Configuration.State[4].SlaveCompDistance=(-1500));

(iAx_CamSequence.Configuration.State[4].Event[0].Type=ncST_END);
(iAx_CamSequence.Configuration.State[4].Event[0].Attribute=ncST_END);
(iAx_CamSequence.Configuration.State[4].Event[0].NextState=5);


(iAx_CamSequence.Configuration.State[5].CamProfileIndex=65535);
(iAx_CamSequence.Configuration.State[5].MasterFactor=300);
(iAx_CamSequence.Configuration.State[5].SlaveFactor=(-400));

(iAx_CamSequence.Configuration.State[5].Event[0].Type=ncST_END);
(iAx_CamSequence.Configuration.State[5].Event[0].Attribute=ncST_END);
(iAx_CamSequence.Configuration.State[5].Event[0].NextState=6);



(iAx_CamSequence.Configuration.State[6].CamProfileIndex=65534);
(iAx_CamSequence.Configuration.State[6].MasterFactor=300);
(iAx_CamSequence.Configuration.State[6].SlaveFactor=(-400));

(iAx_CamSequence.Configuration.State[6].CompMode=ncONLYCOMP);
(iAx_CamSequence.Configuration.State[6].MasterCompDistance=400);
(iAx_CamSequence.Configuration.State[6].SlaveCompDistance=(-3200));

(iAx_CamSequence.Configuration.State[6].Event[0].Type=ncST_END);
(iAx_CamSequence.Configuration.State[6].Event[0].Attribute=ncST_END);
(iAx_CamSequence.Configuration.State[6].Event[0].NextState=2);



}}
#line 43 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.nodebug"

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
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MC_RegMa/MC_RegMa.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpAlarmX/MpAlarmX.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpAlarmX/MpAlarmXError.typ\\\" scope \\\"global\\\"\\n\"");
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
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MC_RegMa/MC_RegMa.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpAlarmX/MpAlarmX.fun\\\" scope \\\"global\\\"\\n\"");
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
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MC_RegMa/MC_RegMa.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Cutter/Cutter/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Cutter/Cutter/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Temp/Objects/Config1/X20CP0484/Cutter/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Temp/Objects/Config1/X20CP0484/Cutter/Main.st.c\\\" \\\"C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.st\\\"\\n\"");
__asm__(".previous");

__asm__(".section \".plciec\"");
__asm__(".ascii \"plcdata_const 'HOMING_VEL'\\n\"");
__asm__(".ascii \"plcdata_const 'HOFFSET_SINGLE'\\n\"");
__asm__(".ascii \"plcdata_const 'START_VEL'\\n\"");
__asm__(".ascii \"plcdata_const 'UPPER_CUT_POS'\\n\"");
__asm__(".ascii \"plcdata_const 'LOWER_CUT_POS'\\n\"");
__asm__(".ascii \"plcdata_const 'ACP10PAR_PCTRL_S_ACT'\\n\"");
__asm__(".ascii \"plcdata_const 'ncAT_ONCE'\\n\"");
__asm__(".ascii \"plcdata_const 'ncONLYCOMP'\\n\"");
__asm__(".ascii \"plcdata_const 'ncST_END'\\n\"");
__asm__(".previous");
