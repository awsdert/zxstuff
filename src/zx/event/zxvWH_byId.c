#include "zxwh.h"
zxWH* ZXSYS_CALL zxvWH_byId( zxui wid )
{
  return zxwh.at( zxwh.all(), wid );
}
