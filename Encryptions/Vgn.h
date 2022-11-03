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
    printf("Keya este : %s",newKey);
    printf("Mesajul este : %s",message);

    int indx_k,indx_m,indx_target;
    for (i=0;i<strlen(message);i++) {
        // cautam indx_k
        for (j=0;j<strlen(message);j++) {
            if (vgn_alphabet[j] == newKey[i]) {
                indx_k = j;
            }
        }

        // cautam indx_m
        printf("Il caut pe %c\n",message[i]);
        for (j=0;j<strlen(message);j++) {
            if (vgn_alphabet[j] == message[i]) {
                printf("Lam gasit\n");
                indx_m = j;
            }
        }

        indx_target = (indx_m + indx_k)%strlen(vgn_alphabet);
        printf("%i = %i -> %i \n",indx_k,indx_m,indx_target);
        enc[i] = vgn_alphabet[indx_target];
    }

	printf(enc);
}

// 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
// A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
// F O C A R F O C A R F O
// N U P O T V E N I A Z I
// S I R O K A S P I R E W