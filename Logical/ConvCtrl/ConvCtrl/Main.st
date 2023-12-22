(*|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|*)
(*| Copyright      :-  B&R Industrial Automation GmbH															 |*)
(*| Contact Person :-  maskeu																					 |*)
(*|——————————————————————————————————————————————————————————————————————————————————————————————————————————————|*)
(*| System       :-  TODO:logo conv axis                                                                      	 |*)
(*| Task Name    :-  TODO: logo conv axis																		 |*)
(*| Auther Name  :-  maskeu																						 |*)
(*| Created Date :-  December 13, 2023 																		   	 |*)
(*| Task Class   :-  Task Class# 1                                                                 				 |*)
(*| Task Time    :-  Task Timing 10mSec                                                                          |*)
(*| OS Version   :-  V4.12.4                                                                                     |*)
(*| AS Version   :-  AS 4.12.4 .107 SP                                                                           |*)
(*|——————————————————————————————————————————————————————————————————————————————————————————————————————————————|*)
(*| Description  :-  TODO: basic movement of axis with the conveyor		    									 |*)

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
	
	//	if new velocity by user input is different then will update
	//	IF iVl_OldVelocity <> iBasicParamMaster.Acceleration THEN
	//		iFb_MasterAx.Update:=TRUE ;
	//		IF	iFb_MasterAx.UpdateDone=TRUE THEN
	//			iVl_OldVelocity:= iBasicParamMaster.Velocity;
	//			iFb_MasterAx.Update:=FALSE ;
	//		END_IF;
	//	END_IF;
	//	
	//	//	if new accelaration by user input is different then will update
	//	IF iVl_OldAcc<> iBasicParamMaster.Acceleration THEN
	//		iFb_MasterAx.Update:=TRUE ;
	//		IF	iFb_MasterAx.UpdateDone=TRUE THEN
	//			iVl_OldAcc:= iBasicParamMaster.Acceleration;
	//			iFb_MasterAx.Update:=FALSE ;
	//		END_IF;
	//	END_IF;
	//	
	//	//	if new deccelaration by user input is different then will update
	//	IF iVl_OldAccNeg<> iBasicParamMaster.Deceleration THEN
	//		iFb_MasterAx.Update:=TRUE ;
	//		IF	iFb_MasterAx.UpdateDone=TRUE THEN
	//			iVl_OldAccNeg:= iBasicParamMaster.Deceleration;
	//			iFb_MasterAx.Update:=FALSE ;
	//		END_IF;
	//	END_IF;
	
	
	//Limit for the torque
	iBasicParamMaster.Torque.Limit:=0.8;
	
	//stopping the axis command
	IF icmdStop=TRUE THEN
		iFb_MasterAx.Stop:=TRUE;
		IF iFb_MasterAx.Stopped=TRUE THEN
			iFb_MasterAx.Stop:=FALSE;
			icmdStop:=FALSE;
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
			iAxStepMaster := 	enSTARTA;
			
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
			//operation mode
			
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
			icmdMoveVelocity := FALSE;
			icmdStop := FALSE;
			
			icmdErrorReset:=TRUE;
			IF iFb_MasterAx.Error = FALSE THEN;
				iAxStepMaster := enSTARTA;
				icmdErrorReset := FALSE;
			END_IF
	END_CASE
	
	
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

