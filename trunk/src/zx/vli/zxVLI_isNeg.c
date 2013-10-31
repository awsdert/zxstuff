#include <zx/vli.h>
ZXCORE_EXP zxuc zxVLI_isNeg( zxVLI const *src )
{
  zxuc last = 0u, bit = 1u;
  ZXASSERT( !src ) return 0u;
  if ( !src->m_isSigned  ||
    src->m_data[ src->m_lastByte ] < src->m_lastBit )
    return 0u;
  for ( ; bit && bit <= src->m_lastBit; bit <<= 1 )
    last |= bit;
  return last;
}