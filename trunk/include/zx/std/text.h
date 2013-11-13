#pragma once
#ifndef ZXTEXT_H
#define ZXTEXT_H
#include "char.h"
#include "wide.h"

ZXC_OPEN

#if ZXUNICODE
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
#if ZXUNICODE
typedef zxWide zxText;
#else
typedef zxChar zxText;
#endif
#endif

#endif
