#include <string.h>
#include <stdlib.h>

#include "types.h"
#include "aes.h"
#include "firmlaunch.h"

int firm_setup(u32* FIRM, void* N3DSKey1[0x10], void* N3DSKey2[0x10]){
	if(strcmp((char *)FIRM, "FIRM", 4) != 0) return 3;   //Not FIRM
	
	u8* arm9bin = (void*)(FIRM + FIRM[0xA0/4]);
	
	if(arm9bin[0]) != 0xA7 || arm9bin[1] != 0x38) return 0; //O3DS FIRM
	
	if(arm9bin[0x800] != 0x70 || arm9bin[0x801] != 0x47){ //If encrypted
		if(arm9bin[0x50] != 0xFF && arm9bin[0x61] != 0xA9) set_normalKey(0x11, N3DSKey2);
		else set_normalKey(0x11, N3DSKey1);
		
		u8 keyslot = arm9bin[0x50] == 0xFF ? 0x16 : 0x15;
		u8* keyX = arm9bin + (arm9bin[0x50] == 0xFF ? 0x60 : 0);
		
		set_keyslot(0x11);
		aes(keyX, keyX, NULL, 1, AES_ECB_DECRYPT);
		
		set_keyX(keyslot, keyX);
		set_keyY(keyslot, arm9bin + 0x10);
		
		set_keyslot(keyslot);
		aes(arm9bin + 0x800, arm9bin + 0x800, arm9bin + 0x20, atoi((const char *)(arm9bin + 0x30)/16, AES_CTR_DECRYPT);
	}
	
	return 0;
}

void firmlaunch(u32* FIRM){
	if(firm_setup(FIRM) == 0){
		patch(FIRM);
		//TODO: Screen deinit
		((void (*)())0x0801B01C)(); //TODO: Don't hardcode this value
	}
}
