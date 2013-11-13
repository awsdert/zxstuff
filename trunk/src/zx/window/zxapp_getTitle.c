#include <zx/app.h>
zxTEXT zx_l_appTitle = {0};
ZXSYS zxTEXT* zxapp_getTitle( void )
  { return &zx_l_appTitle; }
ZXSYS void zxapp_setTitle( zxch const *txt )
{
  zxstr._kill( &zx_l_appTitle );
  if ( !txt )
    return;
  zxstr._init( &zx_l_appTitle, txt, zxstr.len( txt ) );
}
