#include "c.h"

#ifndef ZXVECTOR_OBJ_H
#define ZXVECTOR_OBJ_H

ZXC_OPEN

/*
  Since c89/90 does not provide namespaces we provide an alternative instead
  This makes it simpler to program because the IDE can find the
  list of functions more easily and the developer only has to remember the
  name of the struct namespace he needs.
*/

typedef struct zxn_v_struct
{
  const zxVECTOR def;
  /*
    This is our shorthand for constructor & destructor,
    the underscore at front is merely to stop it being accidently
    used on an obj that's not supposed to reach either state yet
  */
  void   (*_init)(         zxVECTOR       *obj,
                           size_t         Tsize,
                           zxuc     const *src,
                           size_t         srcCount );
  void   (*_kill)(         zxVECTOR       *obj );
  /*
    Here we attempt to replicate the standard functions
    (and where necessary add our own
  */
  size_t (*size)(          zxVECTOR const *obj );
  size_t (*max_size)(      zxVECTOR const *obj );
  /* Uses grow()/erase() to modify buffer */
  void   (*resize)(        zxVECTOR       *obj,
                           size_t   const  setCount,
                           zxuchr   const *setNew );
  size_t (*capacity)(      zxVECTOR const *obj );
  bool   (*empty)(         zxVECTOR const *obj );
  /* Uses zxv.grow() */
  void   (*reserve)(       zxVECTOR       *obj,
                           size_t          minSize );
  void   (*grow)(          zxVECTOR       *obj,
                           size_t          setCount,
                           zxuchr   const *setNew );
  void   (*shrink)(        zxVECTOR       *obj,
                           size_t          setCount );
  /* Uses zxv.shrink() */
  void   (*shrink_to_fit)( zxVECTOR       *obj );
  /** Uses grow()/erase() to modify buffer **/
  void   (*assign)(        zxVECTOR       *obj,
                           size_t   const  setCount,
                           zxuchr   const *setNew );
  /** Inserts buffer AFTER pos **/
  void   (*append)(        zxVECTOR       *obj,
                           zxVECTOR const *src,
                           size_t   const  at );
  bool   (*push_back)(     zxVECTOR       *obj,
                           zxVECTOR   const *src );
  void   (*pop_back)(      zxVECTOR       *obj );
  /** Inserts buffer BEFORE pos **/
  void   (*insert)(        zxVECTOR       *obj,
                           zxVECTOR const *src,
                           size_t   const  at );
  /**
    @param obj   The buffer to erase nodes from
    @param first The first node to be deleted (always done if valid)
    @param last  The last node to be deleted (set 0 for 1 node)
  **/
  void   (*erase)(         zxVECTOR       *obj,
                           size_t          first,
                           size_t          last );
  void   (*swap)(          zxVECTOR       *obj,
                           zxVECTOR       *src );
  /*
    Uses memset to clear the buffer but not delete it
    this facilitates fast recovery of count
  */
  void   (*clear)(         zxVECTOR       *obj );
  void   (*reverse)(       zxVECTOR       *obj );
  size_t (*copy)(          zxVECTOR const *obj,
                           zxuchr         *des,
                           size_t   const  desCount,
                           size_t   const  from );
  zxuc*   (*at)(           zxVECTOR const *obj,
                           size_t   const  i );
  /**
    if ( !obj || !cmp )
      i = SIZE_MAX
    else if false returned
      if ( count, size & Tsize members match )
        i = first node from end that is not equal
      else
        i = first node from end
    else
      i = 0
  **/
  bool    (*isEqual)(      zxVECTOR const *obj,
                           zxVECTOR const *src,
                           size_t         *i );
  zxVECTOR* (*cpyEql)(      zxVECTOR       *obj,
                           zxVECTOR const *src );
  zxVECTOR* (*opAdd)(      zxVECTOR       *obj,
                           zxVECTOR const *src );
  zxVECTOR* (*opMvl)(      zxVECTOR       *obj,
                           zxVECTOR const *src );
  bool    (*cmpEQ)(        zxVECTOR const *obj,
                           zxVECTOR const *cmp );
  bool    (*cmpNE)(        zxVECTOR const *obj,
                           zxVECTOR const *cmp );
} zxn_v;

static const zxn_v zxv = {
  {0},
  /*
    We don't need to vary from the macro here so
    we take advantage of it instead
  */
  ZXV_DEF_BODY( zxVECTOR )
};

/* refer to wide.h for full example of macros in use */

ZXC_SHUT

#endif