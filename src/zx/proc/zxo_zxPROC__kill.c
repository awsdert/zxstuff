#include <zx/proc.h>
ZXSYS_EXP void zxo_zxPROC__kill( zxPROC *proc )
{
  if ( !proc )
    return;
#if ZXMSW
  CloseHandle( proc->m_ph );
#endif
  *proc = zxproc.def;
}