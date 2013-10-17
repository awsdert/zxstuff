#include <zx/vli.h>
ZXCORE_EXP void zxc_zxVLI_grow( zxVLI *vli, size_t newSize )
{
  zxuc sv = 0u, *VLI = (zxuc*)vli->m_vector.m_data;
  size_t tmp = 0u;
  if ( newSize < vli->m_vector.m_size )
    return;
  if ( vli->m_isSigned && VLI[ vli->m_lastByte ] >= 0x80 )
    sv = UCHAR_MAX;
  tmp = newSize * CHAR_BIT;


  zxv.grow( &vli->m_vector, newSize, &sv );
  vli->m_bits      = tmp;
  for ( ; tmp >= CHAR_BIT; tmp -= CHAR_BIT );
  if ( tmp )
    vli->m_lastBit = 1u << ( CHAR_BIT - tmp );
  else
    vli->m_lastBit = zxLastCharBit;
  vli->m_lastByte  = newSize - 1u;
}