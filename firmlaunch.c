#include <string.h>
#include <stdlib.h>

#include "types.h"
#include "aes.h"
#include "firmlaunch.h"

int N3DSFirmDecrypt(u32* FIRM, u8 N3DSKey1[0x10], u8 N3DSKey2[0x10]){//Address of FIRM (Must manually set up keyslot0x11)
	if(FIRM[0] != 0x4D524946) return 3;   //Not FIRM
	
	u8* arm9bin = (void*)(FIRM + FIRM[0xA0/4]);
	
	if(*((u32*)arm9bin) != 0x465F38A7) return 2; //O3DS FIRM
	if(*((u32*)arm9bin + 0x800) != 0x47704770) return 1; //Decrypted
	
	if(arm9bin[0x50] != 0xFF && arm9bin[0x61] != 0xA9) set_normalKey(0x11, N3DSKey2);
	else set_normalKey(0x11, N3DSKey1);
	
	u8 keyslot = arm9bin[0x61] == 0xA9 ? 0x16 : 0x15;
	u8* keyX = arm9bin + (arm9bin[0x61] == 0xA9 ? 0x60 : 0);
	
	set_keyslot(0x11);
	aes(keyX, keyX, NULL, 1, AES_ECB_DECRYPT);
	
	set_keyX(keyslot, keyX);
	set_keyY(keyslot, arm9bin + 0x10);
	
	set_keyslot(keyslot);
	aes(arm9bin + 0x800, arm9bin + 0x800, (u8*)(arm9bin+0x20), atoi((const char *)(arm9bin+0x30)/16, AES_CTR_DECRYPT);
	
	return 0;
}
