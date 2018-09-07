#include <stdio.h>
#include "operations.h"


int main( ) {

    puts("\nWelcome to the Ryan Eisenbarth grocery store!\n");
    display();
    char prodName[20];
    loadData("main.txt");

    while (customer != 9){

        switch(customer){
            case 1:
                puts("Add Item:\n");
                product p;
                char name[20];
                char qUnit[20];
                char pUnit[20];
                float quant;
                float pPrice;
                printf("Enter the name of the new product: ");
                scanf("%s", name);
                printf("Enter the quantity of the product: ");
                scanf("%f", &quant);
                printf("Enter the quantity units: ");
                scanf("%s", qUnit);
                printf("Enter the price for this product: ");
                scanf("%f", &pPrice);
                printf("Enter the price units: ");
                scanf("%s", pUnit);
                strncpy(p.name, name, 20);
                p.quantity_value = quant;
                strncpy(p.quantity_unit, qUnit, 20);
                p.price_value = pPrice;
                strncpy(p.price_unit, pUnit, 20);

                insert(&LINK, &p);
                display();
                break;
            case 2:
                puts("Purchase Item:\n");
                float i = 0;
                puts("Enter the name of the product to purchase: ");
                scanf("%s", prodName);
                puts("Enter the amount of the product to purchase: ");
                scanf("%f", &i);
                purchase(LINK, prodName, i);
                display();
                break;
            case 3:
                puts("Check Price:\n");
                puts("Enter Name of Product to Check: ");
                scanf("%s", prodName);
                check_price(LINK, prodName);
                display();
                break;
            case 4:
                puts("Items for Sale:");
                showList(LINK);
                display();
                break;
            case 5:
                puts("Clean Up Item:\n");
                puts("Enter Name of Product to Clean: ");
                scanf("%s", prodName);
                rmItem(LINK, prodName);
                display();
                break;
            case 6:
                puts("Find Product:\n");
                puts("Enter Name of Product to Find: ");
                scanf("%s", prodName);
                findItem(LINK, prodName);
                display();
                break;
            case 7:
                puts("Inventory: \n");
                showList(LINK);
                display();
                break;
            case 8:
                puts("All Done!");
                done();
                puts("Thank you for using my store!");
                customer = 9;
                break;
            default:
                printf("You put an invalid command %d!\n", customer);
                display();
                break;
        }
    }
    //system("clear");
    return 0;
}