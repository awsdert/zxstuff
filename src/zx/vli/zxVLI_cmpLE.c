#include <zx/vli.h>
ZXCORE bool zxVLI_cmpLE( zxVLI const *src, zxVLI const *val )
{
  size_t i = 0;
  zxuc *SRC = (zxuc*)src->m_core.m_data,
    *VAL = (zxuc*)val->m_core.m_data;
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
    return false;
  }
  return true;
}
#if ZXCPP
bool zxVli::operator<=( zxVli val )
{
  return zxvli.cmpLE( this, &val );
}
#endif
