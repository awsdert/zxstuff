#include <zx/std/wide.h>
ZXV_SHRINK_TO_FIT( zxWIDE, ZXCORE_EXP )
{
  ZXASSERT( !src ) return;
  zxv.shrink_to_fit( &src->m_core );
}