#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef VARS
#define VARS
#include "..\Utilits\Vars.h"
#endif

char *CSR_keygen(char *key){
   int i, j, k, length;
   strcat(key, caesar_alphabet);
   length = strlen(key);
   
   for(i = 0; i<length; i++) {
      for(j = i+1; j<length; j++) {
         if(key[i] == key[j]){
            for(k = j; k < length; k++)
               key[k] = key[k+1];
            length--;  
         }
	  }
   }
         
    return (key);
}
void CSRencrypt_key(char *message) {
	int i,j;
	char key[100];
	char enc[100] = "";
	
    printf("Key : ");
    scanf("%s",&key);
    
	CSR_keygen(key);

	for (i=0; i<strlen(message); i++) {
		for (j=0;j<strlen(key);j++) {
			if (message[i] == caesar_alphabet[j]) {
				enc[i] = key[j];
			}
		}
	}
	printf(enc);
}
void CSRdecrypt_key(char *message) {
	int i,j;
	char key[100];
	char enc[100] = "";
	
    printf("Key : ");
    scanf("%s",&key);
    
	CSR_keygen(key);

	for (i=0; i<strlen(message); i++) {
		for (j=0;j<strlen(key);j++) {
			if (message[i] == key[j]) {
				enc[i] = caesar_alphabet[j];
			}
		}
	}
	printf(enc);
}