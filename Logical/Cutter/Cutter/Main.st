
PROGRAM _INIT
	(* Insert code here *)
	iBasicParSlave.Acceleration:=10800;
	iBasicParSlave.Deceleration:=108000;
	iBasicParSlave.Jog.Deceleration:=108000;
	iBasicParSlave.Jog.Acceleration:=108000;
	iBasicParSlave.Jog.Velocity:=360;
	
		
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
	
	iRegCapConfig.DistanceToSensor := 1050;
	iRegCapConfig.ProductLength := 700;
	iRegCapConfig.RegMarkPosition := 700;
	iRegCapConfig.RegMarkOffset := 10;
END_PROGRAM

PROGRAM _CYCLIC
	(* Insert code here *)
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
	iFb_CamSequ.Enable :=TRUE;
	
	//parameters for cam seqeunce
	iFb_CamSequ.Parameters :=ADR(iAx_CamSequence);
	
	//linking the master with cam sequence
	iFb_CamSequ.MpLinkMaster :=ADR(gmlMaster);
	iFb_CamSequ.StartSequence :=iFb_CamSequ.Info.MasterReady AND iFb_CamSequ.Info.SlaveReady;
	
	//fucniton block is callled
	iFb_CamSequ();
	
	
END_PROGRAM

PROGRAM _EXIT
	
	//disabling all the functions
	iFb_AxisSlave.Enable:=FALSE;
	iFb_AxisSlave();
	iFb_CamSequ.Enable:=FALSE;
	iFb_CamSequ();
END_PROGRAM

