#include<stdio.h> 
#include<stdlib.h> 
#include<assert.h> 
  
struct Node { 
    int num; 
    struct Node* next; 
}; 
struct Node* res = NULL; 
struct Node* a = NULL; 
struct Node* b = NULL; 

void swap(struct Node** target, struct Node** from){
    struct Node* newNode = *from; 
    assert(newNode != NULL); 
    *from = newNode->next;
    newNode->next = *target; 
    *target = newNode; 
} 
  
struct Node* merge(struct Node* a, struct Node* b){ 
    struct Node temp; 
    struct Node* tail = &temp; 
    temp.next = NULL; 

    while(1){ 
        if (a == NULL){ 
            tail->next = b; 
            break; 
        }else if (b == NULL){ 
            tail->next = a; 
            break; 
        } 
        if(a->num <= b->num){
            swap(&(tail->next), &a); 
        }else{
            swap(&(tail->next), &b); 
        }
        tail = tail->next; 
    } 
    return(temp.next); 
} 

void pushTail(struct Node** tar, int newnum){ 
    struct Node* newNode =  (struct Node*) malloc(sizeof(struct Node)); 
  
    newNode->num  = newnum; 
    newNode->next = *tar; 
    *tar = newNode; 
} 

void printList(struct Node *node){ 
    printf("Merge:");
    while (node){ 
        printf(" %d", node->num); 
        node = node->next; 
    } printf("\n");
} 

int main(){ 
  
    pushTail(&a, 5); 
    pushTail(&a, 3); 
    pushTail(&a, 1); 
    pushTail(&b, 10); 
    pushTail(&b, 6); 
    pushTail(&b, 2); 
  
    res = merge(a, b); 
    printList(res); 
  
    return 0; 
} 
