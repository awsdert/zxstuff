#include "zxtbox.h"
ZXSYS zxTBOX* zxTBOX_opNew( zxWINDOW *win )
{
  zxTBOX *tbox = (zxTBOX*)mnew( sizeof( zxTBOX ), NULL );
  zxWH *wh = NULL;
  size_t i = 0;
  win   = zxwin.opNew( win );
  *win->m_wcx = zxwin.defWCX( zxWIN_TBOX );
  wh = zxwh.at( zxwh.all(), win->m_wid );
  tbox->m_win   = win;
  win->m_win    = zxWIN_TBOX;
  win->m_wObj.obj = tbox;
  if  ( !wh )
  {
    zxwin.opDel( win );
    return NULL;
  }
  wh->onEvent = zxTBOX_onEvent;
  return tbox;
}
