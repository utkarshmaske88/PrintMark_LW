
ACTION Alarms: 
	//in Cutting zone alarm
//	IF pSlaveAx.Position < 3013 AND pSlaveAx.Position > 2653 AND NOT iAutoCtrl.Cmd.AutoMode THEN
//		MpAlarmXSet(gAlarmXMain,'InCuttingZone');
//	ELSE
//		MpAlarmXReset(gAlarmXMain,'InCuttingZone');
//	END_IF
//	
//	//Product without pritn mark limit exceeded alarm
//	IF pRegCapture.ProductsWithoutRM > PROUCT_WITHOUT_RM THEN
//		pAx_CamSeq.In.StartSequence := FALSE;
//		gAx_Master.In.Power := FALSE;
//		gAx_Slave.In.Power := FALSE;
//		MpAlarmXSet(gAlarmXMain,'CuttingError');
//		AutoCtrlState := STOP;
//	ELSE
//		MpAlarmXReset(gAlarmXMain,'CuttingError');
//	END_IF
//	
END_ACTION

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
