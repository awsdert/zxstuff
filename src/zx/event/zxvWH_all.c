#include "zxwh.h"
static zxvWH zx_l_allWH = {0};
zxvWH* ZXSYS_CALL zxvWH_all( void )
{
  return &zx_l_allWH;
}
