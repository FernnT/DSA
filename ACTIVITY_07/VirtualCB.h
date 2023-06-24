#ifndef VIRTUALCB_H
#define VIRTUALCB_H
#include<stdbool.h>
#define MAX 20

typedef char String[30];

typedef struct{
	int date;
	int month;
	int year;
}Date;

typedef struct{
	int prodID;
	String prodName;
	int prodQty;
	double prodPrice;
	Date prodExp;
	
}Product;

typedef struct{
	Product items;
	int link;
}Stype;

typedef struct{
	Stype data[MAX];
	int avail;
}VirtualSpace;

typedef int StackList;

typedef struct{
	int front;
	int rear;
}Queue;

Date newDate(int date,int month,int year);
Product newProd(int prodID,String prodName,int prodQty,double prodPrice,Date prodExp);
VirtualSpace newVirtualSpace(); 
int allocSpace(VirtualSpace *vh);

void push(VirtualSpace *vh,StackList *list ,Product prod);
void pop(VirtualSpace *vh,StackList *list);
int peek(VirtualSpace vh, StackList list);
void displayStack(VirtualSpace vh,StackList list); 



void initQueue(Queue *q);
void enqueue(VirtualSpace *vh,Product prod,Queue *fr);
void dequeue(VirtualSpace *vh,Queue *fr);
int front(VirtualSpace vh,Queue fr);
void displayQueue(VirtualSpace vh,Queue fr);


void visualizeSpace(VirtualSpace vh,StackList list);

void populateSpace(VirtualSpace *vh,StackList *list,Queue *q);
#endif
