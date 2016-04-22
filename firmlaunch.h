#ifndef FIRMLAUNCH_H
#define FIRMLAUNCH_H

#include "types.h"

int firm_setup(u32* FIRM, u8 N3DSKey1, u8 N3DSKey2);
void firmlaunch(u32* FIRM);
void patch(u32* FIRM);

#endif
