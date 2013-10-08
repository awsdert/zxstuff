#include <zx/std/char.h>
ZXCORE_EXP void zxv_zxCHAR_swap( zxCHAR *txt, zxCHAR *src )
{
  if ( !txt || !src )
    return;
  zxv.swap( &txt->m_data, &src->m_data );
  txt->m_text = (char*)txt->m_data.m_data;
}