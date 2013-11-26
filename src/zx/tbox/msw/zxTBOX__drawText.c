#include <zx/tbox.h>
#if ZXMSW
bool zxTBOX__drawText( zxTBOX *tbox, bool setCaret )
{
  zxWINDOW *win = tbox->m_win;
  zxTEXT  *text = &win->m_txt;
  zxWH *wh = zxwh.at( zxwh.all(), win->m_wid );
  RECT    cRect = {0}, wRect = {0},
            ltr = {0}, str = {0}, rtr = {0};
  POINT      pt = {0};
  TEXTMETRIC tm = {0};
  HDC       hdc = GetDC( NULL );
  HBRUSH    bgh, fgh;
  COLORREF  bgc, fgc;
  zxui pos = 0u;
  if ( !hdc )
    return false;
  GetClientRect( wh->wh, &cRect );
  GetWindowRect( wh->wh, &wRect );
  pt.x = ( wRect.right - wRect.left ) - cRect.right;
  pt.y = ( wRect.bottom - wRect.top ) - cRect.bottom;
  wRect.left   += pt.x;
  wRect.right  -= pt.x;
  wRect.top    += pt.y;
  wRect.bottom -= pt.y;
  GetTextMetrics( hdc, &tm );
  bgc = RGB(  win->m_bgc.r,  win->m_bgc.g,  win->m_bgc.b );
  fgc = RGB( ~win->m_bgc.r, ~win->m_bgc.g, ~win->m_bgc.b );
  bgh = CreateHatchBrush( 0, bgc );
  fgh = CreateHatchBrush( 0, fgc );
  if ( setCaret && tbox->m_fc == tbox->m_lc )
    SetCaretPos( ( tbox->m_fc * tm.tmAveCharWidth ) -
      ( pt.x >> 1 ), ( pt.y >> 1 ) );
  FillRect( hdc, &wRect, bgh );
  SetTextColor( hdc, fgc );
  /* TODO: zxTBOX__drawText(): provide selection support */
  ltr = wRect;
  ltr.right = ( tbox->m_fc * tm.tmAveCharWidth ) - ( pt.x >> 1 );
  if ( ltr.right > ltr.left && ltr.right <= wRect.right )
  {
    ExtTextOut(
      hdc, ltr.left, ltr.top, ETO_CLIPPED, &ltr,
      text->m_data, tbox->m_fc, NULL );
  }
  str       = wRect;
  str.left  = ltr.right;
  str.right = ( tbox->m_lc * tm.tmAveCharWidth ) - ( pt.x >> 1 );
  if ( str.right > str.left && str.right <= wRect.right )
  {
    FillRect( hdc, &str, fgh );
    SetTextColor( hdc, bgc );
    ExtTextOut(
      hdc, str.left, str.top, ETO_CLIPPED, &str,
      &text->m_data[ tbox->m_fc ], tbox->m_lc - tbox->m_fc, NULL );
  }
  rtr = wRect;
  rtr.left = str.right;
  if ( rtr.right > rtr.left && rtr.right <= wRect.right )
  {
    SetTextColor( hdc, fgc );
    ExtTextOut(
      hdc, rtr.left, rtr.top, ETO_CLIPPED, &rtr,
      &text->m_data[ tbox->m_lc ],
      zxstr.size( text ) - tbox->m_lc, NULL );
  }
  InvalidateRect( wh->wh, &wRect, true );
  ReleaseDC( NULL, hdc );
  return true;
}
bool zxTBOX__setCaret( zxTBOX *tbox )
{
  DWORD fc = tbox->m_fc, lc = tbox->m_lc;
  zxWH *wh = zxwh.at( zxwh.all(), tbox->m_win->m_wid );
  if ( !SendMessage( wh->wh, WM_SETTEXT, 0, (LPARAM)tbox->m_win->m_txt.m_data ) ||
    !SendMessage( wh->wh, EM_SETSEL, (WPARAM)fc, (LPARAM)lc ) ) return false;
  return true;
}
#endif
