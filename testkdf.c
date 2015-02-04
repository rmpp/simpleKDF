#include "kdf.h"


int main(int argc, const char *argv[])
{  

	unsigned char sourceKey[] = 
	{ 
	0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
	0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
	
	//	Simple "string" dependent of the aplication, and diferent from each one
	unsigned char context[]= { 0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70,
							   0x80, 0x90, 0xa0, 0xb0, 0xc0, 0xd0, 0xe0, 0x00};
	
	/* The number of keys to derive (each one with of 128 bits) */
	int numKeys = 2;
	
	unsigned char devKey[BLOCK_SIZE * numKeys]; 
	
	deriveKey(sourceKey, context, numKeys, devKey);
	
	int e;	
	printf("\n DEV_KEY \n");
	for(e = 0; e < BLOCK_SIZE * numKeys; e++){
		printf("%02x, ",devKey[e] & 0xff);
		}

	return 0;
}
