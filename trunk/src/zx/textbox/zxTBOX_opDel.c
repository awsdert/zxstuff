#include <zx/tbox.h>
ZXSYS_EXP void zxTBOX_opDel( void* winObj )
{
  zxTBOX* tbox = (zxTBOX*)winObj;
  if ( !winObj || !zxwin.isKnown( tbox->m_win ) ||
    tbox->m_win->m_winObj != winObj )
    return;
  /* The above simply defends against invald objects */
  free( tbox );
}