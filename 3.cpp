#include <stdio.h>
#include <stdlib.h>

struct Node{
    int num;
    Node *next;
}*head, *tail;

void push(struct Node** head, int newnum) {  
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));  
  
    newNode->num = newnum;  
    newNode->next = *head; 
    *head = newNode;  
}  

void mid(struct Node* head){
    struct Node *fast = head;
    struct Node *slow = head;
    if(head != NULL){
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
    }printf("Mid : %d\n", slow->num);
}

int main(){
    struct Node *head = NULL;
    int t;
    scanf("%d", &t);
    
    for(int i = t; i > 0; i--){
        push(&head, i);
        mid(head);
    }
    

    return 0;
}