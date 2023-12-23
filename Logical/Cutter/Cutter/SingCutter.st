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
(*| Description  :-  CUTTER cam sequnce and basic initial prameters		    									 |*)
(*| V1.00.0   19/12/2023	 Maskeu        added homing states									Complete		 |*)
(*| V2.00.0   20/12/2023	 Maskeu        added jog limits										Complete		 |*)
(*| V3.00.0   23/12/2023	 Maskeu        modified positive homing state						Complete		 |*)

ACTION SingleCutter: 
	//linking the motor with axis
	gIR_Trigger:=iFb_SlaveAx.Info.DigitalInputsStatus.Trigger1;
	iFb_SlaveAx.Enable := 1;
	iFb_SlaveAx.MpLink := ADR(gmlSlave);
	iFb_SlaveAx.Axis := ADR(gAxSlave);

	iFb_SlaveAx.Parameters := ADR(iBasicParSlave);
	iFb_SlaveAx();
	
	//	if new velocity by user input is different then will update
	//	IF iVl_OldVelocity <> iBasicParSlave.Acceleration THEN
	//		iFb_SlaveAx.Update:=TRUE ;
	//		IF	iFb_SlaveAx.UpdateDone=TRUE THEN
	//			iVl_OldVelocity:= iBasicParSlave.Velocity;
	//			iFb_SlaveAx.Update:=FALSE ;
	//		END_IF;
	//	END_IF;
	//	
	//	//	if new accelaration by user input is different then will update
	//	IF iVl_OldAcc<> iBasicParSlave.Acceleration THEN
	//		iFb_SlaveAx.Update:=TRUE ;
	//		IF	iFb_SlaveAx.UpdateDone=TRUE THEN
	//			iVl_OldAcc:= iBasicParSlave.Acceleration;
	//			iFb_SlaveAx.Update:=FALSE ;
	//		END_IF;
	//	END_IF;
	//	
	//	//	if new deccelaration by user input is different then will update
	//	IF iVl_OldAccNeg<> iBasicParSlave.Deceleration THEN
	//		iFb_SlaveAx.Update:=TRUE ;
	//		IF	iFb_SlaveAx.UpdateDone=TRUE THEN
	//			iVl_OldAccNeg:= iBasicParSlave.Deceleration;
	//			iFb_SlaveAx.Update:=FALSE ;
	//		END_IF;
	//	END_IF;
	
	
	//Limit for the torque
	iBasicParSlave.Torque.Limit:=0.8;
	
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
				
				//when axis has passed lower cut positon
				IF iFb_SlaveAx.PowerOn AND iFb_SlaveAx.Position < LOWER_CUT_POS THEN
					iFb_SlaveAx.Update:=TRUE; 
					IF iFb_SlaveAx.UpdateDone=TRUE THEN
						iAxStep_enum := enNEGHOMING;
						iFb_SlaveAx.Update:=FALSE;
					END_IF;
				END_IF
				
				//when axis has not passed upper cut positon
				IF iFb_SlaveAx.PowerOn AND iFb_SlaveAx.Position > UPPER_CUT_POS THEN
					iFb_SlaveAx.Update:=TRUE; 
					IF iFb_SlaveAx.UpdateDone=TRUE THEN
						iAxStep_enum := enPOSHOMING;
						iFb_SlaveAx.Update:=FALSE;
					END_IF;
				END_IF
			END_IF

			//homing in positive direction
		enNEGHOMING:
			iBasicParSlave.Home.Mode:=mpAXIS_HOME_MODE_REF_PULSE;
			iBasicParSlave.Home.HomingDirection:=mpAXIS_HOME_DIR_NEGATIVE;
			iBasicParSlave.Home.SensorOffset := HOFFSET_SINGLE;
			iBasicParSlave.Home.HomingVelocity := HOMING_VEL;
			iBasicParSlave.Home.StartVelocity := START_VEL;
			iFb_SlaveAx.Home := TRUE;
			iAxStep_enum:=	enOPERATIONA;
			
			//homing in negative direction
		enPOSHOMING:	
			iBasicParSlave.Home.Mode:=mpAXIS_HOME_MODE_REF_PULSE;
			iBasicParSlave.Home.HomingDirection:=mpAXIS_HOME_DIR_POSITIVE;;
			iBasicParSlave.Home.SensorOffset := HOFFSET_SINGLE;
			iBasicParSlave.Home.HomingVelocity := HOMING_VEL;
			iBasicParSlave.Home.StartVelocity := START_VEL;
			iFb_SlaveAx.Home := TRUE;
			iAxStep_enum:=	enOPERATIONA;
			//operation mode
		enOPERATIONA:
			
			IF iFb_SlaveAx.IsHomed=TRUE THEN
				iFb_SlaveAx.Home := FALSE;
				iAxStep_enum:=enOPERATIONA;
				IF gAutoMode=TRUE THEN
					
				ELSIF gManulMode THEN
					iAxStep_enum:=	enMANUAL;
				END_IF;
			END_IF;
			
		enMANUAL:
			IF iCutCtrl.Cmd.JogFwd THEN
				iAxStep_enum:=	enJOGPOSITIVE;
			END_IF;
			IF iCutCtrl.Cmd.JogBack THEN
				iAxStep_enum:=	enJOGNEGATIVE;
			END_IF;
			
			IF iFb_SlaveAx.Position = FIRST_CUT_LOWER THEN
				iCutCtrl.Cmd.JogFwd := FALSE;
			END_IF
		enJOGPOSITIVE:
			IF NOT iCutCtrl.Cmd.JogFwd=TRUE OR iFb_SlaveAx.Position=FIRST_CUT_LOWER THEN
				iFb_SlaveAx.JogPositive:=FALSE;
				iAxStep_enum:=enOPERATIONA;
			ELSE
				iFb_SlaveAx.JogPositive:=TRUE;
			END_IF;
				
			IF iFb_SlaveAx.Position= FIRST_CUT_LOWER THEN
				iCutCtrl.Cmd.JogFwd:=FALSE;
			END_IF;
			
		enJOGNEGATIVE:
			IF NOT iCutCtrl.Cmd.JogBack=TRUE OR iFb_SlaveAx.Position=FIRST_CUT_UPPER THEN
				iFb_SlaveAx.JogNegative:=FALSE;
				iAxStep_enum:=enOPERATIONA;
			ELSE
				iFb_SlaveAx.JogNegative:=TRUE;
			END_IF;
				
			IF iFb_SlaveAx.Position= FIRST_CUT_UPPER THEN
				iCutCtrl.Cmd.JogBack:=FALSE;
			END_IF;
			
		enCUTTINGZONE:
			iFb_SlaveAx.Power:=FALSE;
			IF (iFb_SlaveAx.Position < FIRST_CUT_LOWER OR iFb_SlaveAx.Position  >FIRST_CUT_UPPER) AND iFb_SlaveAx.IsHomed THEN
				iFb_SlaveAx.Power:=TRUE;
				iAxStep_enum := enOPERATIONA;
			ELSIF  (iFb_SlaveAx.Position  < FIRST_CUT_LOWER OR iFb_SlaveAx.Position  >FIRST_CUT_UPPER) AND NOT  iFb_SlaveAx.IsHomed THEN
				iAxStep_enum := enPOWER_ONA;
			END_IF
			//error mode
		enERRORA:
			iFb_SlaveAx.Power := FALSE;
			icmdMoveVelocity := FALSE;
			icmdStop := FALSE;
			
			icmdErrorReset:=TRUE;
			IF iFb_SlaveAx.Error = FALSE THEN;
				iAxStep_enum := enSTARTA;
				icmdErrorReset := FALSE;
			END_IF
	END_CASE
	
	
	CASE iJogLimState OF
		
		//checking the value of jog positive and negative
		enCHECKVEL:
			IF iFb_SlaveAx.JogNegative = TRUE THEN
				iJogLimState							:= enUPPERPOS;
			END_IF;
			IF (iFb_SlaveAx.JogPositive = TRUE) THEN
				iJogLimState							:= enLOWERPOS;
			END_IF;
			
			//will give command once again
		enADDVEL:
			iFb_SlaveAx.JogPositive						:= TRUE;
			iFb_SlaveAx.JogNegative						:= TRUE;
			iJogLimState								:= enCHECKVEL;
				
			//if axis position is greater than upper cut
		enUPPERPOS:
			IF (iFb_SlaveAx.CommandAborted = TRUE) THEN
				iJogLimState							:= enADDVEL;
				iFb_SlaveAx.JogNegative	:= FALSE;
			END_IF;
				
			IF (iFb_SlaveAx.Position > UPPER_CUT_POS)THEN
				iBasicParSlave.Jog.LowerLimit			:= FIRST_CUT_UPPER;
				iBasicParSlave.Jog.UpperLimit			:= MAX_POS_AXIS;
				iFb_SlaveAx.Update						:= TRUE;
				iJogLimState							:= enUPDATE;
			END_IF;
			
			//if axis position is lower than lower cut
		enLOWERPOS:
			IF (iFb_SlaveAx.CommandAborted = TRUE) THEN
				iJogLimState							:= enADDVEL;
				iFb_SlaveAx.JogPositive					:= FALSE;
			END_IF;
				
			IF (iFb_SlaveAx.Position < LOWER_CUT_POS)THEN
				iBasicParSlave.Jog.LowerLimit			:=ZERO;
				iBasicParSlave.Jog.UpperLimit			:= FIRST_CUT_LOWER;
				iFb_SlaveAx.Update						:= TRUE;
				iJogLimState							:= enUPDATE;
			END_IF;
			
			//updating state on position
		enUPDATE:
			IF iFb_SlaveAx.UpdateDone = TRUE THEN
				iFb_SlaveAx.Update						:= FALSE;
			END_IF;
			IF iFb_SlaveAx.JogNegative = TRUE AND iFb_SlaveAx.Position <ZERO AND iFb_SlaveAx.Position > UPPER_CUT_POS THEN
				iJogLimState							:= enUPPERPOS;
			END_IF;
			IF (iFb_SlaveAx.JogPositive = TRUE) AND iFb_SlaveAx.Position > ZERO AND iFb_SlaveAx.Position < LOWER_CUT_POS  THEN
				iJogLimState							:= enLOWERPOS;
			END_IF;
			IF ((iFb_SlaveAx.Position = FIRST_CUT_UPPER) OR (iFb_SlaveAx.Position =FIRST_CUT_LOWER )) THEN
				iFb_SlaveAx.JogNegative					:= FALSE;
				iFb_SlaveAx.JogPositive					:= FALSE;
				iJogLimState							:= enRESET;
			END_IF;
			
			//reseting the values
		enRESET:
	
			iBasicParSlave.Jog.LowerLimit				:= ZERO;
			iBasicParSlave.Jog.UpperLimit				:= ZERO;
			iFb_SlaveAx.Update							:= TRUE;
			IF iFb_SlaveAx.UpdateDone = TRUE THEN
				iFb_SlaveAx.Update						:= FALSE;
				iJogLimState							:= enCHECKVEL;
			END_IF;
	END_CASE;
	
	
	iBasicParSlave.CyclicRead.TorqueMode			:=mpAXIS_READ_CYCLIC;
	//Reset Condition
	IF iCutCtrl.Cmd.Start= FALSE THEN
		iAxStep_enum 			:= enINITA;
		iJogLimState 			:= enCHECKVEL;
	END_IF
	
END_ACTION
