#include <zx/std/wide.h>
ZXV_INSERT( zxWIDE, ZXCORE_EXP )
{
  ZXASSERT( !src || !cpy )
    return;
  zxv.insert( &src->m_core, &cpy->m_core, pos );
  zxv.grow( &src->m_core, zxw.size( src ) - 1, NULL );
  src->m_data = (wide*)src->m_core.m_data;
}

