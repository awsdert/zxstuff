#include <zx/std/wide.h>
ZXCORE_EXP void zxv_zxWIDE_swap( zxWIDE *txt, zxWIDE *src )
{
  if ( !txt || !src )
    return;
  zxv.swap( &txt->m_data, &src->m_data );
  txt->m_text = (wide*)txt->m_data.m_data;
}