
ACTION CamMulti: 
	iAx_CamSequence.Configuration.Master := ADR(gAxMaster); // refrencing axis 
	iAx_CamSequence.Configuration.MasterParID := ACP10PAR_PCTRL_S_ACT; //412 parid -
	(** STATE 0 - Event 1 - WAIT FOR TRIGGER **) 
	
	iAx_CamSequence.Configuration.State[0].Event[0].Type :=ncST_END ; //Trigger 
	iAx_CamSequence.Configuration.State[0].Event[0].Attribute := ncAT_ONCE; //Reaction
	iAx_CamSequence.Configuration.State[0].Event[0].NextState := 4; //Next State
	
	
	
//	(** STATE 4 - Event 4 - WAIT FOR TRIGGER **) 
//	iAx_CamSequence.Configuration.State[4].CamProfileIndex := 16#FFFE; 
//	iAx_CamSequence.Configuration.State[4].MasterFactor := 300 ; //Master Dist. 
//	iAx_CamSequence.Configuration.State[4].SlaveFactor := -400; //Slave Dist. 
//	
//	iAx_CamSequence.Configuration.State[4].CompMode := ncONLYCOMP; 
//	iAx_CamSequence.Configuration.State[4].MasterCompDistance := 900; //Master Dist. 
//	iAx_CamSequence.Configuration.State[4].SlaveCompDistance :=  -700; //Slave Dist. 
//	
//	iAx_CamSequence.Configuration.State[4].Event[0].Type := ncST_END; //Trigger 
//	iAx_CamSequence.Configuration.State[4].Event[0].Attribute := ncST_END; //Reaction
//	iAx_CamSequence.Configuration.State[4].Event[0].NextState := 5; //Next State 	
//	
//		
//	(** STATE 5 - Event 5 - WAIT FOR TRIGGER **) 
//	iAx_CamSequence.Configuration.State[5].CamProfileIndex := 16#FFFF; 
//	iAx_CamSequence.Configuration.State[5].MasterFactor := 300 ; //Master Dist. 
//	iAx_CamSequence.Configuration.State[5].SlaveFactor := -400; //Slave Dist. 
//	
//	iAx_CamSequence.Configuration.State[5].Event[0].Type := ncST_END; //Trigger 
//	iAx_CamSequence.Configuration.State[5].Event[0].Attribute := ncST_END; //Reaction
//	iAx_CamSequence.Configuration.State[5].Event[0].NextState := 6; //Next State 	
//		
//	(** STATE 6 - Event 6 - WAIT FOR TRIGGER **) 
//	iAx_CamSequence.Configuration.State[6].CamProfileIndex := 16#FFFE; 
//	iAx_CamSequence.Configuration.State[6].MasterFactor := 300 ; //Master Dist. 
//	iAx_CamSequence.Configuration.State[6].SlaveFactor := -400; //Slave Dist. 
//	
//	iAx_CamSequence.Configuration.State[6].CompMode := ncONLYCOMP; 
//	iAx_CamSequence.Configuration.State[6].MasterCompDistance := 300; //Master Dist. 
//	iAx_CamSequence.Configuration.State[6].SlaveCompDistance :=  -1400; //Slave Dist. 
//	
//	iAx_CamSequence.Configuration.State[6].Event[0].Type := ncST_END; //Trigger 
//	iAx_CamSequence.Configuration.State[6].Event[0].Attribute := ncST_END; //Reaction
//	iAx_CamSequence.Configuration.State[6].Event[0].NextState := 5; //Next State 	
//	
//	
	
		
	(** STATE 2 - Event 2 - WAIT FOR TRIGGER **) 
	iAx_CamSequence.Configuration.State[2].CamProfileIndex := 16#FFFF; 
	iAx_CamSequence.Configuration.State[2].MasterFactor := 300 ; //Master Dist. 
	iAx_CamSequence.Configuration.State[2].SlaveFactor := -400; //Slave Dist. 
	
	iAx_CamSequence.Configuration.State[2].Event[0].Type := ncST_END; //Trigger 
	iAx_CamSequence.Configuration.State[2].Event[0].Attribute := ncST_END; //Reaction
	iAx_CamSequence.Configuration.State[2].Event[0].NextState := 1; //Next State
		
	(** STATE 1 - Event 1 - WAIT FOR TRIGGER **) 
	iAx_CamSequence.Configuration.State[1].CamProfileIndex := 16#FFFE; 
	iAx_CamSequence.Configuration.State[1].MasterFactor := 300 ; //Master Dist. 
	iAx_CamSequence.Configuration.State[1].SlaveFactor := -400; //Slave Dist. 
	
	iAx_CamSequence.Configuration.State[1].CompMode := ncONLYCOMP; 
	iAx_CamSequence.Configuration.State[1].MasterCompDistance := 400; //Master Dist. 
	iAx_CamSequence.Configuration.State[1].SlaveCompDistance :=  -1400; //Slave Dist. 
	
	iAx_CamSequence.Configuration.State[1].Event[0].Type := ncST_END; //Trigger 
	iAx_CamSequence.Configuration.State[1].Event[0].Attribute := ncST_END; //Reaction
	iAx_CamSequence.Configuration.State[1].Event[0].NextState := 2; //Next State 	
	 
	
	
	
	
	
	
	
	
		
	
	(** STATE 4 - Event 4 - WAIT FOR TRIGGER **) 
	iAx_CamSequence.Configuration.State[4].CamProfileIndex := 16#FFFE; 
	iAx_CamSequence.Configuration.State[4].MasterFactor := 300 ; //Master Dist. 
	iAx_CamSequence.Configuration.State[4].SlaveFactor := -400; //Slave Dist. 
	
	iAx_CamSequence.Configuration.State[4].CompMode := ncONLYCOMP; 
	iAx_CamSequence.Configuration.State[4].MasterCompDistance := 150; //Master Dist. 
	iAx_CamSequence.Configuration.State[4].SlaveCompDistance :=  -680; //Slave Dist. 
	
	iAx_CamSequence.Configuration.State[4].Event[0].Type := ncST_END; //Trigger 
	iAx_CamSequence.Configuration.State[4].Event[0].Attribute := ncST_END; //Reaction
	iAx_CamSequence.Configuration.State[4].Event[0].NextState := 5; //Next State 	
	
		
	(** STATE 5 - Event 5 - WAIT FOR TRIGGER **) 
	iAx_CamSequence.Configuration.State[5].CamProfileIndex := 16#FFFF; 
	iAx_CamSequence.Configuration.State[5].MasterFactor := 400 ; //Master Dist. 
	iAx_CamSequence.Configuration.State[5].SlaveFactor := -420; //Slave Dist. 
	
	iAx_CamSequence.Configuration.State[5].Event[0].Type := ncST_END; //Trigger 
	iAx_CamSequence.Configuration.State[5].Event[0].Attribute := ncST_END; //Reaction
	iAx_CamSequence.Configuration.State[5].Event[0].NextState := 6; //Next State 	
		
	(** STATE 6 - Event 6 - WAIT FOR TRIGGER **) 
	iAx_CamSequence.Configuration.State[6].CamProfileIndex := 16#FFFE; 
	iAx_CamSequence.Configuration.State[6].MasterFactor := 300 ; //Master Dist. 
	iAx_CamSequence.Configuration.State[6].SlaveFactor := -400; //Slave Dist. 
	
	iAx_CamSequence.Configuration.State[6].CompMode := ncONLYCOMP; 
	iAx_CamSequence.Configuration.State[6].MasterCompDistance := 300; //Master Dist. 
	iAx_CamSequence.Configuration.State[6].SlaveCompDistance :=  -1330; //Slave Dist. 
	
	iAx_CamSequence.Configuration.State[6].Event[0].Type := ncST_END; //Trigger 
	iAx_CamSequence.Configuration.State[6].Event[0].Attribute := ncST_END; //Reaction
	iAx_CamSequence.Configuration.State[6].Event[0].NextState := 2; //Next State 	
END_ACTION
