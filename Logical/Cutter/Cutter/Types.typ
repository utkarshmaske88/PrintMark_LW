(*jog limiting enumeration*)

TYPE
	Joglim_enum : 
		( (*jog limit state enumeration*)
		enCHECKVEL, (*Checking value*)
		enADDVEL, (*gicing jog values*)
		enUPPERPOS, (*upper position state*)
		enLOWERPOS, (*lower position state*)
		enUPDATE, (*updating the state according position*)
		enRESET (*reseting the values*)
		);
END_TYPE

(*axis steps enumeration*)

TYPE
	AxStep_enum : 
		( (*axis enumeration*)
		enINITA, (*initiate*)
		enSTARTA, (*starting axis*)
		enNEEGHOMEMOVE, (*negative direction homing*)
		enPOWER_ONA, (*powering on*)
		enPOSHOMINGSEC, (*positive direction homing*)
		enPOSHOMING, (*positive side homing*)
		enNEGHOMING, (*negative side homing*)
		enHOMEA, (*homing state*)
		enOPERATIONA, (*operation state*)
		enERRORA, (*error state*)
		enMANUAL, (*manual mode is on*)
		enAUTOMATIC, (*automatic mode is on*)
		enJOGPOSITIVE, (*jog positive state*)
		enJOGNEGATIVE, (*jog backward state*)
		enCUTTINGZONE (*cutting zone*)
		);
END_TYPE
