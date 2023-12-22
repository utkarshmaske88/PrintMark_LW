
TYPE
	Reset_enum : 
		(
		enRESETONE,
		enRESETTWO,
		enEXIT
		);
	AutoCmd_typ : 	STRUCT  (*Auto Ctrl Command Type*)
		Start : BOOL; (*Start cmd*)
		Stop : BOOL; (*Stop cmd*)
		AutoMode : BOOL; (*Auto Mode cmd*)
		ChangeMode : BOOL; (*Change Mode cmd*)
		DisableCutter : BOOL; (*Disable Cutter cmd*)
		SingleCutter : BOOL; (*Single or Dual Cutter bit*)
		Reset : BOOL; (*Reset Complete Machine*)
	END_STRUCT;
	AutoPara_typ : 	STRUCT  (*Auto Ctrl Para Type*)
		ConvSpeed : REAL; (*Conv speed Para*)
		ConvJogSpeed : REAL; (*Conv Jog SPeed*)
		CutterJogSpeed : REAL; (*Cutter Jog Speed*)
	END_STRUCT;
	AutoManCmd_typ : 	STRUCT  (*Auto Ctrl Manaual Cmd Type*)
		ConvPowerON : BOOL; (*Conv power on*)
		CutterPowerON : BOOL; (*Cutter Power On*)
	END_STRUCT;
	AutoCtrl_typ : 	STRUCT  (*Auto Ctrl Type*)
		Cmd : AutoCmd_typ; (*Auto Ctrl cmd type*)
		Para : AutoPara_typ; (*Auto Ctrl Para type*)
		ManualCmd : AutoManCmd_typ; (*Auto Ctrl Manual Cmd Type*)
	END_STRUCT;
	AutoCtrl_enum : 
		( (*Auto Ctrl State*)
		enWAIT, (*Wait state*)
		enMODE, (*Mode Select state*)
		enHOMING, (*homing State*)
		enMANUAL, (*Manual Mode*)
		enAUTO, (*Auto mode state*)
		enSTOP, (*Stop state*)
		enMAN_JOGFWD, (*Manual jog f State*)
		enMAN_JOGBWD, (*Manual jog N State*)
		enCUT_ZONE, (*Cutting zone state*)
		enCUT_DISABLED, (*Cutter Disabled STate*)
		enCUT_DISABLE_HOME (*Cutter Homing after disable*)
		);
END_TYPE
