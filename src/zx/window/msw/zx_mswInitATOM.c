#include <zx/window.h>
void zx_mswInitATOM( void )
{
  int i = zxWIN_NULL, count = zxWIN_COUNT;
  for ( ; i < count; ++i )
  {
    zx_mswATOM[  i ] = 0u;
    zx_mswATOMX[ i ] = 0u;
  }
}