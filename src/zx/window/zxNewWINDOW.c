#include <zx/window.h>
zxWINDOW* zxNewWINDOW( void )
{
  zxWINDOW* win = (zxWINDOW*)malloc( sizeof( zxWINDOW ) );
  /* zxWINDOW */
  win->m_winType = zxWIN_NULL;
  zx_InitWINDOW( win );
  return win;
}
