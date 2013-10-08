#include <zx/proc.h>
ZXSYS_EXP zxui zxo_zxPROC_newPH_c( zxPH* ph, DWORD access, BOOL inherit, zxCHAR const *name )
{
#if ZXMSW
  zxPE32 pe32 = {0};
  if ( !ph || !zxproc.getPE32_c( &pe32, name ) )
    return 0u;
  *ph = OpenProcess( access, inherit, pe32.th32ProcessID );
  if ( !(*ph) )
    return 0u;
  return 1u;
#else
  return 0;
#endif
}
