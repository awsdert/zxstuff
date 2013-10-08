#include <zx/window.h>
zxTEXT zx_l_appTitle = zxstr.def;
ZXSYS_EXP zxTEXT const* zxGetAppTitle( void )
  { return &zx_l_appTitle; }
ZXSYS_EXP void zxSetAppTitle( zxTEXT const *txt )
{
  zxstr._kill( &zx_l_appTitle );
  if ( !txt )
    return;
  zxstr._init( &zx_l_appTitle, txt->m_text, txt->m_data.m_count );
}