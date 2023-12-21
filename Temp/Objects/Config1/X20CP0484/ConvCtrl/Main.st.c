#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Temp/Objects/Config1/X20CP0484/ConvCtrl/Mainst.h"
#line 1 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.nodebug"
#line 16 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{

(iBasicParamMaster.Acceleration=480000);
(iBasicParamMaster.Deceleration=4800000);
(iBasicParamMaster.Jog.Velocity=45);
(iBasicParamMaster.Home.Mode=2);
(iBasicParamMaster.Home.StartVelocity=200);
(iBasicParamMaster.Home.HomingDirection=0);
(iBasicParamMaster.Home.StartDirection=0);
(iBasicParamMaster.Home.SwitchEdge=1);
}}
#line 26 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.nodebug"
#line 28 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{

(iFb_MasterAx.Enable=1);
((*(unsigned long*)&(iFb_MasterAx.MpLink))=((unsigned long)(&gmlMaster)));
(iFb_MasterAx.Axis=((unsigned long)(&gAxMaster)));

((*(unsigned long*)&(iFb_MasterAx.Parameters))=((unsigned long)(&iBasicParamMaster)));
MpAxisBasic(&iFb_MasterAx);






























(iBasicParamMaster.Torque.Limit=(8.00000011920928955078E-01));


if((((unsigned long)(unsigned char)icmdStop==(unsigned long)(unsigned char)1))){
(iFb_MasterAx.Stop=1);
if((((unsigned long)(unsigned char)iFb_MasterAx.Stopped==(unsigned long)(unsigned char)1))){
(iFb_MasterAx.Stop=0);
(icmdStop=0);
}
}


if((((unsigned long)(unsigned char)iFb_MasterAx.Error==(unsigned long)(unsigned char)1))){
(iAxStepMaster=9);
}


switch(iAxStepMaster){


case 0:{
(iAxStepMaster=1);


}break;case 1:{
if((((unsigned long)(unsigned char)iFb_MasterAx.Info.ReadyToPowerOn==(unsigned long)(unsigned char)1))){
(iAxStepMaster=2);
}


}break;case 2:{
(icmdPower=1);
if(iFb_MasterAx.PowerOn){

(icmdHome=1);
if((((unsigned long)(unsigned char)gAutoMode==(unsigned long)(unsigned char)1))){
(iAxStepMaster=3);
}else if((((unsigned long)(unsigned char)gManulMode==(unsigned long)(unsigned char)1))){
(iAxStepMaster=6);
}
}


}break;case 6:{
if(iConCtrl.Cmd.JogFwd){
(iAxStepMaster=4);
}

if(iConCtrl.Cmd.JogBack){
(iAxStepMaster=5);
}
(iVa_OldRecPosition=K_ZERO);
if((((unsigned long)(unsigned char)iConCtrl.Cmd.Start==(unsigned long)(unsigned char)0))){
(iAxStepMaster=0);
(icmdPower=0);
}



}break;case 4:{

(iFb_MasterAx.JogPositive=1);
if((iConCtrl.Cmd.JogFwd^1)){
(iFb_MasterAx.JogPositive=0);
(iAxStepMaster=6);
}


}break;case 5:{
(iFb_MasterAx.JogNegative=1);

if(((iFb_MasterAx.JogNegative&(~iConCtrl.Cmd.PrintMark&Edge0000100000&1?((Edge0000100000=iConCtrl.Cmd.PrintMark&1),1):((Edge0000100000=iConCtrl.Cmd.PrintMark&1),0)))|((iFb_MasterAx.JogNegative&~Edge0000100001&1?((Edge0000100001=iFb_MasterAx.JogNegative&1),1):((Edge0000100001=iFb_MasterAx.JogNegative&1),0))&iConCtrl.Cmd.PrintMark))){
(iVa_OldRecPosition=iFb_MasterAx.Position);
}

if(((((iVa_OldRecPosition-iFb_MasterAx.Position)>PRINT_MARK_LIMIT))&((iVa_OldRecPosition!=K_ZERO)))){
(iFb_MasterAx.JogNegative=0);
(iConCtrl.Cmd.JogBack=0);
(iAxStepMaster=6);
}else{
(iConCtrl.Status.JogNegReady=1);
}


}break;case 9:{
(icmdPower=0);
(icmdMoveVelocity=0);
(icmdStop=0);

(icmdErrorReset=1);
if((((unsigned long)(unsigned char)iFb_MasterAx.Error==(unsigned long)(unsigned char)0))){
(iAxStepMaster=1);
(icmdErrorReset=0);
}
}break;}

(iFb_MasterAx.Update=icmdUpdate);
(iFb_MasterAx.Home=icmdHome);
(iFb_MasterAx.Power=icmdPower);

(iConCtrl.Cmd.PrintMark=gIR_Trigger);
(iVa_MasterInputs.Enable=1);
(iVa_MasterInputs.Axis=((unsigned long)(&gAxMaster)));
(iVa_MasterInputs.HomeSwitch=gIR_Trigger);
MC_BR_SetHardwareInputs(&iVa_MasterInputs);

if((((unsigned long)(unsigned char)iConCtrl.Cmd.Start==(unsigned long)(unsigned char)0))){
(iAxStepMaster=0);
}
}imp1_else14_0:imp1_end14_0:;}
#line 175 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.nodebug"
#line 177 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{

(iFb_MasterAx.Enable=0);
MpAxisBasic(&iFb_MasterAx);
(iVa_MasterInputs.Enable=0);
MC_BR_SetHardwareInputs(&iVa_MasterInputs);
}}
#line 183 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.nodebug"

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
__asm__(".ascii \"iecfile \\\"Temp/Objects/Config1/X20CP0484/ConvCtrl/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".previous");

__asm__(".section \".plciec\"");
__asm__(".ascii \"plcdata_const 'K_ZERO'\\n\"");
__asm__(".ascii \"plcdata_const 'PRINT_MARK_LIMIT'\\n\"");
__asm__(".previous");
