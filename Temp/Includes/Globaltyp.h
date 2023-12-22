/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1703245902_1_
#define _BUR_1703245902_1_

#include <bur/plctypes.h>

/* Datatypes and datatypes of function blocks */
typedef struct AxisCmd_typ
{	plcbit Start;
	plcbit Stop;
	plcbit PrintMark;
	plcbit ErrorReset;
	plcbit AutoMode;
	plcbit JogFwd;
	plcbit JogBack;
	plcbit Home;
	plcbit SingleCutter;
} AxisCmd_typ;

typedef struct AxisPara_typ
{	unsigned short Speed;
} AxisPara_typ;

typedef struct AxisStatus_typ
{	plcbit JogNegReady;
	plcbit JogPosReady;
} AxisStatus_typ;

typedef struct AxisCtrl_typ
{	struct AxisCmd_typ Cmd;
	struct AxisPara_typ Para;
	struct AxisStatus_typ Status;
} AxisCtrl_typ;






__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Global.typ\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1703245902_1_ */

