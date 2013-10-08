#include <zx/vli.h>
ZXCORE_EXP bool zxc_zxVLI_cmpMT( zxVLI const *src, zxVLI const *val )
{
  size_t i = 0;
  if ( !zxvli.isEqual( src, val, &i ) )
  {
    if ( val && val->m_isSigned && val->m_vector.m_data[ val->m_lastByte ] >= 0x80 )
    {
      if ( !src )
        return true;
      if ( src->m_isSigned && src->m_vector.m_data[ src->m_lastByte ] >= 0x80 )
        return src->m_vector.m_data[ i ] > val->m_vector.m_data[ i ];
      return true;
    }
    if ( !src || ( src->m_isSigned && src->m_vector.m_data[ src->m_lastByte ] >= 0x80 ) )
      return false;
    if ( val )
      return src->m_vector.m_data[ i ] > val->m_vector.m_data[ i ];
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