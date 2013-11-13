#include <zx/proc.h>
ZXSYS zxui zxo_zxPROC_newPHId( zxPH* ph, DWORD access, BOOL inherit, zxPID pid )
{
#if ZXMSW
  if ( !ph )
    return 0u;
  *ph = OpenProcess( access, inherit, pid );
  if ( !(*ph) )
    return 0u;
  return 1u;
#else
  return 0;
#endif
}
