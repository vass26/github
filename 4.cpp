#include <stdio.h>
#include <stdlib.h>

struct Node{
    int num;
    Node *next;
};

void remove(struct Node* head){
    struct Node* curr = head;
    struct Node* temp;

    if(curr == NULL){
        return;
    }

    while(curr->next != NULL){
        if(curr->num == curr->next->num){
            temp = curr->next->next;
            free(curr->next);
            curr->next = temp;
        }else{
            curr = curr->next;
        }
    }
}

void pushtail(struct Node** head, int newnum){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->num = newnum;
    newNode->next = *head;
    *head = newNode;
}

void print(struct Node *node){
    while(node){
        printf("%d ", node->num);
        node = node->next;
    }
}

int main(){
    struct Node* head = NULL;

    pushtail(&head, 10); 
    pushtail(&head, 12); 
    pushtail(&head, 12);   
    pushtail(&head, 8); 
    remove(head);
    print(head);
     


    return 0;
}