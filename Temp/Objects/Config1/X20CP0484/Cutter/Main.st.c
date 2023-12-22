#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Temp/Objects/Config1/X20CP0484/Cutter/Mainst.h"
#line 1 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.nodebug"
#line 2 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{

(iBasicParSlave.Acceleration=10800);
(iBasicParSlave.Deceleration=108000);
(iBasicParSlave.Jog.Deceleration=108000);
(iBasicParSlave.Jog.Acceleration=108000);
(iBasicParSlave.Jog.Velocity=360);


(iRegCapAdvPar.EventSourceParID=ACP10PAR_STAT_TRIGGER1);
(iRegCapAdvPar.Edge=ncP_EDGE);
(iRegCapAdvPar.MinWidth=50);
(iRegCapAdvPar.MaxWidth=200);
(iRegCapAdvPar.WindowNeg=200);
(iRegCapAdvPar.WindowPos=200);
(iRegCapAdvPar.SensorDelay=200);
(iRegCapAdvPar.CorrectCurrentCycle=1);
(iRegCapAdvPar.CorrectionValueLimitNeg=70);
(iRegCapAdvPar.CorrectionValueLimitPos=70);

(iRegCapConfig.DistanceToSensor=1050);
(iRegCapConfig.ProductLength=700);
(iRegCapConfig.RegMarkPosition=700);
(iRegCapConfig.RegMarkOffset=10);
}}
#line 26 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.nodebug"
#line 28 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{

if(iCutCtrl.Cmd.SingleCutter){

__AS__Action__SingleCutter();

__AS__Action__CamSingle();
}else{

__AS__Action__MultCutter();

__AS__Action__CamMulti();
}

if((((signed long)iFb_SlaveAx.Info.PLCopenState==(signed long)4))){
MC_BR_RegMarkCapture002(&iFb_RegCap);
}


__AS__Action__RegCap();




((*(unsigned long*)&(iFb_CamSequ.MpLink))=((unsigned long)(&gmlSlave)));
(iFb_CamSequ.Enable=1);


((*(unsigned long*)&(iFb_CamSequ.Parameters))=((unsigned long)(&iAx_CamSequence)));


((*(unsigned long*)&(iFb_CamSequ.MpLinkMaster))=((unsigned long)(&gmlMaster)));
(iFb_CamSequ.StartSequence=(iFb_CamSequ.Info.MasterReady&iFb_CamSequ.Info.SlaveReady));


MpAxisCamSequencer(&iFb_CamSequ);


}}
#line 66 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.nodebug"
#line 68 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{


(iFb_AxisSlave.Enable=0);
MpAxisBasic(&iFb_AxisSlave);
(iFb_CamSequ.Enable=0);
MpAxisCamSequencer(&iFb_CamSequ);
}}
#line 75 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.nodebug"
#line 16 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/SingCutter.st"
static void __AS__Action__SingleCutter(void){
{
(gIR_Trigger=iFb_SlaveAx.Info.DigitalInputsStatus.Trigger1);
(iFb_SlaveAx.Enable=1);
((*(unsigned long*)&(iFb_SlaveAx.MpLink))=((unsigned long)(&gmlSlave)));
(iFb_SlaveAx.Axis=((unsigned long)(&gAxSlave)));

((*(unsigned long*)&(iFb_SlaveAx.Parameters))=((unsigned long)(&iBasicParSlave)));
MpAxisBasic(&iFb_SlaveAx);






























(iBasicParSlave.Torque.Limit=(8.00000011920928955078E-01));


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
if((((unsigned long)(unsigned char)iCutCtrl.Cmd.Start==(unsigned long)(unsigned char)1))){
(iAxStep_enum=1);
}

}break;case 1:{
if((((unsigned long)(unsigned char)iFb_SlaveAx.Info.ReadyToPowerOn==(unsigned long)(unsigned char)1))){
(iAxStep_enum=3);
}


}break;case 3:{
(iFb_SlaveAx.Power=1);
if((((unsigned long)(unsigned char)iFb_SlaveAx.PowerOn==(unsigned long)(unsigned char)1))){


if((iFb_SlaveAx.PowerOn&((iFb_SlaveAx.Position<LOWER_CUT_POS)))){
(iFb_SlaveAx.Update=1);
if((((unsigned long)(unsigned char)iFb_SlaveAx.UpdateDone==(unsigned long)(unsigned char)1))){
(iAxStep_enum=6);
(iFb_SlaveAx.Update=0);
}
}


if((iFb_SlaveAx.PowerOn&((iFb_SlaveAx.Position>UPPER_CUT_POS)))){
(iFb_SlaveAx.Update=1);
if((((unsigned long)(unsigned char)iFb_SlaveAx.UpdateDone==(unsigned long)(unsigned char)1))){
(iAxStep_enum=5);
(iFb_SlaveAx.Update=0);
}
}
}


}break;case 6:{
(iBasicParSlave.Home.Mode=5);
(iBasicParSlave.Home.HomingDirection=1);
(iBasicParSlave.Home.SensorOffset=HOFFSET_SINGLE);
(iBasicParSlave.Home.HomingVelocity=HOMING_VEL);
(iBasicParSlave.Home.StartVelocity=START_VEL);
(iFb_SlaveAx.Home=1);
(iAxStep_enum=8);


}break;case 5:{
(iBasicParSlave.Home.Mode=5);
(iBasicParSlave.Home.HomingDirection=0);
(iBasicParSlave.Home.SensorOffset=HOFFSET_SINGLE);
(iBasicParSlave.Home.HomingVelocity=HOMING_VEL);
(iBasicParSlave.Home.StartVelocity=START_VEL);
(iFb_SlaveAx.Home=1);
(iAxStep_enum=8);

}break;case 8:{

if((((unsigned long)(unsigned char)iFb_SlaveAx.IsHomed==(unsigned long)(unsigned char)1))){
(iFb_SlaveAx.Home=0);
(iAxStep_enum=8);
if((((unsigned long)(unsigned char)gAutoMode==(unsigned long)(unsigned char)1))){

}else if(gManulMode){
(iAxStep_enum=10);
}
}

}break;case 10:{
if(iCutCtrl.Cmd.JogFwd){
(iAxStep_enum=12);
}
if(iCutCtrl.Cmd.JogBack){
(iAxStep_enum=13);
}

if(((iFb_SlaveAx.Position==FIRST_CUT_LOWER))){
(iCutCtrl.Cmd.JogFwd=0);
}
}break;case 12:{
if(((((unsigned long)(unsigned char)(iCutCtrl.Cmd.JogFwd^1)==(unsigned long)(unsigned char)1))|((iFb_SlaveAx.Position==FIRST_CUT_LOWER)))){
(iFb_SlaveAx.JogPositive=0);
(iAxStep_enum=8);
}else{
(iFb_SlaveAx.JogPositive=1);
}

if(((iFb_SlaveAx.Position==FIRST_CUT_LOWER))){
(iCutCtrl.Cmd.JogFwd=0);
}

}break;case 13:{
if(((((unsigned long)(unsigned char)(iCutCtrl.Cmd.JogBack^1)==(unsigned long)(unsigned char)1))|((iFb_SlaveAx.Position==FIRST_CUT_UPPER)))){
(iFb_SlaveAx.JogNegative=0);
(iAxStep_enum=8);
}else{
(iFb_SlaveAx.JogNegative=1);
}

if(((iFb_SlaveAx.Position==FIRST_CUT_UPPER))){
(iCutCtrl.Cmd.JogBack=0);
}

}break;case 14:{
(iFb_SlaveAx.Power=0);
if(((((iFb_SlaveAx.Position<FIRST_CUT_LOWER))|((iFb_SlaveAx.Position>FIRST_CUT_UPPER)))&iFb_SlaveAx.IsHomed)){
(iFb_SlaveAx.Power=1);
(iAxStep_enum=8);
}else if(((((iFb_SlaveAx.Position<FIRST_CUT_LOWER))|((iFb_SlaveAx.Position>FIRST_CUT_UPPER)))&(iFb_SlaveAx.IsHomed^1))){
(iAxStep_enum=3);
}

}break;case 9:{
(iFb_SlaveAx.Power=0);
(icmdMoveVelocity=0);
(icmdStop=0);

(icmdErrorReset=1);
if((((unsigned long)(unsigned char)iFb_SlaveAx.Error==(unsigned long)(unsigned char)0))){
(iAxStep_enum=1);
(icmdErrorReset=0);
}
}break;}


switch(iJogLimState){

case 0:{
if((((unsigned long)(unsigned char)iFb_SlaveAx.JogNegative==(unsigned long)(unsigned char)1))){
(iJogLimState=2);
}
if((((unsigned long)(unsigned char)iFb_SlaveAx.JogPositive==(unsigned long)(unsigned char)1))){
(iJogLimState=3);
}
}break;case 1:{
(iFb_SlaveAx.JogPositive=1);
(iFb_SlaveAx.JogNegative=1);
(iJogLimState=0);

}break;case 2:{
if((((unsigned long)(unsigned char)iFb_SlaveAx.CommandAborted==(unsigned long)(unsigned char)1))){
(iJogLimState=1);
(iFb_SlaveAx.JogNegative=0);
}

if(((iFb_SlaveAx.Position>UPPER_CUT_POS))){
(iBasicParSlave.Jog.LowerLimit=FIRST_CUT_UPPER);
(iBasicParSlave.Jog.UpperLimit=MAX_POS_AXIS);
(iFb_SlaveAx.Update=1);
(iJogLimState=4);
}
}break;case 3:{
if((((unsigned long)(unsigned char)iFb_SlaveAx.CommandAborted==(unsigned long)(unsigned char)1))){
(iJogLimState=1);
(iFb_SlaveAx.JogPositive=0);
}

if(((iFb_SlaveAx.Position<LOWER_CUT_POS))){
(iBasicParSlave.Jog.LowerLimit=ZERO);
(iBasicParSlave.Jog.UpperLimit=FIRST_CUT_LOWER);
(iFb_SlaveAx.Update=1);
(iJogLimState=4);
}
}break;case 4:{
if((((unsigned long)(unsigned char)iFb_SlaveAx.UpdateDone==(unsigned long)(unsigned char)1))){
(iFb_SlaveAx.Update=0);
}
if(((((unsigned long)(unsigned char)iFb_SlaveAx.JogNegative==(unsigned long)(unsigned char)1))&((iFb_SlaveAx.Position<ZERO))&((iFb_SlaveAx.Position>UPPER_CUT_POS)))){
(iJogLimState=2);
}
if(((((unsigned long)(unsigned char)iFb_SlaveAx.JogPositive==(unsigned long)(unsigned char)1))&((iFb_SlaveAx.Position>ZERO))&((iFb_SlaveAx.Position<LOWER_CUT_POS)))){
(iJogLimState=3);
}
if((((iFb_SlaveAx.Position==FIRST_CUT_UPPER))|((iFb_SlaveAx.Position==FIRST_CUT_LOWER)))){
(iFb_SlaveAx.JogNegative=0);
(iFb_SlaveAx.JogPositive=0);
(iJogLimState=5);
}
}break;case 5:{

(iBasicParSlave.Jog.LowerLimit=ZERO);
(iBasicParSlave.Jog.UpperLimit=ZERO);
(iFb_SlaveAx.Update=1);
if((((unsigned long)(unsigned char)iFb_SlaveAx.UpdateDone==(unsigned long)(unsigned char)1))){
(iFb_SlaveAx.Update=0);
(iJogLimState=0);
}
}break;}


(iBasicParSlave.CyclicRead.TorqueMode=1);

if((((unsigned long)(unsigned char)iCutCtrl.Cmd.Start==(unsigned long)(unsigned char)0))){
(iAxStep_enum=0);
(iJogLimState=0);
}

}imp16389_else34_0:imp16389_end34_0:;}
#line 77 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.nodebug"
#line 16 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/MultCutter.st"
static void __AS__Action__MultCutter(void){
{
(gIR_Trigger=iFb_SlaveAx.Info.DigitalInputsStatus.Trigger1);
(iFb_SlaveAx.Enable=1);
((*(unsigned long*)&(iFb_SlaveAx.MpLink))=((unsigned long)(&gmlSlave)));
(iFb_SlaveAx.Axis=((unsigned long)(&gAxSlave)));

((*(unsigned long*)&(iFb_SlaveAx.Parameters))=((unsigned long)(&iBasicParSlave)));
MpAxisBasic(&iFb_SlaveAx);






























(iBasicParSlave.Torque.Limit=(8.00000011920928955078E-01));


(iBasicParSlave.Position=1900);


if((((unsigned long)(unsigned char)iFb_SlaveAx.Stop==(unsigned long)(unsigned char)1))){
if((((unsigned long)(unsigned char)iFb_SlaveAx.Stopped==(unsigned long)(unsigned char)1))){
(iFb_SlaveAx.Stop=0);
}
}


if((((unsigned long)(unsigned char)iFb_SlaveAx.Error==(unsigned long)(unsigned char)1))){
(iAxStep_enum=9);
}


switch(iAxStep_enum){


case 0:{
if((((unsigned long)(unsigned char)iCutCtrl.Cmd.Start==(unsigned long)(unsigned char)1))){
(iAxStep_enum=1);
}

}break;case 1:{
if((((unsigned long)(unsigned char)iFb_SlaveAx.Info.ReadyToPowerOn==(unsigned long)(unsigned char)1))){
(iAxStep_enum=3);
}


}break;case 3:{
(iFb_SlaveAx.Power=1);
if((((unsigned long)(unsigned char)iFb_SlaveAx.PowerOn==(unsigned long)(unsigned char)1))){

if((iFb_SlaveAx.PowerOn&((iFb_SlaveAx.Position<FIRST_CUT_LOWER))&((iFb_SlaveAx.Position>HOME_POS)))){

(iBasicParSlave.Home.Mode=4);
(iBasicParSlave.Direction=1);
(iBasicParSlave.Home.HomingDirection=1);
(iBasicParSlave.Home.StartDirection=1);
(iBasicParSlave.Home.SensorOffset=HOFFSET_NEGDUAL);
(iBasicParSlave.Home.HomingVelocity=HOMING_VEL);
(iBasicParSlave.Home.StartVelocity=START_VEL);
(iFb_SlaveAx.Update=1);
(iAxStep_enum=6);


}else if((iFb_SlaveAx.PowerOn&((iFb_SlaveAx.Position<HOME_POS))&((iFb_SlaveAx.Position>SEC_CUT_UPPER)))){

(iBasicParSlave.Home.Mode=4);
(iBasicParSlave.Direction=0);
(iBasicParSlave.Home.HomingDirection=0);
(iBasicParSlave.Home.StartDirection=1);
(iBasicParSlave.Home.SensorOffset=HOFFSET_NEGDUAL);
(iBasicParSlave.Home.HomingVelocity=HOMING_VEL);
(iBasicParSlave.Home.StartVelocity=START_VEL);
(iFb_SlaveAx.Update=1);
(iAxStep_enum=6);


}else if((iFb_SlaveAx.PowerOn&((iFb_SlaveAx.Position>FIRST_CUT_UPPER))&((iFb_SlaveAx.Position<MAX_POS_AXIS)))){

(iBasicParSlave.Home.Mode=5);
(iBasicParSlave.Home.HomingDirection=0);
(iBasicParSlave.Home.SensorOffset=HOFFSET_DUAL);
(iBasicParSlave.Home.HomingVelocity=150);
(iBasicParSlave.Home.StartVelocity=50);
(iFb_SlaveAx.Update=1);
if((((unsigned long)(unsigned char)iFb_SlaveAx.UpdateDone==(unsigned long)(unsigned char)1))){
(iFb_SlaveAx.Home=1);
(iAxStep_enum=5);
(iFb_SlaveAx.Update=0);
}
}else if((iFb_SlaveAx.PowerOn&((iFb_SlaveAx.Position<SEC_CUT_LOWER))&((iFb_SlaveAx.Position>HOME_OFFSET)))){
(iFb_SlaveAx.Update=1);
if((((unsigned long)(unsigned char)iFb_SlaveAx.UpdateDone==(unsigned long)(unsigned char)1))){

(iBasicParSlave.Home.Mode=5);
(iBasicParSlave.Home.HomingDirection=1);
(iBasicParSlave.Home.SensorOffset=HOFFSET_DUAL);
(iBasicParSlave.Home.HomingVelocity=HOMING_VEL);
(iBasicParSlave.Home.StartVelocity=START_VEL);
(iFb_SlaveAx.Update=1);
if((((unsigned long)(unsigned char)iFb_SlaveAx.UpdateDone==(unsigned long)(unsigned char)1))){
(iFb_SlaveAx.Home=1);
(iAxStep_enum=4);
(iFb_SlaveAx.Update=0);
}
}
}
}


}break;case 6:{
if((((unsigned long)(unsigned char)iFb_SlaveAx.UpdateDone==(unsigned long)(unsigned char)1))){
(iFb_SlaveAx.MoveAbsolute=1);
(iFb_SlaveAx.Update=0);
(iAxStep_enum=2);
}

}break;case 2:{
if((((unsigned long)(unsigned char)iFb_SlaveAx.InPosition==(unsigned long)(unsigned char)1))){
(iFb_SlaveAx.MoveAbsolute=0);
(iFb_SlaveAx.Home=1);
(iAxStep_enum=8);
}

}break;case 5:{
if((((unsigned long)(unsigned char)iFb_AxisSlave.IsHomed==(unsigned long)(unsigned char)1))){
(iAxStep_enum=8);
}

}break;case 4:{

if((((unsigned long)(unsigned char)iFb_AxisSlave.IsHomed==(unsigned long)(unsigned char)1))){
(iAxStep_enum=8);
}

}break;case 8:{

if((((unsigned long)(unsigned char)iFb_AxisSlave.IsHomed==(unsigned long)(unsigned char)1))){
(iFb_SlaveAx.Home=0);
}

}break;case 9:{
(iFb_AxisSlave.Power=0);
(iFb_AxisSlave.MoveVelocity=0);
if((((unsigned long)(unsigned char)iFb_SlaveAx.Error==(unsigned long)(unsigned char)0))){
(iAxStep_enum=1);
(iFb_SlaveAx.ErrorReset=0);
}
}break;}

}imp16387_case3_8:imp16387_endcase3_0:;}
#line 77 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.nodebug"
#line 22 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/CamAutoSingle.st"
static void __AS__Action__CamSingle(void){
{(iAx_CamSequence.Configuration.Master=((unsigned long)(&gAxMaster)));
(iAx_CamSequence.Configuration.MasterParID=ACP10PAR_PCTRL_S_ACT);


(iAx_CamSequence.Configuration.State[0].Event[0].Type=ncTRIGGER1);
(iAx_CamSequence.Configuration.State[0].Event[0].Attribute=ncAT_ONCE);
(iAx_CamSequence.Configuration.State[0].Event[0].NextState=4);



(iAx_CamSequence.Configuration.State[4].CamProfileIndex=65534);
(iAx_CamSequence.Configuration.State[4].MasterFactor=300);
(iAx_CamSequence.Configuration.State[4].SlaveFactor=(-400));

(iAx_CamSequence.Configuration.State[4].CompMode=ncONLYCOMP);
(iAx_CamSequence.Configuration.State[4].MasterCompDistance=900);
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









































}}
#line 77 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.nodebug"
#line 2 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/CamAutoMulti.st"
static void __AS__Action__CamMulti(void){
{(iAx_CamSequence.Configuration.Master=((unsigned long)(&gAxMaster)));
(iAx_CamSequence.Configuration.MasterParID=ACP10PAR_PCTRL_S_ACT);


(iAx_CamSequence.Configuration.State[0].Event[0].Type=ncTRIGGER1);
(iAx_CamSequence.Configuration.State[0].Event[0].Attribute=ncAT_ONCE);
(iAx_CamSequence.Configuration.State[0].Event[0].NextState=4);




(iAx_CamSequence.Configuration.State[4].CamProfileIndex=65534);
(iAx_CamSequence.Configuration.State[4].MasterFactor=300);
(iAx_CamSequence.Configuration.State[4].SlaveFactor=(-400));

(iAx_CamSequence.Configuration.State[4].CompMode=ncONLYCOMP);
(iAx_CamSequence.Configuration.State[4].MasterCompDistance=900);
(iAx_CamSequence.Configuration.State[4].SlaveCompDistance=(-600));

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
(iAx_CamSequence.Configuration.State[6].MasterCompDistance=300);
(iAx_CamSequence.Configuration.State[6].SlaveCompDistance=(-1310));

(iAx_CamSequence.Configuration.State[6].Event[0].Type=ncST_END);
(iAx_CamSequence.Configuration.State[6].Event[0].Attribute=ncST_END);
(iAx_CamSequence.Configuration.State[6].Event[0].NextState=2);






(iAx_CamSequence.Configuration.State[2].CamProfileIndex=65535);
(iAx_CamSequence.Configuration.State[2].MasterFactor=300);
(iAx_CamSequence.Configuration.State[2].SlaveFactor=(-400));

(iAx_CamSequence.Configuration.State[2].Event[0].Type=ncST_END);
(iAx_CamSequence.Configuration.State[2].Event[0].Attribute=ncST_END);
(iAx_CamSequence.Configuration.State[2].Event[0].NextState=1);



(iAx_CamSequence.Configuration.State[1].CamProfileIndex=65534);
(iAx_CamSequence.Configuration.State[1].MasterFactor=300);
(iAx_CamSequence.Configuration.State[1].SlaveFactor=(-400));

(iAx_CamSequence.Configuration.State[1].CompMode=ncONLYCOMP);
(iAx_CamSequence.Configuration.State[1].MasterCompDistance=400);
(iAx_CamSequence.Configuration.State[1].SlaveCompDistance=(-1400));

(iAx_CamSequence.Configuration.State[1].Event[0].Type=ncST_END);
(iAx_CamSequence.Configuration.State[1].Event[0].Attribute=ncST_END);
(iAx_CamSequence.Configuration.State[1].Event[0].NextState=2);















































}}
#line 77 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.nodebug"
#line 2 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/RegCap.st"
static void __AS__Action__RegCap(void){
{(iFb_RegCap.Axis=((unsigned long)(&gAxSlave)));
(iFb_RegCap.Master=((unsigned long)(&gAxMaster)));
(iFb_RegCap.AdvancedParameters=*(struct MC_BR_ADV_RM2_REF*)&iRegCapAdvPar);
(iFb_RegCap.InitData=1);
(iFb_RegCap.SearchRM=1);
(iFb_RegCap.Configuration=*(struct MC_BR_CFG_RM2_REF*)&iRegCapConfig);
(iFb_RegCap.CutPosition=(signed long)(iRegCapConfig.ProductLength>=0.0?iRegCapConfig.ProductLength+0.5:iRegCapConfig.ProductLength-0.5));
(iFb_RegCap.Enable=iFb_CamSequ.InSync);
if((((signed long)iFb_AxisSlave.Info.PLCopenState==(signed long)4))){
MC_BR_RegMarkCapture002(&iFb_RegCap);
}
}imp16388_else0_0:imp16388_end0_0:;}
#line 77 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/Cutter/Cutter/Main.nodebug"

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
__asm__(".ascii \"plcdata_const 'HOFFSET_NEGDUAL'\\n\"");
__asm__(".ascii \"plcdata_const 'FIRST_CUT_UPPER'\\n\"");
__asm__(".ascii \"plcdata_const 'HOME_POS'\\n\"");
__asm__(".ascii \"plcdata_const 'SEC_CUT_UPPER'\\n\"");
__asm__(".ascii \"plcdata_const 'FIRST_CUT_LOWER'\\n\"");
__asm__(".ascii \"plcdata_const 'MAX_POS_AXIS'\\n\"");
__asm__(".ascii \"plcdata_const 'SEC_CUT_LOWER'\\n\"");
__asm__(".ascii \"plcdata_const 'HOME_OFFSET'\\n\"");
__asm__(".ascii \"plcdata_const 'ACP10PAR_PCTRL_S_ACT'\\n\"");
__asm__(".ascii \"plcdata_const 'ACP10PAR_STAT_TRIGGER1'\\n\"");
__asm__(".ascii \"plcdata_const 'ncAT_ONCE'\\n\"");
__asm__(".ascii \"plcdata_const 'ncONLYCOMP'\\n\"");
__asm__(".ascii \"plcdata_const 'ncP_EDGE'\\n\"");
__asm__(".ascii \"plcdata_const 'ncST_END'\\n\"");
__asm__(".ascii \"plcdata_const 'ncTRIGGER1'\\n\"");
__asm__(".previous");
