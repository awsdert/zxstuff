#include <zx/window.h>

zxWINDOW   zx_l_rootWindow = {0};
zxVECTOR   zx_l_allWindows = {0};
zxInstance zx_l_prevI = NULL, zx_l_thisI = NULL;

ZXSYS_EXP int zxapp_main(
  zxHandle   rootWH,
  zxInstance prevI,
  zxInstance thisI,
  zxTEXT     *args )
{
  size_t i = 0, stop = zxWIN_COUNT;
  zxWINDOW *root = &zx_l_rootWindow;
  root->m_core = (zxoWINDOW*)mnew( sizeof( zxoWINDOW ), NULL );
  root->m_core->m_hdl = rootWH;
  zx_l_prevI = prevI;
  zx_l_thisI = thisI;
  zxv._init( &zx_l_allWindows, sizeof( zxWINDOW* ), NULL, 0 );
  zxv.grow(  &zx_l_allWindows, 1, (zxuc*)&zx_l_rootWindow );
  for ( ; i < stop; ++i )
  {
    zxwin._initWC(  &zxwin.WC[  i ] );
    zxwin._initWCX( &zxwin.WCX[ i ] );
  }
#if ZXMSW
  i = zxWIN_NULL;
  zxwin.WC[  i ].lpszClassName = ZXT("ZXWINDOW");
  zxwin.WCX[ i ].lpszClassName = ZXT("ZXWINDOW");
  i = zxWIN_FRAME;
  zxwin.WC[  i ].lpszClassName = ZXT("ZXFRAME");
  zxwin.WCX[ i ].lpszClassName = ZXT("ZXFRAME");
  i = zxWIN_TEXTBOX;
  zxwin.WC[  i ].lpszClassName = ZXT("EDIT");
  zxwin.WC[  i ].hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME);
  zxwin.WCX[ i ].lpszClassName = ZXT("EDIT");
  zxwin.WCX[ i ].hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME);
#endif
  return zxFreeWindows( 0 );
}

ZXSYS_EXP zxWINDOW* zxNewWindow( zxWINDOW *parent )
{
  zxWINDOW  *kid  = (zxWINDOW*)mnew( sizeof( zxWINDOW ), NULL );
  if ( !parent )
    parent = &zx_l_rootWindow;
  kid->m_base = parent;
  /* Modify from here */
#if ZXMSW
  zx_mswNewWindow( kid, 0, 0 );
#endif
}

/* DO NOT MODIFY */

ZXSYS_EXP zxVECTOR* zxv_zxWINDOW_allWindows( void )
{
  return &zx_l_allWindows;
}

ZXSYS_EXP zxWINDOW*  const zxGetRootWindow( void )
{
  return &zx_l_rootWindow;
}
ZXSYS_EXP zxHandle   zxGetRootWH( void )
{
  return zx_l_rootWindow.m_core->m_hdl;
}
ZXSYS_EXP zxInstance zxGetPrevI( void )
{
  return zx_l_prevI;
}
ZXSYS_EXP zxInstance zxGetThisI( void )
{
  return zx_l_thisI;
}