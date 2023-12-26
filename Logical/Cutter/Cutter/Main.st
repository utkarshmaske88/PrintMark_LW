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
(*| V1.00.0   19/12/2023	 Maskeu        added cam sequnce 									Complete		 |*)
(*| V2.00.0   21/12/2023	 Maskeu        added basic parameters for axis						Complete		 |*)
(*| V3.00.0   22/12/2023	 Maskeu        added reg capture parameters 						Complete		 |*)
PROGRAM _INIT
	
	//providing initial parameters
	iBasicParSlave.Acceleration:=10800;
	iBasicParSlave.Deceleration:=108000;
	iBasicParSlave.Jog.Deceleration:=108000;
	iBasicParSlave.Jog.Acceleration:=108000;
	iBasicParSlave.Jog.Velocity:=360;
	
	//assigning reg capture prameters
	iRegCapAdvPar.EventSourceParID := ACP10PAR_STAT_TRIGGER1;
	iRegCapAdvPar.Edge := ncP_EDGE;
	iRegCapAdvPar.MinWidth := 50;
	iRegCapAdvPar.MaxWidth := 200;
	iRegCapAdvPar.WindowNeg := 200;
	iRegCapAdvPar.WindowPos := 200;
	iRegCapAdvPar.SensorDelay := 200;
	iRegCapAdvPar.CorrectCurrentCycle := TRUE;
	iRegCapAdvPar.CorrectionValueLimitNeg := 70;
	iRegCapAdvPar.CorrectionValueLimitPos := 70;
	
	iRegCapConfig.DistanceToSensor := 1050; //distance betwwen ir sensor to cutter
	iRegCapConfig.ProductLength := 700;		//length of the product
	iRegCapConfig.RegMarkPosition := 700;	//reg par at positon 7c,
	iRegCapConfig.RegMarkOffset := 10;		//offset value 
	
END_PROGRAM

PROGRAM _CYCLIC
	IF iCutCtrl.Cmd.SingleCutter THEN
		//axis control  in single mode
		SingleCutter;
		// cam for single cutter
		CamSingle;
	ELSE
		//axis control  in dual mode
		MultCutter;
		// cam for Dual Cutter
		CamMulti;
	END_IF
	
	IF iFb_SlaveAx.Info.PLCopenState = mpAXIS_SYNCHRONIZED_MOTION THEN
		iFb_RegCap();
	END_IF
	
	//reg capturing action
	RegCap;

	
	
	//linking the slave to cam sequence
	iFb_CamSequ.MpLink :=ADR(gmlSlave);
	
	//parameters for cam seqeunce
	iFb_CamSequ.Parameters :=ADR(iAx_CamSequence);
	
	//linking the master with cam sequence
	iFb_CamSequ.MpLinkMaster :=ADR(gmlMaster);

	
	//fucniton block is callled
	iFb_CamSequ();
	
		
	IF (iMI_CutSetJogAcc <> (iBasicParSlave.Jog.Acceleration * PER_SEC)/PRODUCT_LENGTH 
		OR iMI_CutSetJogDeacc <> (iBasicParSlave.Jog.Deceleration  * PER_SEC)/PRODUCT_LENGTH 
		OR iMI_CutSetJogVel <> (iBasicParSlave.Jog.Velocity * PER_SEC)/PRODUCT_LENGTH) 
		AND NOT gMI_MODE THEN
		iFb_SlaveAx.Update := TRUE;
		IF iFb_SlaveAx.UpdateDone THEN
			iFb_SlaveAx.Update := FALSE;
		END_IF
	END_IF
	
	
	iBasicParSlave.Jog.Acceleration := (iMI_CutSetJogAcc * PRODUCT_LENGTH)/PER_SEC;
	iBasicParSlave.Jog.Deceleration := (iMI_CutSetJogDeacc * PRODUCT_LENGTH)/PER_SEC;
	iBasicParSlave.Jog.Velocity := (iMI_CutSetJogVel * PRODUCT_LENGTH)/PER_SEC;
	
	//iMI_CutActSpeed := (iFb_SlaveAx.Velocity * PER_SEC)/PRODUCT_LENGTH ;
END_PROGRAM

PROGRAM _EXIT
	
	//disabling all the functions
	iFb_SlaveAx.Enable:=FALSE;
	iFb_SlaveAx();
	iFb_CamSequ.Enable:=FALSE;
	iFb_CamSequ();
END_PROGRAM

