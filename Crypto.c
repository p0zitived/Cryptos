#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Encryptions\CaesarEncryption.h"

char *options[10];

// Utils -=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-==-=
int IsOption(char *str) {
	int i;
    for (i = 0;i<strlen(options);i++) {
        if (strcmp(options[i],str) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(int argc,char *argv[]) 
{ 
    // Options
    options[0] = "-Ecsr";
    options[1] = "-Dcsr";

    char *program = argv[0]; 
    char *option = argv[1]; 
    char *message = argv[2]; 

    switch (argc) { 
    case 1: 
        fprintf(stderr,"%s: no option and message\n",program); 
        exit(2); 
    break; 
    case 2: 
        if (IsOption(option)) {
            fprintf(stderr,"%s: no message introduced\n",program); 
        } else {
            fprintf(stderr,"%s: no option introduced\n",program); 
        }
        exit(3); 
    break; 
    case 3: 
        if (strcmp(argv[1],"-Ecsr") == 0) { 
                CSRencrypt_math(message);
        } else if (strcmp(argv[1],"-Dcsr") == 0) { 
                CSRdecrypt_math(message);
        } else { 
            fprintf(stderr,"%s: illegal option %s\n",program,option); 
            exit(4); 
        } 
    break;
    default:
        fprintf(stderr,"%s: too many arguments.\n",program);
    break; 
    }  
 
    exit(0); 
}
