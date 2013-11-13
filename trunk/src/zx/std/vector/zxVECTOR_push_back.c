#include <zx/std/vector.h>

ZXV_PUSH_BACK( zxVECTOR, void*, ZXCORE, ZXCORE_CALL )
{
  size_t i = 0, j = 0, stop = zxv.size( src );
  zxuc *SRC;
  ZXASSERT( !src )
    return false;
  SRC = (zxuc*)src->m_data;
  if ( unique )
  {
    for ( ; i < stop; ++i, j += src->m_Tsize )
    {
        if ( mcmp( &SRC[ j ], cpy, src->m_Tsize, NULL ) )
            return true;
    }
  }
  zxv.grow( src, stop + 1, cpy );
  if ( zxv.size( src ) == stop )
    return false;
  return true;
}
