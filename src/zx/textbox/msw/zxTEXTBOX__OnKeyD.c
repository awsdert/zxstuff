#include <zx/textbox.h>
zxEvtCBR zxTEXTBOX__OnKeyD( zxWINDOW* win, zxEVENT* event )
{
#if ZXMSW
/* TODO: check for application's event handler */
  zxTEXTBOX *tbox = NULL;
  zxTEXT    *text = NULL;
  WORD vk = LOWORD( event->m_mswWP );
  if ( win->m_winType != zxWIN_TEXTBOX )
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
    SetFocus( win->m_parent->m_hdl );
    return 0;
  default:
    return zxDefWinEvt;
  }
  if ( !zx_TEXTBOX_DrawText( tbox, true ) )
    return 3;
#endif
  return 0;
}
