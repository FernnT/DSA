#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10

typedef int DATA;

typedef struct node{
	DATA data;
	int top;
	struct node* next;
}Stack, *StackPtr; 

void initStack(StackPtr *list);
StackPtr createNode(DATA item);
bool isEmpty(StackPtr *list);
//bool isFuLL(StackPtr *list); //cant use in linked list because a linked list can never be full;
void push(StackPtr *list,StackPtr node);
void pop(StackPtr *list);
DATA peek(StackPtr *list);
void display(StackPtr list);
void visualize(StackPtr list);

int main(){
	StackPtr head;
	initStack(&head);
	
	push(&head,createNode(2));
	push(&head,createNode(5));
	push(&head,createNode(6));
	push(&head,createNode(9));
	push(&head,createNode(10));	
	
	display(head);
	
	visualize(head);
	
	printf("\nAfter pop: \n");
	pop(&head);
	visualize(head);
	
		return 0;
}
void initStack(StackPtr *list){
			*list=NULL;
}

StackPtr createNode(DATA item){
	StackPtr newNode=(StackPtr)malloc(sizeof(Stack));
	newNode->data=item;
	newNode->next=NULL;
	
	return newNode;	
}

void push(StackPtr *list,StackPtr node){
	
	if(*list==NULL){
		(*list)=node;
	}else{
		node->next=(*list);
		(*list)=node;
	}
	
}

void pop(StackPtr *list){
	if(*list==NULL){
		printf("EMPTY");
	}else{
		StackPtr temp=*list;
		
		(*list)=(*list)->next;
		
		free(temp);
	}
	
}
DATA peek(StackPtr *list){
	return (*list)->data;
}

void display(StackPtr list){
	 if (list == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack Contents: ");
        StackPtr current = list;
        while (current != NULL) {
            printf(" %d |", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void visualize(StackPtr list) {
    if (list == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack Visualization:\n");
        StackPtr current = list;
        while (current != NULL) {
            printf("| %d |\n", current->data);
            printf("-----\n");
            current = current->next;
        }
        printf("\n");
    }
}

	
	
	
	
	
	
	

