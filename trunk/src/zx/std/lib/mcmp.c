/* USER: Lee DATE: 04/11/2013; TIME: 06:30 */
#include <zx/std/lib.h>
ZXCORE bool mcmp(
    void const *src,
    void const *cmp,
    size_t size,
    size_t *I )
{
    zxuc const
        *SRC = (zxuc const*)src,
        *CMP = (zxuc const*)cmp;
    size_t i = size - 1;
    if ( src == cmp )
    {
        if ( I )
            *I = i;
        return true;
    }
    if ( !cmp )
    {
        for ( ; i < size; --i, --size )
        {
            if ( SRC[ i ] != 0u )
                break;
        }
    }
    else
    {
       for ( ; i < size; --i, --size )
       {
           if ( SRC[ i ] == CMP[ i ] )
               break;
       }
    }
    if ( I )
        *I = i;
    if ( size )
        return false;
    return true;
}
