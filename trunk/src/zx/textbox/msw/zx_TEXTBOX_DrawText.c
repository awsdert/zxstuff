#include <zx/textbox.h>
#if ZXMSW
bool zx_TEXTBOX_DrawText( zxTEXTBOX *tbox, bool setCaret )
{
  zxWINDOW *win = &tbox->m_win;
  zxTEXT  *text = &tbox->m_text;
  RECT    cRect = {0},
           rect = {0};
  POINT      pt = {0};
  TEXTMETRIC tm = {0};
  HDC       hdc = GetDC( NULL );
  if ( !hdc )
    return false;
  GetWindowRect( win->m_hdl, &rect );
  GetClientRect( win->m_hdl, &cRect );
  pt.x = ( rect.right - rect.left ) - cRect.right;
  pt.y = ( rect.bottom - rect.top ) - cRect.bottom;
  rect.left   += pt.x;
  rect.right  -= pt.x;
  rect.top    += pt.y;
  rect.bottom -= pt.y;
  GetTextMetrics( hdc, &tm );
  if ( setCaret )
    SetCaretPos( ( tbox->m_pos * tm.tmAveCharWidth ) -
      ( pt.x >> 1 ), ( pt.y >> 1 ) );
  if ( win->m_wc )
    FillRect( hdc, &rect, win->m_wc->hbrBackground  );
  else
    FillRect( hdc, &rect, win->m_wcx->hbrBackground );
  /* TODO: zx__TEXTBOX_DrawText(): provide selection support */
  ExtTextOut(
    hdc, rect.left, rect.top, ETO_CLIPPED, &rect,
    text->m_text, zxstr.size( text ), NULL );
  ReleaseDC( NULL, hdc );
  return true;
}
#endif