#include <zx/window.h>
int zx_NewWindow( zxTEXT *txt, zxWINDOW *kid, zxul style, zxul ext )
{
#if ZXMSW
  zxHandle   parent = NULL;
  if ( !kid )
    return 1;
#if 1
  style |= CS_VREDRAW | CS_HREDRAW;
#endif
  if ( kid->m_parent )
  {
    parent = kid->m_parent->m_hdl;
    style |= WS_CHILD;
  }
  if ( ext )
  {
    switch ( kid->m_winType )
    {
    case zxWIN_COUNT:
      if ( !kid->m_wc )
        return 1;
      break;
    case zxWIN_NULL:
      kid->m_wcx          = &zx_WCX[ kid->m_winType ];
      kid->m_wcx->hIcon   = LoadIcon( NULL, IDI_APPLICATION );
      kid->m_wcx->hIconSm = LoadIcon( NULL, IDI_APPLICATION );
      break;
    default:
      kid->m_wcx          = &zx_WCX[ kid->m_winType ];
    }
    kid->m_wcx->hInstance = zxGetThisI();
    if ( !zx_mswATOMX[ kid->m_winType ] )
      zx_mswATOMX[ kid->m_winType ] = RegisterClassEx( kid->m_wcx );
    if ( !zx_mswATOMX[ kid->m_winType ] )
      return 1;
    kid->m_hdl = CreateWindowEx( ext, kid->m_wcx->lpszClassName,
      txt->m_text, style, kid->m_x, kid->m_y, kid->m_w, kid->m_h,
      parent, (HMENU)kid->m_id, kid->m_wcx->hInstance, NULL );
  }
  else
  {
    switch ( kid->m_winType )
    {
    case zxWIN_COUNT:
      if ( !kid->m_wc )
        return 1;
      break;
    case zxWIN_NULL:
      kid->m_wc           = &zx_WC[ kid->m_winType ];
      kid->m_wc->hIcon    = LoadIcon( NULL, IDI_APPLICATION );
      break;
    default:
      kid->m_wc  = &zx_WC[ kid->m_winType ];
    }
    kid->m_wc->hInstance  = zxGetThisI();
    if ( !zx_mswATOM[ kid->m_winType ] )
      zx_mswATOM[  kid->m_winType ] = RegisterClass(   kid->m_wc );
    if ( !zx_mswATOM[ kid->m_winType ] )
      return 1;
    kid->m_hdl = CreateWindow( kid->m_wc->lpszClassName,
      txt->m_text, style, kid->m_x, kid->m_y, kid->m_w, kid->m_h,
      parent, (HMENU)kid->m_id, kid->m_wc->hInstance, NULL );
  }
  if ( !kid->m_hdl )
    return 2;
#endif
  return 0;
}
