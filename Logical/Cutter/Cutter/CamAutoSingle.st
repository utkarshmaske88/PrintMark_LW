(*|ｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯｯ|*)
(*| Copyright      :-  B&R Industrial Automation GmbH															 |*)
(*| Contact Person :-  maskeu																					 |*)
(*|覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧|*)
(*| System       :-  TODO: Printmark                                                                             |*)
(*| Task Name    :-  TODO: CAMAuto                                                                   	         |*)
(*| Auther Name  :-  maskeu																						 |*)
(*| Created Date :-  October 10, 2023 																		   	 |*)
(*| Task Class   :-  Task Class# Task Class No                                                                   |*)
(*| Task Time    :-  Task Timing mSec                                                                            |*)
(*| OS Version   :-  V G.9.43                                                                                    |*)
(*| AS Version   :-  AS 4.12.4.107 SPXY                                                                          |*)
(*|覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧|*)
(*| Description  :-  TODO: Description about task                                                                |*)
(*|                                                                                                              |*)
(*|覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧|*)
(*| History (Task Modification):                                                                                 |*)
(*|                                                                                                              |*)
(*| Version      Date       Modified By      Modification                                          Status     	 |*)
(*| V1.00.0   21/12/2023	 Maskeu        written all cam auto			                      	   Complete		 |*)
(*|______________________________________________________________________________________________________________|*)
ACTION CamSingle: 
	iAx_CamSequence.Configuration.Master := ADR(gAxMaster); // Not Mplink Axis Address 
	iAx_CamSequence.Configuration.MasterParID := ACP10PAR_PCTRL_S_ACT; //412 parid -
	
	(** STATE 0 - Event 1 - WAIT FOR TRIGGER **) 
	
	iAx_CamSequence.Configuration.State[0].Event[0].Type :=ncTRIGGER1; //Trigger 
	iAx_CamSequence.Configuration.State[0].Event[0].Attribute := ncAT_ONCE; //Reaction
	iAx_CamSequence.Configuration.State[0].Event[0].NextState := 4; //Next State

	
	(** STATE 4 - Event 4 - for first print mark**) 
	iAx_CamSequence.Configuration.State[4].CamProfileIndex := 16#FFFE; 
	iAx_CamSequence.Configuration.State[4].MasterFactor := 300 ; //Master Dist. 
	iAx_CamSequence.Configuration.State[4].SlaveFactor := -400; //Slave Dist. 
	
	iAx_CamSequence.Configuration.State[4].CompMode := ncONLYCOMP; 
	iAx_CamSequence.Configuration.State[4].MasterCompDistance := 900; //Master Dist. 
	iAx_CamSequence.Configuration.State[4].SlaveCompDistance :=  -1500; //Slave Dist. 
	
	iAx_CamSequence.Configuration.State[4].Event[0].Type := ncST_END; //Trigger 
	iAx_CamSequence.Configuration.State[4].Event[0].Attribute := ncST_END; //Reaction
	iAx_CamSequence.Configuration.State[4].Event[0].NextState := 5; //Next State 	
	
	(** STATE 5 - Event 5 - for first printmark linear motion**) 
	iAx_CamSequence.Configuration.State[5].CamProfileIndex := 16#FFFF; 
	iAx_CamSequence.Configuration.State[5].MasterFactor := 300 ; //Master Dist. 
	iAx_CamSequence.Configuration.State[5].SlaveFactor := -400; //Slave Dist. 
	
	iAx_CamSequence.Configuration.State[5].Event[0].Type := ncST_END; //Trigger 
	iAx_CamSequence.Configuration.State[5].Event[0].Attribute := ncST_END; //Reaction
	iAx_CamSequence.Configuration.State[5].Event[0].NextState := 6; //Next State 
	
	
	(** STATE 6 - Event 6 - for next cutting non linear motion**) 
	iAx_CamSequence.Configuration.State[6].CamProfileIndex := 16#FFFE; 
	iAx_CamSequence.Configuration.State[6].MasterFactor := 300 ; //Master Dist. 
	iAx_CamSequence.Configuration.State[6].SlaveFactor := -400; //Slave Dist. 
	
	iAx_CamSequence.Configuration.State[6].CompMode := ncONLYCOMP; 
	iAx_CamSequence.Configuration.State[6].MasterCompDistance := 400; //Master Dist. 
	iAx_CamSequence.Configuration.State[6].SlaveCompDistance :=  -3200; //Slave Dist. 
	
	iAx_CamSequence.Configuration.State[6].Event[0].Type := ncST_END; //Trigger 
	iAx_CamSequence.Configuration.State[6].Event[0].Attribute := ncST_END; //Reaction
	iAx_CamSequence.Configuration.State[6].Event[0].NextState := 2; //Next State 
	
	
	iAx_CamSequence.Configuration.State[1].CamProfileIndex := 16#FFFE; 
	iAx_CamSequence.Configuration.State[1].MasterFactor := 300 ; //Master Dist. 
	iAx_CamSequence.Configuration.State[1].SlaveFactor := -400; //Slave Dist. 
	
	iAx_CamSequence.Configuration.State[1].CompMode := ncONLYCOMP; 
	iAx_CamSequence.Configuration.State[1].MasterCompDistance := 400; //Master Dist. 
	iAx_CamSequence.Configuration.State[1].SlaveCompDistance := -3200; //Slave Dist. 
	
	iAx_CamSequence.Configuration.State[1].Event[0].Type := ncST_END; //Trigger 
	iAx_CamSequence.Configuration.State[1].Event[0].Attribute := ncST_END; //Reaction
	iAx_CamSequence.Configuration.State[1].Event[0].NextState := 2; //Next State
	
	
	//Sync Motion of cutter and conv
	iAx_CamSequence.Configuration.State[2].CamProfileIndex := 16#FFFF; 
	iAx_CamSequence.Configuration.State[2].MasterFactor := 300; //Master Dist. 
	iAx_CamSequence.Configuration.State[2].SlaveFactor := -400; //Slave Dist. 
	
	iAx_CamSequence.Configuration.State[2].Event[0].Type := ncST_END; //Trigger 
	iAx_CamSequence.Configuration.State[2].Event[0].Attribute := ncST_END; //Reaction
	iAx_CamSequence.Configuration.State[2].Event[0].NextState := 1; //Next State
	
END_ACTION
