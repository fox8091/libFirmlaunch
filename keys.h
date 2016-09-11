#include "types.h"

typedef enum KeySlot {
	TWL_0                 = 0x00,
	TWL_1                 = 0x01,
	TWL_2                 = 0x02,
	TWL_3                 = 0x03,
	CTRNAND_OLD           = 0x04,
	CTRNAND_NEW           = 0x05,
	FIRM_PARTITION        = 0x06,
	AGBSAVE_PARTITION     = 0x07,
	UNKNOWN_0             = 0x08,
	UNKNOWN_1             = 0x09,
	DSIWARE_EXPORT_0      = 0x0A,
	NAND_DB_CMAC          = 0x0B,
	SSL_CERT_0            = 0x0C,
	SSL_CERT_1            = 0x0D,
	SSL_CERT_2            = 0x0E,
	SSL_CERT_3            = 0x0F,
	UNKNOWN_2             = 0x10,
	ARM9BIN_TEMP          = 0x11,
	UNKNOWN_3             = 0x12,
	UNKNOWN_4             = 0x13,
	PSPXI_MASTER          = 0x14,
	ARM9BIN_0             = 0x15,
	ARM9BIN_1             = 0x16,
	UNKNOWN_5             = 0x17,
	NCCH_SECURE3          = 0x18,
	SAVE_N3DS_CMAC        = 0x19,
	SAVE_N3DS             = 0x1A,
	NCCH_SECURE4          = 0x1B,
	UNUSED_0              = 0x1C,
	UNUSED_1              = 0x1D,
	UNUSED_2              = 0x1E,
	UNUSED_3              = 0x1F,
	UNKNOWN_6             = 0x20,
	UNKNOWN_7             = 0x21,
	UNKNOWN_8             = 0x22,
	UNKNOWN_9             = 0x23,
	AGBSAVE_CMAC          = 0x24,
	NCCH_SECURE2          = 0x25,
	UNKNOWN_10            = 0x26,
	UNKNOWN_11            = 0x27,
	UNKNOWN_12            = 0x28,
	UNKNOWN_13            = 0x29,
	UNKNOWN_14            = 0x2A,
	UNKNOWN_15            = 0x2B,
	NCCH_SECURE1          = 0x2C,
	PSPXI_UDS_CCMP        = 0x2D,
	PSPXI_STREETPASS      = 0x2E,
	SAVE_6X               = 0x2F,
	SD_NAND_MAC           = 0x30,
	APT_WRAP              = 0x31,
	PSPXI_UNKNOWN_0       = 0x32,
	SAVE_CMAC             = 0x33,
	SD                    = 0x34,
	MOVABLESED            = 0x35,
	PSPXI_UNKNOWN_1       = 0x36,
	SAVE                  = 0x37,
	BOSS                  = 0x38,
	DLP_NFC               = 0x39,
	DSIWARE_EXPORT_1      = 0x3A,
	CTRCARD_HARDWARE_SEED = 0x3B,
	UNKNOWN_16            = 0x3C,
	COMMON                = 0x3D,
	UNKNOWN_17            = 0x3E,
	UNKNOWN_18            = 0x3F
};

typedef struct {
	u8 keyX[0x10];
	u8 keyY[0x10];
	u8 normalKey[0x10];
} AESKey;


typedef struct {
	bool initialized;
	AESKey slots[0x40];
} KeyStorage;

