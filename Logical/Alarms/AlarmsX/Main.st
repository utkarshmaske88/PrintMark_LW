(*|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|*)
(*| Copyright      :-  B&R Industrial Automation GmbH															 |*)
(*| Contact Person :-  maskeu																					 |*)
(*|——————————————————————————————————————————————————————————————————————————————————————————————————————————————|*)
(*| System       :-  TODO: Sewing Machine                                                                        |*)
(*| Task Name    :-  TODO: Dosctrl                                                                   	         |*)
(*| Auther Name  :-  maskeu																						 |*)
(*| Created Date :-  October 10, 2023 																		   	 |*)
(*| Task Class   :-  Task Class #1                                                                               |*)
(*| Task Time    :-  Task Timing 10mSec                                                                          |*)
(*| OS Version   :-  V0.00.0                                                                                     |*)
(*| AS Version   :-  AS 4.12.4.107                                                                               |*)
(*|——————————————————————————————————————————————————————————————————————————————————————————————————————————————|*)
(*| Description  :-  Dosing Control                                                            |*)
(*|                                                                                                              |*)
(*|——————————————————————————————————————————————————————————————————————————————————————————————————————————————|*)
(*| History (Task Modification):                                                                                 |*)
(*|                                                                                                              |*)
(*| Version      Date       Modified By      Modification                                             Status     |*)
(*| V1.00.0   10/10/2023    maskeu        TODO: Insert Modification Done                       Update Status     |*)
(*|______________________________________________________________________________________________________________|*)

PROGRAM _INIT
	
	//if any errors then will be removed
	iFb_AlarmX.ErrorReset:=TRUE;
	iFb_AlarmX();
END_PROGRAM

PROGRAM _CYCLIC
	
	// alarmx on
	iFb_AlarmX.Enable:=TRUE;
	iFb_AlarmX.MpLink:=ADR(gAlarmXCore);

	iFb_AlarmX();
	
	
END_PROGRAM

PROGRAM _EXIT
	//Disabling the function block
	iFb_AlarmX.Enable:=FALSE;
	iFb_AlarmX();
END_PROGRAM

