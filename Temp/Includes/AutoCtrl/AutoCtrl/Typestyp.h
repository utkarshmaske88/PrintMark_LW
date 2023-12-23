/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1703356586_7_
#define _BUR_1703356586_7_

#include <bur/plctypes.h>

/* Datatypes and datatypes of function blocks */
typedef enum Reset_enum
{	enRESETONE,
	enRESETTWO,
	enEXIT
} Reset_enum;

typedef enum AutoCtrl_enum
{	enWAIT,
	enMODE,
	enHOMING,
	enMANUAL,
	enAUTO,
	enSTOP,
	enMAN_JOGFWD,
	enMAN_JOGBWD,
	enCUT_ZONE,
	enCUT_DISABLED,
	enCUT_DISABLE_HOME
} AutoCtrl_enum;

typedef struct AutoCmd_typ
{	plcbit Start;
	plcbit Stop;
	plcbit AutoMode;
	plcbit ChangeMode;
	plcbit DisableCutter;
	plcbit SingleCutter;
	plcbit Reset;
} AutoCmd_typ;

typedef struct AutoPara_typ
{	float ConvSpeed;
	float ConvJogSpeed;
	float CutterJogSpeed;
} AutoPara_typ;

typedef struct AutoManCmd_typ
{	plcbit ConvPowerON;
	plcbit CutterPowerON;
} AutoManCmd_typ;

typedef struct AutoCtrl_typ
{	struct AutoCmd_typ Cmd;
	struct AutoPara_typ Para;
	struct AutoManCmd_typ ManualCmd;
} AutoCtrl_typ;






__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/AutoCtrl/AutoCtrl/Types.typ\\\" scope \\\"local\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1703356586_7_ */

