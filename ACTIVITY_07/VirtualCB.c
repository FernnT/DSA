#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include "VirtualCB.h"

Date newDate(int date,int month,int year){
	Date newDate;
	
	newDate.date=date;
	newDate.month=month;
	newDate.year=year;
	
	return newDate;
}
Product newProd(int prodID,String prodName,int prodQty,double prodPrice,Date prodExp){
	Product prod;
	
	prod.prodID=prodID;
	strcpy(prod.prodName,prodName);
	prod.prodQty=prodQty;
	prod.prodPrice=prodPrice;
	prod.prodExp=prodExp;
	
	return prod;
	
}
VirtualSpace newVirtualSpace() { 
	VirtualSpace vh;
	
	int i;
	for(i=0;i<MAX;++i){
		vh.data[i].link=i-1;
		vh.data[i].items=newProd(0,"EMPTY",0,0,newDate(0,0,0));
	}
	vh.avail=MAX-1;
	
	return vh;
}

int allocSpace(VirtualSpace *vh){
	int retVal=vh->avail;
	
	if(retVal!=-1){
		vh->avail=vh->data[retVal].link;
	}
	
	return retVal;
}

void push(VirtualSpace *vh,StackList *list ,Product prod){
	int space=allocSpace(vh);
	
	if(space!=-1){
		vh->data[space].items=prod;
		vh->data[space].link=*list;
		
		*list=space;
	}

	
}
void pop(VirtualSpace *vh,StackList *list){
	int delTopStack = *list;
	*list=vh->data[*list].link;
	vh->data[delTopStack].link=vh->avail;
	vh->data[delTopStack].items=newProd(0,"EMPTY",0,0,newDate(0,0,0));
	
	vh->avail=delTopStack;	
}

int peek(VirtualSpace vh,StackList list){
	printf("%4d - %-10s - %02d/%02d/%-5d %10.2fPhp | \n",vh.data[list].items.prodID,vh.data[list].items.prodName,vh.data[list].items.prodExp.date,vh.data[list].items.prodExp.month,vh.data[list].items.prodExp.year,vh.data[list].items.prodPrice);
//	return vh.data[list].items.prodID;
}

void displayStack(VirtualSpace vh,StackList list){
	int i,j=list;
	VirtualSpace temp;
	StackList toptemp=-1;
	temp=newVirtualSpace(temp);
	
	printf("\nITEMS IN STACK: \n");
		for(i=list;i!=-1;i=vh.data[i].link){
			push(&temp,&toptemp,vh.data[i].items);
		}
		for(j=list;j!=-1;j=vh.data[j].link){
			peek(temp,toptemp);
		//	printf("%d | ",peek(temp,toptemp));
			pop(&temp,&toptemp);
		}

}


void initQueue(Queue *q){
	q->front=-1;
	q->rear=-1;
}


void enqueue(VirtualSpace *vh,Product prod,Queue *fr){
	if(fr->front==-1&&fr->rear==-1){
		int space=allocSpace(vh); 
		
		vh->data[space].items=prod;
		vh->data[space].link=fr->rear;
		
		fr->front=space;
		fr->rear=space;
		
	}else{
		int space=allocSpace(vh);
		
		vh->data[fr->rear].link=space;
		
		vh->data[space].items=prod;
		vh->data[space].link=-1;
		
		fr->rear=space;
	}
		
	

}

void dequeue(VirtualSpace *vh,Queue *fr){
	if(fr->front==-1&&fr->rear==-1){
		printf("QUEUE IS EMPTY");
	}else{
		
		vh->data[fr->front].items=newProd(0,"EMPTY",0,0,newDate(0,0,0));
		
		vh->avail=fr->front;
		fr->front=vh->data[fr->front].link;
		
		
	}
}
 int front(VirtualSpace vh,Queue fr){
 		printf("%4d - %-10s - %02d/%02d/%-5d %10.2fPhp | \n",vh.data[fr.front].items.prodID,vh.data[fr.front].items.prodName,vh.data[fr.front].items.prodExp.date,vh.data[fr.front].items.prodExp.month,vh.data[fr.front].items.prodExp.year,vh.data[fr.front].items.prodPrice);
//return vh.data[fr.front].items.prodID;
 }
 
 void displayQueue(VirtualSpace vh,Queue fr){
 	int i;
 	
 		printf("\nITEMS IN QUEUE: \n");
		for(i=fr.front;i!=-1;i=vh.data[i].link){
			front(vh,fr);
			dequeue(&vh,&fr);
		}

 }


void visualizeSpace(VirtualSpace vh,StackList list){
	int i;
	printf("%5s | %-45s | %s\n","INDEX", "ELEMENTS", "NEXT");
	printf("------------------------------------------------------------\n");
	for(i=0;i<MAX;++i){
		printf("%5d | ",i);
		if(vh.data[i].items.prodID==0){
			printf(" %-42s   | ","EMPTY");
		}else{
			printf("%4d - %-10s - %02d/%02d/%-5d %10.2fPhp | ",vh.data[i].items.prodID,vh.data[i].items.prodName,vh.data[i].items.prodExp.date,vh.data[i].items.prodExp.month,vh.data[i].items.prodExp.year,vh.data[i].items.prodPrice);
		}
		printf("%d\n",vh.data[i].link);
	}
	printf("-------------------------------------------------------------\n");
	printf("AVAILABLE: %d\n\n",vh.avail);
	printf("TOP STACK: %d \n\n",list);
}

void populateSpace(VirtualSpace *vh,StackList *list,Queue *q){
	push(vh,list,newProd(101,"Stack1",20,120,newDate(1,12,2025)));
	enqueue(vh,newProd(221,"Queue1",31,92,newDate(1,1,2099)),q);
	push(vh,list,newProd(120,"Stack2",2,140,newDate(5,1,2035)));
	push(vh,list,newProd(101,"Stack3",15,20,newDate(13,12,2075)));
	enqueue(vh,newProd(202,"Queue2",31,92,newDate(1,1,2099)),q);
	push(vh,list,newProd(143,"Stack4",15,20,newDate(13,12,2075)));
	enqueue(vh,newProd(222,"Queue3",31,92,newDate(1,1,2099)),q);
	push(vh,list,newProd(200,"Stack5",31,92,newDate(1,1,2099)));
}
