#include <stdio.h>
#include <stdlib.h>

void swap(int*, int*);

int main() {
    printf("input N \n");
    int N;
    scanf("%d", &N);

    int* arr = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i){
        scanf("%d", arr + i);
    }
    for (int i = 0; i < N / 2; ++i){
        swap(arr + i, arr + N - 1 - i);
    }
    for (int i = 0; i < N; ++i){
        printf("%d", arr[i]);
    }
    free(arr);
    return 0;
}
 
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

