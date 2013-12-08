#include <zx/std/vector.h>

ZXV_PUSH_BACK( zxVECTOR, void*, ZXCORE, ZXCORE_CALL )
{
  zxui i = 0, stop = zxv.size( src );
  size_t j = 0;
  zxuc *SRC;
  ZXASSERT( !src )
    return false;
  SRC = (zxuc*)src->m_data;
  if ( unique && stop )
  {
    do
    {
      if ( mcmp( &SRC[ j ], cpy, src->m_Tsize, NULL ) )
        return true;
      ++i; j += src->m_Tsize;
    }
    while ( i < stop );
  }
  zxv.grow( src, stop + 1, cpy );
  if ( zxv.size( src ) == stop )
    return false;
  return true;
}
