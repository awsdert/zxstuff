#include <zx/proc.h>
ZXSYS zxui zxo_zxPROC_getPE32_c( zxPE32* pe32, zxCHAR const *name )
{
#if ZXMSW
  size_t i    = 0u, len;
  BOOL   got  = TRUE;
  HANDLE shot = NULL;
  if ( !name || !pe32 )
    return 0u;
  shot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
  if ( !shot )
    return 0u;
  len = zxc.size( name );
  if ( !len )
    len = zxc.len( name->m_data );
  if ( len > MAX_PATH )
    return 0u;
  pe32->dwSize = sizeof( zxPE32 );
  if ( Process32First( shot, pe32 ) )
  {
    do
    {
      for ( ; got && i < len; ++i )
        got = ( name->m_data[ i ] == pe32->szExeFile[ i ] );
      if ( got )
      {
        CloseHandle( shot );
        return 1u;
      }
      else
        got = TRUE;
    } while ( Process32Next( shot, pe32 ) );
  }
  CloseHandle( shot );
  return 0u;
#else
  return 0u;
#endif
}
