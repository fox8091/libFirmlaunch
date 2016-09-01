#pragma once

#include "types.h"

#define AES_CNT         *((vu32 *)0x10009000)
#define AES_BLKCNT      *((vu32 *)0x10009004)
#define AES_WRFIFO      *((vu32 *)0x10009008)
#define AES_RDFIFO      *((vu32 *)0x1000900C)
#define AES_KEYSEL      *((vu8 *)0x10009010)
#define AES_KEYCNT      *((vu8 *)0x10009011)
#define AES_CTR         ((vu32 *)0x10009020)
#define AES_KEYFIFO     *((vu32 *)0x10009100)
#define AES_KEYXFIFO    *((vu32 *)0x10009104)
#define AES_KEYYFIFO    *((vu32 *)0x10009108)

#define AES_CCM_DECRYPT	(0 << 27)
#define AES_CCM_ENCRYPT	(1 << 27)
#define AES_CTR_DECRYPT	(2 << 27)
#define AES_CTR_ENCRYPT	(3 << 27)
#define AES_CBC_DECRYPT	(4 << 27)
#define AES_CBC_ENCRYPT	(5 << 27)
#define AES_ECB_DECRYPT	(6 << 27)
#define AES_ECB_ENCRYPT	(7 << 27)



void set_keyslot(u8 keyslot);
void set_normalKey(u8 keyslot, u8* key);
void set_keyX(u8 keyslot, u8* keyX);
void set_keyY(u8 keyslot, u8* keyY);
void aes(void* in, void* out, void* iv, u32 blocks, u32 method);
