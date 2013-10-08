#include <zx/std/wide.h>
ZXCORE_EXP zxWIDE* zxv_zxWIDE_cpyEql( zxWIDE *txt, zxWIDE const *src )
{
  if ( !txt || !src )
    return txt;
  zxv.cpyEql( &txt->m_data, &src->m_data );
  txt->m_text = (wide*)txt->m_data.m_data;
  return txt;
}