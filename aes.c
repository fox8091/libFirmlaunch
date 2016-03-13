
#include "types.h"
#include "AES_REGISTERS.h"
#include "aes.h"

int set_keyslot(u8 keyslot){
	if (keyslot > 0x3F && keyslot < 0) return 1;
	SET_AES_KEYSEL(keyslot);
	return 0;
}

int set_normalKey(u8 keyslot, void* key){
	if (keyslot > 0x3F && keyslot < 0) return 1;
	SET_AES_KEYCNT(keyslot);
	SET_AES_KEYFIFO((u32*)key);
	return 0;
}

int set_keyX(u8 keyslot, void* keyX){
	if (keyslot > 0x3F && keyslot < 0) return 1;
	SET_AES_KEYCNT(keyslot);
	SET_AES_KEYXFIFO((u32*)keyX);
	return 0;
}

int set_keyY(u8 keyslot, void* keyY){
	if (keyslot > 0x3F && keyslot < 0) return 1;
	SET_AES_KEYCNT(keyslot);
	SET_AES_KEYYFIFO((u32*)keyY);
	return 0;
}

void add_ctr(u8* ctr){
	int i;
	for (i = 15; i >= 0; i--){
		if (ctr[i] == 0xFF) ctr[i] = 0;
		else {
			ctr[i] += 1;
			break;
		}
	}
}

void aes(void* in, void* out, void* iv, u32 blocks, u32 method){
	SET_AES_BLKCNT(blocks<<16);
	SET_AES_CNT(method | 0x83C00C00);
	u32* input = in;
	u32* output = out;
	for (int j = 0; j < blocks*4; j+=4){
		for (int i = 0; i < 4; i++){
			SET_AES_WRFIFO(input[j+i]);
			GET_AES_RDFIFO(output[j+i]);
		}
		if (iv != NULL){
			add_ctr((u8*)iv);
			SET_AES_CTR((u32*)iv);
		}
	}
}
