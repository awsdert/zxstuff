#include <zx/vli.h>
ZXCORE_EXP bool zxc_zxVLI_cmpLT( zxVLI const *src, zxVLI const *val )
{
  size_t i = 0;
  zxuc *SRC = (zxuc*)src->m_vector.m_data,
    *VAL = (zxuc*)val->m_vector.m_data;
  if ( !zxvli.isEqual( src, val, &i ) )
  {
    if ( val && val->m_isSigned && VAL[ val->m_lastByte ] >= 0x80 )
    {
      if ( !src )
        return false;
      if ( src->m_isSigned && SRC[ src->m_lastByte ] >= 0x80 )
        return SRC[ i ] < VAL[ i ];
      return false;
    }
    if ( !src || ( src->m_isSigned && SRC[ src->m_lastByte ] >= 0x80 ) )
      return true;
    if ( val )
      return SRC[ i ] < VAL[ i ];
  }
  return false;
}
#if ZXCPP
bool zxVli::operator<( zxVli val )
{
  return zxvli.cmpLT( this, &val );
}
#endif