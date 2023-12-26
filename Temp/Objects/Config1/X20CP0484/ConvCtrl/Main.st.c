#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Temp/Objects/Config1/X20CP0484/ConvCtrl/Mainst.h"
#line 1 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.nodebug"
#line 17 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.st"
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
#line 27 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.nodebug"
#line 29 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{


((*(unsigned long*)&(iFb_MasterAx.MpLink))=((unsigned long)(&gmlMaster)));
(iFb_MasterAx.Axis=((unsigned long)(&gAxMaster)));

((*(unsigned long*)&(iFb_MasterAx.Parameters))=((unsigned long)(&iBasicParamMaster)));
MpAxisBasic(&iFb_MasterAx);


(iBasicParamMaster.Velocity=((iMI_ConSetSpeed*PRODUCT_LENGTH)/PER_SEC));




if((((iMI_ConSetSpeed!=((iFb_MasterAx.Velocity*PER_SEC)/PRODUCT_LENGTH)))|((iMI_ConSetJogAcc!=((iBasicParamMaster.Jog.Acceleration*PER_SEC)/PRODUCT_LENGTH)))|((iMI_ConSetJogDeacc!=((iBasicParamMaster.Jog.Deceleration*PER_SEC)/PRODUCT_LENGTH)))|((iMI_ConSetJogVel!=((iBasicParamMaster.Jog.Velocity*PER_SEC)/PRODUCT_LENGTH))))){
(iFb_MasterAx.Update=1);
if(iFb_MasterAx.UpdateDone){
(iFb_MasterAx.Update=0);
}
}



(iBasicParamMaster.Jog.Acceleration=((iMI_ConSetJogAcc*PRODUCT_LENGTH)/PER_SEC));
(iBasicParamMaster.Jog.Deceleration=((iMI_ConSetJogDeacc*PRODUCT_LENGTH)/PER_SEC));
(iBasicParamMaster.Jog.Velocity=((iMI_ConSetJogVel*PRODUCT_LENGTH)/PER_SEC));
(iMI_ConActSpeed=((iFb_MasterAx.Velocity*PER_SEC)/PRODUCT_LENGTH));

if((((unsigned long)(unsigned char)iFb_MasterAx.Stop==(unsigned long)(unsigned char)1))){
if((((unsigned long)(unsigned char)iFb_MasterAx.Stopped==(unsigned long)(unsigned char)1))){
(iFb_MasterAx.Stop=0);
}
}


if((((unsigned long)(unsigned char)iFb_MasterAx.Error==(unsigned long)(unsigned char)1))){
(iAxStepMaster=9);
}


switch(iAxStepMaster){


case 0:{
if((((unsigned long)(unsigned char)iConCtrl.Cmd.Start==(unsigned long)(unsigned char)1))){
(iAxStepMaster=1);
}

}break;case 1:{
if((((unsigned long)(unsigned char)iFb_MasterAx.Info.ReadyToPowerOn==(unsigned long)(unsigned char)1))){
(iAxStepMaster=2);
}


}break;case 2:{
if(iConCtrl.Cmd.AutoMode){
(iFb_MasterAx.Power=1);
}

if(iFb_MasterAx.PowerOn){

(iFb_MasterAx.Home=1);
if((((unsigned long)(unsigned char)iConCtrl.Cmd.AutoMode==(unsigned long)(unsigned char)1))){
(iAxStepMaster=3);
}else{
(iAxStepMaster=6);
}
}

}break;case 3:{

if((((unsigned long)(unsigned char)iFb_MasterAx.IsHomed==(unsigned long)(unsigned char)1))){
(iFb_MasterAx.Home=0);
}

if((((unsigned long)(unsigned char)iConCtrl.Cmd.Start==(unsigned long)(unsigned char)0))){
(iAxStepMaster=0);
}

}break;case 6:{
if((((unsigned long)(unsigned char)iFb_MasterAx.IsHomed==(unsigned long)(unsigned char)1))){
(iFb_MasterAx.Home=0);
}
if(iConCtrl.Cmd.JogFwd){
(iAxStepMaster=4);
}

if(iConCtrl.Cmd.JogBack){
(iAxStepMaster=5);
}
(iVa_OldRecPosition=K_ZERO);
if((((unsigned long)(unsigned char)iConCtrl.Cmd.Start==(unsigned long)(unsigned char)0))){
(iAxStepMaster=0);
(iFb_MasterAx.Power=0);
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

(iFb_MasterAx.Power=0);
(iFb_MasterAx.MoveVelocity=0);
(iFb_MasterAx.Home=0);
if((((unsigned long)(unsigned char)iFb_MasterAx.Error==(unsigned long)(unsigned char)0))){
(iAxStepMaster=0);
(icmdErrorReset=0);
}
}break;}


(iConCtrl.Cmd.PrintMark=gIR_Trigger);
(iVa_MasterInputs.Enable=1);
(iVa_MasterInputs.Axis=((unsigned long)(&gAxMaster)));
(iVa_MasterInputs.HomeSwitch=gIR_Trigger);
MC_BR_SetHardwareInputs(&iVa_MasterInputs);

if((((unsigned long)(unsigned char)iConCtrl.Cmd.Start==(unsigned long)(unsigned char)0))){
(iAxStepMaster=0);
}

}imp1_else21_0:imp1_end21_0:;}
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
__asm__(".ascii \"iecfile \\\"Logical/Cutter/CutCtrl.typ\\\" scope \\\"global\\\"\\n\"");
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
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpUserX/MpUserX.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpUserX/MpUserXError.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpUserX/MpUserXAlarm.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpData/MpData.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpData/MpDataError.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpData/MpDataAlarm.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/FileIO/FileIO.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/DataObj/DataObj.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsBrStr/AsBrStr.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpServer/Types.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpPackML/MpPackML.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpPackML/MpPackMLError.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpPackML/MpPackMLAlarm.typ\\\" scope \\\"global\\\"\\n\"");
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
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpUserX/MpUserX.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpData/MpData.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/FileIO/FileIO.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/DataObj/DataObj.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsBrStr/AsBrStr.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpServer/MpServer.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpPackML/MpPackML.fun\\\" scope \\\"global\\\"\\n\"");
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
__asm__(".ascii \"iecfile \\\"Logical/Libraries/FileIO/FileIO.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/DataObj/DataObj.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsBrStr/AsBrStr.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpServer/Constants.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/ConvCtrl/ConvCtrl/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/ConvCtrl/ConvCtrl/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Temp/Objects/Config1/X20CP0484/ConvCtrl/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Temp/Objects/Config1/X20CP0484/ConvCtrl/Main.st.c\\\" \\\"C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/ConvCtrl/ConvCtrl/Main.st\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Temp/Objects/Config1/X20CP0484/ConvCtrl/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".previous");

__asm__(".section \".plciec\"");
__asm__(".ascii \"plcdata_const 'PRODUCT_LENGTH'\\n\"");
__asm__(".ascii \"plcdata_const 'PER_SEC'\\n\"");
__asm__(".ascii \"plcdata_const 'PRINT_MARK_LIMIT'\\n\"");
__asm__(".ascii \"plcdata_const 'K_ZERO'\\n\"");
__asm__(".previous");
