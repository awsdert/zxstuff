#include <zx/vli.h>

ZXCORE_EXP bool zxc_zxVLI_cmpEQ( zxVLI const *src, zxVLI const *val )
{
  return zxvli.isEqual( src, val, NULL );
}
#if ZXCPP
bool zxVli::operator==( zxVli val )
{
  return zxvli.isEqual( this, &val, NULL );
}
#endif