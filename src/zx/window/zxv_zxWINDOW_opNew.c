#include <zx/window.h>
ZXSYS_EXP zxWINDOW* zxv_zxWINDOW_opNew( void )
{
  return (zxWINDOW*)malloc( sizeof( zxWINDOW ) );
}
