(*|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|*)
(*| Copyright      :-  B&R Industrial Automation GmbH															 |*)
(*| Contact Person :-  maskeu																					 |*)
(*|——————————————————————————————————————————————————————————————————————————————————————————————————————————————|*)
(*| System       :-  data recorder																				 |*)
(*| Task Name    :-  data control																		  		 |*)
(*| Auther Name  :-  maskeu																						 |*)
(*| Created Date :-  December 19, 2023 																		   	 |*)
(*| Task Class   :-  Task Class# 1                                                                 				 |*)
(*| Task Time    :-  Task Timing 2mSec                                                                           |*)
(*| OS Version   :-  G4.93                                                                                       |*)
(*| AS Version   :-  AS 4.12.4.107 SP                                                                            |*)
(*|——————————————————————————————————————————————————————————————————————————————————————————————————————————————|*)
(*| Description  :-  CUTTER cam sequnce and basic initial prameters		    									 |*)
(*| V1.00.0   23/12/2023	 Maskeu        added data recorder 									Complete		 |*)

PROGRAM _INIT
	
	 
END_PROGRAM

PROGRAM _CYCLIC
	
	//fucntion block for data recorder
	iFB_DataR.DeviceName 		:= ADR('USER');
	iFB_DataR.Enable 			:= TRUE;
	iFB_DataR.MpLink 			:= ADR(gDataRecorder);
	iFB_DataR.SamplingTime 		:= T#1s;
	iFB_DataR.Record 			:= TRUE;
	iFB_DataR.RecordMode		:= mpDATA_RECORD_MODE_VALUE;
	
	iFB_DataR();
	
	//data reg par parameters
	iFB_DataRegPar.Enable		:= TRUE;
	iFB_DataRegPar.MpLink 		:= ADR(gDataRecorder);
	iFB_DataRegPar.PVName 		:= ADR('AutoCtrl:iMI_AvgBagLen');
	iFB_DataRegPar();
	
END_PROGRAM

PROGRAM _EXIT
	//Diabling   fucniton block
	iFB_DataR.Enable := FALSE;
	iFB_DataRegPar.Enable := FALSE;
	iFB_DataR();
	iFB_DataRegPar();
END_PROGRAM

