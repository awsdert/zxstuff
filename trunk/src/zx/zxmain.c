#include <zx/tbox.h>

ZXV_DEF( zx_win, zxWINDOWS, zxWINDOW*, ZXSYS, ZXSYS_CALL )

static zxWINDOWS  zx_l_allWindows = {0};
static zxWINDOW*  zx_l_rootWindow = NULL;
static zxInstance zx_l_prevI = NULL, zx_l_thisI = NULL;
static zxEVENTS   zx_l_events = {0};

/*
#if ZXMSW && defined( ZXBUILD_SYS )
extern "C" ZXSYS BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
#endif
/* */

ZXSYS zxsi zxapp__main(
  zxInstance thisI,
  zxInstance prevI,
  LPSTR      args,
  int        showAs )
{
#if ZXMSW
  MSG    msg = {0};
  HACCEL  acc = NULL;
  size_t i = 0;
  zxWINDOW *root = NULL, *win;
  zxTBOX *tbox;
  zxWINDOWS *all = &zx_l_allWindows;
  zxEVTPTR ptr;
  zx_l_prevI = prevI;
  zx_l_thisI = thisI;
  zx_win._init( all, NULL, 0 );
  zxevt._init( &zx_l_events, NULL, 0 );
  for ( ; i < zxWIN_COUNT; ++i )
    zxwin._initWCX( &zxwin.WCX[ i ] );
  for ( i = 0; i < zxEVT_COUNT; ++i )
  {
    ptr.type = (zxEVT)i;
    ptr.proc = zxevt.events[ i ];
    zxevt.addEvent( &zx_l_events, ptr );
  }
  InitCommonControls();
#if 0
  th = CreateWindowEx( 0u, WC_EDIT, WC_EDIT, WS_OVERLAPPEDWINDOW, 0, 0, 640, 480, NULL, NULL, thisI, NULL );
  ShowWindow( th, SW_SHOW );
#else
  zxwin.WCX[ zxWIN_NULL  ].lpszClassName = WC_STATIC;
  zxwin.WCX[ zxWIN_FRAME ].lpszClassName = WC_STATIC;
  i = zxWIN_TBOX;
  zxwin.WCX[ i ].lpszClassName = WC_EDIT;
  zxwin.WCX[ i ].hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME);
  root = zxwin.opNew( NULL );
  zx_l_rootWindow = root;
  root->m_wcx = (zxWCX*)mnew( sizeof( zxWCX ), NULL );
  *root->m_wcx = zxwin.WCX[ zxWIN_NULL ];
  root->m_style = WS_OVERLAPPEDWINDOW;
  root->m_h     = 640;
  root->m_w     = 480;
  zxstr._initC( root->m_txt, args, 0 );
  zxwin.osOpNew( root );
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
  zxwin.osOpNew( win );
  ShowWindow( root->m_wh, showAs );
  UpdateWindow( root->m_wh );
  ShowWindow( win->m_wh,  showAs );
  UpdateWindow( win->m_wh );
#endif
  while (GetMessage(&msg, NULL, 0, 0))
  {
    if ( !IsDialogMessage( msg.hwnd, &msg ) &&
      !TranslateAccelerator( msg.hwnd, acc, &msg) )
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
  }
#if 0
  return 0;
#else
  return zxobj.freeAll( (int)msg.wParam );
#endif
#else
  return zxobj.freeAll( 0 );
#endif
}

/* DO NOT MODIFY */
ZXSYS zxEVENTS* zxEVENTS_getDefEvents( void )
{
  return &zx_l_events;
}

ZXSYS zxWINDOWS* zxWINDOW_allWindows( void )
{
  return &zx_l_allWindows;
}

ZXSYS zxWINDOW*  zxWINDOW_getRootWindow( void )
{
  return zx_l_rootWindow;
}
ZXSYS zxHwnd     zxWINDOW_getRootWH( void )
{
  return zx_l_rootWindow->m_wh;
}
ZXSYS zxInstance zxGetPrevI( void )
{
  return zx_l_prevI;
}
ZXSYS zxInstance zxGetThisI( void )
{
  return zx_l_thisI;
}
