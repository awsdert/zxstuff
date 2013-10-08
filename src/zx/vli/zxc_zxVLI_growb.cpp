#include <zx/vli.h>
ZXCORE void zxc_zxVLI_growb( zxVLI* obj, size_t newBits )
{
  zxuc sv = 0u;
  size_t tmp = 0u, newSize;
  if ( newBits < obj->m_bits )
    return;
  if ( obj->m_isSigned && obj->m_vector.m_data[ obj->m_lastByte ] >= 0x80 )
    sv = UCHAR_MAX;
  newSize = zxc_size_udiv( newBits, CHAR_BIT, &tmp );
  if ( tmp )
    ++newSize;
  zxv.grow( &obj->m_vector, newSize, &sv );
  obj->m_bits      = newBits;
  for ( ; newBits >= CHAR_BIT; newBits -= CHAR_BIT );
  if ( newBits )
    obj->m_lastBit = 1u << ( CHAR_BIT - newBits );
  else
    obj->m_lastBit = zxLastCharBit;
  obj->m_lastByte  = newSize - 1u;
}