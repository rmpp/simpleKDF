#include "kdf.h"


int main(int argc, const char *argv[])
{  

	unsigned char sourceKey[] = 
	{ 
	0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
	0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
	
	/* the number of keys to derive(each one with of 128 bits)*/
	int numKeys = 2;
	
	
	unsigned char devKey[BLOCK_SIZE * numKeys]; 
	
	deriveKey(sourceKey,numKeys,devKey);
	
	int e;	
	printf("\n DEV_KEY \n");
	for(e = 0; e < BLOCK_SIZE * numKeys; e++){
		printf("%02x, ",devKey[e] & 0xff);
		}

	return 0;
}
