#ifndef VARS
#define VARS
	#include "..\Utilits\Vars.h"
#endif

void CSRencrypt(char *message) { 
    int key,i,j;
	char enc[100] = "";
	
    printf("Key : ");
    scanf("%i",&key);
    
    for (i = 0;i< strlen(message);i++) {
    	for (j=0;j<strlen(caesar_alphabet);j++) {
    		if (message[i] == caesar_alphabet[j]) {
    			if ((j+key)<strlen(caesar_alphabet)) {
    				enc[i] = caesar_alphabet[j+key];
				} else {
					enc[i] = caesar_alphabet[(j+key) - strlen(caesar_alphabet)];
				}
			}
		}
	}
	printf(enc);
} 
void CSRencrypt_math(char *message) {
    int key,i,j;
	char enc[100] = "";
	
    printf("Key : ");
    scanf("%i",&key);
    
    for (i = 0;i< strlen(message);i++) {
    	for (j=0;j<strlen(caesar_alphabet);j++) {
            if (message[i] == caesar_alphabet[j]) {
                //printf("\n %i + %i mod %zu - %zu * %i = %i\n",j,key,strlen(caesar_alphabet),strlen(caesar_alphabet),j>strlen(caesar_alphabet)-key,j + key%(int) strlen(caesar_alphabet) - strlen(caesar_alphabet)*(j>=strlen(caesar_alphabet)-key));
                enc[i] = caesar_alphabet[j + key%(int) strlen(caesar_alphabet) - strlen(caesar_alphabet)*(j>=strlen(caesar_alphabet)-key)];
            }
        }
	}

	printf(enc);
}
void CSRdecrypt(char *message) {
    int key,i,j;
	char enc[100] = "";
	
    printf("Key : ");
    scanf("%i",&key);
    
    for (i = 0;i< strlen(message);i++) {
    	for (j=0;j<strlen(caesar_alphabet);j++) {
    		if (message[i] == caesar_alphabet[j]) {
    			if ((j-key)>=0) {
    				enc[i] = caesar_alphabet[j-key];
				} else {
					enc[i] = caesar_alphabet[strlen(caesar_alphabet) - (key-j)];
				}
			}
		}
	}

	printf(enc);
}
void CSRdecrypt_math(char *message) {
    int key,i,j;
	char enc[100] = "";
	
    printf("Key : ");
    scanf("%i",&key);
    
    for (i = 0;i< strlen(message);i++) {
    	for (j=0;j<strlen(caesar_alphabet);j++) {
            if (message[i] == caesar_alphabet[j]) {
                //printf("\n %i + %i mod %zu - %zu * %i = %i\n",j,key,strlen(caesar_alphabet),strlen(caesar_alphabet),j>strlen(caesar_alphabet)-key,j + key%(int) strlen(caesar_alphabet) - strlen(caesar_alphabet)*(j>=strlen(caesar_alphabet)-key));
                enc[i] = caesar_alphabet[abs(j - key%(int) strlen(caesar_alphabet))*(j!=0) + (strlen(caesar_alphabet)-key)*(j==0)];
            }
        }
	}

	printf(enc);
}