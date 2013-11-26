#include <zx/proc.h>
ZXSYS bool zxo_zxPROC_getPE32Id( zxPE32* pe32, zxPID pid )
{
#if ZXMSW
  HANDLE shot = NULL;
  if ( !pe32 || !pid )
    return false;
  shot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
  if ( !shot )
    return false;
  pe32->dwSize = sizeof( zxPE32 );
  if ( Process32First( shot, pe32 ) )
  {
    do
    {
      if ( pid == pe32->th32ProcessID )
      {
        CloseHandle( shot );
        return true;
      }
    } while ( Process32Next( shot, pe32 ) );
  }
  CloseHandle( shot );
  return false;
#else
  return false;
#endif
}
