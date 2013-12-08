#include <zx/vli.h>
ZXCORE void zxVLI_growb( zxVLI* src, size_t setBits )
{
  zxuc   def = 0u, last = zxvli.isNeg( src );
  zxui   size;
  size_t bits = 0u;
  ZXASSERT( !src ) return;
  if ( setBits <= src->m_bits )
    return;
  if ( last )
    def = UCHAR_MAX;
  size = zxdivu_size( setBits, CHAR_BIT, &bits ) & ZXUINT_MAX;
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


ZXCORE void zxVLI_resizeb( zxVLI *src, size_t setBits )
{
  ZXASSERT( !src ) return;
  if ( setBits >= src->m_bits )
    zxvli.growb( src, setBits );
  else
    zxvli.eraseb( src, src->m_bits - setBits, src->m_bits );
}



ZXV_DEF_AT( zxVLI, zxuc, ZXCORE, ZXCORE_CALL )

