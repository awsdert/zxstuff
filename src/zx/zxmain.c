#include "tbox/zxtbox.h"

static zxWINDOW*  zx_l_rootWindow = NULL;
static zxInstance zx_l_prevI = NULL, zx_l_thisI = NULL;

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
  size_t i = 0;
  zxWINDOW *root = NULL, *win;
  zxWH *wh = NULL;
  zxTBOX *tbox;
  zxTEXT  txtArgs;
  zxWCX wcx = {0};
  zxvOBJ *all = zxobj.all();
  zxEVT ptr = {0};
  zx_l_prevI = prevI;
  zx_l_thisI = thisI;
  /* Init */
  InitCommonControls();
  zxobj._init( all, NULL, 0 );
  zxwh._init( zxwh.all(), NULL, 0 );
    /* WCX */
  wcx = zxwin.defWCX( zxWIN_NULL );
  RegisterClassEx( &wcx );
  wcx = zxwin.defWCX( zxWIN_TBOX );
  RegisterClassEx( &wcx );
  /* Root */
  root = zxwin.opNew( NULL );
  root->m_style = WS_OVERLAPPEDWINDOW;
  root->m_h     = 640;
  root->m_w     = 480;
  root->m_bgc.r = 0x99;
  root->m_bgc.g = 0x99;
  root->m_bgc.b = 0x99;
  zxstr._initC( &txtArgs, args, 0 );
  zxstr.append( &root->m_txt, &txtArgs, 0 );
  zxstr._kill( &txtArgs );
  zx_l_rootWindow = root;
  zxwin.osOpNew( root );
  zxwin.show(    root );
  zxwin.update(  root );
  /* Tbox */
  tbox = zxtbox.opNew( NULL );
  win  = tbox->m_win;
  zxwin.setBase( win, root );
  win->m_x = 5;
  win->m_y = 5;
  win->m_h = 30;
  win->m_w = 100;
  win->m_bgc.r = 0xFF;
  win->m_bgc.g = 0xFF;
  win->m_bgc.b = 0xFF;
  win->m_stylex = WS_EX_CLIENTEDGE;
  zxwin.osOpNew( win  );
  zxwin.show(    win  );
  zxwin.update(  win  );
  GetMessage(&msg, msg.hwnd, 0, 0);
  do
  {
    TranslateMessage( &msg );
    DispatchMessage(  &msg );
  }
  while( GetMessage(&msg, msg.hwnd, 0, 0) );
  return zxwin.freeAll( 0 );
#else
  return 0;
#endif
}

/* DO NOT MODIFY */
ZXSYS bool zxWINDOW_show( zxWINDOW *win )
{
  zxWH *wh;
  ZXASSERT( !win ) return false;
  wh = zxwh.byId( win->m_wid );
  if ( !wh->wh ) return false;
  return ShowWindow( wh->wh, SW_SHOW );
}
ZXSYS bool zxWINDOW_hide( zxWINDOW *win )
{
  zxWH *wh;
  ZXASSERT( !win ) return false;
  wh = zxwh.byId( win->m_wid );
  if ( !wh->wh ) return false;
  return ShowWindow( wh->wh, SW_HIDE );
}
ZXSYS bool zxWINDOW_update( zxWINDOW *win )
{
  zxWH *wh;
  ZXASSERT( !win ) return false;
  wh = zxwh.byId( win->m_wid );
  if ( !wh->wh ) return false;
  UpdateWindow( wh->wh );
  if ( IsWindowVisible( wh->wh ) )
  {
    GetClientRect( wh->wh, &win->m_cRect );
    GetClientRect( wh->wh, &win->m_wRect );
    return true;
  }
  win->m_wRect = zxwin.defRECT;
  win->m_cRect = zxwin.defRECT;
  return true;
}

ZXSYS zxWINDOW*  zxWINDOW__fromPoint( zxWINDOW* win, zxPOINT pt,
  zxus maxDepth, zxus depth )
{
  zxWINDOW *kid = NULL;
  zxvUI   *kids = &win->m_kids;
  zxRECT   rect = win->m_cRect;
  zxui i = 0, stop;
  if ( depth < maxDepth )
  {
    stop = zxv_ui.size( kids );
    for ( ; i < stop; ++i )
    {
      kid = zxwin.getWindow( kids->m_data[ i ] );
      kid = zxWINDOW__fromPoint( kid, pt, maxDepth, depth + 1 );
      if ( kid )
        return kid;
    }
  }
  if ( pt.x < rect.left || pt.x > rect.right ||
     pt.y < rect.top || pt.y > rect.bottom )
    return NULL;
  return win;
}

ZXSYS zxWINDOW*  zxWINDOW_fromPoint( zxPOINT pt, zxus maxDepth )
{
  zxOBJ   obj;
  zxvOBJ *all = zxobj.all();
  zxWINDOW *win = NULL, *kid = NULL;
  zxRECT rect;
  size_t i = 0, stop = zxobj.size( all );
  for ( ; i < stop; ++i )
  {
    obj = all->m_data[ i ];
    if ( obj.type == zxOBJ_SYS_WIN )
    {
      win = (zxWINDOW*)obj.obj;
      rect = win->m_cRect;
      if ( pt.x < rect.left || pt.x > rect.right ||
        pt.y < rect.top || pt.y > rect.bottom )
        continue;
      if ( maxDepth )
        kid = zxWINDOW__fromPoint( win, pt, maxDepth, 1 );
      if ( kid )
        win = kid;
      return win;
    }
  }
  return NULL;
}

ZXSYS zxWINDOW*  zxWINDOW_getRootWindow( void )
{
  return zx_l_rootWindow;
}
ZXSYS zxHwnd     zxWINDOW_getRootWH( void )
{
  return zxwh.byId( zx_l_rootWindow->m_wid )->wh;
}
ZXSYS zxInstance zxGetPrevI( void )
{
  return zx_l_prevI;
}
ZXSYS zxInstance zxGetThisI( void )
{
  return zx_l_thisI;
}
