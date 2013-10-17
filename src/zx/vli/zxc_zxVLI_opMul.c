#include <zx/vli.h>
ZXCORE_EXP zxVLI* zxc_zxVLI_opMul( zxVLI *src, zxVLI const *val )
{
  size_t s = 0, pi = 0, I = 0;
  zxVLI des = zxvli.def, tmp = des;
  zxuc bit = zx_char_LastBit,
    *SRC = (zxuc*)src->m_vector.m_data,
    *VAL = (zxuc*)val->m_vector.m_data;
  if ( !src )
    return NULL;
  if ( !val )
  {
    memset( SRC, 0, src->m_vector.m_size );
    return src;
  }
  des.m_vector.m_data = mnew( src->m_vector.m_size, NULL );
  tmp.m_vector.m_data = malloc( src->m_vector.m_size );
  for (
    pi = src->m_bits, s = pi - 1, I = val->m_lastByte;
    s != pi; --s, --pi )
  {
    if ( VAL[ I ] & bit )
    {
      mcpy( tmp.m_vector.m_data, SRC, src->m_vector.m_size );
      zxvli.opAdd( &des, zxvli.opMvl( &tmp, s ) );
    }
    bit >>= 1;
    if ( !bit )
    {
      bit = zx_char_LastBit;
      --I;
    }
  }
  mcpy( SRC, des.m_vector.m_data, src->m_vector.m_size );
  free( des.m_vector.m_data );
  free( tmp.m_vector.m_data );
  return src;
}
ZXCORE_EXP zxVLI* zxc_zxVLI_cpyMul( zxVLI *dst, zxVLI const *src, zxVLI const *val )
{
  if ( dst )
  {
    zxvli.cpyEql( dst, src );
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