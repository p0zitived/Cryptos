#include "..\Utilits\Vars.h"

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