#include <zx/tbox.h>
#if ZXMSW
bool zxTBOX__drawText( zxTBOX *tbox, bool setCaret )
{
  zxWINDOW *win = tbox->m_win;
  zxTEXT  *text = &tbox->m_text;
  RECT    cRect = {0},
           rect = {0};
  POINT      pt = {0};
  TEXTMETRIC tm = {0};
  HDC       hdc = GetDC( NULL );
  if ( !hdc )
    return false;
  GetWindowRect( win->m_wh, &rect );
  GetClientRect( win->m_wh, &cRect );
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
  FillRect( hdc, &rect, win->m_wcx->hbrBackground );
  /* TODO: zxTBOX__drawText(): provide selection support */
  ExtTextOut(
    hdc, rect.left, rect.top, ETO_CLIPPED, &rect,
    text->m_data, zxstr.size( text ), NULL );
  ReleaseDC( NULL, hdc );
  return true;
}
bool zxTBOX__setCaret( zxTBOX *tbox )
{
  DWORD fc = tbox->m_pos, lc = tbox->m_pos;
  HWND  wh = tbox->m_win->m_wh;
  if ( !SendMessage( wh, WM_SETTEXT, 0, (LPARAM)tbox->m_text.m_data ) ||
    !SendMessage( wh, EM_SETSEL, (WPARAM)fc, (LPARAM)lc ) ) return false;
  return true;
}
#endif