#include "TI_aes_128.h"
#include "kdf.h"

#include <sys/types.h>
#include <inttypes.h>

void deriveKey(unsigned char* key, int numBlocks,unsigned char* devKey){
	
	
	//simple "string" dependent of the aplication, and diferent from each one
	unsigned char context[]= { 0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70,
							   0x80, 0x90, 0xa0, 0xb0, 0xc0, 0xd0, 0xe0, 0xf0};
	uint8_t	count = 0;				   
		
	int i,e;
	unsigned char state[BLOCK_SIZE];
	unsigned char keyAux[BLOCK_SIZE];
	
	for(i = 0; i < numBlocks; i++){
		
		context[BLOCK_SIZE-1]=count;   
		memcpy(state,&context[0], BLOCK_SIZE);

		
		//Encrip the IV/nonce using a - k1;
		memcpy(keyAux,key, BLOCK_SIZE);
		aes_enc_dec(state,keyAux,0);
		
		memcpy(&devKey[BLOCK_SIZE * i],state,BLOCK_SIZE);
		count++;
		
			printf("\n state \n");
			for(e = 0; e < BLOCK_SIZE; e++){
			printf("%02x, ",devKey[e] & 0xff);
			}
		
		}
	
	
	return;
	}
