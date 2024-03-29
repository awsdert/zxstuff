#include <zx/vli.h>
/* operator-= */
ZXVLI_OPSUB
{
  zxuc add1_val = 1u;
  zxVLI  add1 = zxvli.def;
  if ( !src || val )
    return src;
  zxv.grow( &add1.m_core, 1, &add1_val );
  add1.m_bits = 1;
  zxvli.opNot( src );
  zxvli.opAdd( src, &add1 );
  /*
    on growable binary this would end up with a leading bit
    but since our buffers are never grown here the leading bit
    cannot be reached which gives us the correct result instead
  */
  zxvli.opAdd( src, val );
  return src;
}
ZXVLI_CPYSUB
{
  if ( dst )
  {
    zxvli.opEql( dst, src );
    zxvli.opSub( dst, val );
  }
  return dst;
}
#if ZXCPP
zxVli& zxVli::operator--( void )
{
  zxVlu val = 1;
  val.m_bits = 1u;
  zxvli.opSub( this, &val );
  return *this;
}
zxVli  zxVli::operator--( int ignored )
{
  zxVli cpy = *this;
  zxVlu val = 1;
  val.m_bits = 1u;
  zxvli.opSub( &cpy, &val );
  return cpy;
}
zxVli  zxVli::operator-( zxVli val )
{
  zxVli cpy = *this;
  zxvli.opSub( &cpy, &val );
  return cpy;
}
zxVli& zxVli::operator-=( zxVli val )
{
  zxvli.opSub( this, &val );
  return *this;
}
#endif
