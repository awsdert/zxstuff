#include <zx/window.h>

zxWINDOW   zx_l_rootWindow = {0};
zxVECTOR   zx_l_allWindows = {0};
zxInstance zx_l_prevI = NULL, zx_l_thisI = NULL;

ZXSYS_EXP zxsi zxmain(
  zxHandle   rootWH,
  zxInstance prevI,
  zxInstance thisI,
  zxTEXT     *args )
{
  zxWINDOW *root = &zx_l_rootWindow;
  root->m_core = (zxoWINDOW*)mnew( sizeof( zxoWINDOW ), NULL );
  root->m_core->m_hdl = rootWH;
  zx_l_prevI = prevI;
  zx_l_thisI = thisI;
  zxv._init( &zx_l_allWindows, sizeof( zxWINDOW* ), NULL, 0 );
  zxv.grow(  &zx_l_allWindows, 1, (zxuc*)&zx_l_rootWindow );
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
ZXSYS zxWINDOW*        zxo_zxWINDOW_byId( size_t id )
{
  zxWINDOW** ary = zx_l_allWindows.m_data;
  if ( id < zx_l_allWindows.m_count )
    return ary[ id ];
  return (zxWINDOW*)0;
}
ZXSYS zxWINDOW*        zxo_zxWINDOW_byHandle( zxHandle );
ZXSYS_EXP zxWINDOW* zxNewWindow( zxoWINDOW* core )
{
  zxWINDOW*  win = NULL;
  zxWINDOW** ary = (zxWINDOW**)zx_l_allWindows.m_data;
  size_t i = 0, stop = zx_l_allWindows.m_count;
  if ( core )
    return win;
  if ( core->m_id )
  {
    i = core->m_id;
    if ( i < stop && ary[ i ] )
      return win;
  }
  else
  {
    for ( ; i < stop; ++i )
    {
      if ( !ary[ i ] )
        break;
    }
  }
  if ( i >= stop )
  {
    if ( i >= SSIZE_MAX )
      return win;
    zxv.grow( &zx_l_allWindows, i + 1, NULL );
    ary = (zxWINDOW**)zx_l_allWindows.m_data;
  }
  win = (zxWINDOW*)malloc( sizeof( zxWINDOW ) );
  core->m_id  = i;
  win->m_core = core;
  ary[ i ]    = win;
  return win;
}

ZXSYS_EXP zxWINDOW* zxDelWindow( zxWINDOW* win, bool delKids )
{
  zxWINDOW* nw = (zxWINDOW*)0;
  zxWINDOW** ary = zx_l_allWindows.m_data, kids;
  size_t i = 0, stop;
  if ( !win )
    return nw;
  ary[ win->m_core->m_id ] = nw;
  if ( delKids )
  {
    kids = (zxWINDOW**)win->m_kids.m_data;
    stop = win->m_kids.m_count;
    for ( ; i < stop; ++i )
      zxDelWindow( kids[ i ], true );
  }
  ZXFREE( win->m_core );
  return nw;
}

ZXSYS_EXP zxVECTOR*  const zxGetAllWindows( void )
{
  return &zx_l_allWindows;
}

ZXSYS_EXP zxWINDOW*  const zxGetRootWindow( void )
{
  return &zx_l_rootWindow;
}
ZXSYS_EXP zxHandle         zxGetRootWH( void )
{
  return zx_l_rootWindow.m_core->m_hdl;
}
ZXSYS_EXP zxInstance       zxGetPrevI( void )
{
  return zx_l_prevI;
}
ZXSYS_EXP zxInstance       zxGetThisI( void )
{
  return zx_l_thisI;
}