#include <zx/std/wide.h>
ZXCORE_EXP zxWIDE* zxWIDE_cpyEql( zxWIDE *txt, zxWIDE const *src )
{
  if ( !txt || !src )
    return txt;
  zxv.cpyEql( &txt->m_core, &src->m_core );
  txt->m_data = (wide*)txt->m_core.m_data;
  return txt;
}