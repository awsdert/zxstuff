#include <zx/vli.h>
ZXCORE void zxVLI_grow( zxVLI *src, size_t setSize )
{
  zxuc   def  = 0u, last = zxvli.isNeg( src );
  ZXASSERT( !src ) return;
  if ( last )
    def = UCHAR_MAX;
  zxv.grow( &src->m_core, setSize, &def );
  src->m_bits = CHAR_BIT * setSize;
  src->m_lastByte = setSize - 1;
  src->m_lastBit = zxuc_last;
}

ZXCORE void zxVLI_resize( zxVLI *src, size_t setSize )
{
  size_t stop = zxvli.size( src );
  ZXASSERT( !src ) return;
  if ( setSize >= stop )
    zxvli.grow( src, setSize );
  else
    zxvli.erase( src, stop - setSize, stop );
}
