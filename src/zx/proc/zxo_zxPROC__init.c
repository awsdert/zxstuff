#include <zx/proc.h>
ZXSYS_EXP bool zxo_zxPROC__init( zxPROC *proc, zxTEXT const *txt )
{
  if ( !proc )
    return false;
  *proc = zxproc.def;
  if ( txt )
    zxstr._init( &proc->m_name, txt->m_data, zxstr.size( txt ) );
#if ZXUNICODE
  return zxproc.getPE32_w( &proc->m_pe32, &proc->m_name ) > 0;
#else
  return zxproc.getPE32_c( &proc->m_pe32, &proc->m_name ) > 0;
#endif
}