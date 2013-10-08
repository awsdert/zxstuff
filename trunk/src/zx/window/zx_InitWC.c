#include <zx/window.h>
void zx_InitWC( void )
{
  int i = zxWIN_NULL, count = zxWIN_COUNT;
  for ( ; i < count; ++i )
  {
    zxInitWndClass(   &zx_WC[  i ] );
    zxInitWndClassEx( &zx_WCX[ i ] );
  }
#ifdef zxMSW
  i = zxWIN_NULL;
  zx_WC[  i ].lpszClassName = zxt("ZXWINDOW");
  zx_WCX[ i ].lpszClassName = zxt("ZXWINDOW");
  i = zxWIN_FRAME;
  zx_WC[  i ].lpszClassName = zxt("ZXFRAME");
  zx_WCX[ i ].lpszClassName = zxt("ZXFRAME");
  i = zxWIN_TEXTBOX;
  zx_WC[  i ].lpszClassName = zxt("EDIT");
  zx_WC[  i ].hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME);
  zx_WCX[ i ].lpszClassName = zxt("EDIT");
  zx_WCX[ i ].hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME);
  zx_mswInitATOM();
#endif
}