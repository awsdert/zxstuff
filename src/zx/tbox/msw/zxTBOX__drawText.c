#include <zx/tbox.h>
#if ZXMSW
bool zxTBOX__drawText( zxTBOX *tbox, bool setCaret )
{
  zxWINDOW *win = tbox->m_win;
  zxCOLOR  *clr = &win->m_bgc;
  zxWH      *wh = zxwh.byId( win->m_wid );
  zxTEXT  *text = &win->m_txt;
  zxRECT  cRect = {0},
          wRect = {0},
          fRect = {0},
          sRect = {0},
          lRect = {0};
  POINT      pt = {0};
  TEXTMETRIC tm = {0};
  HDC       hdc = GetDC( wh->wh );
  zxui i = 0, len = zxstr.size( text ), format =
    DT_EDITCONTROL | DT_LEFT | DT_NOPREFIX | DT_SINGLELINE | DT_VCENTER;
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
  FillRect( hdc, &wRect, CreateSolidBrush( RGB(  clr->r,  clr->g,  clr->b ) ) );
  SetTextColor( hdc, RGB( ~clr->r, ~clr->g, ~clr->b ) );
  /* Draw text & caret  */
  if ( len )
    DrawText( hdc, text->m_data, len, &wRect, format );
  if ( !len || tbox->m_fc >= tbox->m_lc )
  {
    if ( setCaret )
      SetCaretPos( ( tbox->m_fc * tm.tmAveCharWidth ) -
        ( pt.x >> 1 ), ( pt.y >> 1 ) );
    goto zxTBOX__drawText_return;
  }
  /* calculate first none selected characters */
  lRect = sRect = fRect = wRect;
  fRect.right = fRect.left;
  do fRect.right += tm.tmAveCharWidth;
  while ( i < tbox->m_fc && fRect.right < wRect.right );
  if ( i == tbox->m_fc )
    sRect.left = fRect.right;
  /* calculate seleceted characters */
  sRect.right = sRect.left;
  do sRect.right += tm.tmAveCharWidth;
  while ( i < tbox->m_lc && sRect.right < wRect.right );
  if ( i == tbox->m_lc )
    InvertRect( hdc, &sRect );
  /* Finish */
zxTBOX__drawText_return:
  InvalidateRect( wh->wh, &cRect, TRUE );
  ReleaseDC( wh->wh, hdc );
  return true;
}
bool zxTBOX__setCaret( zxTBOX *tbox )
{
  DWORD fc = tbox->m_fc, lc = tbox->m_lc;
  HWND  wh = zxwh.byId( tbox->m_win->m_wid )->wh;
  if ( !SendMessage( wh, EM_SETSEL, (WPARAM)fc, (LPARAM)fc ) )
    return false;
  return true;
}
bool zxTBOX__setText( zxTBOX *tbox )
{
  HWND  wh = zxwh.byId( tbox->m_win->m_wid )->wh;
  if ( !SetWindowText( wh, tbox->m_win->m_txt.m_data ) )
    return false;
  return zxTBOX__setCaret( tbox );
}
#endif
