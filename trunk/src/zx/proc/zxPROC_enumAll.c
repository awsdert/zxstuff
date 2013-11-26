#include <zx/proc.h>
ZXSYS zxui zxo_zxPROC_enumAll( zxPROC **plist, bool visibleOnly )
{
#if ZXMSW
  HANDLE shot = NULL;
  zxPE32 pe32 = {0};
  zxui i = 0u, j = 0u, len = 0u;
  zxPROC* pl = NULL;
  zxVECTOR plv = zxv.def;
  ZXASSERT( !plist )
    return 0;
  *plist = NULL;
  shot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
  if ( !shot )
    return 0;
  pe32.dwSize = sizeof( zxPE32 );
  if ( Process32First( shot, &pe32 ) )
  {
    do ++len;
    while ( Process32Next( shot, &pe32 ) );
    plv.m_Tsize = sizeof( zxPROC );
    zxv.grow( &plv, len, NULL );
    if ( plv.m_data )
      return 0;
    pl = (zxPROC*)plv.m_data;
    if ( plv.m_count != len )
    {
      free( pl );
      return 0;
    }
    pl[ 0 ].m_pe32.dwSize = pe32.dwSize;
    if ( !Process32First( shot, &pl[ 0 ].m_pe32 ) )
    {
      free( pl );
      return 0u;
    }
    *plist = pl;
    if ( !visibleOnly )
    {
      do
      {
        zxstr._init( &pl[ j ].m_name, pl[ j ].m_pe32.szExeFile, 0 );
        ++i; ++j;
      }
      while ( i < len &&
        ( pl[ j ].m_pe32.dwSize = pe32.dwSize ) &&
        Process32Next( shot, &pl[ j ].m_pe32 ) );
    }
    else
    {
      do
      {
        if ( zxproc.isVisible( pl[ j ].m_pe32.th32ProcessID, NULL ) )
        {
          zxstr._init( &pl[ j ].m_name, pl[ j ].m_pe32.szExeFile, 0 );
          ++j;
        }
        ++i;
      }
      while ( i < len &&
        ( pl[ j ].m_pe32.dwSize = pe32.dwSize ) &&
        Process32Next( shot, &pl[ j ].m_pe32 ) );
    }
  }
  CloseHandle( shot );
  return j;
#else
  return 0u;
#endif
}
