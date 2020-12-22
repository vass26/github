#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int num;
    Node *next;
};

Node *createNode(int num){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->num = num;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** head, int num){
    struct Node* newNode = new Node();
    newNode->num = num;
    newNode->next = *head;
    *head = newNode;
}   

void print(struct Node* head , int num){
    struct Node* temp = head;
    int len = 0;

    while(temp != NULL){
        temp = temp->next;
        len++;
    }

    if(len < num)return;
    temp = head;

    for(int i = 0; i < len-num+1; i++){
        temp = temp->next; 
        printf("%d ", temp->num);
    }

    return;
}


int main(){
    struct Node* head = NULL;
    push(&head, 10);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);
    print(head,4);

  return 0;
}