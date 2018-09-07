//
// Created by Ryan Eisenbarth on 10/23/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef PROJECT2_OPERATIONS_H
#define PROJECT2_OPERATIONS_H
#define N 20

struct product
{
    char name[N];
    float quantity_value;
    char quantity_unit[N];
    float price_value;
    char price_unit[N];
    struct product *next;

};

typedef struct product product;
product *LINK;

float money;

int customer;

//insert a node to the list
void insert(product **l, product *node);

//remove a node from the list
void rmItem(product *l, product *node);

//show list
void showList(product * l);

//load data from file inf
void loadData(char outf[] );

// save data to file outf
void saveData();

// sell product product of quantity q
void purchase(product *l, char product[], float q);

// check out price of product p from list l
void check_price(product *l, char p[]);

// find a product p from list l
void findItem(product *l, char p[]);

void display();

void done();


#endif //PROJECT2_OPERATIONS_H
