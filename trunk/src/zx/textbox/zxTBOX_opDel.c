#include <zx/tbox.h>
ZXSYS_EXP void zxTBOX_opDel( void* wObj, size_t type )
{
  if ( type == zxWIN_TBOX )
    free( wObj );
}