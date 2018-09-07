//
// Created by Ryan Eisenbarth on 10/2/17.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef UNTITLED1_FUNCTIONS_H
#define UNTITLED1_FUNCTIONS_H
#endif //UNTITLED1_FUNCTIONS_H

// remove duplicate characters in array word and return the result string
char * removeDuplicates(char word []);


// initialize the encrypt array with appropriate cipher letters according to the given key
char *encrypt(char key[]);

// initialize the decrypt array with appropriate substitute letters based on the encrypt array
char *decrypt(char encrypt[]);

// process data from the input file and write the result to the output file
// pass the encrypt array to parameter substitute if encryption is intended
// pass the decrypt array to parameter substitute if decryption is intended
void processInput(FILE * inf, FILE * outf, int w);

