#include <zx/tbox.h>
ZXSYS zxsl zxTBOX_onKeyD( zxEVENT* event )
{
  zxWINDOW  *win  = zxwin.getWindow( event->m_obj.gid ), *base;
  zxTBOX *tbox = NULL;
  zxTEXT    *text = NULL;
#if ZXMSW
  WORD vk = LOWORD( event->m_mswWP );
  event->m_stopEvent = true;
  if ( win->m_win != zxWIN_TBOX )
    return 0;
  tbox = (zxTBOX*)win;
  text = win->m_txt;
  switch ( vk )
  {
  case VK_DELETE:
    zxstr.erase( text, tbox->m_pos, tbox->m_pos + 1 );
    break;
  case VK_LEFT:
    if ( tbox->m_pos > 0u )
      --tbox->m_pos;
    return 0;
  case VK_RIGHT:
    if ( tbox->m_pos < zxstr.size( text ) )
      ++tbox->m_pos;
    return 0;
  case VK_TAB:
    base = zxwin.getWindow( win->m_base );
    if ( base )
      SetFocus( base->m_wh );
    return 0;
  default:
    return 0;
  }
  if ( !zxtbox._setCaret( tbox ) )
    return 3;
#else
  event->m_stopEvent = true;
#endif
  return 0;
}
