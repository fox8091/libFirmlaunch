#pragma once

#include "types.h"

int firm_setup(u32* FIRM, void* N3DSKey1, void* N3DSKey2);
void firmlaunch(u32* FIRM);
void *pattern_match(u8* baseaddr, u32 search_size, u8* pattern, u32 size, bool reversed)
int patch(u32* FIRM, u32 search_size, u8* pattern, u8* patch_data, u32 pattern_size, u32 patch_size, u32 offset, bool reversed);
