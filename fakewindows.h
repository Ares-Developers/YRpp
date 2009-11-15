#ifndef FAKEWIN_H
#define FAKEWIN_H

#ifndef _MSC_VER
int __stdcall GetTickCount(void) { return 0; };
#endif

#endif
