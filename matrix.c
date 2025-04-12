#include <stdio.h>
#include <stdlib.h>

void swap(int*, int*);

int main() {
    printf("input N \n");
    int N;
    scanf("%d", &N);

    int** arr = (int**) malloc(N * sizeof(int*));
    for (int i = 0; i < N; ++i){
        arr[i] = (int*) malloc(N * sizeof(int));
        for (int j = 0; j < N; ++j){
            scanf("%d", &arr[i][j]);
        }
    }


    for (int i = 0; i < N; ++i){
        for (int j = i + 1; j < N; ++j){
            
            swap(&arr[i][j], &arr[j][i]);
        }
        
    }


    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < N; ++i)
        free(arr[i]);
    free(arr);
    return 0;
}
 
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

