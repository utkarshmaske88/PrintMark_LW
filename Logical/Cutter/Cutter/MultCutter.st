(*|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|*)
(*| Copyright      :-  B&R Industrial Automation GmbH															 |*)
(*| Contact Person :-  maskeu																					 |*)
(*|——————————————————————————————————————————————————————————————————————————————————————————————————————————————|*)
(*| System       :-  cutter control                                                                    	 		 |*)
(*| Task Name    :-  cutter control																		  		 |*)
(*| Auther Name  :-  maskeu																						 |*)
(*| Created Date :-  December 19, 2023 																		   	 |*)
(*| Task Class   :-  Task Class# 1                                                                 				 |*)
(*| Task Time    :-  Task Timing 2mSec                                                                           |*)
(*| OS Version   :-  G4.93                                                                                       |*)
(*| AS Version   :-  AS 4.12.4.107 SP                                                                            |*)
(*|——————————————————————————————————————————————————————————————————————————————————————————————————————————————|*)
(*| Description  :-  Multiple cutter fucnitoning		    													 |*)
(*| V1.00.0   19/12/2023	 Maskeu        added homing states									Complete		 |*)
(*| V2.00.0   21/12/2023	 Maskeu        added homing for lower positon with absolute homing	Complete		 |*)
(*| V3.00.0   25/12/2023	 Maskeu        edited homing for negative`							Complete		 |*)

ACTION MultCutter: 
	//linking the motor with axis
	gIR_Trigger:=iFb_SlaveAx.Info.DigitalInputsStatus.Trigger1;
	//iFb_SlaveAx.Enable := 1;
	iFb_SlaveAx.MpLink := ADR(gmlSlave);
	iFb_SlaveAx.Axis := ADR(gAxSlave);

	iFb_SlaveAx.Parameters := ADR(iBasicParSlave);
	iFb_SlaveAx();
	
	
	//position for the axis for homing
	iBasicParSlave.Position:=1900;
	
	//stopping the axis command
	IF iFb_SlaveAx.Stop=TRUE THEN
		IF iFb_SlaveAx.Stopped=TRUE THEN
			iFb_SlaveAx.Stop:=FALSE;
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
			IF iCutCtrl.Cmd.Start=TRUE THEN
				iAxStep_enum := 	enSTARTA;
			END_IF;
			//starting
		enSTARTA:
			IF iFb_SlaveAx.Info.ReadyToPowerOn = TRUE THEN
				iAxStep_enum := enPOWER_ONA;
			END_IF
			
			//poweron the axis
		enPOWER_ONA:
			iFb_SlaveAx.Power := TRUE;
			IF iFb_SlaveAx.PowerOn = TRUE THEN
				//if axis is between first blade cutting upper and homing position
				IF iFb_SlaveAx.PowerOn AND iFb_SlaveAx.Position < FIRST_CUT_LOWER AND iFb_SlaveAx.Position > HOME_POS   THEN
					
					iBasicParSlave.Home.Mode:=4;
					iBasicParSlave.Direction:=mpAXIS_DIR_NEGATIVE ; 
					iBasicParSlave.Home.HomingDirection:=mpAXIS_HOME_DIR_NEGATIVE;
					iBasicParSlave.Home.StartDirection:=1;
					iBasicParSlave.Home.SensorOffset := HOFFSET_NEGDUAL;
					iBasicParSlave.Home.HomingVelocity := HOMING_VEL;
					iBasicParSlave.Home.StartVelocity := START_VEL;
					iFb_SlaveAx.Update:=TRUE;
					IF iFb_SlaveAx.UpdateDone=TRUE THEN
						iFb_SlaveAx.Home := TRUE;
						iAxStep_enum := enNEGHOMING;
						iFb_SlaveAx.Update:=FALSE;
					END_IF;			
					//if axis is between first blade cutting upper and homing position
				ELSIF iFb_SlaveAx.PowerOn AND iFb_SlaveAx.Position < HOME_POS AND iFb_SlaveAx.Position> SEC_CUT_UPPER THEN 
					
					iBasicParSlave.Home.Mode:=4;
					iBasicParSlave.Direction:=mpAXIS_DIR_POSITIVE ; 
					iBasicParSlave.Home.HomingDirection:=mpAXIS_HOME_DIR_POSITIVE;
					iBasicParSlave.Home.StartDirection:=1;
					iBasicParSlave.Home.SensorOffset := HOFFSET_NEGDUAL;
					iBasicParSlave.Home.HomingVelocity := HOMING_VEL;
					iBasicParSlave.Home.StartVelocity := START_VEL;
					iFb_SlaveAx.Update:=TRUE;
					IF iFb_SlaveAx.UpdateDone=TRUE THEN
						iAxStep_enum := enNEGHOMING;
						iFb_SlaveAx.Update:=FALSE;
					END_IF;			
					
					//if axis is between first blade cutting upper and homing position
				ELSIF iFb_SlaveAx.PowerOn AND iFb_SlaveAx.Position > FIRST_CUT_UPPER AND iFb_SlaveAx.Position < MAX_POS_AXIS THEN
					
					iBasicParSlave.Home.Mode:=mpAXIS_HOME_MODE_REF_PULSE;
					iBasicParSlave.Home.HomingDirection:=mpAXIS_HOME_DIR_POSITIVE;
					iBasicParSlave.Home.SensorOffset := HOFFSET_DUAL;
					iBasicParSlave.Home.HomingVelocity := 150;
					iBasicParSlave.Home.StartVelocity := 50;
					iFb_SlaveAx.Update:=TRUE; 
					IF iFb_SlaveAx.UpdateDone=TRUE THEN
						iAxStep_enum := enPOSHOMING;
						iFb_SlaveAx.Update:=FALSE;
					END_IF;			
				ELSIF iFb_SlaveAx.PowerOn AND iFb_SlaveAx.Position < SEC_CUT_LOWER AND iFb_SlaveAx.Position> HOME_OFFSET THEN
					iFb_SlaveAx.Update:=TRUE; 
					IF iFb_SlaveAx.UpdateDone=TRUE THEN
							
						iBasicParSlave.Home.Mode:=mpAXIS_HOME_MODE_REF_PULSE;
						iBasicParSlave.Home.HomingDirection:=mpAXIS_HOME_DIR_NEGATIVE;
						iBasicParSlave.Home.SensorOffset := HOFFSET_DUAL;
						iBasicParSlave.Home.HomingVelocity := HOMING_VEL;
						iBasicParSlave.Home.StartVelocity := START_VEL;
						iFb_SlaveAx.Update:=TRUE; 
						IF iFb_SlaveAx.UpdateDone=TRUE THEN
							iFb_SlaveAx.Home := TRUE;
							iAxStep_enum := enPOSHOMINGSEC;
							iFb_SlaveAx.Update:=FALSE;
						END_IF;
					END_IF;
				END_IF
			END_IF

			//homing the motor
		enNEGHOMING:
			iFb_SlaveAx.MoveAbsolute:=TRUE;
			IF iFb_SlaveAx.UpdateDone=TRUE THEN
				iFb_SlaveAx.MoveAbsolute:=FALSE;
				iFb_SlaveAx.Update:=FALSE;
				iAxStep_enum :=	enNEEGHOMEMOVE;
			END_IF;
			
		enNEEGHOMEMOVE:
			IF iFb_SlaveAx.InPosition=TRUE THEN
				iFb_SlaveAx.MoveAbsolute:=FALSE;
				iFb_SlaveAx.Home:=TRUE;
				iAxStep_enum := enOPERATIONA;
			END_IF;
			
		enPOSHOMING:
			IF iFb_SlaveAx.IsHomed=TRUE THEN
				iAxStep_enum := enOPERATIONA;
			END_IF;
			//operation mode			
		enPOSHOMINGSEC:
		
			iFb_SlaveAx.Home := TRUE;
			IF iFb_SlaveAx.IsHomed=TRUE THEN
				iAxStep_enum := enOPERATIONA;
			END_IF;
			//operation mode
		enOPERATIONA:
					
			iFb_SlaveAx.Home:=TRUE;
			IF iFb_SlaveAx.IsHomed=TRUE THEN
				iFb_SlaveAx.Home:=FALSE;
			END_IF;
			
			IF iCutCtrl.Cmd.Start=FALSE THEN
				iAxStep_enum := enINITA;
				iFb_SlaveAx.Power := FALSE;
			END_IF;
			//error mode
		enERRORA:
			iFb_SlaveAx.Power := FALSE;
			iFb_SlaveAx.MoveVelocity:= FALSE;
			IF iFb_SlaveAx.Error = FALSE THEN;
				iAxStep_enum := enSTARTA;
				iFb_SlaveAx.ErrorReset := FALSE;
			END_IF
	END_CASE
	//Reset Condition
	IF iCutCtrl.Cmd.Start= FALSE THEN
		iAxStep_enum 			:= enINITA;
	END_IF
END_ACTION
