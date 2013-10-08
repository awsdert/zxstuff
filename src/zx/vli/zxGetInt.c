#include <zx/vli.h>
ZXCORE_EXP zxusht   zxGetUSht(    zxuchr* src, size_t size )
{
  zxusht val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuchr*)&val, sizeof( short ), zxIntEndian() );
  return val;
}
ZXCORE_EXP zxssht   zxGetSSht(    zxuchr* src, size_t size )
{
  zxssht val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuchr*)&val, sizeof( short ), zxIntEndian() );
  return val;
}
ZXCORE_EXP zxulng   zxGetULng(    zxuchr* src, size_t size )
{
  zxulng val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuchr*)&val, sizeof( long ), zxIntEndian() );
  return val;
}
ZXCORE_EXP zxslng   zxGetSLng(    zxuchr* src, size_t size )
{
  zxslng val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuchr*)&val, sizeof( long ), zxIntEndian() );
  return val;
}
ZXCORE_EXP zxuint   zxGetUInt(    zxuchr* src, size_t size )
{
  zxuint val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuchr*)&val, sizeof( int ), zxIntEndian() );
  return val;
}
ZXCORE_EXP zxsint   zxGetSInt(    zxuchr* src, size_t size )
{
  zxsint val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuchr*)&val, sizeof( int ), zxIntEndian() );
  return val;
}
#ifdef ZXILL
ZXCORE_EXP zxuill   zxGetUIll(    zxuchr* src, size_t size )
{
  zxuill val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuchr*)&val, sizeof( ZXILL ), zxIntEndian() );
  return val;
}
ZXCORE_EXP zxsill   zxGetSIll(    zxuchr* src, size_t size )
{
  zxsill val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuchr*)&val, sizeof( ZXILL ), zxIntEndian() );
  return val;
}
#endif
ZXCORE_EXP zxumax   zxGetUMax(    zxuchr* src, size_t size )
{
  zxumax val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuchr*)&val, sizeof( ZXIMAX ), zxIntEndian() );
  return val;
}
ZXCORE_EXP zxsmax   zxGetSMax(    zxuchr* src, size_t size )
{
  zxsmax val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuchr*)&val, sizeof( ZXIMAX ), zxIntEndian() );
  return val;
}
ZXCORE_EXP size_t   zxGetSize_t(  zxuchr* src, size_t size )
{
  size_t val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuchr*)&val, sizeof( size_t ), zxIntEndian() );
  return val;
}
ZXCORE_EXP ssize_t  zxGetSSize_t( zxuchr* src, size_t size )
{
  ssize_t val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuchr*)&val, sizeof( size_t ), zxIntEndian() );
  return val;
}
