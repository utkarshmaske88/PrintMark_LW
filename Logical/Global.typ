
TYPE
	AxisCtrl_typ : 	STRUCT  (*Axis Ctrl Struture*)
		Cmd : AxisCmd_typ; (*Axis Ctrl CMd type*)
		Para : AxisPara_typ; (*Axis para type*)
		Status : AxisStatus_typ; (*Axis Status Type*)
	END_STRUCT;
	AxisCmd_typ : 	STRUCT  (*Axis Ctrl CMd type*)
		Start : BOOL; (*Start Cmd*)
		Stop : BOOL; (*Stop cmd*)
		PrintMark : BOOL; (*Print mark detection bit*)
		ErrorReset : BOOL; (*Error reset*)
		AutoMode : BOOL; (*AutoMode*)
		JogFwd : BOOL; (*Jog fwd cmd*)
		JogBack : BOOL; (*jog BAck cmd*)
		Home : BOOL; (*home Cmd*)
		SingleCutter : BOOL;
	END_STRUCT;
	AxisPara_typ : 	STRUCT  (*Axis para type*)
		Speed : UINT; (*Axis Speed*)
	END_STRUCT;
	AxisStatus_typ : 	STRUCT  (*Axis Status*)
		JogNegReady : BOOL; (*Axis jog neg ready status*)
		JogPosReady : BOOL; (*axis jog pos ready Statsus*)
	END_STRUCT;
END_TYPE
