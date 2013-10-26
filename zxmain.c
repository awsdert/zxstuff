#include <zx/window.h>

ZXV_DEF( zxWINDOWS, zxWINDOW*, ZXSYS_EXP )

static zxWINDOWS  zx_l_allWindows = {0};
static zxInstance zx_l_prevI = NULL, zx_l_thisI = NULL;

ZXSYS_EXP zxsi zxapp__main(
  zxInstance thisI,
  zxInstance prevI,
  LPSTR      args,
  int        showAs )
{
#if !ZXALL
#if ZXMSW
  MSG    msg = {0};
  HACCEL  acc = NULL;
#endif
  size_t i = 0, stop = zxWIN_COUNT;
  zxWINDOW *root = NULL;
  zxWINDOWS *all = &zx_l_allWindows;
  zx_l_prevI = prevI;
  zx_l_thisI = thisI;
  zx_win._init( all, NULL, 0 );
  root = zxwin.opNew( NULL );
  for ( ; i < stop; ++i )
  {
    zxwin._initWC(  &zxwin.WC[  i ] );
    zxwin._initWCX( &zxwin.WCX[ i ] );
  }
#endif
#if ZXMSW
  i = zxWIN_NULL;
  zxwin.WC[  i ].lpszClassName = ZXT("ZXWINDOW");
  zxwin.WCX[ i ].lpszClassName = ZXT("ZXWINDOW");
  i = zxWIN_FRAME;
  zxwin.WC[  i ].lpszClassName = ZXT("ZXFRAME");
  zxwin.WCX[ i ].lpszClassName = ZXT("ZXFRAME");
  i = zxWIN_TBOX;
  zxwin.WC[  i ].lpszClassName = ZXT("EDIT");
  zxwin.WC[  i ].hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME);
  zxwin.WCX[ i ].lpszClassName = ZXT("EDIT");
  zxwin.WCX[ i ].hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME);
  root->m_wc = (zxWC*)mnew( sizeof( zxWC ), NULL );
  *root->m_wc = zxwin.WC[ zxWIN_NULL ];
  root->m_style = WS_OVERLAPPEDWINDOW;
  root->m_h     = 640;
  root->m_w     = 480;
  zxstr._initC( &root->m_title, "Tester", 0 );
  zxwin.mswOpNew( root );
  ShowWindow( root->m_wh, showAs );
  while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, acc, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return zxFreeWindows( (int)msg.wParam );
#else
  return zxFreeWindows( 0 );
#endif
}

/* DO NOT MODIFY */

ZXSYS_EXP zxWINDOWS* zxWINDOW_allWindows( void )
{
  return &zx_l_allWindows;
}

ZXSYS_EXP zxWINDOW*  const zxGetRootWindow( void )
{
  return zxwin.getWindow( 0 );
}
ZXSYS_EXP zxHwnd     zxGetRootWH( void )
{
  return zxwin.getWindow( 0 )->m_wh;
}
ZXSYS_EXP zxInstance zxGetPrevI( void )
{
  return zx_l_prevI;
}
ZXSYS_EXP zxInstance zxGetThisI( void )
{
  return zx_l_thisI;
}