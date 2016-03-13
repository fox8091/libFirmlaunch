#ifndef FIRMLAUNCH_H
#define FIRMLAUNCH_H

#include "types.h"

int N3DSFirmDecrypt(u32* FIRM, u8 N3DSKey1, u8 N3DSKey2);
void firmlaunch(u32* FIRM);
void patchAndFirmlaunch(u32* FIRM);

#endif
