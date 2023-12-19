
PROGRAM _INIT
	(* Insert code here *)
	 
END_PROGRAM

PROGRAM _CYCLIC
	(* Insert code here *)
	//SingleCutter;
//	MultCutter;
	
		 
	iFb_AxisMater.MpLink :=ADR(gAxisMaster);
	iFb_AxisMater.Enable :=TRUE;
	iFb_AxisMater.Parameters :=ADR(iParamMaster);
	iFb_AxisMater.Axis :=ADR(gAxMaster);//gVAxis01
	iFb_AxisMater();
	
	iFb_AxisSlave.MpLink :=ADR(gAxisSlave);
	iFb_AxisSlave.Enable :=TRUE;
	iFb_AxisSlave.Parameters :=ADR(iParaSlave);
	iFb_AxisSlave.Axis :=ADR(gAxSlave);//gAxis01
	iFb_AxisSlave();
	
	CamSingle;
	
	iFb_CamSequ.MpLink :=ADR(gAxisSlave);
	iFb_CamSequ.Enable :=TRUE;
	iFb_CamSequ.Parameters :=ADR(iAx_CamSequence);
	iFb_CamSequ.MpLinkMaster :=ADR(gAxisMaster);
	iFb_CamSequ.StartSequence :=iFb_CamSequ.Info.MasterReady AND iFb_CamSequ.Info.SlaveReady;
	iFb_CamSequ();

END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	iFb_CamSequ.Enable:=FALSE;
	iFb_AxisSlave.Enable:=FALSE;
	iFb_AxisMater.Enable:=FALSE;
	iFb_AxisMater();
	iFb_AxisSlave();
	iFb_CamSequ();
	iFb_SlaveAx.Enable := 0;
	iFb_SlaveAx();
END_PROGRAM

