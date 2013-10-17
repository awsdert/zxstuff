#include <zx/vli.h>
ZXCORE void zxc_zxVLI_growb( zxVLI* vli, size_t newBits )
{
  zxuc sv = 0u, *VLI = (zxuc*)vli->m_vector.m_data;
  size_t tmp = 0u, newSize;
  if ( newBits < vli->m_bits )
    return;
  if ( vli->m_isSigned && VLI[ vli->m_lastByte ] >= 0x80 )
    sv = UCHAR_MAX;
  newSize = zxc_size_udiv( newBits, CHAR_BIT, &tmp );
  if ( tmp )
    ++newSize;
  zxv.grow( &vli->m_vector, newSize, &sv );
  vli->m_bits      = newBits;
  for ( ; newBits >= CHAR_BIT; newBits -= CHAR_BIT );
  if ( newBits )
    vli->m_lastBit = 1u << ( CHAR_BIT - newBits );
  else
    vli->m_lastBit = zxLastCharBit;
  vli->m_lastByte  = newSize - 1u;
}