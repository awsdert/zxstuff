#include <zx/window.h>
#if ZXMSW
ZXSYS zxsi zxWINDOW_osOpNew( zxWINDOW *win )
{
  zxWINDOW  *base = zxwin.getWindow( win->m_base );
  zxWH      *wh   = zxwh.at( zxwh.all(), win->m_wid );
  zxTEXT    *text = &win->m_txt;
  zxHwnd    baseWH = NULL;
  win->m_style |= CS_VREDRAW | CS_HREDRAW;
  if ( base && base != win )
  {
    win->m_style |= WS_CHILD;
    baseWH = zxwh.at( zxwh.all(), base->m_wid )->wh;
  }
  if ( !win->m_wcx )
    return 1;
  if ( text )
    wh->wh = CreateWindowEx( win->m_stylex,
      win->m_wcx->lpszClassName, text->m_data, win->m_style,
      win->m_x, win->m_y, win->m_w, win->m_h,
      baseWH, (HMENU)win->m_wid,
      win->m_wcx->hInstance, NULL );
  else
    wh->wh = CreateWindowEx( win->m_stylex,
      win->m_wcx->lpszClassName, ZXT(""), win->m_style,
      win->m_x, win->m_y, win->m_w, win->m_h,
      baseWH, (HMENU)win->m_wid,
      win->m_wcx->hInstance, NULL );
  if ( !wh->wh )
    return 2;
  return 0;
}
#endif
