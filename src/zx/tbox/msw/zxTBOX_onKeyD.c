#include <zx/tbox.h>
ZXEVENT( zxTBOX_onKeyD )
{
  zxWINDOW  *win  = zxwin.getWindow( event->m_wid );
  zxTBOX    *tbox = NULL;
  zxTEXT    *text = NULL;
#if ZXMSW
  SHORT scancode = VkKeyScanW( LOWORD( event->m_wp ) );
  CHAR vk = LOBYTE( scancode ), xk = HIBYTE( scancode );
  if ( !win || win->m_win != zxWIN_TBOX )
    return 0;
  tbox = (zxTBOX*)win->m_wObj.obj;
  text = &win->m_txt;
  switch ( vk )
  {
  case VK_DELETE:
    zxstr.erase( text, tbox->m_fc, tbox->m_lc );
    break;
  case VK_LEFT:
    if ( tbox->m_fc > 0u )
      --tbox->m_fc;
    if ( !( xk & VK_SHIFT ) )
      tbox->m_lc = tbox->m_fc;
    break;
  case VK_RIGHT:
    if ( tbox->m_lc < zxstr.size( text ) )
      ++tbox->m_lc;
    if ( !( xk & VK_SHIFT ) )
      tbox->m_fc = tbox->m_lc;
    break;
  default:
    return 0;
  }
  event->m_stopEvent = true;
  if ( !zxtbox._drawText( tbox, true ) )
    return 3;
#endif
  return 0;
}
