
PROGRAM _INIT
	(* Insert code here *)
	iBasicParameters.Acceleration:=10800;
	iBasicParameters.Deceleration:=108000;
	iBasicParameters.Jog.Deceleration:=108000;
	iBasicParameters.Jog.Acceleration:=108000;
	iBasicParameters.Jog.Velocity:=360;
	
		
	iVa_reg.EventSourceParID := ACP10PAR_STAT_TRIGGER1;
	iVa_RegCaptureAdvPara.Edge := ncP_EDGE;
	iVa_RegCaptureAdvPara.MinWidth := 50;
	iVa_RegCaptureAdvPara.MaxWidth := 200;
	iVa_RegCaptureAdvPara.WindowNeg := 200;
	iVa_RegCaptureAdvPara.WindowPos := 200;
	iVa_RegCaptureAdvPara.SensorDelay := 200;
	iVa_RegCaptureAdvPara.CorrectCurrentCycle := TRUE;
	iVa_RegCaptureAdvPara.CorrectionValueLimitNeg := 70;
	iVa_RegCaptureAdvPara.CorrectionValueLimitPos := 70;
	
	iVa_RegCaptureConfig.DistanceToSensor := 1050;
	iVa_RegCaptureConfig.ProductLength := 700;
	iVa_RegCaptureConfig.RegMarkPosition := 700;
	iVa_RegCaptureConfig.RegMarkOffset := 10;
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
		iFb_RegCapture();
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

