/*******************************************************************
				C&C Yuri's Revenge 1.001 C++ Wrapper
				====================================
				   (c) 2007-2008 by pd and DCoder

*******************************************************************/

#ifdef __GNUC__

#error GCC is not supported. This is because it produces a different binary class layout     \
	which is utterly incompatible with data layout of objects in the game, therefore it cannot \
	be used to interact with it without converting the YRPP headers to plain C, which is a massive \
	undertaking for dubious gain, as GCC even optimises code worse than MSVC.

#endif

#ifndef YRPLUSPLUS_H
#define YRPLUSPLUS_H

#include <YRPPCore.h>
#include <FileSystem.h>
#include <StringTable.h>
#include <MessageBox.h>
#include <Drawing.h>
#include <PCX.h>
#include <CommandClass.h>
#include <GameClasses.h>
#include <SwizzleManagerClass.h>
#include <MacroHelpers.h>

#endif
