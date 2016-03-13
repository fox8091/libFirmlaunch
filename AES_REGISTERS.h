#ifndef AES_REGISTERS_H
#define AES_REGISTERS_H

#include "types.h"

void SET_AES_CNT(u32 cnt);
void SET_AES_BLKCNT(u32 cnt);
void SET_AES_WRFIFO(u32 in);
void GET_AES_RDFIFO(u32 out);
void SET_AES_KEYSEL(u8 slot);
void SET_AES_KEYCNT(u8 cnt);
void SET_AES_CTR(u32* ctr);
void SET_AES_MAC(u32* mac);
void SET_AES_KEY0(u8 keyslot, u32* key);
void SET_AES_KEY1(u8 keyslot, u32* key);
void SET_AES_KEY2(u8 keyslot, u32* key);
void SET_AES_KEY3(u8 keyslot, u32* key);
void SET_AES_KEYFIFO(u32* key);
void SET_AES_KEYYFIFO(u32* key);
void SET_AES_KEYXFIFO(u32* key);

#endif
