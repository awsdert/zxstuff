/* USER: Lee; DATE: 04/11/2013; TIME: 06:37*/
#include <zx/std/vector.h>
ZXV_PUSH( zxVECTOR, void*, ZXCORE, ZXCORE_CALL )
{
  zxui i = 0, stop;
  size_t t = 0, f = 0, Tsize;
  zxuc *SRC;
  ZXASSERT( !src )
    return false;
  stop  = src->m_count;
  Tsize = src->m_Tsize;
  SRC   = (zxuc*)src->m_data;
  if ( unique )
  {
    for ( ; i < stop; ++i, t += Tsize )
    {
      if ( mcmp( &SRC[ t ], cpy, Tsize, NULL ) )
          return true;
    }
  }
  zxv.grow( src, stop + 1, cpy );
  if ( zxv.size( src ) == stop )
    return false;
  if ( pos >= stop )
    return true;
  i = src->m_count;
  t = src->m_size - Tsize;
  f = src->m_size - (Tsize << 1 );
  for ( ; i > pos; --i, t -= Tsize, f -= Tsize )
    mcpy( &SRC[ t ], &SRC[ f ], Tsize );
  mcpy( &SRC[ t ], cpy, Tsize );
  return true;
}
