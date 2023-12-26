#ifndef __AS__TYPE_
#define __AS__TYPE_
typedef struct {
	unsigned char bit0  : 1;
	unsigned char bit1  : 1;
	unsigned char bit2  : 1;
	unsigned char bit3  : 1;
	unsigned char bit4  : 1;
	unsigned char bit5  : 1;
	unsigned char bit6  : 1;
	unsigned char bit7  : 1;
} _1byte_bit_field_;

typedef struct {
	unsigned short bit0  : 1;
	unsigned short bit1  : 1;
	unsigned short bit2  : 1;
	unsigned short bit3  : 1;
	unsigned short bit4  : 1;
	unsigned short bit5  : 1;
	unsigned short bit6  : 1;
	unsigned short bit7  : 1;
	unsigned short bit8  : 1;
	unsigned short bit9  : 1;
	unsigned short bit10 : 1;
	unsigned short bit11 : 1;
	unsigned short bit12 : 1;
	unsigned short bit13 : 1;
	unsigned short bit14 : 1;
	unsigned short bit15 : 1;
} _2byte_bit_field_;

typedef struct {
	unsigned long bit0  : 1;
	unsigned long bit1  : 1;
	unsigned long bit2  : 1;
	unsigned long bit3  : 1;
	unsigned long bit4  : 1;
	unsigned long bit5  : 1;
	unsigned long bit6  : 1;
	unsigned long bit7  : 1;
	unsigned long bit8  : 1;
	unsigned long bit9  : 1;
	unsigned long bit10 : 1;
	unsigned long bit11 : 1;
	unsigned long bit12 : 1;
	unsigned long bit13 : 1;
	unsigned long bit14 : 1;
	unsigned long bit15 : 1;
	unsigned long bit16 : 1;
	unsigned long bit17 : 1;
	unsigned long bit18 : 1;
	unsigned long bit19 : 1;
	unsigned long bit20 : 1;
	unsigned long bit21 : 1;
	unsigned long bit22 : 1;
	unsigned long bit23 : 1;
	unsigned long bit24 : 1;
	unsigned long bit25 : 1;
	unsigned long bit26 : 1;
	unsigned long bit27 : 1;
	unsigned long bit28 : 1;
	unsigned long bit29 : 1;
	unsigned long bit30 : 1;
	unsigned long bit31 : 1;
} _4byte_bit_field_;
#endif

_BUR_PUBLIC unsigned short ERRxfatal(unsigned short errornr, unsigned long errorinfo, unsigned long errorstring);
_BUR_PUBLIC unsigned short ST_name(unsigned long st_ident, unsigned long st_name_p, unsigned long st_grp);
_BUR_PUBLIC signed char CheckDivSint(signed char divisor);
_BUR_PUBLIC unsigned char CheckDivUsint(unsigned char divisor);
_BUR_PUBLIC signed short CheckDivInt(signed short divisor);
_BUR_PUBLIC unsigned short CheckDivUint(unsigned short divisor);
_BUR_PUBLIC signed long CheckDivDint(signed long divisor);
_BUR_PUBLIC unsigned long CheckDivUdint(unsigned long divisor);
_BUR_PUBLIC float CheckDivReal(float divisor);
_BUR_PUBLIC double CheckDivLReal(double divisor);
_BUR_PUBLIC signed long CheckBounds(signed long index, signed long lower, signed long upper);
_BUR_PUBLIC signed long CheckRange(signed long value, signed long lower, signed long upper);
_BUR_PUBLIC signed long CheckSignedSubrange(signed long value, signed long lower, signed long upper);
_BUR_PUBLIC unsigned long CheckUnsignedSubrange(unsigned long value, unsigned long lower, unsigned long upper);
_BUR_PUBLIC unsigned long CheckReadAccess(unsigned long address);
_BUR_PUBLIC unsigned long CheckWriteAccess(unsigned long address);
_BUR_PUBLIC unsigned long MakeEntry(unsigned short number, signed long index, plcstring text[51]);
_BUR_PUBLIC unsigned long brsstrcat(unsigned long pDest, unsigned long pSrc);
_BUR_PUBLIC unsigned long brsstrcpy(unsigned long pDest, unsigned long pSrc);
