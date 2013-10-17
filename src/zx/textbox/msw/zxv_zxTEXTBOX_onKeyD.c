#include <zx/textbox.h>
ZXSYS_EXP zxEvtCBR zxv_zxTEXTBOX_onKeyD( zxEVENT* event )
{
  zxWINDOW  *win  = zxwin.getWindow( event->m_wid );
  zxTEXTBOX *tbox = NULL;
  zxTEXT    *text = NULL;
#if ZXMSW
  WORD vk = LOWORD( event->m_mswWP );
  if ( win->m_win != zxWIN_TEXTBOX )
    return zxDefWinEvt;
  tbox = (zxTEXTBOX*)win;
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
    SetFocus( win->m_base->m_wh );
    return 0;
  default:
    return zxDefWinEvt;
  }
  if ( !zx_TEXTBOX_DrawText( tbox, true ) )
    return 3;
#endif
  return 0;
}
