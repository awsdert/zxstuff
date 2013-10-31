#include <zx/vli.h>
ZXCORE_EXP void zxVLI_grow( zxVLI *src, size_t setSize )
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
ZXCORE_EXP void zxVLI_shrink( zxVLI *src, size_t setSize )
{
  size_t size = zxvli.size( src );
  ZXASSERT( !src ) return;
  zxv.shrink( &src->m_core, setSize );
  src->m_bits = CHAR_BIT * setSize;
  src->m_lastByte = setSize - 1;
  src->m_lastBit = zxuc_last;
}
ZXCORE_EXP void zxVLI_resize( zxVLI *src, size_t setSize )
{
  size_t stop = zxvli.size( src );
  ZXASSERT( !src ) return;
  if ( setSize >= stop )
    zxvli.grow( src, setSize );
  else
    zxvli.erase( src, stop - setSize, stop );
}
ZXV_ERASE( zxVLI, ZXCORE_EXP )
{
  size_t size;
  ZXASSERT( !src ) return;
  zxv.erase( &src->m_core, first, last );
  size = zxv.capacity( &src->m_core );
  src->m_bits = CHAR_BIT * size;
  src->m_lastByte = size - 1;
  src->m_lastBit = zxuc_last;
}
ZXV_RESERVE( zxVLI, ZXCORE_EXP )
{
  zxvli.grow( src, minSize );
}