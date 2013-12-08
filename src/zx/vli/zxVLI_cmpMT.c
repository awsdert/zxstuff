#include <zx/vli.h>
ZXCORE bool zxVLI_cmpMT( zxVLI const *src, zxVLI const *val )
{
  zxui i = 0;
  zxuc *SRC = (zxuc*)src->m_core.m_data,
    *VAL = (zxuc*)val->m_core.m_data;
  if ( !zxvli.isEqual( src, val, &i ) )
  {
    if ( val && val->m_isSigned && VAL[ val->m_lastByte ] >= 0x80 )
    {
      if ( !src )
        return true;
      if ( src->m_isSigned && SRC[ src->m_lastByte ] >= 0x80 )
        return SRC[ i ] > VAL[ i ];
      return true;
    }
    if ( !src || ( src->m_isSigned && SRC[ src->m_lastByte ] >= 0x80 ) )
      return false;
    if ( val )
      return SRC[ i ] > VAL[ i ];
    return true;
  }
  return false;
}
#if ZXCPP
bool zxVli::operator>( zxVli val )
{
  return zxvli.cmpMT( this, &val );
}
#endif
