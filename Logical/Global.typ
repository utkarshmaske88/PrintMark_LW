(*main control*)

TYPE
	AxisCtrl_typ : 	STRUCT  (*Axis Ctrl Struture*)
		Cmd : AxisCmd_typ; (*Axis Ctrl CMd type*)
		Para : AxisPara_typ; (*Axis para type*)
		Status : AxisStatus_typ; (*Axis Status Type*)
	END_STRUCT;
END_TYPE

(*commands*)

TYPE
	AxisCmd_typ : 	STRUCT  (*Axis Ctrl CMd type*)
		Start : BOOL; (*Start Cmd*)
		Stop : BOOL; (*Stop cmd*)
		PrintMark : BOOL; (*Print mark detection bit*)
		ErrorReset : BOOL; (*Error reset*)
		AutoMode : BOOL; (*AutoMode*)
		JogFwd : BOOL; (*Jog forward command*)
		JogBack : BOOL; (*jog BAckward c0mmand*)
		Home : BOOL; (*home Cmd*)
		SingleCutter : BOOL;
	END_STRUCT;
END_TYPE

(*parameters*)

TYPE
	AxisPara_typ : 	STRUCT  (*Axis para type*)
		Speed : UINT; (*Axis Speed*)
	END_STRUCT;
END_TYPE

(*status*)

TYPE
	AxisStatus_typ : 	STRUCT  (*Axis Status*)
		JogNegReady : BOOL; (*Axis jog neg ready status*)
		JogPosReady : BOOL; (*axis jog pos ready Statsus*)
	END_STRUCT;
END_TYPE
