(*|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|*)
(*| Copyright      :-  B&R Industrial Automation GmbH															 |*)
(*| Contact Person :-  maskeu																					 |*)
(*|——————————————————————————————————————————————————————————————————————————————————————————————————————————————|*)
(*| System       :-  alarms Control  	                                                                         |*)
(*| Task Name    :-  alarms Control                                                                    	         |*)
(*| Auther Name  :-  maskeu																						 |*)
(*| Created Date :-  October 10, 2023 																		   	 |*)
(*| Task Class   :-  Task Class #1                                                                               |*)
(*| Task Time    :-  Task Timing 10mSec                                                                          |*)
(*| OS Version   :-  G 4.93	                                                                                     |*)
(*| AS Version   :-  AS 4.12.4.107 SP                                                                            |*)
(*|——————————————————————————————————————————————————————————————————————————————————————————————————————————————|*)
(*| Description  :-  alarms Control                                                            					 |*)
(*|                                                                                                              |*)
(*|——————————————————————————————————————————————————————————————————————————————————————————————————————————————|*)
(*| History (Task Modification):                                                                                 |*)
(*|                                                                                                              |*)
(*| V1.00.0   23/12/2023    maskeu        added alarms fucntion block	                       compelete	     |*)

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
	
	
	iFb_AlarmUI.Enable:=TRUE;
	iFb_AlarmUI.MpLink:=ADR(gAlarmXCore);
	iFb_AlarmUI.UIConnect:=ADR(iUIConnectCore);
END_PROGRAM

PROGRAM _EXIT
	//Disabling the function block
	iFb_AlarmX.Enable:=FALSE;
	iFb_AlarmX();
END_PROGRAM

