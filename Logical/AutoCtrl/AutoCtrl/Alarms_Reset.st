(*|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|*)
(*| Copyright      :-  B&R Industrial Automation GmbH															 |*)
(*| Contact Person :-  maskeu																					 |*)
(*|——————————————————————————————————————————————————————————————————————————————————————————————————————————————|*)
(*| System       :-  auto control                                                                    	 		 |*)
(*| Task Name    :-  auto control																		  		 |*)
(*| Auther Name  :-  maskeu																						 |*)
(*| Created Date :-  December 19, 2023 																		   	 |*)
(*| Task Class   :-  Task Class# 1                                                                 				 |*)
(*| Task Time    :-  Task Timing 2mSec                                                                           |*)
(*| OS Version   :-  G4.93                                                                                       |*)
(*| AS Version   :-  AS 4.12.4.107 SP                                                                            |*)
(*|——————————————————————————————————————————————————————————————————————————————————————————————————————————————|*)
(*| Description  :-  alarmsaction file				    									 					 |*)
(*| V1.00.0   23/12/2023	 Maskeu        added alarms and reset file							Complete	     |*)

ACTION Alarms: 
//	in Cutting zone alarm
	IF pSlaveAx.Position < 3013 AND pSlaveAx.Position > 2653 AND NOT iAutoCtrl.Cmd.AutoMode THEN
		MpAlarmXSet(gAlarmXCore,'InTheCuttingZone');
	ELSE
		MpAlarmXReset(gAlarmXCore,'InTheCuttingZone');
	END_IF
	
	//Product without pritn mark limit exceeded alarm
	IF pRegCapture.ProductsWithoutRM > LIMIT_ERROR_PRODUCT THEN
		pAx_CamSeq.StartSequence 	 := FALSE;
		pMasterAx.Power					 := FALSE;
		pSlaveAx.Power					 := FALSE;
		MpAlarmXSet(gAlarmXCore,'ErrorCutting');
		iAutoCtrlState := enSTOP;
	ELSE
		MpAlarmXReset(gAlarmXCore,'ErrorCutting');
	END_IF
	
END_ACTION

//resetting all the values
ACTION Reset: 
	
	CASE iResetState OF
		enRESETONE:
		  
			iAutoCtrl.Cmd.Start 				:= FALSE;
			iAutoCtrl.Cmd.AutoMode				:= FALSE;
			iAutoCtrl.Cmd.Stop 					:= FALSE;
			iAutoCtrl.ManualCmd.ConvPowerON		:= FALSE;
			iAutoCtrl.ManualCmd.CutterPowerON 	:= FALSE;
			pMasterAx.Power 					:= FALSE;
			gMi_ModeConfirm						:= FALSE;
			pSlaveAx.Power 						:= FALSE;
			pSlaveAx.ErrorReset 				:= TRUE;
			pMasterAx.ErrorReset 				:= TRUE;
			pConvCtrl.Cmd.Start 				:= FALSE;
			pCutterCtrl.Cmd.Start 				:= FALSE;
			pAx_CamSeq.StartSequence 		:= FALSE;
			iResetState:=enRESETTWO;
		enRESETTWO:

			pMasterAx.ErrorReset 				:= FALSE;
			pMasterAx.ErrorReset 				:= FALSE;
			iAutoCtrl.Cmd.DisableCutter 		:= FALSE;
			iAutoCtrl.Cmd.SingleCutter 			:= FALSE;
			iAutoCtrl.Cmd.AutoMode 				:= FALSE;
			iMi_CutModeSelected 				:= FALSE;
			iResetState:=enEXIT;
		enEXIT:
			gMi_ModeConfirm 					:= FALSE;
			pAx_CamSeq.ErrorReset 				:= FALSE;
			pAx_CamSeq.ErrorReset 				:= TRUE;
			pMasterAx.Enable 					:= FALSE;
			pSlaveAx.Enable 					:= FALSE;
			iResetState							:=enRESETONE;
			iAutoCtrlState 						:= enWAIT ;
	END_CASE;
END_ACTION
