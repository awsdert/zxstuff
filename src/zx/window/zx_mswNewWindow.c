#include <zx/window.h>
int zx_mswNewWindow( zxWINDOW *kid, zxul style, zxul ext )
{
  zxWINDOW  *base = NULL;
  zxoWINDOW *core = NULL;
  zxTEXT    *text = &core->m_title;
  base = kid->m_base;
  core = kid->m_core;
#if ZXMSW
#if 1
  style |= CS_VREDRAW | CS_HREDRAW;
#endif
  if ( base )
    style |= WS_CHILD;
  if ( ext )
  {
    switch ( core->m_win )
    {
    case zxWIN_COUNT:
      if ( !core->m_wc )
        return 1;
      break;
    case zxWIN_NULL:
      core->m_wcx          = &zxwin.WCX[ core->m_win ];
      core->m_wcx->hIcon   = LoadIcon( NULL, IDI_APPLICATION );
      core->m_wcx->hIconSm = LoadIcon( NULL, IDI_APPLICATION );
      break;
    default:
      core->m_wcx          = &zxwin.WCX[ core->m_win ];
    }
    core->m_wcx->hInstance = zxGetThisI();
    if ( !zxwin.mswATOMX[ core->m_win ] )
      zxwin.mswATOMX[ core->m_win ] = RegisterClassEx( core->m_wcx );
    if ( !zxwin.mswATOMX[ core->m_win ] )
      return 1;
    core->m_hdl = CreateWindowEx( ext,
      core->m_wcx->lpszClassName, text->m_text, style,
      core->m_x, core->m_y, core->m_w, core->m_h,
      core->m_hdl, (HMENU)core->m_wid,
      core->m_wcx->hInstance, NULL );
  }
  else
  {
    switch ( core->m_win )
    {
    case zxWIN_COUNT:
      if ( !core->m_wc )
        return 1;
      break;
    case zxWIN_NULL:
      core->m_wc           = &zxwin.WC[ core->m_win ];
      core->m_wc->hIcon    = LoadIcon( NULL, IDI_APPLICATION );
      break;
    default:
      core->m_wc  = &zx_WC[ core->m_win ];
    }
    core->m_wc->hInstance  = zxGetThisI();
    if ( !zxwin.mswATOM[ core->m_win ] )
      zxwin.mswATOM[ core->m_win ] = RegisterClass( core->m_wc );
    if ( !zxwin.mswATOM[ core->m_win ] )
      return 1;
    core->m_hdl = CreateWindow(
      core->m_wc->lpszClassName, text->m_text, style,
      kid->m_x, kid->m_y, kid->m_w, kid->m_h,
      ore->m_hdl, (HMENU)core->m_wid,
      kid->m_wc->hInstance, NULL );
  }
  if ( !core->m_hdl )
    return 2;
#endif
  return 0;
}
