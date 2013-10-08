#include <zx/window.h>
zxuint zx_l_windowsCount = 0u;
ZXSYS_EXP zxuint zxGetWindowCount( void ) { return zx_l_windowsCount; }
ZXSYS_EXP void zx_SetWindowCount( zxuint newCount ) { zx_l_windowsCount = newCount; }