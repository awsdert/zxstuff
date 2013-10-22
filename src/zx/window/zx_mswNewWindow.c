#include <zx/window.h>
ZXSYS_EXP zxsi zx_mswNewWindow( zxWINDOW *win )
{
  zxWINDOW  *base = zxwin.getWindow( win->m_base );
  zxTEXT    *text = &win->m_title;
  zxHwnd    baseWH = NULL;
#if ZXMSW
#if 1
  win->m_style |= CS_VREDRAW | CS_HREDRAW;
#endif
  if ( base && base != win )
  {
    win->m_style |= WS_CHILD;
    baseWH = base->m_wh;
  }
  if ( win->m_stylex )
  {
    if ( !win->m_wcx )
    {
      switch ( win->m_win )
      {
      case zxWIN_COUNT:
        if ( !win->m_wc )
          return 1;
        break;
      case zxWIN_NULL:
        win->m_wcx          = &zxwin.WCX[ win->m_win ];
        win->m_wcx->hIcon   = LoadIcon( NULL, IDI_APPLICATION );
        win->m_wcx->hIconSm = LoadIcon( NULL, IDI_APPLICATION );
        break;
      default:
        win->m_wcx          = &zxwin.WCX[ win->m_win ];
      }
    }
    win->m_wcx->hInstance = zxGetThisI();
    if ( !zxwin.mswATOMX[ win->m_win ] )
      zxwin.mswATOMX[ win->m_win ] = RegisterClassEx( win->m_wcx );
    if ( !zxwin.mswATOMX[ win->m_win ] )
      return 1;
    win->m_wh = CreateWindowEx( win->m_stylex,
      win->m_wcx->lpszClassName, text->m_data, win->m_style,
      win->m_x, win->m_y, win->m_w, win->m_h,
      baseWH, (HMENU)win->m_wid,
      win->m_wcx->hInstance, NULL );
  }
  else
  {
    if ( !win->m_wc )
    {
      switch ( win->m_win )
      {
      case zxWIN_COUNT:
        if ( !win->m_wc )
          return 1;
        break;
      case zxWIN_NULL:
        win->m_wc           = &zxwin.WC[ win->m_win ];
        win->m_wc->hIcon    = LoadIcon( NULL, IDI_APPLICATION );
        break;
      default:
        win->m_wc  = &zxwin.WC[ win->m_win ];
      }
    }
    win->m_wc->hInstance  = zxGetThisI();
    if ( !zxwin.mswATOM[ win->m_win ] )
      zxwin.mswATOM[ win->m_win ] = RegisterClass( win->m_wc );
    if ( !zxwin.mswATOM[ win->m_win ] )
      return 1;
    win->m_wh = CreateWindow(
      win->m_wc->lpszClassName, text->m_data, win->m_style,
      win->m_x, win->m_y, win->m_w, win->m_h,
      baseWH, (HMENU)win->m_wid,
      win->m_wc->hInstance, NULL );
  }
  if ( !win->m_wh )
    return 2;
#endif
  return 0;
}
