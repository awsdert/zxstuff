#include <zx/vli.h>
ZXVLI_OPMUL
{
  size_t s = 0, pi = 0, I = 0, stop = zxvli.size( src );
  zxVLI des = zxvli.def, tmp = des;
  zxuc bit = zx_char_LastBit, *SRC, *VAL;
  if ( !src )
    return NULL;
  SRC = src->m_data;
  if ( !val )
  {
    memset( SRC, 0, stop );
    return src;
  }
  VAL = val->m_data;
  zxvli.grow( &des, stop );
  zxvli.grow( &tmp, stop );
  for (
    pi = src->m_bits, s = pi - 1, I = val->m_lastByte;
    s != pi; --s, --pi )
  {
    if ( VAL[ I ] & bit )
    {
      mcpy( tmp.m_data, SRC, stop );
      zxvli.opAdd( &des, zxvli.opMvl( &tmp, s ) );
    }
    bit >>= 1;
    if ( !bit )
    {
      bit = zx_char_LastBit;
      --I;
    }
  }
  mcpy( SRC, des.m_data, stop );
  free( des.m_data );
  free( tmp.m_data );
  return src;
}
ZXVLI_CPYMUL
{
  if ( dst )
  {
    zxvli.opEql( dst, src );
    zxvli.opMul( dst, val );
  }
  return dst;
}
#if ZXCPP
zxVli  zxVli::operator*( zxVli val )
{
  zxVli cpy = *this;
  zxvli.opMul( &cpy, &val );
  return cpy;
}
zxVli& zxVli::operator*=( zxVli val )
{
  zxvli.opMul( this, &val );
  return *this;
}
#endif
