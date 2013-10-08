#include <zx/vli.h>
#if ZXCPP
zxVli::zxVli( void )
{
  *(zxVLI*)this = zxvli.def;
  m_vector.m_Tsize = sizeof( char );
}
zxVli::zxVli( char val )
{
  *(zxVLI*)this = zxvli.def;
  m_vector.m_Tsize = sizeof( char );
  if ( val >= '0' && val <= '9' )
    val -= '0';
  else
    val = 0u;
  zxv.grow( &m_vector, 1, (zxuc*)&val );
  m_bits          = CHAR_BIT;
  m_lastBit       = zxCHAR_LAST;
  m_lastByte      = 0;
  m_isSigned      = true;
}
zxVli::zxVli( zxuc const val )
{
  *(zxVLI*)this = zxvli.def;
  m_vector.m_Tsize = sizeof( char );
  zxv.grow( &m_vector, 1, &val );
  m_bits          = CHAR_BIT;
  m_lastBit       = zxCHAR_LAST;
  m_lastByte      = 0;
  m_isSigned      = false;
}
zxVli::zxVli( zxsc const val )
{
  *(zxVLI*)this = zxvli.def;
  m_vector.m_Tsize = sizeof( char );
  zxv.grow( &m_vector, 1, (zxuc*)&val );
  m_bits          = CHAR_BIT;
  m_lastBit       = zxCHAR_LAST;
  m_lastByte      = 0;
  m_isSigned      = true;
}
zxVli::zxVli( zxus const val )
{
  zxVECTOR src    = zxv.def;
  size_t   tmp    = 0;
  src.m_Tsize     = sizeof( char );
  src.m_data      = (zxuc*)&val;
  src.m_size      = sizeof( short );
  src.m_fullSize  = src.m_size;
  src.m_count     = zxc_size_udiv( src.m_size, src.m_Tsize, &tmp );
  if ( tmp )
    ++src.m_count;
  src.m_fullCount = src.m_count;
  *(zxVLI*)this = zxvli.def;
  m_vector.m_Tsize = src.m_Tsize;
  zxv.push_back( &m_vector, &src );
  m_bits          = zxSHORT_BITS;
  m_lastBit       = zxSHORT_LAST >> (( src.m_size - 1 ) * CHAR_BIT );
  m_lastByte      = m_vector.m_count - 1;
  m_isSigned      = false;
}
zxVli::zxVli( zxss const val )
{
  zxVECTOR src    = zxv.def;
  size_t   tmp    = 0;
  src.m_Tsize     = sizeof( char );
  src.m_data      = (zxuc*)&val;
  src.m_size      = sizeof( short );
  src.m_fullSize  = src.m_size;
  src.m_count     = zxc_size_udiv( src.m_size, src.m_Tsize, &tmp );
  if ( tmp )
    ++src.m_count;
  src.m_fullCount = src.m_count;
  *(zxVLI*)this = zxvli.def;
  m_vector.m_Tsize = src.m_Tsize;
  zxv.push_back( &m_vector, &src );
  m_bits          = zxSHORT_BITS;
  m_lastBit       = zxSHORT_LAST >> (( src.m_size - 1 ) * CHAR_BIT );
  m_isSigned      = true;
}
zxVli::zxVli( zxul const val )
{
  zxVECTOR src    = zxv.def;
  size_t   tmp    = 0;
  src.m_Tsize     = sizeof( char );
  src.m_data      = (zxuc*)&val;
  src.m_size      = sizeof( long );
  src.m_fullSize  = src.m_size;
  src.m_count     = zxc_size_udiv( src.m_size, src.m_Tsize, &tmp );
  if ( tmp )
    ++src.m_count;
  src.m_fullCount = src.m_count;
  *(zxVLI*)this = zxvli.def;
  m_vector.m_Tsize = src.m_Tsize;
  zxv.push_back( &m_vector, &src );
  m_bits          = zxLONG_BITS;
  m_lastBit       = ( zxLONG_LAST >> (( src.m_size - 1 ) * CHAR_BIT ) ) & UCHAR_MAX;
  m_lastByte      = m_vector.m_count - 1;
  m_isSigned      = false;
}
zxVli::zxVli( zxsl const val )
{
  zxVECTOR src    = zxv.def;
  size_t   tmp    = 0;
  src.m_Tsize     = sizeof( char );
  src.m_data      = (zxuc*)&val;
  src.m_size      = sizeof( long );
  src.m_fullSize  = src.m_size;
  src.m_count     = zxc_size_udiv( src.m_size, src.m_Tsize, &tmp );
  if ( tmp )
    ++src.m_count;
  src.m_fullCount = src.m_count;
  *(zxVLI*)this = zxvli.def;
  m_vector.m_Tsize = src.m_Tsize;
  zxv.push_back( &m_vector, &src );
  m_bits          = zxLONG_BITS;
  m_lastBit       = ( zxLONG_LAST >> (( src.m_size - 1 ) * CHAR_BIT ) ) & UCHAR_MAX;
  m_lastByte      = m_vector.m_count - 1;
  m_isSigned      = true;
}
zxVli::zxVli( zxui const val )
{
  zxVECTOR src    = zxv.def;
  size_t   tmp    = 0;
  src.m_Tsize     = sizeof( char );
  src.m_data      = (zxuc*)&val;
  src.m_size      = sizeof( int );
  src.m_fullSize  = src.m_size;
  src.m_count     = zxc_size_udiv( src.m_size, src.m_Tsize, &tmp );
  if ( tmp )
    ++src.m_count;
  src.m_fullCount = src.m_count;
  *(zxVLI*)this = zxvli.def;
  m_vector.m_Tsize = src.m_Tsize;
  zxv.push_back( &m_vector, &src );
  m_bits          = zxINT_BITS;
  m_lastBit       = zxINT_LAST >> (( src.m_size - 1 ) * CHAR_BIT );
  m_lastByte      = m_vector.m_count - 1;
  m_isSigned      = false;
}
zxVli::zxVli( zxsi const val )
{
  zxVECTOR src    = zxv.def;
  size_t   tmp    = 0;
  src.m_Tsize     = sizeof( char );
  src.m_data      = (zxuc*)&val;
  src.m_size      = sizeof( int );
  src.m_fullSize  = src.m_size;
  src.m_count     = zxc_size_udiv( src.m_size, src.m_Tsize, &tmp );
  if ( tmp )
    ++src.m_count;
  src.m_fullCount = src.m_count;
  *(zxVLI*)this = zxvli.def;
  m_vector.m_Tsize = src.m_Tsize;
  zxv.push_back( &m_vector, &src );
  m_bits          = zxINT_BITS;
  m_lastBit       = zxINT_LAST >> (( src.m_size - 1 ) * CHAR_BIT );
  m_lastByte      = m_vector.m_count - 1;
  m_isSigned      = true;
}
#ifdef ZXILL
zxVli::zxVli( zxull const val )
{
  zxVECTOR src    = zxv.def;
  size_t   tmp    = 0;
  src.m_Tsize     = sizeof( char );
  src.m_data      = (zxuc*)&val;
  src.m_size      = sizeof( ZXILL );
  src.m_fullSize  = src.m_size;
  src.m_count     = zxc_size_udiv( src.m_size, src.m_Tsize, &tmp );
  if ( tmp )
    ++src.m_count;
  src.m_fullCount = src.m_count;
  *(zxVLI*)this = zxvli.def;
  m_vector.m_Tsize = src.m_Tsize;
  zxv.push_back( &m_vector, &src );
  m_bits          = zxILL_BITS;
  m_lastBit       = ( zxILL_LAST >> (( src.m_size - 1 ) * CHAR_BIT ) ) & UCHAR_MAX;
  m_lastByte      = m_vector.m_count - 1;
  m_isSigned      = false;
}
zxVli::zxVli( zxsll const val )
{
  zxVECTOR src    = zxv.def;
  size_t   tmp    = 0;
  src.m_Tsize     = sizeof( char );
  src.m_data      = (zxuc*)&val;
  src.m_size      = sizeof( ZXILL );
  src.m_fullSize  = src.m_size;
  src.m_count     = zxc_size_udiv( src.m_size, src.m_Tsize, &tmp );
  if ( tmp )
    ++src.m_count;
  src.m_fullCount = src.m_count;
  *(zxVLI*)this = zxvli.def;
  m_vector.m_Tsize = src.m_Tsize;
  zxv.push_back( &m_vector, &src );
  m_bits          = zxILL_BITS;
  m_lastBit       = ( zxILL_LAST >> (( src.m_size - 1 ) * CHAR_BIT ) ) & UCHAR_MAX;
  m_lastByte      = m_vector.m_count - 1;
  m_isSigned      = true;
}
#endif
zxVli::zxVli( zxVli const &val )
{
  *(zxVLI*)this = zxvli.def;
  zxv.push_back( &m_vector, &val.m_vector );
  m_bits     = val.m_bits;
  m_lastBit  = val.m_lastBit;
  m_lastByte = val.m_lastByte;
  m_isSigned = val.m_isSigned;
}
zxVli::~zxVli( void ) { zxcKill_zxVLI( this ); }
#endif