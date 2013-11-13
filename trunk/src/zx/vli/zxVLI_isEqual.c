#include <zx/vli.h>
ZXCORE bool zxVLI_isEqual( zxVLI const *src, zxVLI const *val, size_t* I )
{
  size_t pi = 0, i = 0;
  bool isVS = false;
  zxuc *SRC = (zxuc*)src->m_core.m_data,
    *VAL = (zxuc*)val->m_core.m_data;
  if ( I )
    *I = SIZE_MAX;
  if ( src == val )
    return true;
  if ( !src || !SRC )
  {
    i  = val->m_lastByte;
    pi = val->m_core.m_size;
    for ( ; i != pi; --i, --pi )
    {
      if ( VAL[ i ] != 0u )
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
  if ( !val || !VAL )
  {
    i  = src->m_lastByte;
    pi = src->m_core.m_size;
    for ( ; i != pi; --i, --pi )
    {
      if ( SRC[ i ] != 0u )
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
  pi = src->m_core.m_size;
  isVS = ( val->m_isSigned && VAL[ val->m_lastByte ] >= 0x80 );
  if ( src->m_isSigned && SRC[ src->m_lastByte ] >= 0x80 )
  {
    if ( !isVS )
    {
      if ( I )
        *I = i;
      return false;
    }
    for ( ; i != pi && i >= val->m_core.m_size; --i, --pi )
    {
      if ( SRC[ i ] != UCHAR_MAX )
      {
        if ( I )
          *I = i;
        return false;
      }
    }
    i  = val->m_lastByte;
    pi = val->m_core.m_size;
    for ( ; i != pi && i >= src->m_core.m_size; --i, --pi )
    {
      if ( VAL[ i ] != UCHAR_MAX )
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
      if ( SRC[ i ] != 0u )
      {
        if ( I )
          *I = i;
        return false;
      }
    }
    i  = val->m_lastByte;
    pi = val->m_core.m_size;
    for ( ; i != pi && i != src->m_lastByte; --i, --pi )
    {
      if ( VAL[ i ] != 0u )
      {
        if ( I )
          *I = i;
        return false;
      }
    }
  }
  for ( ; i != pi; --i, --pi )
  {
    if ( SRC[ i ] != VAL[ i ] )
    {
      if ( I )
        *I = i;
      return false;
    }
  }
  return true;
}
ZXVLI_OPEQL
{
  if ( src )
  {
    zxvli._kill( src );
    if ( val )
      zxv.opEql( &src->m_core, &val->m_core );
  }
  return src;
}
