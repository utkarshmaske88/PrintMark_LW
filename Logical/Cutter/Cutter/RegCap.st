
ACTION RegCap: 
	
	// assinging configuration for reg capture
	iFb_RegCap.Axis					:=ADR(gAxSlave);
	iFb_RegCap.Master				:=ADR(gAxMaster);
	iFb_RegCap.AdvancedParameters 	:= iRegCapAdvPar;
	iFb_RegCap.InitData				:=TRUE;
	iFb_RegCap.SearchRM				:=TRUE;
	iFb_RegCap.Configuration		:=iRegCapConfig;
	iFb_RegCap.CutPosition			:=REAL_TO_DINT(iRegCapConfig.ProductLength);
	iFb_RegCap.Enable				:=iFb_CamSequ.InSync;
	IF iFb_AxisSlave.Info.PLCopenState= mpAXIS_SYNCHRONIZED_MOTION THEN
		iFb_RegCap();
	END_IF;
END_ACTION
