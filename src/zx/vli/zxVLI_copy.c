#include <zx/vli.h>
ZXV_DEF_COPY( zxVLI, zxuc, ZXCORE_EXP )
ZXV_CLEAR( zxVLI, ZXCORE_EXP )
{
  ZXASSERT( !src ) return;
  zxv.clear( &src->m_core );
  src->m_bits     = 0u;
  /* isSigned is left for developer to clear */
  src->m_lastBit  = 0u;
  src->m_lastByte = 0u;
}
ZXV_SWAP( zxVLI, ZXCORE_EXP )
{
  zxVLI tmp;
  ZXASSERT( !src || !dst ) return;
  tmp = *src;
  zxv.swap( &src->m_core, &dst->m_core );
  src->m_bits     = dst->m_bits;
  src->m_isSigned = dst->m_isSigned;
  src->m_lastBit  = dst->m_lastBit;
  src->m_lastByte = dst->m_lastByte;
  dst->m_bits     = tmp.m_bits;
  dst->m_isSigned = tmp.m_isSigned;
  dst->m_lastBit  = tmp.m_lastBit;
  dst->m_lastByte = tmp.m_lastByte;
}
