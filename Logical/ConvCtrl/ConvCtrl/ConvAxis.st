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

ACTION ConvAXisAxn: 
	//linking the motor with axis
	iFb_MasterAx.Enable := 1;
	iFb_MasterAx.MpLink := ADR(gmlSlave);
	iFb_MasterAx.Axis := ADR(gAxSlave);

	iFb_MasterAx.Parameters := ADR(iBasicParameters);
	iFb_MasterAx();
	
	//	if new velocity by user input is different then will update
	//	IF iVl_OldVelocity <> iBasicParameters.Acceleration THEN
	//		iFb_MasterAx.Update:=TRUE ;
	//		IF	iFb_MasterAx.UpdateDone=TRUE THEN
	//			iVl_OldVelocity:= iBasicParameters.Velocity;
	//			iFb_MasterAx.Update:=FALSE ;
	//		END_IF;
	//	END_IF;
	//	
	//	//	if new accelaration by user input is different then will update
	//	IF iVl_OldAcc<> iBasicParameters.Acceleration THEN
	//		iFb_MasterAx.Update:=TRUE ;
	//		IF	iFb_MasterAx.UpdateDone=TRUE THEN
	//			iVl_OldAcc:= iBasicParameters.Acceleration;
	//			iFb_MasterAx.Update:=FALSE ;
	//		END_IF;
	//	END_IF;
	//	
	//	//	if new deccelaration by user input is different then will update
	//	IF iVl_OldAccNeg<> iBasicParameters.Deceleration THEN
	//		iFb_MasterAx.Update:=TRUE ;
	//		IF	iFb_MasterAx.UpdateDone=TRUE THEN
	//			iVl_OldAccNeg:= iBasicParameters.Deceleration;
	//			iFb_MasterAx.Update:=FALSE ;
	//		END_IF;
	//	END_IF;
	
	
	//Limit for the torque
	iBasicParameters.Torque.Limit:=0.8;
	
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
		iAxStep_enum:=enERRORA;
	END_IF;
	
	//state neumeration for axis
	CASE iAxStep_enum OF
		
		//initializtion
		enINITA:
			iAxStep_enum := 	enSTARTA;
			
			//starting
		enSTARTA:
			IF iFb_MasterAx.Info.ReadyToPowerOn = TRUE THEN
				iAxStep_enum := enPOWER_ONA;
			END_IF
			
			//poweron the axis
		enPOWER_ONA:
			icmdPower := TRUE;
			IF iFb_MasterAx.PowerOn = TRUE THEN
				IF iFb_MasterAx.PowerOn AND iFb_MasterAx.Position < LOWER_CUT_POS THEN
					icmdUpdate:=TRUE; 
					IF iFb_MasterAx.UpdateDone=TRUE THEN
						iAxStep_enum := enNEGHOMING;
						icmdUpdate:=FALSE;
					END_IF;
				END_IF
				IF iFb_MasterAx.PowerOn AND iFb_MasterAx.Position > UPPER_CUT_POS THEN
					icmdUpdate:=TRUE; 
					IF iFb_MasterAx.UpdateDone=TRUE THEN
						iAxStep_enum := enPOSHOMING;
						icmdUpdate:=FALSE;
					END_IF;
				END_IF
			END_IF

			//homing the motor
		enNEGHOMING:
			iBasicParameters.Home.Mode:=mpAXIS_HOME_MODE_REF_PULSE;
			iBasicParameters.Home.HomingDirection:=mpAXIS_HOME_DIR_NEGATIVE;
			iBasicParameters.Home.SensorOffset := HOFFSET_SINGLE;
			iBasicParameters.Home.HomingVelocity := HOMING_VEL;
			iBasicParameters.Home.StartVelocity := START_VEL;

			icmdHome := TRUE;
		enPOSHOMING:	
			iBasicParameters.Home.Mode:=mpAXIS_HOME_MODE_REF_PULSE;
			iBasicParameters.Home.HomingDirection:=mpAXIS_HOME_DIR_POSITIVE;;
			iBasicParameters.Home.SensorOffset := HOFFSET_SINGLE;
			iBasicParameters.Home.HomingVelocity := HOMING_VEL;
			iBasicParameters.Home.StartVelocity := START_VEL;
			
		
			icmdHome := TRUE;
			//operation mode
		enOPERATIONA:
			
			IF iFb_MasterAx.IsHomed=TRUE THEN
				icmdHome := FALSE;
				iAxStep_enum:=enOPERATIONA;
			END_IF;
			
			IF iFb_MasterAx.Error =TRUE THEN
				iAxStep_enum := enERRORA;
			END_IF
			IF icmdMoveAdditive=TRUE THEN
				iFb_MasterAx.MoveAdditive:=TRUE;
				icmdMoveAdditive := FALSE;
				icmdHome := FALSE;
			END_IF;
			
			//error mode
		enERRORA:
			icmdPower := FALSE;
			icmdMoveVelocity := FALSE;
			icmdStop := FALSE;
			
			icmdErrorReset:=TRUE;
			IF iFb_MasterAx.Error = FALSE THEN;
				iAxStep_enum := enSTARTA;
				icmdErrorReset := FALSE;
			END_IF
	END_CASE
	iFb_MasterAx.Update:=icmdUpdate;
	iFb_MasterAx.Home:=icmdHome;
	iFb_MasterAx.Power:=icmdPower;
	
END_ACTION
