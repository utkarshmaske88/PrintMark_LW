(*|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|*)
(*| Copyright      :-  B&R Industrial Automation GmbH															 |*)
(*| Contact Person :-  maskeu																					 |*)
(*|——————————————————————————————————————————————————————————————————————————————————————————————————————————————|*)
(*| System       :- conveyor control                                                                    	 	 |*)
(*| Task Name    :- conveyor control																			 |*)
(*| Auther Name  :-  maskeu																						 |*)
(*| Created Date :-  December 13, 2023 																		   	 |*)
(*| Task Class   :-  Task Class# 1                                                                 				 |*)
(*| Task Time    :-  Task Timing 10mSec                                                                          |*)
(*| OS Version   :-  V4.12.4                                                                                     |*)
(*| AS Version   :-  AS 4.12.4 .107 SP                                                                           |*)
(*|——————————————————————————————————————————————————————————————————————————————————————————————————————————————|*)
(*| Description  :-  movement of  conveyor		    															 |*)
(*| V1.00.0   22/12/2023	 Maskeu        added homing mode 									Complete	 	 |*)
(*| V2.00.0   23/12/2023	 Maskeu        added manual mode jog pos-neg						Complete		 |*)
PROGRAM _INIT
	(* Insert code here *)
	iBasicParamMaster.Acceleration:=480000;
	iBasicParamMaster.Deceleration:=4800000;
	iBasicParamMaster.Jog.Velocity:=45;
	iBasicParamMaster.Home.Mode:= mpAXIS_HOME_MODE_ABS_SWITCH;
	iBasicParamMaster.Home.StartVelocity:=200;
	iBasicParamMaster.Home.HomingDirection:= mpAXIS_HOME_DIR_POSITIVE;
	iBasicParamMaster.Home.StartDirection:=mpAXIS_HOME_DIR_POSITIVE;
	iBasicParamMaster.Home.SwitchEdge:=mpAXIS_HOME_DIR_NEGATIVE;
END_PROGRAM

PROGRAM _CYCLIC
		//linking the motor with axis
	iFb_MasterAx.Enable := 1;
	iFb_MasterAx.MpLink := ADR(gmlMaster);
	iFb_MasterAx.Axis := ADR(gAxMaster);

	iFb_MasterAx.Parameters := ADR(iBasicParamMaster);
	iFb_MasterAx();

	//Updating the paramters set from HMI by converting them 
	iBasicParamMaster.Velocity := (iMI_ConSetSpeed * PRODUCT_LENGTH)/PER_SEC;
	IF iMI_ConSetSpeed <> (iBasicParamMaster.Velocity * PER_SEC)/PRODUCT_LENGTH  
		OR iMI_ConSetJogAcc <> (iBasicParamMaster.Jog.Acceleration * PER_SEC)/PRODUCT_LENGTH 
		OR iMI_ConSetJogDeacc <> (iBasicParamMaster.Jog.Deceleration * PER_SEC)/PRODUCT_LENGTH 
		OR iMI_ConSetJogVel <> (iBasicParamMaster.Jog.Velocity  * PER_SEC)/PRODUCT_LENGTH 
		THEN
		iFb_MasterAx.Update := TRUE;
		IF iFb_MasterAx.UpdateDone THEN
			iFb_MasterAx.Update := FALSE;
		END_IF
	END_IF
	
	
	//Mapping of parameters
	iBasicParamMaster.Jog.Acceleration := (iMI_ConSetJogAcc * PRODUCT_LENGTH)/PER_SEC;
	iBasicParamMaster.Jog.Deceleration := (iMI_ConSetJogDeacc * PRODUCT_LENGTH)/PER_SEC;
	iBasicParamMaster.Jog.Velocity := (iMI_ConSetJogVel * PRODUCT_LENGTH)/PER_SEC;
	iMI_ConActSpeed := (iFb_MasterAx.Velocity * PER_SEC)/PRODUCT_LENGTH ;
	//stopping the axis command
	IF	iFb_MasterAx.Stop=TRUE THEN
		IF iFb_MasterAx.Stopped=TRUE THEN
			iFb_MasterAx.Stop:=FALSE;
		END_IF;
	END_IF;
		
	//if axis is in error mode
	IF iFb_MasterAx.Error=TRUE THEN
		iAxStepMaster:=enERRORA;
	END_IF;
	
	//state neumeration for axis
	CASE iAxStepMaster OF
		
		//initializtion
		enINITA:
			IF iConCtrl.Cmd.Start=TRUE THEN
				iAxStepMaster := 	enSTARTA;
			END_IF;
			//starting
		enSTARTA:
			IF iFb_MasterAx.Info.ReadyToPowerOn = TRUE THEN
				iAxStepMaster := enPOWER_ONA;
			END_IF
			
			//poweron the axis
		enPOWER_ONA:
			iFb_MasterAx.Power 	:= TRUE;
			IF iFb_MasterAx.PowerOn THEN

				iFb_MasterAx.Home 	:= TRUE;
				IF gAutoMode =TRUE THEN
					iAxStepMaster:=enAUTOMATIC;
				ELSIF gManulMode=TRUE THEN
					iAxStepMaster:=enMANUAL;
				END_IF;
			END_IF;
			//manual mode
			
		enMANUAL:
			IF iConCtrl.Cmd.JogFwd THEN
				iAxStepMaster		:=	enJOGPOSITIVE;
			END_IF;
		
			IF iConCtrl.Cmd.JogBack THEN
				iAxStepMaster 		:= 	enJOGNEGATIVE;
			END_IF
			iVa_OldRecPosition 		:= K_ZERO;
			IF iConCtrl.Cmd.Start = FALSE THEN
				iAxStepMaster 		:= enINITA;
				iFb_MasterAx.Power := FALSE;
			END_IF
			
		
			//Jog Positive of Conv
		enJOGPOSITIVE :
			
			iFb_MasterAx.JogPositive := TRUE;
			IF NOT iConCtrl.Cmd.JogFwd THEN
				iFb_MasterAx.JogPositive := FALSE;
				iAxStepMaster := enMANUAL;
			END_IF
			
			//Jog negative of COnv
		enJOGNEGATIVE :
			iFb_MasterAx.JogNegative := TRUE;
			IF (iFb_MasterAx.JogNegative  AND EDGENEG(iConCtrl.Cmd.PrintMark)) OR 
				(EDGEPOS(iFb_MasterAx.JogNegative) AND iConCtrl.Cmd.PrintMark ) THEN
				iVa_OldRecPosition := iFb_MasterAx.Position;
			END_IF
			//Setting 3 Cm limit for jog Negative
			IF (iVa_OldRecPosition - iFb_MasterAx.Position) > (PRINT_MARK_LIMIT) AND iVa_OldRecPosition <> K_ZERO THEN
				iFb_MasterAx.JogNegative := FALSE;
				iConCtrl.Cmd.JogBack := FALSE;
				iAxStepMaster := enMANUAL;
			ELSE
				iConCtrl.Status.JogNegReady := TRUE;
			END_IF
		
			//error mode
		enERRORA:
			iFb_MasterAx.Power := FALSE;
			iFb_MasterAx.MoveVelocity:= FALSE;
			IF iFb_MasterAx.Error = FALSE THEN;
				iAxStepMaster := enSTARTA;
				icmdErrorReset := FALSE;
			END_IF
	END_CASE
	
	//trigger for conveyor for homing
	iConCtrl.Cmd.PrintMark:=gIR_Trigger;
	iVa_MasterInputs.Enable:=TRUE;
	iVa_MasterInputs.Axis:=ADR(gAxMaster);
	iVa_MasterInputs.HomeSwitch:=gIR_Trigger;
	iVa_MasterInputs();
	
	IF iConCtrl.Cmd.Start = FALSE THEN
		iAxStepMaster := enINITA;
	END_IF
	
	iBasicParamMaster.CyclicRead.TorqueMode:=mpAXIS_READ_CYCLIC;
END_PROGRAM

PROGRAM _EXIT
	//DISABLING THE funciton block
	iFb_MasterAx.Enable:=FALSE;
	iFb_MasterAx();
	iVa_MasterInputs.Enable:=FALSE;
	iVa_MasterInputs();
END_PROGRAM

