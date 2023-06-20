#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10

typedef int DATA;

typedef struct {
	DATA arr[MAX];
	int top;
}Stack;

void initStack(Stack *list);
bool isEmpty(Stack *list);
bool isFuLL(Stack *list); //cant use in linked list;
void push(Stack *list,int val);
void pop(Stack *list);
DATA peek(Stack *list);
void display(Stack list);
void visualize(Stack list);

int main(){

	Stack list;
	initStack(&list);
	push(&list,1);
	push(&list,2);
	push(&list,3);
	push(&list,4);
	push(&list,5);
	
	 display(list);

	 

	 visualize(list);	
	 
	 printf("\nAfter pop: \n");
	 pop(&list);
	display(list);

	 visualize(list);	
		return 0;
}
	
	
	
	
	
	
	
	
	
	
	


void initStack(Stack *list){
	list->top=-1;
}
bool isEmpty(Stack *list){
	if(list->top==-1){
		return true;
	}else{
		return false;
	}
}
bool isFuLL(Stack *list){
	if(list->top==MAX-1){
		return true;
	}else{
		return false;
	}
}



void push(Stack *list,int val){
//	int val;
//	
//	if(stack.top==MAX-1){
//		printf("FULL");
//	}else{
//		printf("Enter element to push ");
//		scanf("%d",&val);
//		stack.top=stack.top+1;
//		stack.arr[top]=val;		
//	}
	if(list->top==MAX-1){
		printf("FULL");
	}else{
		list->top=list->top+1;
		list->arr[list->top]=val;
	}
}

void pop(Stack *list){
//	if(Stack.top==-1){
//		printf("EMPTY!");
//	}else{
//		printf("Deleted")
//		Stack.top=Stack.top-1;
//		
//	}
if(list->top==-1){
	printf("EMPTY!");
}else{
	list->top=list->top-1;
}

}
DATA peek(Stack *list){
	return list->arr[list->top];
}

void display(Stack list){
	Stack list2;
	initStack(&list2);
	
	int i,temp;
		for(i=list.top;i>-1;--i){
			temp=list.arr[i];  
//			list2->top++;
//			list2->arr[list2->top]=temp;
			push(&list2,temp);
			pop(&list);
			
		//	printf("%d |", peek(&list2));
		}
		printf("Stack contents: ");
		for(i=list2.top;i>-1;--i){
			temp=list2.arr[i];
		//	printf("top of arr1: %d\n", list->top);
			push(&list,temp);
			printf(" %d |", peek(&list));
		}
		printf("\n");
}
void visualize(Stack list){
	if(isEmpty(&list)){
		printf("Stack is empty. \n");
	}
	int i;
	for(i=list.top;i>=0;i--){
		//	printf("top of arr: %d\n", list->top);
		printf("| %d |\n",list.arr[i]);
		printf("-----\n");
	}
	printf("\n");
}

