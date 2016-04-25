#ifndef FIRMLAUNCH_H
#define FIRMLAUNCH_H

#include "types.h"

int firm_setup(u32* FIRM, void* N3DSKey1, void* N3DSKey2);
void firmlaunch();
void patch(u32* FIRM, u32* search_size, u8* pattern, u8* patch_data, u32 pattern_size, u32 patch_size);

#endif
