#include "zxwh.h"
ZXSYS zxWH* ZXSYS_CALL zxvWH_byId( size_t wid )
{
  return zxwh.at( zxwh.all(), wid );
}
