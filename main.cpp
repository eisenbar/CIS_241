#include <iostream>

void swap(int *a, int *b){

    int c = *a;
    *a = *b;
    *b = c;
}
int main() {
    int x = 5;
    int z = 9;

    printf("%d, %d\n", x, z);
    swap(&x, &z);
    printf("%d, %d\n", x, z);
    return 0;
}