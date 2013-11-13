#include <zx/std/vector.h>
ZXV_ERASE( zxVECTOR, ZXCORE, ZXCORE_CALL )
{
  size_t i = first, s, f, t;
  zxuc *SRC;
  ZXASSERT( !src ) return;
  SRC = (zxuc*)src->m_data;
  if ( !i ) t = 0;
  else t = i * src->m_Tsize;
  if ( !last )
  {
    s = i + 1;
    f = t + src->m_Tsize;
  }
  else if ( last >= src->m_count )
  {
    s = src->m_count;
    f = src->m_size;
  }
  else
  {
    s = last;
    f = s * src->m_Tsize;
  }
  last = s;
  for ( ; s < src->m_count; ++s, ++i, t += src->m_Tsize, f += src->m_Tsize )
    mcpy( &SRC[ t ], &SRC[ f ], src->m_Tsize );
  for ( ; i < src->m_count; ++i, t += src->m_Tsize )
    mset( &SRC[ t ], 0, src->m_Tsize );
  src->m_count = last;
  src->m_size  = last * src->m_Tsize;
}
