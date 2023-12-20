#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Temp/Objects/Config1/X20CP0484/ConvCtrl/Mainst.h"
#line 1 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.nodebug"
#line 2 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{


}}
#line 5 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.nodebug"
#line 7 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{

__AS__Action__ConvAXisAxn();
}}
#line 10 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.nodebug"
#line 12 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{


}}
#line 15 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.nodebug"
#line 16 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/ConvAxis.st"
static void __AS__Action__ConvAXisAxn(void){
{
(iFb_MasterAx.Enable=1);
((*(unsigned long*)&(iFb_MasterAx.MpLink))=((unsigned long)(&gmlSlave)));
(iFb_MasterAx.Axis=((unsigned long)(&gAxSlave)));

((*(unsigned long*)&(iFb_MasterAx.Parameters))=((unsigned long)(&iBasicParameters)));
MpAxisBasic(&iFb_MasterAx);






























(iBasicParameters.Torque.Limit=(8.00000011920928955078E-01));


if((((unsigned long)(unsigned char)icmdStop==(unsigned long)(unsigned char)1))){
(iFb_MasterAx.Stop=1);
if((((unsigned long)(unsigned char)iFb_MasterAx.Stopped==(unsigned long)(unsigned char)1))){
(iFb_MasterAx.Stop=0);
(icmdStop=0);
}
}


if((((unsigned long)(unsigned char)iFb_MasterAx.Error==(unsigned long)(unsigned char)1))){
(iAxStep_enum=7);
}


switch(iAxStep_enum){


case 0:{
(iAxStep_enum=1);


}break;case 1:{
if((((unsigned long)(unsigned char)iFb_MasterAx.Info.ReadyToPowerOn==(unsigned long)(unsigned char)1))){
(iAxStep_enum=2);
}


}break;case 2:{
(icmdPower=1);
if((((unsigned long)(unsigned char)iFb_MasterAx.PowerOn==(unsigned long)(unsigned char)1))){
if((iFb_MasterAx.PowerOn&((iFb_MasterAx.Position<LOWER_CUT_POS)))){
(icmdUpdate=1);
if((((unsigned long)(unsigned char)iFb_MasterAx.UpdateDone==(unsigned long)(unsigned char)1))){
(iAxStep_enum=4);
(icmdUpdate=0);
}
}
if((iFb_MasterAx.PowerOn&((iFb_MasterAx.Position>UPPER_CUT_POS)))){
(icmdUpdate=1);
if((((unsigned long)(unsigned char)iFb_MasterAx.UpdateDone==(unsigned long)(unsigned char)1))){
(iAxStep_enum=3);
(icmdUpdate=0);
}
}
}


}break;case 4:{
(iBasicParameters.Home.Mode=5);
(iBasicParameters.Home.HomingDirection=1);
(iBasicParameters.Home.SensorOffset=HOFFSET_SINGLE);
(iBasicParameters.Home.HomingVelocity=HOMING_VEL);
(iBasicParameters.Home.StartVelocity=START_VEL);

(icmdHome=1);
}break;case 3:{
(iBasicParameters.Home.Mode=5);
(iBasicParameters.Home.HomingDirection=0);
(iBasicParameters.Home.SensorOffset=HOFFSET_SINGLE);
(iBasicParameters.Home.HomingVelocity=HOMING_VEL);
(iBasicParameters.Home.StartVelocity=START_VEL);


(icmdHome=1);

}break;case 6:{

if((((unsigned long)(unsigned char)iFb_MasterAx.IsHomed==(unsigned long)(unsigned char)1))){
(icmdHome=0);
(iAxStep_enum=6);
}

if((((unsigned long)(unsigned char)iFb_MasterAx.Error==(unsigned long)(unsigned char)1))){
(iAxStep_enum=7);
}
if((((unsigned long)(unsigned char)icmdMoveAdditive==(unsigned long)(unsigned char)1))){
(iFb_MasterAx.MoveAdditive=1);
(icmdMoveAdditive=0);
(icmdHome=0);
}


}break;case 7:{
(icmdPower=0);
(icmdMoveVelocity=0);
(icmdStop=0);

(icmdErrorReset=1);
if((((unsigned long)(unsigned char)iFb_MasterAx.Error==(unsigned long)(unsigned char)0))){
(iAxStep_enum=1);
(icmdErrorReset=0);
}
}break;}
(iFb_MasterAx.Update=icmdUpdate);
(iFb_MasterAx.Home=icmdHome);
(iFb_MasterAx.Power=icmdPower);

}}
#line 17 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.nodebug"

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
__asm__(".ascii \"iecfile \\\"Logical/ConvCtrl/ConvCtrl/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/ConvCtrl/ConvCtrl/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Temp/Objects/Config1/X20CP0484/ConvCtrl/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Temp/Objects/Config1/X20CP0484/ConvCtrl/Main.st.c\\\" \\\"C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.st\\\"\\n\"");
__asm__(".previous");

__asm__(".section \".plciec\"");
__asm__(".ascii \"plcdata_const 'HOMING_VEL'\\n\"");
__asm__(".ascii \"plcdata_const 'HOFFSET_SINGLE'\\n\"");
__asm__(".ascii \"plcdata_const 'START_VEL'\\n\"");
__asm__(".ascii \"plcdata_const 'UPPER_CUT_POS'\\n\"");
__asm__(".ascii \"plcdata_const 'LOWER_CUT_POS'\\n\"");
__asm__(".previous");
