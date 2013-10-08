#include <zx/proc.h>
ZXSYS_EXP bool zxo_zxPROC_isVisible( zxPID const pid, zxui* err )
{
#if ZXMSW
  zx___PID ptr = {0,0,0};
  if ( err )
    *err = 0u;
  ptr.pid = pid;
  if ( EnumWindows( zx___enumWindowsIsVisible, (LPARAM)&ptr ) )
  {
    if ( ptr.done )
    {
      if ( ptr.err )
        return true;
      else if ( err )
        *err = 2u;
    }
    else if ( err )
      *err = 1u;
  }
  return false;
#else
  return false;
#endif
}