#include <zx/vli.h>
ZXV__INITCPY( zxVLI, ZXCORE, ZXCORE_CALL )
{
  ZXASSERT( !src || !cpy ) return;
  zxv._initCpy( &src->m_core, &cpy->m_core );
}
ZXCORE void zxVLI__init( zxVLI *src, zxsm value )
{
  zxui size = sizeof( zxsm ) & ZXUINT_MAX;
  ZXASSERT( !src ) return;
  *src = zxvli.def;
  src->m_isSigned = true;
  src->m_core.m_ptr = (void**)&src->m_data;
  zxv.grow( &src->m_core, size,  NULL );
  zxcopy( (zxuc*)&value, size, zxIntEndian(),
     src->m_data, size, zxENDIAN_BIG );
  src->m_bits    = size * CHAR_BIT;
  src->m_lastByte = size - 1;
  src->m_lastBit = zxuc_last;
}
ZXCORE void zxVLI__initU( zxVLI *src, zxum value )
{
  zxui size = sizeof( zxsm ) & ZXUINT_MAX;
  ZXASSERT( !src ) return;
  *src = zxvli.def;
  src->m_core.m_ptr = (void**)&src->m_data;
  zxv.grow( &src->m_core, size,  NULL );
  zxcopy( (zxuc*)&value, size, zxIntEndian(),
     src->m_data, size, zxENDIAN_BIG );
  src->m_bits    = size * CHAR_BIT;
  src->m_lastByte = size - 1;
  src->m_lastBit = zxuc_last;
}
