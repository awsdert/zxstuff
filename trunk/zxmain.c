#include <zx/tbox.h>

ZXV_DEF( zxWINDOWS, zxWINDOW*, ZXSYS_EXP )

static zxWINDOWS  zx_l_allWindows = {0};
static zxInstance zx_l_prevI = NULL, zx_l_thisI = NULL;
static zxEVENTS   zx_l_events = {0};

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
  zxWINDOW *root = NULL, *win;
  zxTBOX *tbox;
  zxWINDOWS *all = &zx_l_allWindows;
  zxEVTPTR ptr;
  zx_l_prevI = prevI;
  zx_l_thisI = thisI;
  zx_win._init( all, NULL, 0 );
  zxevt._init( &zx_l_events, NULL, 0 );
  root = zxwin.opNew( NULL );
  for ( ; i < stop; ++i )
    zxwin._initWCX( &zxwin.WCX[ i ] );
  for ( i = 0; i < zxEVT_COUNT; ++i )
  {
    ptr.type = (zxEVT)i;
    ptr.proc = zxevt.events[ i ];
    zxevt.addEvent( &zx_l_events, ptr );
  }
#endif
#if ZXMSW
  zxwin.WCX[ zxWIN_NULL  ].lpszClassName = ZXT("ZXWINDOW");
  zxwin.WCX[ zxWIN_FRAME ].lpszClassName = ZXT("ZXFRAME");
  i = zxWIN_TBOX;
  zxwin.WCX[ i ].lpszClassName = ZXT("EDIT");
  zxwin.WCX[ i ].hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME);
  root->m_wcx = (zxWCX*)mnew( sizeof( zxWCX ), NULL );
  *root->m_wcx = zxwin.WCX[ zxWIN_NULL ];
  root->m_style = WS_OVERLAPPEDWINDOW;
  root->m_h     = 640;
  root->m_w     = 480;
  zxstr._initC( &root->m_title, args, 0 );
  zxwin.mswOpNew( root );
  tbox = zxtbox.opNew( NULL );
  win  = tbox->m_win;
  zxwin.setBase( win, root );
  win->m_x = 5;
  win->m_y = 5;
  win->m_h = 30;
  win->m_w = 100;
  win->m_stylex = WS_EX_CLIENTEDGE;
  win->m_wcx = (zxWCX*)mnew( sizeof( zxWCX ), NULL );
  *win->m_wcx = zxwin.WCX[ zxWIN_TBOX ];
  zxwin.mswOpNew( win );
  ShowWindow( root->m_wh, showAs );
  UpdateWindow( root->m_wh );
  ShowWindow( win->m_wh,  showAs );
  UpdateWindow( win->m_wh );
  while (GetMessage(&msg, NULL, 0, 0))
	{
		if ( /* !IsDialogMessage( msg.hwnd, &msg ) && /* */
      !TranslateAccelerator( msg.hwnd, acc, &msg) )
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
ZXSYS_EXP zxEVENTS* zxEVENTS_getDefEvents( void )
{
  return &zx_l_events;
}
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