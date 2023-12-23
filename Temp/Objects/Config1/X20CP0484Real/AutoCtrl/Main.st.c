#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Temp/Objects/Config1/X20CP0484/AutoCtrl/Mainst.h"
#line 1 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/AutoCtrl/AutoCtrl/Main.nodebug"
#line 20 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/AutoCtrl/AutoCtrl/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{

(iStatus_CutCtrl=PV_xgetadr(((unsigned long)(&"Cutter:iCutCtrl")),((unsigned long)(&CutterAdd)),((unsigned long)(&SizeCutter))));
(iStatus_ConvCtrl=PV_xgetadr(((unsigned long)(&"ConvCtrl:iConCtrl")),((unsigned long)(&ConvAdd)),((unsigned long)(&SizeConv))));
(iStatus_CamSeq=PV_xgetadr(((unsigned long)(&"Cutter:iFb_CamSequ")),((unsigned long)(&CamAdd)),((unsigned long)(&SizeCam))));
(iStatus_RegCapt=PV_xgetadr(((unsigned long)(&"Cutter:iFb_RegCap")),((unsigned long)(&RegAdd)),((unsigned long)(&RegSize))));
(iStatus_SlaveAx=PV_xgetadr(((unsigned long)(&"Cutter:iFb_SlaveAx")),((unsigned long)(&SlaveAx)),((unsigned long)(&SlaveSize))));
(iStatus_MasterAx=PV_xgetadr(((unsigned long)(&"ConvCtrl:iFb_MasterAx")),((unsigned long)(&MasterAx)),((unsigned long)(&MasterSize))));

}}
#line 29 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/AutoCtrl/AutoCtrl/Main.nodebug"
#line 31 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/AutoCtrl/AutoCtrl/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){int __AS__Local0_00000;plcwstring* __AS__Local5_00000;plcwstring* __AS__Local6_00000;{



(pCutterCtrl=CutterAdd);
(pConvCtrl=ConvAdd);
(pAx_CamSeq=CamAdd);
(pRegCapture=RegAdd);
(pMasterAx=MasterAx);
(pSlaveAx=SlaveAx);
switch(iAutoCtrlState){

case 0:{
__AS__Local5_00000=(plcwstring*)iMi_StatusTxt; __AS__Local6_00000=(plcwstring*)"\x50\x00\x6C\x00\x65\x00\x61\x00\x73\x00\x65\x00\x20\x00\x73\x00\x65\x00\x6C\x00\x65\x00\x63\x00\x74\x00\x20\x00\x73\x00\x69\x00\x6E\x00\x67\x00\x6C\x00\x65\x00\x20\x00\x6F\x00\x72\x00\x20\x00\x64\x00\x75\x00\x61\x00\x6C\x00\x20\x00\x63\x00\x75\x00\x74\x00\x74\x00\x65\x00\x72\x00\x00"; for(__AS__Local0_00000=0; __AS__Local0_00000<35l && __AS__Local6_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local5_00000[__AS__Local0_00000] = __AS__Local6_00000[__AS__Local0_00000]; __AS__Local5_00000[__AS__Local0_00000] = 0;
((*(pMasterAx)).Enable=1);
((*(pSlaveAx)).Enable=1);
if((((unsigned long)(unsigned char)iAutoCtrl.Cmd.SingleCutter==(unsigned long)(unsigned char)1))){
((*(pCutterCtrl)).Cmd.SingleCutter=1);
}else{
((*(pCutterCtrl)).Cmd.SingleCutter=0);
}
if((((unsigned long)(unsigned char)iMi_CutModeSelected==(unsigned long)(unsigned char)1))){
__AS__Local5_00000=(plcwstring*)iMi_StatusTxt; __AS__Local6_00000=(plcwstring*)"\x50\x00\x6C\x00\x65\x00\x61\x00\x73\x00\x65\x00\x20\x00\x73\x00\x65\x00\x6C\x00\x65\x00\x63\x00\x74\x00\x20\x00\x6D\x00\x6F\x00\x64\x00\x65\x00\x20\x00\x61\x00\x6E\x00\x64\x00\x20\x00\x73\x00\x74\x00\x61\x00\x72\x00\x74\x00\x20\x00\x6D\x00\x61\x00\x63\x00\x68\x00\x69\x00\x6E\x00\x65\x00\x00"; for(__AS__Local0_00000=0; __AS__Local0_00000<36l && __AS__Local6_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local5_00000[__AS__Local0_00000] = __AS__Local6_00000[__AS__Local0_00000]; __AS__Local5_00000[__AS__Local0_00000] = 0;
}

if(((((unsigned long)(unsigned char)iAutoCtrl.Cmd.Start==(unsigned long)(unsigned char)1))&(((unsigned long)(unsigned char)iMi_CutModeSelected==(unsigned long)(unsigned char)1)))){
((*(pConvCtrl)).Cmd.Start=1);
((*(pCutterCtrl)).Cmd.Start=1);
(iAutoCtrlState=1);
}

}break;case 1:{
if((((unsigned long)(unsigned char)gMi_ModeConfirm==(unsigned long)(unsigned char)1))){
if((((unsigned long)(unsigned char)iAutoCtrl.Cmd.AutoMode==(unsigned long)(unsigned char)1))){
__AS__Local5_00000=(plcwstring*)iMi_SelectedMode; __AS__Local6_00000=(plcwstring*)"\x41\x00\x75\x00\x74\x00\x6F\x00\x6D\x00\x61\x00\x74\x00\x69\x00\x63\x00\x65\x00\x20\x00\x4D\x00\x6F\x00\x64\x00\x65\x00\x20\x00\x73\x00\x65\x00\x6C\x00\x65\x00\x63\x00\x74\x00\x65\x00\x64\x00\x00"; for(__AS__Local0_00000=0; __AS__Local0_00000<24l && __AS__Local6_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local5_00000[__AS__Local0_00000] = __AS__Local6_00000[__AS__Local0_00000]; __AS__Local5_00000[__AS__Local0_00000] = 0;
(iAutoCtrlState=2);
}else{
__AS__Local5_00000=(plcwstring*)iMi_SelectedMode; __AS__Local6_00000=(plcwstring*)"\x4D\x00\x61\x00\x6E\x00\x75\x00\x61\x00\x6C\x00\x20\x00\x4D\x00\x6F\x00\x64\x00\x65\x00\x20\x00\x53\x00\x65\x00\x6C\x00\x65\x00\x63\x00\x74\x00\x65\x00\x64\x00\x00"; for(__AS__Local0_00000=0; __AS__Local0_00000<20l && __AS__Local6_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local5_00000[__AS__Local0_00000] = __AS__Local6_00000[__AS__Local0_00000]; __AS__Local5_00000[__AS__Local0_00000] = 0;
(iAutoCtrlState=3);
}
}


}break;case 2:{
__AS__Local5_00000=(plcwstring*)iMi_StatusTxt; __AS__Local6_00000=(plcwstring*)"\x48\x00\x6F\x00\x6D\x00\x69\x00\x6E\x00\x67\x00\x20\x00\x74\x00\x68\x00\x65\x00\x20\x00\x61\x00\x78\x00\x69\x00\x73\x00\x20\x00\x77\x00\x61\x00\x69\x00\x74\x00\x2E\x00\x2E\x00\x2E\x00\x00"; for(__AS__Local0_00000=0; __AS__Local0_00000<23l && __AS__Local6_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local5_00000[__AS__Local0_00000] = __AS__Local6_00000[__AS__Local0_00000]; __AS__Local5_00000[__AS__Local0_00000] = 0;
((*(pAx_CamSeq)).ErrorReset=1);
if((((*(pMasterAx)).IsHomed)&((*(pSlaveAx)).IsHomed))){
((*(pAx_CamSeq)).ErrorReset=0);
(iAutoCtrlState=4);
}


}break;case 4:{
if(((((unsigned long)(unsigned char)((*(pAx_CamSeq)).Info.MasterReady)==(unsigned long)(unsigned char)1))&(((unsigned long)(unsigned char)((*(pAx_CamSeq)).Info.SlaveReady)==(unsigned long)(unsigned char)1))&(((signed long)((*(pAx_CamSeq)).StatusID)==(signed long)0)))){
((*(pAx_CamSeq)).StartSequence=1);
}

if((((signed long)((*(pAx_CamSeq)).StatusID)!=(signed long)0))){
((*(pAx_CamSeq)).ErrorReset=1);
}else{
((*(pAx_CamSeq)).ErrorReset=0);
}

if(((((unsigned long)(unsigned char)((*(pAx_CamSeq)).InSync)==(unsigned long)(unsigned char)1))&(((unsigned long)(unsigned char)iAutoCtrl.Cmd.Start==(unsigned long)(unsigned char)1)))){
__AS__Local5_00000=(plcwstring*)iMi_StatusTxt; __AS__Local6_00000=(plcwstring*)"\x20\x00\x49\x00\x6E\x00\x20\x00\x52\x00\x75\x00\x6E\x00\x20\x00\x4D\x00\x6F\x00\x64\x00\x65\x00\x20\x00\x2D\x00\x20\x00\x41\x00\x75\x00\x74\x00\x6F\x00\x20\x00\x4D\x00\x6F\x00\x64\x00\x65\x00\x00"; for(__AS__Local0_00000=0; __AS__Local0_00000<24l && __AS__Local6_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local5_00000[__AS__Local0_00000] = __AS__Local6_00000[__AS__Local0_00000]; __AS__Local5_00000[__AS__Local0_00000] = 0;
((*(pMasterAx)).MoveVelocity=1);
}


if(iAutoCtrl.Cmd.Stop){
__AS__Local5_00000=(plcwstring*)iMi_StatusTxt; __AS__Local6_00000=(plcwstring*)"\x53\x00\x74\x00\x6F\x00\x70\x00\x20\x00\x50\x00\x72\x00\x65\x00\x73\x00\x73\x00\x65\x00\x64\x00\x2E\x00\x20\x00\x50\x00\x72\x00\x65\x00\x73\x00\x73\x00\x20\x00\x53\x00\x74\x00\x61\x00\x72\x00\x74\x00\x20\x00\x61\x00\x6E\x00\x64\x00\x20\x00\x73\x00\x65\x00\x6C\x00\x65\x00\x63\x00\x74\x00\x20\x00\x6D\x00\x6F\x00\x64\x00\x65\x00\x2E\x00\x00"; for(__AS__Local0_00000=0; __AS__Local0_00000<42l && __AS__Local6_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local5_00000[__AS__Local0_00000] = __AS__Local6_00000[__AS__Local0_00000]; __AS__Local5_00000[__AS__Local0_00000] = 0;
((*(pMasterAx)).MoveVelocity=0);
}


if((((unsigned long)(unsigned char)iAutoCtrl.Cmd.DisableCutter==(unsigned long)(unsigned char)1))){
__AS__Local5_00000=(plcwstring*)iMi_StatusTxt; __AS__Local6_00000=(plcwstring*)"\x43\x00\x75\x00\x74\x00\x74\x00\x65\x00\x72\x00\x20\x00\x44\x00\x69\x00\x73\x00\x61\x00\x62\x00\x6C\x00\x65\x00\x64\x00\x20\x00\x69\x00\x73\x00\x20\x00\x50\x00\x72\x00\x65\x00\x73\x00\x73\x00\x65\x00\x64\x00\x00"; for(__AS__Local0_00000=0; __AS__Local0_00000<26l && __AS__Local6_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local5_00000[__AS__Local0_00000] = __AS__Local6_00000[__AS__Local0_00000]; __AS__Local5_00000[__AS__Local0_00000] = 0;
((*(pAx_CamSeq)).StartSequence=0);
((*(pCutterCtrl)).Cmd.Start=0);
((*(pSlaveAx)).Power=0);
((*(pSlaveAx)).Enable=0);
(iAutoCtrlState=9);
}



if(((((unsigned long)(unsigned char)iAutoCtrl.Cmd.ChangeMode==(unsigned long)(unsigned char)1))&(((unsigned long)(unsigned char)iAutoCtrl.Cmd.Stop==(unsigned long)(unsigned char)1)))){
__AS__Local5_00000=(plcwstring*)iMi_StatusTxt; __AS__Local6_00000=(plcwstring*)"\x4D\x00\x61\x00\x63\x00\x68\x00\x69\x00\x6E\x00\x65\x00\x20\x00\x68\x00\x61\x00\x73\x00\x20\x00\x53\x00\x74\x00\x6F\x00\x70\x00\x70\x00\x65\x00\x64\x00\x00"; for(__AS__Local0_00000=0; __AS__Local0_00000<19l && __AS__Local6_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local5_00000[__AS__Local0_00000] = __AS__Local6_00000[__AS__Local0_00000]; __AS__Local5_00000[__AS__Local0_00000] = 0;
((*(pMasterAx)).MoveVelocity=0);
(iAutoCtrl.Cmd.ChangeMode=0);
((*(pAx_CamSeq)).StartSequence=0);
(iAutoCtrlState=5);
}


}break;case 9:{
((*(pCutterCtrl)).Cmd.Start=1);
if((((unsigned long)(unsigned char)((*(pSlaveAx)).IsHomed)==(unsigned long)(unsigned char)1))){
__AS__Local5_00000=(plcwstring*)iMi_StatusTxt; __AS__Local6_00000=(plcwstring*)"\x44\x00\x69\x00\x73\x00\x61\x00\x62\x00\x6C\x00\x65\x00\x64\x00\x20\x00\x43\x00\x75\x00\x74\x00\x74\x00\x65\x00\x72\x00\x20\x00\x2E\x00\x20\x00\x52\x00\x65\x00\x73\x00\x74\x00\x61\x00\x72\x00\x74\x00\x20\x00\x74\x00\x6F\x00\x20\x00\x73\x00\x74\x00\x61\x00\x72\x00\x74\x00\x00"; for(__AS__Local0_00000=0; __AS__Local0_00000<34l && __AS__Local6_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local5_00000[__AS__Local0_00000] = __AS__Local6_00000[__AS__Local0_00000]; __AS__Local5_00000[__AS__Local0_00000] = 0;
((*(pSlaveAx)).Home=0);
}


if(iAutoCtrl.Cmd.Stop){
((*(pMasterAx)).MoveVelocity=0);
}


if(iAutoCtrl.Cmd.Start){
((*(pMasterAx)).MoveVelocity=1);
}



if((((unsigned long)(unsigned char)iAutoCtrl.Cmd.DisableCutter==(unsigned long)(unsigned char)0))){
__AS__Local5_00000=(plcwstring*)iMi_StatusTxt; __AS__Local6_00000=(plcwstring*)"\x43\x00\x75\x00\x74\x00\x74\x00\x65\x00\x72\x00\x20\x00\x45\x00\x6E\x00\x61\x00\x62\x00\x6C\x00\x65\x00\x64\x00\x00"; for(__AS__Local0_00000=0; __AS__Local0_00000<14l && __AS__Local6_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local5_00000[__AS__Local0_00000] = __AS__Local6_00000[__AS__Local0_00000]; __AS__Local5_00000[__AS__Local0_00000] = 0;
(iAutoCtrlState=4);
}


if((iAutoCtrl.Cmd.ChangeMode&iAutoCtrl.Cmd.Stop)){
__AS__Local5_00000=(plcwstring*)iMi_StatusTxt; __AS__Local6_00000=(plcwstring*)"\x4D\x00\x61\x00\x63\x00\x68\x00\x69\x00\x6E\x00\x65\x00\x20\x00\x68\x00\x61\x00\x73\x00\x20\x00\x62\x00\x65\x00\x65\x00\x6E\x00\x20\x00\x53\x00\x74\x00\x6F\x00\x70\x00\x70\x00\x65\x00\x64\x00\x00"; for(__AS__Local0_00000=0; __AS__Local0_00000<24l && __AS__Local6_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local5_00000[__AS__Local0_00000] = __AS__Local6_00000[__AS__Local0_00000]; __AS__Local5_00000[__AS__Local0_00000] = 0;
((*(pMasterAx)).MoveVelocity=0);
(iAutoCtrl.Cmd.ChangeMode=0);
((*(pAx_CamSeq)).StartSequence=0);
(iAutoCtrlState=5);
}


}break;case 3:{
__AS__Local5_00000=(plcwstring*)iMi_StatusTxt; __AS__Local6_00000=(plcwstring*)"\x4D\x00\x61\x00\x6E\x00\x75\x00\x61\x00\x6C\x00\x20\x00\x4D\x00\x6F\x00\x64\x00\x65\x00\x20\x00\x69\x00\x73\x00\x20\x00\x4F\x00\x4E\x00\x00"; for(__AS__Local0_00000=0; __AS__Local0_00000<17l && __AS__Local6_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local5_00000[__AS__Local0_00000] = __AS__Local6_00000[__AS__Local0_00000]; __AS__Local5_00000[__AS__Local0_00000] = 0;
if(((((unsigned long)(unsigned char)iAutoCtrl.Cmd.Stop==(unsigned long)(unsigned char)1))&iAutoCtrl.Cmd.ChangeMode)){
__AS__Local5_00000=(plcwstring*)iMi_StatusTxt; __AS__Local6_00000=(plcwstring*)"\x4D\x00\x61\x00\x63\x00\x68\x00\x69\x00\x6E\x00\x65\x00\x20\x00\x73\x00\x74\x00\x6F\x00\x70\x00\x70\x00\x65\x00\x64\x00\x00"; for(__AS__Local0_00000=0; __AS__Local0_00000<15l && __AS__Local6_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local5_00000[__AS__Local0_00000] = __AS__Local6_00000[__AS__Local0_00000]; __AS__Local5_00000[__AS__Local0_00000] = 0;
(iAutoCtrl.ManualCmd.ConvPowerON=0);
(iAutoCtrl.ManualCmd.CutterPowerON=0);
(iAutoCtrlState=5);
}


}break;case 5:{
__AS__Local5_00000=(plcwstring*)iMi_StatusTxt; __AS__Local6_00000=(plcwstring*)"\x4D\x00\x61\x00\x63\x00\x68\x00\x69\x00\x6E\x00\x65\x00\x20\x00\x68\x00\x61\x00\x73\x00\x20\x00\x62\x00\x65\x00\x65\x00\x6E\x00\x20\x00\x73\x00\x74\x00\x6F\x00\x70\x00\x70\x00\x65\x00\x64\x00\x00"; for(__AS__Local0_00000=0; __AS__Local0_00000<24l && __AS__Local6_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local5_00000[__AS__Local0_00000] = __AS__Local6_00000[__AS__Local0_00000]; __AS__Local5_00000[__AS__Local0_00000] = 0;
(iAutoCtrl.Cmd.Start=0);
(gMi_ModeConfirm=0);
((*(pMasterAx)).Power=0);
((*(pMasterAx)).Enable=0);
((*(pSlaveAx)).Power=0);
((*(pSlaveAx)).Enable=0);
((*(pConvCtrl)).Cmd.Start=0);
(iAutoCtrl.Cmd.ChangeMode=0);
(iMi_CutModeSelected=0);
((*(pCutterCtrl)).Cmd.Start=0);
(iAutoCtrl.Cmd.DisableCutter=0);
(iAutoCtrl.Cmd.Stop=0);
(iAutoCtrlState=0);

}break;case 8:{
__AS__Local5_00000=(plcwstring*)iMi_StatusTxt; __AS__Local6_00000=(plcwstring*)"\x43\x00\x75\x00\x74\x00\x74\x00\x69\x00\x6E\x00\x67\x00\x20\x00\x5A\x00\x6F\x00\x6E\x00\x65\x00\x00"; for(__AS__Local0_00000=0; __AS__Local0_00000<12l && __AS__Local6_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local5_00000[__AS__Local0_00000] = __AS__Local6_00000[__AS__Local0_00000]; __AS__Local5_00000[__AS__Local0_00000] = 0;
(iAutoCtrl.ManualCmd.ConvPowerON=0);
(iAutoCtrl.ManualCmd.CutterPowerON=0);

if((((((*(pSlaveAx)).Position)>UPPER_CUT_POS))|((((*(pSlaveAx)).Position)<LOWER_CUT_POS)))){
(iAutoCtrl.Cmd.Start=0);
(iAutoCtrlState=0);
}

}break;}

if((((unsigned long)(unsigned char)(iAutoCtrl.Cmd.AutoMode^1)==(unsigned long)(unsigned char)1))){
((*(pMasterAx)).Power=iAutoCtrl.ManualCmd.ConvPowerON);
((*(pSlaveAx)).Power=iAutoCtrl.ManualCmd.CutterPowerON);
((*(pSlaveAx)).JogNegative=((*(pCutterCtrl)).Cmd.JogBack));
((*(pSlaveAx)).JogPositive=((*(pCutterCtrl)).Cmd.JogFwd));
((*(pMasterAx)).JogPositive=((*(pConvCtrl)).Cmd.JogFwd));
((*(pMasterAx)).JogNegative=((*(pConvCtrl)).Cmd.JogBack));
}


((*(pConvCtrl)).Cmd.AutoMode=iAutoCtrl.Cmd.AutoMode);
((*(pCutterCtrl)).Cmd.AutoMode=iAutoCtrl.Cmd.AutoMode);



if((((((*(pSlaveAx)).Position)<UPPER_CUT_POS))&((((*(pSlaveAx)).Position)>LOWER_CUT_POS))&(iAutoCtrl.Cmd.AutoMode^1))){
(iAutoCtrlState=8);
}



(iMI_LastBagLen=(((*(pRegCapture)).AdditionalInfo.ActLength)/TEN));
(iMI_AvgBagLen=(((*(pRegCapture)).AdditionalInfo.AverageProductLength)/TEN));

if(iAutoCtrl.Cmd.AutoMode){
__AS__Local5_00000=(plcwstring*)iMi_SelectedMode; __AS__Local6_00000=(plcwstring*)"\x41\x00\x75\x00\x74\x00\x6F\x00\x20\x00\x4D\x00\x6F\x00\x64\x00\x65\x00\x20\x00\x69\x00\x73\x00\x20\x00\x53\x00\x65\x00\x6C\x00\x65\x00\x63\x00\x74\x00\x65\x00\x64\x00\x00"; for(__AS__Local0_00000=0; __AS__Local0_00000<21l && __AS__Local6_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local5_00000[__AS__Local0_00000] = __AS__Local6_00000[__AS__Local0_00000]; __AS__Local5_00000[__AS__Local0_00000] = 0;
}else{
__AS__Local5_00000=(plcwstring*)iMi_SelectedMode; __AS__Local6_00000=(plcwstring*)"\x4D\x00\x61\x00\x6E\x00\x75\x00\x61\x00\x6C\x00\x20\x00\x4D\x00\x6F\x00\x64\x00\x65\x00\x20\x00\x69\x00\x73\x00\x20\x00\x53\x00\x65\x00\x6C\x00\x65\x00\x63\x00\x74\x00\x65\x00\x64\x00\x00"; for(__AS__Local0_00000=0; __AS__Local0_00000<23l && __AS__Local6_00000[__AS__Local0_00000]!=0; __AS__Local0_00000++) __AS__Local5_00000[__AS__Local0_00000] = __AS__Local6_00000[__AS__Local0_00000]; __AS__Local5_00000[__AS__Local0_00000] = 0;
}



if(iAutoCtrl.Cmd.Reset){
__AS__Action__Reset();
}


if((((signed long)((*(pSlaveAx)).Info.PLCopenState)==(signed long)4))){
MC_BR_RegMarkCapture002(&((*(pRegCapture))));
}


(gMI_MODE=iAutoCtrl.Cmd.AutoMode);
__AS__Action__Alarms();
}}
#line 242 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/AutoCtrl/AutoCtrl/Main.nodebug"
#line 254 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/AutoCtrl/AutoCtrl/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{


}}
#line 257 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/AutoCtrl/AutoCtrl/Main.nodebug"
#line 17 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/AutoCtrl/AutoCtrl/Alarms_Reset.st"
static void __AS__Action__Alarms(void){
{
if((((((*(pSlaveAx)).Position)<3013))&((((*(pSlaveAx)).Position)>2653))&(iAutoCtrl.Cmd.AutoMode^1))){
MpAlarmXSet(&gAlarmXCore,"InTheCuttingZone");
}else{
MpAlarmXReset(&gAlarmXCore,"InTheCuttingZone");
}


if((((unsigned long)(unsigned short)((*(pRegCapture)).ProductsWithoutRM)>(unsigned long)(signed long)(short)LIMIT_ERROR_PRODUCT))){
((*(pAx_CamSeq)).StartSequence=0);
((*(pMasterAx)).Power=0);
((*(pSlaveAx)).Power=0);
MpAlarmXSet(&gAlarmXCore,"ErrorCutting");
(iAutoCtrlState=5);
}else{
MpAlarmXReset(&gAlarmXCore,"ErrorCutting");
}

}imp16385_end1_0:;}
#line 259 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/AutoCtrl/AutoCtrl/Main.nodebug"
#line 39 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/AutoCtrl/AutoCtrl/Alarms_Reset.st"
static void __AS__Action__Reset(void){
{
switch(iResetState){
case 0:{

(iAutoCtrl.Cmd.Start=0);
(iAutoCtrl.Cmd.AutoMode=0);
(iAutoCtrl.Cmd.Stop=0);
(iAutoCtrl.ManualCmd.ConvPowerON=0);
(iAutoCtrl.ManualCmd.CutterPowerON=0);
((*(pMasterAx)).Power=0);
(gMi_ModeConfirm=0);
((*(pSlaveAx)).Power=0);
((*(pSlaveAx)).ErrorReset=1);
((*(pMasterAx)).ErrorReset=1);
((*(pConvCtrl)).Cmd.Start=0);
((*(pCutterCtrl)).Cmd.Start=0);
((*(pAx_CamSeq)).StartSequence=0);
(iResetState=1);
}break;case 1:{

((*(pMasterAx)).ErrorReset=0);
((*(pMasterAx)).ErrorReset=0);
(iAutoCtrl.Cmd.DisableCutter=0);
(iAutoCtrl.Cmd.SingleCutter=0);
(iAutoCtrl.Cmd.AutoMode=0);
(iMi_CutModeSelected=0);
(iResetState=2);
}break;case 2:{
(gMi_ModeConfirm=0);
((*(pAx_CamSeq)).ErrorReset=0);
((*(pAx_CamSeq)).ErrorReset=1);
((*(pMasterAx)).Enable=0);
((*(pSlaveAx)).Enable=0);
(iResetState=0);
(iAutoCtrlState=0);
}break;}
}imp16386_case0_2:imp16386_endcase0_0:;}
#line 259 "C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/AutoCtrl/AutoCtrl/Main.nodebug"

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
__asm__(".ascii \"iecfile \\\"Logical/AutoCtrl/AutoCtrl/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/AutoCtrl/AutoCtrl/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Temp/Objects/Config1/X20CP0484/AutoCtrl/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Temp/Objects/Config1/X20CP0484/AutoCtrl/Main.st.c\\\" \\\"C:/Users/maskeu/Desktop/All/projects/ECamp/PrintMarkCC_LW3/Logical/AutoCtrl/AutoCtrl/Main.st\\\"\\n\"");
__asm__(".previous");

__asm__(".section \".plciec\"");
__asm__(".ascii \"plcdata_const 'TEN'\\n\"");
__asm__(".ascii \"plcdata_const 'LIMIT_ERROR_PRODUCT'\\n\"");
__asm__(".ascii \"plcdata_const 'UPPER_CUT_POS'\\n\"");
__asm__(".ascii \"plcdata_const 'LOWER_CUT_POS'\\n\"");
__asm__(".previous");
