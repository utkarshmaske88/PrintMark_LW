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
(*| Description  :-  auto control- all fucniton for main control											     |*)
(*| V1.00.0   19/12/2023	 Maskeu        added pointers with homing state						Complete		 |*)
(*| V2.00.0   20/12/2023	 Maskeu        added automatic state							    Complete		 |*)
(*| V3.00.0   21/12/2023	 Maskeu        added manual state									Complete		 |*)
(*| V4.00.0   23/12/2023	 Maskeu        added cutting zone state								Complete	     |*)

PROGRAM _INIT
	//Accessing Various Variables for Pointer references
	iStatus_CutCtrl 	:= PV_xgetadr(ADR('Cutter:iCutCtrl'),ADR(CutterAdd),ADR(SizeCutter));
	iStatus_ConvCtrl 	:= PV_xgetadr(ADR('ConvCtrl:iConCtrl'),ADR(ConvAdd),ADR(SizeConv));
	iStatus_CamSeq 		:= PV_xgetadr(ADR('Cutter:iFb_CamSequ'),ADR(CamAdd),ADR(SizeCam));
	iStatus_RegCapt 	:= PV_xgetadr(ADR('Cutter:iFb_RegCap'),ADR(RegAdd),ADR(RegSize));
	iStatus_SlaveAx 	:= PV_xgetadr(ADR('Cutter:iFb_SlaveAx'),ADR(SlaveAx),ADR(SlaveSize));
	iStatus_MasterAx 	:= PV_xgetadr(ADR('ConvCtrl:iFb_MasterAx'),ADR(MasterAx),ADR(MasterSize));
	
END_PROGRAM

PROGRAM _CYCLIC
	(* Insert code here *)
	 
	//Pointers Access
	pCutterCtrl		ACCESS CutterAdd;
	pConvCtrl 		ACCESS ConvAdd;
	pAx_CamSeq 		ACCESS CamAdd;
	pRegCapture 	ACCESS RegAdd;
	pMasterAx		ACCESS MasterAx;
	pSlaveAx		ACCESS SlaveAx;
	CASE iAutoCtrlState OF
		
		enWAIT:
			iMi_StatusTxt							:= "Please select single or dual cutter";	
			pMasterAx.Enable						:=TRUE;
			pSlaveAx.Enable							:=TRUE;
			IF iAutoCtrl.Cmd.SingleCutter			=TRUE THEN
				pCutterCtrl.Cmd.SingleCutter		:=TRUE;
			ELSE
				pCutterCtrl.Cmd.SingleCutter		:=FALSE;
			END_IF;
			IF iMi_CutModeSelected=TRUE THEN
				iMi_StatusTxt						:= "Please select mode and start machine";	
			END_IF;
		
			IF iAutoCtrl.Cmd.Start = TRUE AND iMi_CutModeSelected=TRUE THEN
				pConvCtrl.Cmd.Start 				:= TRUE;
				pCutterCtrl.Cmd.Start 				:= TRUE;
				iAutoCtrlState:=enMODE;
			END_IF;
		
		enMODE:
			IF gMi_ModeConfirm = TRUE THEN
				IF iAutoCtrl.Cmd.AutoMode= TRUE THEN
					iMi_SelectedMode:="Automatice Mode selected";
					iAutoCtrlState					:=enHOMING;
				ELSE
					iMi_SelectedMode:="Manual Mode Selected";
					iAutoCtrlState					:=enMANUAL;
				END_IF;
			END_IF;
		
			//homing for both the axis
		enHOMING:
			iMi_StatusTxt:="Homing the axis wait...";
			pAx_CamSeq.ErrorReset					:=TRUE;
			IF pMasterAx.IsHomed AND pSlaveAx.IsHomed THEN
				pAx_CamSeq.ErrorReset				:=FALSE;
				iAutoCtrlState						:=enAUTO;
			END_IF
		
			//autoamtic mode
		enAUTO:
			IF pAx_CamSeq.Info.MasterReady=TRUE AND  pAx_CamSeq.Info.SlaveReady=TRUE AND pAx_CamSeq.StatusID=0 THEN
				pAx_CamSeq.StartSequence			:=TRUE;
			END_IF;
			
			IF pAx_CamSeq.StatusID<>0 THEN
				pAx_CamSeq.ErrorReset				:=TRUE;
			ELSE
				pAx_CamSeq.ErrorReset				:=FALSE;
			END_IF;
		
			IF pAx_CamSeq.InSync = TRUE AND iAutoCtrl.Cmd.Start=TRUE THEN
				iMi_StatusTxt						:= " In Run Mode - Auto Mode";
				pMasterAx.MoveVelocity 				:= TRUE;
			END_IF;
			
			//IF stop Pressed
			IF iAutoCtrl.Cmd.Stop THEN
				iMi_StatusTxt 						:= "Stop Pressed. Press Start and select mode.";
				pMasterAx.MoveVelocity 				:= FALSE;
			END_IF
					
			//Disabled Cutter Cmd given
			IF iAutoCtrl.Cmd.DisableCutter=TRUE THEN
				iMi_StatusTxt := "Cutter Disabled is Pressed";
				pAx_CamSeq.StartSequence 			:= FALSE;
				pCutterCtrl.Cmd.Start 				:= FALSE;
				pSlaveAx.Power		 			:= FALSE;
				pSlaveAx.Enable 					:= FALSE;
				iAutoCtrlState			 			:= enCUT_DISABLED;
			END_IF
			
		
			//Stopping the mode and resetting machine
			IF iAutoCtrl.Cmd.ChangeMode				=TRUE AND iAutoCtrl.Cmd.Stop=TRUE THEN
				iMi_StatusTxt 						:= "Machine has Stopped";
				pMasterAx.MoveVelocity 				:= FALSE;
				iAutoCtrl.Cmd.ChangeMode			:= FALSE;
				pAx_CamSeq.StartSequence			:= FALSE;
				iAutoCtrlState 						:= enSTOP;
			END_IF
		
		
		enCUT_DISABLED:
			pCutterCtrl.Cmd.Start					:=TRUE;
			IF pSlaveAx.IsHomed=TRUE THEN
				iMi_StatusTxt:="Disabled Cutter . Restart to start";
				pSlaveAx.Home						:=FALSE;
			END_IF;
		
			//Stop command is Given
			IF iAutoCtrl.Cmd.Stop THEN
				pMasterAx.MoveVelocity 				:= FALSE;
			END_IF
		
			//Start command is given 
			IF iAutoCtrl.Cmd.Start THEN
				pMasterAx.MoveVelocity				:= TRUE;
			END_IF
		
			
			//Cutter  is Enabled
			IF iAutoCtrl.Cmd.DisableCutter 			= FALSE THEN
				iMi_StatusTxt 						:= "Cutter Enabled";
				iAutoCtrlState 						:= enAUTO;
			END_IF
		
			//Mode has been Changed
			IF iAutoCtrl.Cmd.ChangeMode AND iAutoCtrl.Cmd.Stop THEN
				iMi_StatusTxt						:= "Machine has been Stopped";
				pMasterAx.MoveVelocity				:= FALSE;
				iAutoCtrl.Cmd.ChangeMode 			:= FALSE;
				pAx_CamSeq.StartSequence 		:= FALSE;
				iAutoCtrlState 						:= enSTOP;
			END_IF
		
			//Manual Mode 
		enMANUAL:
			iMi_StatusTxt							:= "Manual Mode is ON";
			IF iAutoCtrl.Cmd.Stop=TRUE AND iAutoCtrl.Cmd.ChangeMode THEN
				iMi_StatusTxt						:="Machine stopped";
				iAutoCtrl.ManualCmd.ConvPowerON		:=FALSE;
				iAutoCtrl.ManualCmd.CutterPowerON	:=FALSE;
				iAutoCtrlState 						:= enSTOP;
			END_IF;
			
			//stopping all the fucniton
		enSTOP:
			iMi_StatusTxt							:="Machine has been stopped";
			iAutoCtrl.Cmd.Start						:=FALSE;
			gMi_ModeConfirm							:=FALSE;
			pMasterAx.Power							:=FALSE;
			pMasterAx.Enable						:=FALSE;
			pSlaveAx.Power							:=FALSE;
			pSlaveAx.Enable							:=FALSE;
			pConvCtrl.Cmd.Start						:=FALSE;
			iAutoCtrl.Cmd.ChangeMode				:=FALSE;
			iMi_CutModeSelected						:=FALSE;
			pCutterCtrl.Cmd.Start					:=FALSE;
			iAutoCtrl.Cmd.DisableCutter 			:= FALSE;
			iAutoCtrl.Cmd.Stop 						:= FALSE;
			iAutoCtrlState 							:= enWAIT;
		
		enCUT_ZONE:
			iMi_StatusTxt							:="Cutting Zone";
			iAutoCtrl.ManualCmd.ConvPowerON			:=FALSE;
			iAutoCtrl.ManualCmd.CutterPowerON		:=FALSE;
			
			IF pSlaveAx.Position > UPPER_CUT_POS OR pSlaveAx.Position < LOWER_CUT_POS THEN
				iAutoCtrl.Cmd.Start					:=FALSE;
				iAutoCtrlState						:=enWAIT;
			END_IF;
			
	END_CASE
	
	IF NOT iAutoCtrl.Cmd.AutoMode= TRUE THEN
		pMasterAx.Power								:=iAutoCtrl.ManualCmd.ConvPowerON;
		pSlaveAx.Power								:=iAutoCtrl.ManualCmd.CutterPowerON;
		pSlaveAx.JogNegative						:= pCutterCtrl.Cmd.JogBack;
		pSlaveAx.JogPositive						:=pCutterCtrl.Cmd.JogFwd;
		pMasterAx.JogPositive						:=pConvCtrl.Cmd.JogFwd;
		pMasterAx.JogNegative						:=pConvCtrl.Cmd.JogBack;
	END_IF;
	
	//Mapping some variables for sub task control
	pConvCtrl.Cmd.AutoMode := iAutoCtrl.Cmd.AutoMode;
	pCutterCtrl.Cmd.AutoMode := iAutoCtrl.Cmd.AutoMode;
	
	
	//Cutting zone Logic
	IF pSlaveAx.Position < UPPER_CUT_POS AND pSlaveAx.Position > LOWER_CUT_POS AND NOT iAutoCtrl.Cmd.AutoMode THEN
		iAutoCtrlState := enCUT_ZONE;
	END_IF
	
	
	//Hmi Variables calculation
	iMI_LastBagLen := pRegCapture.AdditionalInfo.ActLength / TEN;
	iMI_AvgBagLen := pRegCapture.AdditionalInfo.AverageProductLength /TEN;
	
	IF iAutoCtrl.Cmd.AutoMode THEN
		iMi_SelectedMode := "Auto Mode is Selected";
	ELSE
		iMi_SelectedMode := "Manual Mode is Selected";
	END_IF
	
	
	//Reset Condition
	IF iAutoCtrl.Cmd.Reset THEN
		Reset;
	END_IF
	
	//Condition For Calling RegMarkCapture FB
	IF pSlaveAx.Info.PLCopenState = mpAXIS_SYNCHRONIZED_MOTION THEN
		pRegCapture();
	END_IF
	
	//Calling Alarm ACtion file
	gMI_MODE := iAutoCtrl.Cmd.AutoMode;
	Alarms;
END_PROGRAM
	
	
	
	
	
	
	
	
	
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

