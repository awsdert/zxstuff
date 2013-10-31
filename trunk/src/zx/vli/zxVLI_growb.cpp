#include <zx/vli.h>
ZXCORE_EXP void zxVLI_growb( zxVLI* src, size_t setBits )
{
  zxuc   def = 0u, last = zxvli.isNeg( src );
  size_t size, bits = 0u;
  ZXASSERT( !src ) return;
  if ( setBits <= src->m_bits )
    return;
  if ( last )
    def = UCHAR_MAX;
  size = zxc_size_udiv( setBits, CHAR_BIT, &bits );
  if ( bits )
    ++size;
  zxv.grow( &src->m_core, size, &def );
  src->m_bits      = setBits;
  src->m_lastByte  = size - 1;
  if ( bits )
    src->m_lastBit = 1u << (--bits);
  else
    src->m_lastBit = zxuc_last;
}
ZXCORE_EXP void zxVLI_shrinkb( zxVLI *src, size_t setBits )
{
  size_t size, bits = 0u;
  ZXASSERT( !src ) return;
  if ( setBits >= src->m_bits )
    return;
  size = zxc_size_udiv( setBits, CHAR_BIT, &bits );
  if ( bits )
    ++size;
  zxv.shrink( &src->m_core, size );
  src->m_bits     = setBits;
  src->m_lastByte = size - 1;
  if ( bits )
    src->m_lastBit = 1u << (--bits);
  else
    src->m_lastBit = zxuc_last;
}

ZXCORE_EXP void zxVLI_resizeb( zxVLI *src, size_t setBits )
{
  ZXASSERT( !src ) return;
  if ( setBits >= src->m_bits )
    zxvli.growb( src, setBits );
  else
    zxvli.eraseb( src, src->m_bits - setBits, src->m_bits );
}

ZXCORE_EXP void zxVLI_eraseb( zxVLI *src,
  size_t firstBit,  size_t lastBit )
{
  zxuc* data, B= 1, S = 1;
  size_t i = 0, b = 0, s = 0, size;
  ZXASSERT( !src ) return;
  if ( firstBit >= src->m_bits )
    firstBit = src->m_bits - 1;
  if ( lastBit >= src->m_bits )
    lastBit = src->m_bits - 1;
  else if ( lastBit < firstBit )
    lastBit = firstBit;
  size = zxv.capacity( &src->m_core );
  data = (zxuc*)malloc( size );
  mset( data, 0, size );
  for ( ; b < firstBit; ++b )
  {
    data[ i ] |= ( src->m_data[ i ] & B );
    B <<= 1u;
    if ( !B )
    {
      B = 1u;
      ++i;
    }
  }
  S = B;
  s = i;
  for ( ; s < lastBit; ++s )
  {
    S <<= 1u;
    if ( !S )
    {
      S = 1u;
      ++s;
    }
  }
  S <<= 1u;
  if ( !S )
  {
    S = 1u;
    ++s;
  }
  for ( ; b < src->m_bits; ++b )
  {
    if ( S & src->m_data[ s ] )
      data[ i ] |= B;
    B <<= 1u;
    if ( !B )
    {
      B = 1u;
      ++i;
    }
    S <<= 1u;
    if ( !S )
    {
      S = 1u;
      ++s;
    }
  }
  mcpy( src->m_data, data, size );
  free( data );
}
ZXV_SHRINK_TO_FIT( zxVLI, ZXCORE_EXP )
{
  ZXASSERT( !src ) return;
  zxvli.shrinkb( src, src->m_bits );
}
ZXV_DEF_AT( zxVLI, zxuc, ZXCORE_EXP )
ZXV_DEF_EMPTY( zxVLI, ZXCORE_EXP )
ZXCORE_EXP void zxVLI_reserveb( zxVLI *src, size_t minBits )
{
  zxvli.growb( src, minBits );
}