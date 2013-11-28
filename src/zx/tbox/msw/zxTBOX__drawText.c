#include <zx/tbox.h>
#if ZXMSW
bool zxTBOX__drawText( zxTBOX *tbox, bool setCaret )
{
  zxWINDOW *win = tbox->m_win;
  zxCOLOR  *clr = &win->m_bgc;
  zxWH      *wh = zxwh.byId( win->m_wid );
  zxTEXT  *text = &win->m_txt;
  RECT    cRect = {0},
          wRect = {0},
          fRect = {0},
          sRect = {0},
          lRect = {0};
  POINT      pt = {0};
  TEXTMETRIC tm = {0};
  COLORREF  bgc = RGB(  clr->r,  clr->g,  clr->b ),
            fgc = RGB( ~clr->r, ~clr->g, ~clr->b );
  HBRUSH    bgh = CreateSolidBrush( bgc ),
            fgh = CreateSolidBrush( fgc );
  HDC       hdc = GetDC( wh->wh );
  size_t i = 0, len = zxstr.size( text );
  if ( !hdc )
    return false;
  GetTextMetrics( hdc, &tm );
  GetWindowRect( wh->wh, &wRect );
  GetClientRect( wh->wh, &cRect );
  pt.x = ( wRect.right - wRect.left ) - cRect.right;
  pt.y = ( wRect.bottom - wRect.top ) - cRect.bottom;
  wRect.left   += pt.x;
  wRect.right  -= pt.x;
  wRect.top    += pt.y;
  wRect.bottom -= pt.y;
  FillRect( hdc, &wRect, win->m_wcx->hbrBackground );
  if ( tbox->m_fc == tbox->m_lc )
  {
    ExtTextOut(
      hdc, wRect.left, wRect.top, ETO_CLIPPED, &wRect,
      text->m_data, zxstr.size( text ), NULL );
    if ( setCaret )
      SetCaretPos( ( tbox->m_fc * tm.tmAveCharWidth ) -
        ( pt.x >> 1 ), ( pt.y >> 1 ) );
    ReleaseDC( wh->wh, hdc );
    return true;
  }
  lRect = sRect = fRect = wRect;
  for
  (
    fRect.right = fRect.left;
    i < tbox->m_fc && fRect.right < wRect.right;
    fRect.right += tm.tmAveCharWidth
  );
  if ( i == tbox->m_fc )
  {
    sRect.left = fRect.right;
    ExtTextOut(
      hdc, wRect.left, wRect.top, ETO_CLIPPED, &fRect,
      text->m_data, tbox->m_fc, NULL );
  }
  for
  (
    sRect.right = sRect.left;
    i < tbox->m_lc && sRect.right < wRect.right;
    sRect.right += tm.tmAveCharWidth
  );
  if ( i == tbox->m_lc )
  {
    lRect.left = sRect.right;
    ExtTextOut(
      hdc, sRect.left, sRect.top, ETO_CLIPPED, &sRect,
      &text->m_data[ tbox->m_fc ], tbox->m_lc - tbox->m_fc, NULL );
  }
  for
  (
    lRect.right = lRect.left;
    i < len && lRect.right < wRect.right;
    lRect.right += tm.tmAveCharWidth
  );
  if ( i == len )
    ExtTextOut(
      hdc, lRect.left, lRect.top, ETO_CLIPPED, &lRect,
      text->m_data, zxstr.size(text) - tbox->m_lc, NULL );
  ReleaseDC( wh->wh, hdc );
  return true;
}
bool zxTBOX__setCaret( zxTBOX *tbox )
{
  DWORD fc = tbox->m_fc, lc = tbox->m_lc;
  HWND  wh = zxwh.byId( tbox->m_win->m_wid )->wh;
  if ( !SendMessage( wh, WM_SETTEXT, 0, (LPARAM)tbox->m_win->m_txt.m_data ) ||
    !SendMessage( wh, EM_SETSEL, (WPARAM)fc, (LPARAM)lc ) ) return false;
  return true;
}
#endif
