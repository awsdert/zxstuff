#include <zx/proc.h>
ZXSYS_EXP BOOL ZXCB zx___enumWindowsIsVisible( HWND wh, LPARAM lp )
{
#if ZXMSW
  zxPID pid = 0u;
  zx___PID *ptr = NULL;
  if ( !lp )
    return FALSE;
  ptr = (zx___PID*)lp;
  if ( !ptr->err )
  {
    GetWindowThreadProcessId( wh, &pid );
    if ( pid == ptr->pid )
    {
      if( IsWindowVisible( wh ) )
        ptr->err = 1u;
      ptr->done = 1u;
    }
  }
  return TRUE;
#else
  return FALSE;
#endif
}
