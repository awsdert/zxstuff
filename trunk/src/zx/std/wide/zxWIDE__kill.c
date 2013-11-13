#include <zx/std/wide.h>
ZXCORE void zxWIDE__kill( zxWIDE *src )
{
  if ( !src )
    return;
  zxv._kill( &src->m_core );
  src->m_data = NULL;
}
