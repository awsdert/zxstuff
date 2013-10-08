#include <zx/textbox.h>
zxEvtCBR zxTEXTBOX__OnKeyD( zxWINDOW* win, zxEVENT* event )
{
#if ZXMSW
/* TODO: check for application's event handler */
  zxTEXTBOX *tbox = NULL;
  zxTEXT    *text = NULL;
  WORD vk = LOWORD( event->mswWP );
  if ( win->m_winType != zxWIN_TEXTBOX )
    return zxDefWinEvt;
  tbox = (zxTEXTBOX*)win;
  text = &tbox->m_text;
  switch ( vk )
  {
  case VK_DELETE:
    if ( tbox->m_pos < text->m_len )
    {
      text->m_len = zxstr.Rem( text->m_text,
        tbox->m_pos, 1u, text->m_len );
    }
    break;
  case VK_LEFT:
    if ( tbox->m_pos > 0u )
      --tbox->m_pos;
    return zxDefWinEvt;
  case VK_RIGHT:
    if ( tbox->m_pos < ( text->m_len - 1u ) )
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
