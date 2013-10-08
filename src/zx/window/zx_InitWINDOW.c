#include <zx/window.h>
void zx_InitWINDOW( zxWINDOW *win )
{
  win->m_parent    = NULL;
  win->m_kids      = NULL;
  win->m_kidsCount = 0u;
  win->m_id        = 0u;
  win->m_x         = 0;
  win->m_y         = 0;
  win->m_w         = 0;
  win->m_h         = 0;
  /* System specific */
  win->m_hdl       = NULL;
  win->m_wc        = NULL;
  win->m_wcx       = NULL;
  win->m_onFocus   = NULL;
  win->m_onBlur    = NULL;
  win->m_onChar    = NULL;
  win->m_onKeyD    = NULL;
  win->m_onKeyP    = NULL;
  win->m_onKeyU    = NULL;
}
