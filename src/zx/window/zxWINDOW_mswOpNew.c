#include <zx/window.h>
#if ZXMSW
ZXSYS_EXP zxsi zxWINDOW_mswOpNew( zxWINDOW *win )
{
  zxWINDOW  *base = zxwin.getWindow( win->m_base );
  zxTEXT    *text = &win->m_title;
  zxHwnd    baseWH = NULL;
  win->m_style |= CS_VREDRAW | CS_HREDRAW;
  if ( base && base != win )
  {
    win->m_style |= WS_CHILD;
    baseWH = base->m_wh;
  }
  if ( !win->m_wcx )
  {
    switch ( win->m_win )
    {
    case zxWIN_COUNT:
      if ( !win->m_wcx )
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
  if ( !win->m_wh )
    return 2;
  return 0;
}
#endif
