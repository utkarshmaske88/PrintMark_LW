/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1703160187_4_
#define _BUR_1703160187_4_

#include <bur/plctypes.h>

/* Datatypes and datatypes of function blocks */
typedef enum AxStep_enum
{	enINITA,
	enSTARTA,
	enNEEGHOMEMOVE,
	enPOWER_ONA,
	enPOSHOMINGSEC,
	enPOSHOMING,
	enNEGHOMING,
	enHOMEA,
	enOPERATIONA,
	enERRORA,
	enMANUAL,
	enAUTOMATIC,
	enJOGPOSITIVE,
	enJOGNEGATIVE,
	enCUTTINGZONE
} AxStep_enum;

typedef enum Joglim_enum
{	enCHECKVEL,
	enADDVEL,
	enUPPERPOS,
	enLOWERPOS,
	enUPDATE,
	enRESET
} Joglim_enum;






__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Cutter/Cutter/Types.typ\\\" scope \\\"local\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1703160187_4_ */

