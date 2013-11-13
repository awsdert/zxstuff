#include <zx/vli.h>
ZXCORE bool zxVLI_cmpNE( zxVLI const *src, zxVLI const *val )
{
  return !zxvli.isEqual( src, val, NULL );
}
#if ZXCPP
bool zxVli::operator!( void )
{
  return !zxvli.isEqual( this, NULL, NULL );
}
bool zxVli::operator!=( zxVli val )
{
  return !zxvli.isEqual( this, &val, NULL );
}
#endif
