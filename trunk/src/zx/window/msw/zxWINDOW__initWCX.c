#include <zx/window.h>
ZXSYS void zxWINDOW__initWCX( zxWCX *wcx )
{
  *wcx = zxwin.defWCX(0);
}
