#include <zx/proc.h>
ZXSYS_EXP zxui zxo_zxPROC_newPH_w( zxPH* ph, DWORD access, BOOL inherit, zxWIDE const *name )
{
#if ZXMSW
  zxPE32 pe32 = {0};
  if ( !zxproc.getPE32_w( &pe32, name ) )
    return 0u;
  *ph = OpenProcess( access, inherit, pe32.th32ProcessID );
  if ( !(*ph) )
    return 0u;
  return 1u;
#else
  return 0;
#endif
}
