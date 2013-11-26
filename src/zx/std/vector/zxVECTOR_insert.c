#include <zx/std/vector.h>
ZXV_INSERT( zxVECTOR, ZXCORE, )
{
  size_t i = 0, f, t, Tsize;
  zxuc *SRC = NULL, *CPY = NULL;
  if ( !src || !cpy || !cpy->m_data ) return;
  Tsize = src->m_Tsize;
  f = src->m_size - Tsize;
  zxv.grow( src, src->m_count + cpy->m_count, NULL );
  t = src->m_size - Tsize;
  SRC = (zxuc*)src->m_data;
  CPY = (zxuc*)cpy->m_data;
  for ( ; i < cpy->m_count; ++i, t -= Tsize, f -= Tsize )
    mcpy( &SRC[ t ], &SRC[ f ], Tsize );
  i = 0;
  f = 0;
  t = pos * Tsize;
  for ( ; i < cpy->m_count; ++i, t += Tsize, f += Tsize )
    mcpy( &SRC[ t ], &CPY[ f ], Tsize );
}
