/* USER: AWSDERT; DATE: 09/11/2013; TIME: 07:58 */
#include <zx/vli.h>
ZXV_RESERVE( zxVLI, ZXCORE, ZXCORE_CALL )
{
  zxvli.grow( src, minSize );
}
ZXCORE void zxVLI_reserveb( zxVLI *src, size_t minBits )
{
  zxvli.growb( src, minBits );
}
