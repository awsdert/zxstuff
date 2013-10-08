#ifndef ZXARCH_H
#define ZXARCH_H

#if defined( __amd64__ ) || defined( __amd64 ) || defined( _M_AMD64 )

#define ZX_X64
#define ZX_AMD64

#elif defined( __x86_64__ ) || defined( __x86_64__ ) || defined( _M_X64 )

#define ZX_X64
#define ZX_X86_X64
#define ZX_X86

#elif defined( __i386__ ) || defined( __i386 ) || defined( i386 )

#define ZX_I386
#define ZX_X86

#elif defined( __i486__ ) || defined( __i486 ) || defined( i486 )

#define ZX_I486
#define ZX_X86

#elif defined( __i586__ ) || defined( __i586 ) || defined( i586 )

#define ZX_I586
#define ZX_X86

#elif defined( __i686__ ) || defined( __i686 ) || defined( i686 )

#define ZX_I686
#define ZX_X86

#elif defined( __i786__ ) || defined( __i786 ) || defined( i786 )

#define ZX_I786
#define ZX_X86

#elif defined( __i886__ ) || defined( __i886 ) || defined( i886 )

#define ZX_I886
#define ZX_X86

#elif defined( __i986__ ) || defined( __i986 ) || defined( i986 )

#define ZX_I986
#define ZX_X86

#elif defined( _M_I86 )

#define ZX_X86

#else

#define ZX_SPECIAL

#endif

#endif
