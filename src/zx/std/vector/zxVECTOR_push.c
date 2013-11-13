/* USER: Lee; DATE: 04/11/2013; TIME: 06:37*/
#include <zx/std/vector.h>
ZXV_PUSH( zxVECTOR, void*, ZXCORE, ZXCORE_CALL )
{
  size_t i = 0, j = 0, k = 0, stop = zxv.size( src ), size;
  zxuc *SRC;
  ZXASSERT( !src )
    return false;
  size = src->m_Tsize;
  SRC = (zxuc*)src->m_data;
  if ( unique )
  {
    for ( ; i < stop; ++i, j += size )
    {
        if ( mcmp( &SRC[ j ], cpy, size, NULL ) )
            return true;
    }
  }
  zxv.grow( src, stop + 1, cpy );
  if ( zxv.size( src ) == stop )
    return false;
  if ( pos > stop )
    pos = stop;
  for ( ++stop, i = pos, j = i * size, k = j + size;
    i < stop; ++i, j += size, k += size )
    mcpy( &SRC[ k ], &SRC[ j ], size );
  mcpy( &SRC[ pos * size ], cpy, size );
  return true;
}
