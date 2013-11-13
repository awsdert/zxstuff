#pragma once
#ifndef ZXV_CPP_H
#define ZXV_CPP_H
#include "c.h"

#if ZXCPP

/*
  This is NOT binary compatible with std::vector
  The functions were chosen to aid in transitions
  and to reduce learning curves, please post an
  issue if a function does not behave as expected
*/
template< class T > class zxVector : public zxVECTOR
{
public:
  zxVector( void )
    { zxv._init( this, sizeof( T ), NULL, 0 ); }
  zxVector( zxVector< T > const &src )
    { zxv._initCpy( this, &src ); }
  ~zxVector( void )
    { zxv._kill( this ); }
  /*
    Most of the work is already done so we just play with pointers now

    Also since developers may want to overide certain functions we'll
    just define the lot as virtual and give them default actions.
    This also helps the developer understand how they can use the
    default handlers.
  */
  virtual void   clear(    void )
                            { zxv.clear( this ); }
  virtual size_t size(     void )
                            { return zxv.size( this ); }
  virtual size_t max_size( void )
                            { return zxv.max_size( this ); }
  virtual void   resize(   size_t       setCount )
                            { zxv.resize( this, setCount, NULL ); }
  virtual void   resize(   size_t const setCount,   T      const setNew )
                            { zxv.resize( this, setCount, &setNew ); }
  virtual size_t capacity( void )
                            { return zxv.capacity( this ); }
  virtual bool   empty(    void )
                            { return zxv.empty( this ); }
  virtual void   reserve(  size_t const minSize )
                            { zxv.reserve( this, minSize ); }
  virtual void   grow(     size_t const setCount )
                            { zxv.grow( this, setCount, NULL ); }
  virtual void   grow(     size_t const setCount,   T      const setNew )
                            { zxv.grow( this, setCount, (zxuc*)&setNew ); }
  virtual void   shrink(   size_t const setCount )
                            { zxv.shrink( this, setCount ); }
  virtual void   shrink_to_fit( void )
    {
      zxv.shrink( this, m_count );
    }
  virtual void
    assign( size_t const setCount )
    {
      zxv.assign( this, setCount, NULL );
    }
  virtual void
    assign( size_t const setCount,
      T      const setNew )
    {
      zxv.assign( this, setCount, &setNew );
    }
  virtual void
    append( zxVector< T > const src,
      size_t const pos )
    {
      zxv.append( this, &src, pos );
    }
  virtual void
    push_back( T const node )
    {
      zxv.push_back( this, (zxuc*)&node );
    }
  virtual void
    insert( zxVector< T > const src,
      size_t const pos )
    {
      zxv.insert( this, &src, pos );
    }
  virtual void
    pop_back( void )
    {
      zxv.pop_back( this );
    }
  virtual void
    erase( size_t const first,
      size_t const last )
    {
      zxv.erase( this, first, last );
    }
  virtual void
    copy(         T*           des,
                  size_t const desCount,
                  size_t const from )
    {
      zxv.copy( this, des, desCount, from );
    }
  virtual T&
    at(           size_t const i )
    {
      return (T&)zxv.at( this, i );
    }
  virtual T&
    operator[]  ( size_t const i )
    {
      return (T&)zxv.at( this, i );
    }
  virtual zxVector< T >
    operator+   ( zxVector< T > const src )
    {
      zxVector< T > cpy = this;
      return (zxVector&)zxv.opAdd( &cpy, &src );
    }
  virtual zxVector< T >
    operator<<  ( zxVector< T > const src )
    {
      zxVector< T > cpy = this;
      return (zxVector&)zxv.opAdd( &cpy, &src );
    }
  virtual zxVector&
    operator+=  ( zxVector< T > const src )
    {
      return (zxVector&)zxv.opAdd( this, &src );
    }
  virtual zxVector&
    operator<<= ( zxVector< T > const src )
    {
      return (zxVector&)zxv.opMvl( this, &src );
    }
};

#endif
#endif
