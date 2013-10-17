#include <zx/window.h>
ZXSYS_EXP void zxv_zxWINDOW_setBase( zxWINDOW *win, zxWINDOW *base )
{
  if ( win && base )
    win->m_base = base;
}