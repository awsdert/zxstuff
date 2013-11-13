#include <zx/std/wide.h>
ZXV_AT( zxWIDE, wide, ZXCORE, ZXCORE_CALL )
{
  ZXASSERT( !src ) return (wide*)0;
  return (wide*)zxv.at( &src->m_core, i );
}
