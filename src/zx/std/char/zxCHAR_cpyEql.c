#include <zx/std/char.h>
ZXCORE_EXP zxCHAR* zxCHAR_cpyEql( zxCHAR *txt, zxCHAR const *src )
{
  if ( !txt )
    return txt;
  zxv.cpyEql( &txt->m_core, &src->m_core );
  txt->m_data = (char*)txt->m_core.m_data;
  return txt;
}