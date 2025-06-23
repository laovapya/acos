#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;     
    struct node* next; 
};


int main() {
    printf("input numbers for list, input 0 to stop \n");

    struct node* list =  NULL;
    struct node* current = NULL;
    while(1){
        int input;
        scanf("%d", &input);
        if (input == 0)
            break;
        struct node* next = (struct node*) malloc(sizeof(struct node));
        next->data = input;
        next->next = NULL; //null check to see if list ended
        if (current == NULL){
            list = next; //pointer to first element 
            current = next;
        } 
        else{
            current->next = next;
            current = next;
        }
    }
    

    //reverse
    current = list; 
    struct node* previous = NULL;
    while (current != NULL) { 
        struct node* temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }
    list = previous;
    //print  
    current = list;
    while (current != NULL) { 
        printf("%d ", current->data);
        current = current->next;
    }
    //free
    while (list != NULL) { 
        struct node* temp = list;
        list = list->next;
        free(temp);
    }
    return 0;
}
 


