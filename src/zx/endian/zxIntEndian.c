#include <zx/endian.h>
ZXCORE_EXP zxEndian zxIntEndian( void )
{
	static zxul dword = 0x12345678;
	static zxuc *byte = (zxuc*)&dword;
	switch ( byte[0] )
	{
		case 0x12: return zxENDIAN_BIG;
		case 0x78: return zxENDIAN_LITTLE;
		default:   return zxENDIAN_PDP;
	}
}
