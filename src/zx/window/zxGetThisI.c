#include <zx/window.h>

static zxInstance zx_l_prevI = NULL;
static zxInstance zx_l_thisI = NULL;

zxInstance zxGetPrevI( void ) { return zx_l_prevI; }
zxInstance zxGetThisI( void ) { return zx_l_thisI; }
void zx_SetPrevI( zxInstance i ) { zx_l_prevI = i; }
void zx_SetThisI( zxInstance i ) { zx_l_thisI = i; }
