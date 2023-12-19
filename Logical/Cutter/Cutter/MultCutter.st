(*|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|*)
(*| Copyright      :-  B&R Industrial Automation GmbH															 |*)
(*| Contact Person :-  maskeu																					 |*)
(*|——————————————————————————————————————————————————————————————————————————————————————————————————————————————|*)
(*| System       :-  TODO: PrintMark CrossCutter																 |*)
(*| Task Name    :-  TODO: PrintMark CrossCutter																 |*)
(*| Auther Name  :-  maskeu																						 |*)
(*| Created Date :-  December 13, 2023 																		   	 |*)
(*| Task Class   :-  Task Class# 1                                                                 				 |*)
(*| Task Time    :-  Task Timing 10mSec                                                                          |*)
(*| OS Version   :-  V4.12.4                                                                                     |*)
(*| AS Version   :-  AS 4.12.4 .107 SP                                                                           |*)
(*|——————————————————————————————————————————————————————————————————————————————————————————————————————————————|*)
(*| Description  :-  TODO: basic movement of axis with the conveyor		    									 |*)

ACTION MultCutter: 
	//linking the motor with axis
	iFb_SlaveAx.Enable := 1;
	iFb_SlaveAx.MpLink := ADR(gAxisSlave);
	iFb_SlaveAx.Axis := ADR(gAxSlave);

	iFb_SlaveAx.Parameters := ADR(iBasicParameters);
	iFb_SlaveAx();
	
	//	if new velocity by user input is different then will update
	//	IF iVl_OldVelocity <> iBasicParameters.Acceleration THEN
	//		iFb_SlaveAx.Update:=TRUE ;
	//		IF	iFb_SlaveAx.UpdateDone=TRUE THEN
	//			iVl_OldVelocity:= iBasicParameters.Velocity;
	//			iFb_SlaveAx.Update:=FALSE ;
	//		END_IF;
	//	END_IF;
	//	
	//	//	if new accelaration by user input is different then will update
	//	IF iVl_OldAcc<> iBasicParameters.Acceleration THEN
	//		iFb_SlaveAx.Update:=TRUE ;
	//		IF	iFb_SlaveAx.UpdateDone=TRUE THEN
	//			iVl_OldAcc:= iBasicParameters.Acceleration;
	//			iFb_SlaveAx.Update:=FALSE ;
	//		END_IF;
	//	END_IF;
	//	
	//	//	if new deccelaration by user input is different then will update
	//	IF iVl_OldAccNeg<> iBasicParameters.Deceleration THEN
	//		iFb_SlaveAx.Update:=TRUE ;
	//		IF	iFb_SlaveAx.UpdateDone=TRUE THEN
	//			iVl_OldAccNeg:= iBasicParameters.Deceleration;
	//			iFb_SlaveAx.Update:=FALSE ;
	//		END_IF;
	//	END_IF;
	
	
	//Limit for the torque
	iBasicParameters.Torque.Limit:=0.8;
	
	//stopping the axis command
	IF icmdStop=TRUE THEN
		iFb_SlaveAx.Stop:=TRUE;
		IF iFb_SlaveAx.Stopped=TRUE THEN
			iFb_SlaveAx.Stop:=FALSE;
			icmdStop:=FALSE;
		END_IF;
	END_IF;
		
	//if axis is in error mode
	IF iFb_SlaveAx.Error=TRUE THEN
		iAxStep_enum:=enERRORA;
	END_IF;
	
	//state neumeration for axis
	CASE iAxStep_enum OF
		
		//initializtion
		enINITA:
			iAxStep_enum := 	enSTARTA;
			
			//starting
		enSTARTA:
			IF iFb_SlaveAx.Info.ReadyToPowerOn = TRUE THEN
				iAxStep_enum := enPOWER_ONA;
			END_IF
			
			//poweron the axis
		enPOWER_ONA:
			icmdPower := TRUE;
			IF iFb_SlaveAx.PowerOn = TRUE THEN
				IF iFb_SlaveAx.PowerOn AND iFb_SlaveAx.Position < LOWER_CUT_POS THEN
					icmdUpdate:=TRUE; 
					IF iFb_SlaveAx.UpdateDone=TRUE THEN
						iAxStep_enum := enNEGHOMING;
						icmdUpdate:=FALSE;
					END_IF;
				END_IF
				IF iFb_SlaveAx.PowerOn AND iFb_SlaveAx.Position > UPPER_CUT_POS THEN
					icmdUpdate:=TRUE; 
					IF iFb_SlaveAx.UpdateDone=TRUE THEN
						iAxStep_enum := enPOSHOMING;
						icmdUpdate:=FALSE;
					END_IF;
				END_IF
			END_IF

			//homing the motor
		enNEGHOMING:
			iBasicParameters.Home.Mode:=mpAXIS_HOME_MODE_REF_PULSE;
			iBasicParameters.Home.HomingDirection:=mpAXIS_HOME_DIR_NEGATIVE;
			iBasicParameters.Home.SensorOffset := HOFFSET_DUAL;
			iBasicParameters.Home.HomingVelocity := HOMING_VEL;
			iBasicParameters.Home.StartVelocity := START_VEL;
			icmdHome := TRUE;
			iAxStep_enum:=enOPERATIONA;
			
		enPOSHOMING:	
			iBasicParameters.Home.Mode:=mpAXIS_HOME_MODE_REF_PULSE;
			iBasicParameters.Home.HomingDirection:=mpAXIS_HOME_DIR_POSITIVE;;
			iBasicParameters.Home.SensorOffset := HOFFSET_DUAL;
			iBasicParameters.Home.HomingVelocity := HOMING_VEL;
			iBasicParameters.Home.StartVelocity := START_VEL;
			icmdHome := TRUE;
			iAxStep_enum:=enOPERATIONA;
			//operation mode
		enOPERATIONA:
			IF iFb_SlaveAx.IsHomed=TRUE THEN
				icmdHome:=FALSE;
			END_IF;
			IF iFb_SlaveAx.Error =TRUE THEN
				iAxStep_enum := enERRORA;
			END_IF
			IF icmdMoveAdditive=TRUE THEN
				iFb_SlaveAx.MoveAdditive:=TRUE;
				icmdMoveAdditive := FALSE;
				icmdHome := FALSE;
			END_IF;
			
			//error mode
		enERRORA:
			icmdPower := FALSE;
			icmdMoveVelocity := FALSE;
			icmdStop := FALSE;
			
			icmdErrorReset:=TRUE;
			IF iFb_SlaveAx.Error = FALSE THEN;
				iAxStep_enum := enSTARTA;
				icmdErrorReset := FALSE;
			END_IF
	END_CASE
	iFb_SlaveAx.Update:=icmdUpdate;
	iFb_SlaveAx.Home:=icmdHome;
END_ACTION
