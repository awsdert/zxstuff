/* USER: AWSDERT; DATE: 09/11/2013; TIME: 08:00 */
#include <zx/vli.h>
ZXV_ERASE( zxVLI, ZXCORE, ZXCORE_CALL )
{
  size_t size;
  ZXASSERT( !src ) return;
  zxv.erase( &src->m_core, first, last );
  size = zxv.capacity( &src->m_core );
  src->m_bits = CHAR_BIT * size;
  src->m_lastByte = size - 1;
  src->m_lastBit = zxuc_last;
}
ZXCORE void zxVLI_eraseb( zxVLI *src, size_t firstBit,  size_t lastBit )
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
