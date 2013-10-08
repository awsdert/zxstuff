#include "char.h"
#include "wide.h"

#ifndef ZXTEXT_H
#define ZXTEXT_H

ZXC_OPEN

#ifdef UNICODE
typedef wide zxch;
#define zxstr zxw
#define ZX_TEXT( TEXT ) ZX_WIDE( TEXT )
typedef zxWIDE zxTEXT;
#else
typedef char zxch;
#define zxstr zxc
#define ZX_TEXT( TEXT ) ZX_CHAR( TEXT )
typedef zxCHAR zxTEXT;
#endif

#define ZXT( TEXT ) ZX_TEXT( TEXT )

ZXC_SHUT

#if ZXCPP
#ifdef UNICODE
typedef zxWide zxText;
#else
typedef zxChar zxText;
#endif
#endif

#endif
