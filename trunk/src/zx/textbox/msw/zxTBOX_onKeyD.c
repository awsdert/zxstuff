#include <zx/tbox.h>
ZXSYS_EXP zxEvtCBR zxTBOX_onKeyD( zxEVENT* event )
{
  zxWINDOW  *win  = zxwin.getWindow( event->m_wid ), *base;
  zxTBOX *tbox = NULL;
  zxTEXT    *text = NULL;
#if ZXMSW
  WORD vk = LOWORD( event->m_mswWP );
  if ( win->m_win != zxWIN_TBOX )
    return zxDefWinEvt;
  tbox = (zxTBOX*)win;
  text = &tbox->m_text;
  switch ( vk )
  {
  case VK_DELETE:
    zxstr.erase( text, tbox->m_pos, tbox->m_pos + 1 );
    break;
  case VK_LEFT:
    if ( tbox->m_pos > 0u )
      --tbox->m_pos;
    return zxDefWinEvt;
  case VK_RIGHT:
    if ( tbox->m_pos < zxstr.size( text ) )
      ++tbox->m_pos;
    return zxDefWinEvt;
  case VK_TAB:
    base = zxwin.getWindow( win->m_base );
    if ( base )
      SetFocus( base->m_wh );
    return 0;
  default:
    return zxDefWinEvt;
  }
  if ( !zxtbox._drawText( tbox, true ) )
    return 3;
#endif
  return 0;
}
