#include <stdio.h>
void swap(int*, int*);

int main() {
    printf("input 2 integers \n");
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("a: %d b: %d \n", a, b);
    swap(&a, &b);
    printf("swap\n");
    printf("a: %d b: %d \n", a, b);
    return 0;
}
 

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
