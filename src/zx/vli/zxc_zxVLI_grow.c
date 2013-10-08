#include <zx/vli.h>
ZXCORE_EXP void zxc_zxVLI_grow( zxVLI *obj, size_t newSize )
{
  zxuc sv = 0u;
  size_t tmp = 0u;
  if ( newSize < obj->m_vector.m_size )
    return;
  if ( obj->m_isSigned && obj->m_vector.m_data[ obj->m_lastByte ] >= 0x80 )
    sv = UCHAR_MAX;
  tmp = newSize * CHAR_BIT;


  zxv.grow( &obj->m_vector, newSize, &sv );
  obj->m_bits      = tmp;
  for ( ; tmp >= CHAR_BIT; tmp -= CHAR_BIT );
  if ( tmp )
    obj->m_lastBit = 1u << ( CHAR_BIT - tmp );
  else
    obj->m_lastBit = zxLastCharBit;
  obj->m_lastByte  = newSize - 1u;
}