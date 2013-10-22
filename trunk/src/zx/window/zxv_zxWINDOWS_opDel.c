#include <zx/window.h>
ZXSYS_EXP zxWINDOW* zxv_zxWINDOW_opDel( zxWINDOW *win )
{
  free( win );
  return NULL;
}