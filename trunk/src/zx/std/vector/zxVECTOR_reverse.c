#include <zx/std/vector.h>
ZXCORE void zxVECTOR_reverse( zxVECTOR *src )
{
  size_t i = 0, d = 0, s;
  zxuc *TMP, *SRC;
  ZXASSERT( !src )
    return;
  if ( !src->m_count )
    return;
  SRC = (zxuc*)src->m_data;
  TMP = (zxuc*)malloc( src->m_size );
  mcpy( TMP, src->m_data, src->m_size );
  s = src->m_size - src->m_Tsize;
  do
  {
    mcpy( &SRC[ d ], &TMP[ s ], src->m_Tsize );
    ++i; d += src->m_Tsize; s -= src->m_Tsize;
  }
  while ( i < src->m_count );
  free( TMP );
}
