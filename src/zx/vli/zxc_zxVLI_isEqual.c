#include <zx/vli.h>
ZXCORE_EXP bool zxc_zxVLI_isEqual( zxVLI const *src, zxVLI const *val, size_t* I )
{
  size_t pi = 0, i = 0;
  bool isVS = false;
  if ( I )
    *I = SIZE_MAX;
  if ( src == val )
    return true;
  if ( !src || !src->m_vector.m_data )
  {
    i  = val->m_lastByte;
    pi = val->m_vector.m_size;
    for ( ; i != pi; --i, --pi )
    {
      if ( val->m_vector.m_data[ i ] != 0u )
      {
        if ( I )
          *I = i;
        return false;
      }
    }
    if ( I )
      *I = 0;
    return true;
  }
  if ( !val || !val->m_vector.m_data )
  {
    i  = src->m_lastByte;
    pi = src->m_vector.m_size;
    for ( ; i != pi; --i, --pi )
    {
      if ( src->m_vector.m_data[ i ] != 0u )
      {
        if ( I )
          *I = i;
        return false;
      }
    }
    if ( I )
      *I = 0;
    return true;
  }
  i  = src->m_lastByte;
  pi = src->m_vector.m_size;
  isVS = ( val->m_isSigned && val->m_vector.m_data[ val->m_lastByte ] >= 0x80 );
  if ( src->m_isSigned && src->m_vector.m_data[ src->m_lastByte ] >= 0x80 )
  {
    if ( !isVS )
    {
      if ( I )
        *I = i;
      return false;
    }
    for ( ; i != pi && i >= val->m_vector.m_size; --i, --pi )
    {
      if ( src->m_vector.m_data[ i ] != UCHAR_MAX )
      {
        if ( I )
          *I = i;
        return false;
      }
    }
    i  = val->m_lastByte;
    pi = val->m_vector.m_size;
    for ( ; i != pi && i >= src->m_vector.m_size; --i, --pi )
    {
      if ( val->m_vector.m_data[ i ] != UCHAR_MAX )
      {
        if ( I )
          *I = i;
        return false;
      }
    }
  }
  else
  {
    if ( isVS )
    {
      if ( I )
        *I = i;
      return false;
    }
    for ( ; i != pi && i != val->m_lastByte; --i, --pi )
    {
      if ( src->m_vector.m_data[ i ] != 0u )
      {
        if ( I )
          *I = i;
        return false;
      }
    }
    i  = val->m_lastByte;
    pi = val->m_vector.m_size;
    for ( ; i != pi && i != src->m_lastByte; --i, --pi )
    {
      if ( val->m_vector.m_data[ i ] != 0u )
      {
        if ( I )
          *I = i;
        return false;
      }
    }
  }
  for ( ; i != pi; --i, --pi )
  {
    if ( src->m_vector.m_data[ i ] != val->m_vector.m_data[ i ] )
    {
      if ( I )
        *I = i;
      return false;
    }
  }
  return true;
}
ZXCORE_EXP zxVLI* zxc_zxVLI_cpyEql( zxVLI *dst, zxVLI const *src )
{
  if ( dst )
  {
    zxcKill_zxVLI( dst );
    if ( src )
    {
      *dst = *src;
      dst->m_vector.m_data = (zxuc*)malloc( dst->m_vector.m_size );
      memcpy( dst->m_vector.m_data, src->m_vector.m_data, dst->m_vector.m_size );
    }
  }
  return dst;
}