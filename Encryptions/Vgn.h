#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef VARS
#define VARS
	#include "..\Utilits\Vars.h"
#endif

void VGN_encrypt(char* message) {
    int i,j;
	char enc[100] = "";
    char key[100];
    char newKey[100] = "";
	
    printf("Key : ");
    scanf("%s",&key);
    
    // creiem o copie a mesajului dar facuta doar din cheie
    int x=0,y=strlen(key);
    for (i=0;i<strlen(message);i++) {
        x%=y;
        newKey[i] = key[x];
        x++;
    }

    int indx_k,indx_m,indx_target;
    for (i=0;i<strlen(message);i++) {
        for (j=0;j<strlen(vgn_alphabet);j++) {
            if (vgn_alphabet[j] == message[i]) {
                indx_m = j;
            }
            if (vgn_alphabet[j] == newKey[i]) {
                indx_k = j;
            }
        }

        indx_target = (indx_m + indx_k)%strlen(vgn_alphabet);
        enc[i] = vgn_alphabet[indx_target];
    }

	printf(enc);
}

void VGN_dencrypt(char* message) {
    int i,j;
	char enc[100] = "";
    char key[100];
    char newKey[100] = "";
	
    printf("Key : ");
    scanf("%s",&key);
    
    // creiem o copie a mesajului dar facuta doar din cheie
    int x=0,y=strlen(key);
    for (i=0;i<strlen(message);i++) {
        x%=y;
        newKey[i] = key[x];
        x++;
    }

    int indx_k,indx_m,indx_target;
    for (i=0;i<strlen(message);i++) {
        for (j=0;j<strlen(vgn_alphabet);j++) {
            if (vgn_alphabet[j] == message[i]) {
                indx_m = j;
            }
            if (vgn_alphabet[j] == newKey[i]) {
                indx_k = j;
            }
        }

        indx_target = (indx_m - indx_k + strlen(vgn_alphabet))%strlen(vgn_alphabet);
        enc[i] = vgn_alphabet[indx_target];
    }

	printf(enc);
}

void VGNencrypt_seed(char* message) {
    int i,j;
	char enc[100] = "";
    char key[100];
    char newKey[100] = "";
	

    printf("Key : ");
    scanf("%s",&key);

    int seed = time(NULL);
    printf("Seed %i\n",seed);
    
    // creiem o copie a mesajului dar facuta doar din cheie
    int x=0,y=strlen(key);
    for (i=0;i<strlen(message);i++) {
        x%=y;
        newKey[i] = key[x];
        x++;
    }

    int indx_k,indx_m,indx_target;
    for (i=0;i<strlen(message);i++) {
        for (j=0;j<strlen(vgn_alphabet);j++) {
            if (vgn_alphabet[j] == message[i]) {
                indx_m = j;
            }
            if (vgn_alphabet[j] == newKey[i]) {
                indx_k = j;
            }
        }

        indx_target = (indx_m + indx_k + seed)%strlen(vgn_alphabet);
        enc[i] = vgn_alphabet[indx_target];
    }

	printf(enc);
}
void VGNdencrypt_seed(char* message) {
    int i,j;
	char enc[100] = "";
    char key[100];
    char newKey[100] = "";

    printf("Key : ");
    scanf("%s",&key);

    int seed;
    printf("Seed : ");
    scanf("%i",&seed);

    // creiem o copie a mesajului dar facuta doar din cheie
    int x=0,y=strlen(key);
    for (i=0;i<strlen(message);i++) {
        x%=y;
        newKey[i] = key[x];
        x++;
    }

    int indx_k,indx_m,indx_target;
    for (i=0;i<strlen(message);i++) {
        for (j=0;j<strlen(vgn_alphabet);j++) {
            if (vgn_alphabet[j] == message[i]) {
                indx_m = j;
            }
            if (vgn_alphabet[j] == newKey[i]) {
                indx_k = j;
            }
        }

        indx_target = (indx_m - indx_k - seed%strlen(vgn_alphabet) + strlen(vgn_alphabet))%strlen(vgn_alphabet);
        printf("%i\n",indx_target);
        enc[i] = vgn_alphabet[indx_target];
    }

	printf(enc);
}

// 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 262728293031323334
// A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z a b c d e f g h i j k l m n o p q r s t u v w x y z 1 2 3 4 5 6 7 8 9 0
// F O C A R F O C A R F O
// N U P O T V E N I A Z I
// S I R O K A S P I R E W