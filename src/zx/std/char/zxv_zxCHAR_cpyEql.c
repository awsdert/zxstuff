#include <zx/std/char.h>
ZXCORE_EXP zxCHAR* zxv_zxCHAR_cpyEql( zxCHAR *txt, zxCHAR const *src )
{
  if ( !txt )
    return txt;
  zxv.cpyEql( &txt->m_data, &src->m_data );
  txt->m_text = (char*)txt->m_data.m_data;
  return txt;
}