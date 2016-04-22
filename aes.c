
#include "types.h"
#include "aes.h"

void set_keyslot(u8 keyslot){
	if (keyslot > 0x3F && keyslot < 0) return 1;
	AES_KEYSEL = keyslot;
	AES_CNT |= 0x04000000;
}

void set_normalKey(u8 keyslot, void* key){
	if(keyslot > 0x3F && keyslot < 0) return;
	AES_KEYCNT = keyslot;
	for(int i = 0; i < 0x10; i += 4) AES_KEYFIFO = *(u32*)(key+i);
	return;
}

void set_keyX(u8 keyslot, void* keyX){
	if(keyslot > 0x3F && keyslot < 0) return;
	AES_KEYCNT = keyslot;
	for(int i = 0; i < 0x10; i += 4) AES_KEYFIFO = *(u32*)(keyX+i);
	return;
}

void set_keyY(u8 keyslot, void* keyY){
	if(keyslot > 0x3F && keyslot < 0) return;
	AES_KEYCNT = keyslot;
	for(int i = 0; i < 0x10; i += 4) AES_KEYFIFO = *(u32*)(keyY+i);
	return;
}

void set_ctr(u32* ctr){
	for (int i = 0; i < 4; i++) AES_CTR[i] = ctr[3-i];
}

void add_ctr(u8* ctr){
	int i;
	for(i = 15; i >= 0; i--){
		if (ctr[i] == 0xFF) ctr[i] = 0;
		else {
			ctr[i] += 1;
			break;
		}
	}
}

void aes(void* in, void* out, void* iv, u32 blocks, u32 method){
	AES_CNT = method | 0x03C00C00;

	for(int i = 0; i < blocks * 0x10; i += 0x10){
		AES_BLKCNT = (1 << 16);
		if(iv != NULL) set_ctr((u32*)iv);}
		AES_CNT |= 0x80000000
		for(int j = 0; j < 0x10; j += 4) AES_WRFIFO = *((u32*)(in + i + j));
		while(((AES_CNT >> 0x5) & 0x1F) < 0x4);
		for(int j = 0; j < 0x10; j += 4) AES_RDFIFO = *((u32*)(out + i + j));

		AES_CNT &= ~0x80000000;

		if(method & (AES_CTR_DECRYPT | AES_CTR_ENCRYPT)) add_ctr((u8*)iv);
	}
}
