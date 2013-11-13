/* USER: AWSDERT; DATE: 09/11/2013; TIME: 07:57 */
#include <zx/vli.h>
ZXCORE void zxVLI_shrink( zxVLI *src, size_t setSize )
{
  size_t size = zxvli.size( src );
  ZXASSERT( !src ) return;
  zxv.shrink( &src->m_core, setSize );
  src->m_bits = CHAR_BIT * setSize;
  src->m_lastByte = setSize - 1;
  src->m_lastBit = zxuc_last;
}
ZXCORE void zxVLI_shrinkb( zxVLI *src, size_t setBits )
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
ZXV_SHRINK_TO_FIT( zxVLI, ZXCORE, ZXCORE_CALL )
{
  ZXASSERT( !src ) return;
  zxvli.shrinkb( src, src->m_bits );
}
