//
// Created by Ryan Eisenbarth on 10/2/17.
//
#include "functions.h"


char* removeDuplicates(char str[])
{
    char found[256] = {0};
    int i = 0, j = 0;

    for(i=0; str[i] != '\0'; i++)
    {
        if(0 == found[str[i]]) //Check if character is already found.
        {
            found[str[i]] = 1; //If a character is found for the first time, found.
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0'; //sets last character to terminating char
    return str;
}


char *encrypt(char key[]){

    char temp[] = {"ZYXWVUTSRQPONMLKJIHGFEDCBA"};
    char *newMessage, *new_str;


    //create key
    if((new_str = malloc(strlen(key)+strlen(temp)+1)) != NULL){
        new_str[0] = '\0';
        strcat(new_str,key);
        strcat(new_str,temp);
    }
    removeDuplicates(new_str);

    //create encrypted message
    for(int i = 0; i < strlen(key); i++) {

        newMessage[i] = new_str[key[i] - 'A'];
    }

    //saves the key to key.txt for later use
    FILE *keySave;
    keySave = fopen("/Users/ryaneisenbarth/CLionProjects/CIS241/Project1_v2/finalFile.txt", "w");
    if (key != NULL)
    {
        fputs(new_str, keySave);
    }
    fclose(keySave);


    return newMessage;
}

char *decrypt(char encrypt[])
{

    //opens key.txt to be read into the new key
    FILE *key;
    char c;
    int size, filePos = 0;

    key = fopen("/Users/ryaneisenbarth/CLionProjects/CIS241/Project1_v2/finalFile.txt", "r");


    //reads key to cipher
    fseek(key, 0, SEEK_END);
    size = ftell(key);
    rewind(key);

    char cipher[size];

    while ((c = getc(key)) != EOF){
        cipher[filePos] = c;
        filePos++;
    }
    fclose(key);


    char encr[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char *decryption;


    if((decryption = malloc(strlen(encrypt) + 1)) != NULL){
        decryption[0] = '\0';

        for(int i = 0; i < strlen(encrypt); i++){
            printf("Made it into for loop1\n");

            char z = encrypt[i];
            printf("Made it into for loop2\n");

            char *ptr = strchr(cipher, z);
            printf("Made it into for loop3\n");

            unsigned long index = ptr - cipher;
            printf("Made it into for loop4\n");

            decryption[i]  = encr[index];
            printf("Made it into for loop5\n");
        }
    }
    printf("This is decryption: %s\n", decryption);
    return decryption;
}

void processInput(FILE * inf, FILE * outf, int w){
    FILE *fp1, *fp2;
    char c;
    int size, filePos = 0;

    char *temp;


    fp1 = fopen(inf, "r");
    fp2 = fopen(outf, "w");

    //reads the key to inFile
    fseek(fp1, 0, SEEK_END);
    size = ftell(fp1);
    rewind(fp1);

    char key[size];

    while ((c = getc(fp1)) != EOF){
        key[filePos] = c;
        filePos++;
    }
    /*
     * MANIPULATE KEY HERE
     */
    if(w == 1)
        temp = encrypt(key);

    if(w == 0)
        temp = decrypt(key);

    //writes key to outFile
    if (fp2 != NULL)
    {
        fputs(temp, fp2);
    }
    fclose(fp1);
    fclose(fp2);
}
