#pragma once

#include "types.h"

typedef struct {
	u32* firm;
	u32* arm9bin;
	u32  arm9size;
	u32* arm11bin;
	u32  arm11size;
} FirmInfo;

int firm_setup(FirmInfo firm, void* N3DSKey1, void* N3DSKey2);
void firmlaunch(FirmInfo firm);
int patch(u32* start_addr, u32 search_size, u8* pattern, u8* patch_data, u32 pattern_size, u32 patch_size, u32 offset);
