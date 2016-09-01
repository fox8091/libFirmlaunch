#include <string.h>
#include <stdlib.h>

#include "types.h"
#include "aes.h"
#include "firmlaunch.h"

#define ARM11Entry 0x1FFFFFF8
#define ARM9Entry 0x0801B01C

int firm_setup(FirmInfo firm, void* N3DSKey1, void* N3DSKey2){
	if(strncmp((char *)firm.firm, "FIRM", 4) != 0) return 3;   //Not FIRM
	
	if(firm.arm9bin[0] != 0xA7 || firm.arm9bin[1] != 0x38) return 0; //O3DS FIRM
	
	if(firm.arm9bin[0x800] != 0x70 || firm.arm9bin[0x801] != 0x47){ //If encrypted
		if(firm.arm9bin[0x50] != 0xFF && firm.arm9bin[0x61] != 0xA9) set_normalKey(0x11, N3DSKey2);
		else set_normalKey(0x11, N3DSKey1);
		
		u8 keyslot = firm.arm9bin[0x50] == 0xFF ? 0x16 : 0x15;
		u8* keyX = (u8*)firm.arm9bin + (firm.arm9bin[0x50] == 0xFF ? 0x60 : 0);
		
		set_keyslot(0x11);
		aes(keyX, keyX, NULL, 1, AES_ECB_DECRYPT);
		
		set_keyX(keyslot, keyX);
		set_keyY(keyslot, (u8*)(firm.arm9bin + 0x10));
		
		set_keyslot(keyslot);
		aes(firm.arm9bin + 0x800, firm.arm9bin + 0x800, firm.arm9bin + 0x20, atoi((const char *)(firm.arm9bin + 0x30))/16, AES_CTR_DECRYPT);
	}
	
	return 0;
}

void firmlaunch(FirmInfo firm){
	memcpy((u8*)firm.firm[0x44/4], (u8*)firm.firm + firm.firm[0x40/4], firm.firm[0x48/4]);
	memcpy((u8*)firm.firm[0x74/4], (u8*)firm.firm + firm.firm[0x70/4], firm.firm[0x78/4]);
	memcpy((u8*)firm.firm[0xA4/4], (u8*)firm.firm + firm.firm[0xA0/4], firm.firm[0xA8/4]);
	//TODO: Screen deinit
	*((vu32 *) ARM11Entry) = firm.firm[0x8/4];
	((void (*)())ARM9Entry)();
}

void *pattern_match(u8* baseaddr, u32 search_size, u8* pattern, u32 size){
	for(u32 i = 0; i < (search_size - size); i++){
		if(memcmp(baseaddr+i, pattern, size) == 0){
			return baseaddr+i;
		}
	}
	return NULL;
}

int patch(u32* start_addr, u32 search_size, u8* pattern, u8* patch_data, u32 pattern_size, u32 patch_size, u32 offset){
    void *ptr = pattern_match((unsigned char *)start_addr, (unsigned)search_size, pattern, pattern_size);
    if(ptr == NULL){
        return -1;
    }
    memcpy(((u8*)ptr + offset), patch_data, patch_size);
    return 0;
}
