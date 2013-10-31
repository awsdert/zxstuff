#include <zx/vli.h>
ZXV__INITCPY( zxVLI, ZXCORE_EXP )
{
  ZXASSERT( !src || !cpy ) return;
  zxv._initCpy( &src->m_core, &cpy->m_core );
}
ZXCORE_EXP void zxVLI__init( zxVLI *src, zxsm value )
{
  size_t size = sizeof( zxsm );
  ZXASSERT( !src ) return;
  *src = zxvli.def;
  src->m_isSigned = true;
  src->m_core.m_ptr = &src->m_data;
  zxv.grow( &src->m_core, size,  NULL );
  zxcopy( (zxuc*)&value, size, zxIntEndian(),
     src->m_data, size, zxENDIAN_BIG );
  src->m_bits    = size * CHAR_BIT;
  src->m_lastByte = size - 1;
  src->m_lastBit = zxuc_last;
}
ZXCORE_EXP void zxVLI__initU( zxVLI *src, zxum value )
{
  size_t size = sizeof( zxsm );
  ZXASSERT( !src ) return;
  *src = zxvli.def;
  src->m_core.m_ptr = &src->m_data;
  zxv.grow( &src->m_core, size,  NULL );
  zxcopy( (zxuc*)&value, size, zxIntEndian(),
     src->m_data, size, zxENDIAN_BIG );
  src->m_bits    = size * CHAR_BIT;
  src->m_lastByte = size - 1;
  src->m_lastBit = zxuc_last;
}
