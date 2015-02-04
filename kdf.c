#include "TI_aes_128.h"
#include "kdf.h"

#include <sys/types.h>
#include <inttypes.h>

void deriveKey(unsigned char* key, unsigned char* context, int numBlocks, unsigned char* devKey){
	

	uint8_t	count = 0;				   
		
	int i,e;
	
	//Auxiliar vector for aes
	unsigned char state[BLOCK_SIZE];
	unsigned char keyAux[BLOCK_SIZE];
	
	for(i = 0; i < numBlocks; i++){
		
		//contex "increment" (CTX||count)
		context[BLOCK_SIZE-1] = count;   

		memcpy(state,&context[0], BLOCK_SIZE);
		memcpy(keyAux,key, BLOCK_SIZE);

		//F(SK,(CTX||n))
		aes_enc_dec(state,keyAux,0);
		
		memcpy(&devKey[BLOCK_SIZE * i],state,BLOCK_SIZE);
		count++;
		
		/*
			printf("\n state \n");
			for(e = 0; e < BLOCK_SIZE; e++){
			printf("%02x, ",devKey[e] & 0xff);
			}
		*/
		
		}		
	
	return;
	
	}
