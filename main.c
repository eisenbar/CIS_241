#include "functions.h"

/*
 * @author Ryan Eisenbarth
 * @version 10/3/17
 *
 *
 * Welcome to the encrypter and decrypter
 *
 * YOU MUST PUN IN SOMETHING TO ENCRYPT FIRST IN inFile.txt FIRST!
 */
int main() {

    char a[1];

    printf("Welcome to the encrypter and decrypter. The file paths given are listed.\nPlease change the 4 paths if you want to save elsewhere.\nMake sure that inFile.txt has the char input you want to encrypt first!\n");
    printf("Enter e if you want to ectrypt inFile.txt or d to decrypt outFile.txt:");
    scanf("%s", a);
    if (a[0] == 'e') {
        processInput("/Users/ryaneisenbarth/CLionProjects/CIS241/Project1_v2/inFile.txt", "/Users/ryaneisenbarth/CLionProjects/CIS241/Project1_v2/outFile.txt", 1);
        printf("Now check outFile.txt to see your encrypted text!\n");
        return 0;
    }


    if( a[0] == 'd') {
        processInput("/Users/ryaneisenbarth/CLionProjects/CIS241/Project1_v2/outFile.txt", "/Users/ryaneisenbarth/CLionProjects/CIS241/Project1_v2/finalFile.txt", 0);
        printf("Now check finalFile.txt to see your original text!\n");
        return 0;
    }
    printf("YOU DID NOT ENTER e OR d. RUN PROGRAM AGAIN");
    return 101;

}