#ifndef AES_H
#define AES_H

#include "types.h"

#define AES_CCM_DECRYPT	(0 << 27)
#define AES_CCM_ENCRYPT	(1 << 27)
#define AES_CTR_DECRYPT	(2 << 27)
#define AES_CTR_ENCRYPT	(3 << 27)
#define AES_CBC_DECRYPT	(4 << 27)
#define AES_CBC_ENCRYPT	(5 << 27)
#define AES_ECB_DECRYPT	(6 << 27)
#define AES_ECB_ENCRYPT	(7 << 27)

int set_keyslot(u8 keyslot);
int set_normalKey(u8 keyslot, void* key);
int set_keyX(u8 keyslot, void* keyX);
int set_keyY(u8 keyslot, void* keyY);
void aes(void* in, void* out, void* iv, u32 blocks, u32 method);

#endif
