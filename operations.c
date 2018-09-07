//
// Created by Ryan Eisenbarth on 10/23/17.
//
#include "operations.h"

int customer = 0;

//insert a node to the list
void insert(product **l, product *node){
    product *newProd;
    newProd = malloc(sizeof(product));
    strncpy(newProd->name, node->name, 20);
    strncpy(newProd->price_unit, node->price_unit, 20);
    newProd->price_value = node->price_value;
    strncpy(newProd->quantity_unit, node->quantity_unit, 20);
    newProd->quantity_value = node->quantity_value;
    newProd->next = *l;
    *l = newProd;

//    if(l->name == newProd->name){
//        newProd->quantity_value++;
//        return;
//    }
//    if ( l ->next == NULL ) {
//        l ->next = newProd;
//        newProd->next = NULL;
//        return;
//    }
//    insert(l->next, newProd);
}

//remove a node from the list
void rmItem(product *l, product *node){
    product *curr = l;

    if(strcmp(curr->name, l->name) == 0){
        LINK = curr->next;
    }
    else{
        while(curr->next != NULL){
            if(strcmp(curr->next->name, l->name) == 0){
                product *deleted = curr->next;
                if(deleted->next != NULL){
                    curr->next = deleted->next;
                    puts("Product Removed!");
                }
                else
                    curr->next = NULL;
            }
            break;
        }
        curr = curr->next;
    }
}

//show list
void showList(product *l){
    product *curr = l;

    while(curr != NULL){
        printf("Product Name: %s\n", curr->name);
        printf("Price: %f per %s\n", curr->price_value, curr->price_unit);
        printf("Quantity: %f %s\n\n", curr->quantity_value, curr->quantity_unit);
        curr = curr->next;
    }
}

//load data from file inf
void loadData(char outf[] ){
    FILE *main = fopen(outf , "r");

    if(main == NULL){
        printf("Could not load file!!\n");
        exit(1);
    }


    product p;
    char buffer[20];
    int c = 0;

    while (fgets(buffer, sizeof(buffer), main)) {
        buffer[strlen(buffer) - 1] = '\0';
        switch(c) {
            case (0):
                strcpy(p.name, buffer);
                break;
            case (1):
                p.quantity_value = strtof(buffer, NULL);
                break;
            case (2):
                strcpy(p.quantity_unit, buffer);
                break;
            case (3):
                p.price_value = strtof(buffer, NULL);
                break;
            case (4):
                strcpy(p.price_unit, buffer);
                c = -1;
                insert(&LINK, &p);
                break;
        }
        c++;
    }
    fclose(main);
}

// save data to file outf
void saveData(){
    FILE *main = fopen("main.txt", "w");
    if(main == NULL){
        printf("Could not save!\n");
        exit(1);
    }

    product* link = LINK;

    while(link != NULL){
        fprintf(main, "%s\n", link->name);
        fprintf(main, "%f\n", link->quantity_value);
        fprintf(main, "%s\n", link->quantity_unit);
        fprintf(main, "%f\n", link->price_value);
        fprintf(main, "%s\n", link->price_unit);
        link = link->next;

    }
    fclose(main);
}

// sell product product of quantity q
void purchase(product *l, char product[], float q){

    float newquant;

   if(l != NULL){
       if(l->quantity_value >= q){
           newquant = l->quantity_value - q;
           l->quantity_value = newquant;
           money += q * l->price_value;
           printf("You Purchased %f %s of %s\n", q, l->quantity_unit, l->name);
           printf("Profits so far: %f\n", money);
       }
       else
           puts("We do not have enough in stock!");
   }
   else
       puts("Could not find product");
}

// check out price of product p from list l
void check_price(product *l, char p[]){

    product* curr = l;

    while(curr != NULL){
        if(strcmp(curr->name, p) == 0){
            printf("%s price is: %f%s\n", curr->name, curr->price_value, curr->price_unit);
        }
        else
            puts("Could not find product");
        curr = curr->next;
    }
}

// find a product p from list l
void findItem(product *l, char p[]){

    product *curr = l;

    while(curr != NULL){
        if(strcmp(curr->name, p) == 0){
            printf("%s:\n", curr->name);
            printf("Price: %f per %s\n", curr->price_value, curr->price_unit);
            printf("Quantity: %f %s\n\n", curr->quantity_value, curr->quantity_unit);
            break;
        }
        else
            puts("Could not find product!");
        curr = curr->next;
    }

//    //found product
//    if(curr->name == p) {
//        printf("%s:\n", curr->name);
//        printf("Price: %f per %s\n", curr->price_value, curr->price_unit);
//        printf("Quantity: %f %s\n\n", curr->quantity_value, curr->quantity_unit);
//        return;
//    }
//    //didn't find product
//    if(curr->next == NULL){
//        printf("Couldn't find product!");
//        return;
//    }
    //try next item in list
    //findItem(curr->next, p);
}

void done(){
    saveData();
    printf("The money made today: $%f\n", money);
    printf("Have a great day!\n");
}

void display() {
    puts("Let me know what you want to do according to the menu\n");
    puts("============================================================");
    puts("1: Add product to store            2: Purchase product from store\n");
    puts("3: Check price of a product        4: Show Products in Store\n");
    puts("5: Clean up a product from store   6: Find Product\n");
    puts("7: Inventory                       8: Done for today\n");
    puts("What would you like to do?\n");
    scanf("%d", &customer);
    printf("%d selected\n", customer);
}