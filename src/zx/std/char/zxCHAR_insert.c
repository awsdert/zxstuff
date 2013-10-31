#include <zx/std/char.h>
ZXV_INSERT( zxCHAR, ZXCORE_EXP )
{
  ZXASSERT( !src || !cpy )
    return;
  zxv.insert( &src->m_core, &cpy->m_core, pos );
  zxv.grow( &src->m_core, zxc.size( src ) - 1, NULL );
  src->m_data = (char*)src->m_core.m_data;
}
