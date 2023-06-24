#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include "VirtualCB.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Product newItem;
	VirtualSpace vh;
	vh=newVirtualSpace();
	StackList list=-1;
	Queue q;
	initQueue(&q);
	
	String options[9]={"VISUALIZE","PUSH","POP","PEEK","DISPLAY STACK","ENQUEUE","DEQUEUE","FRONT","DISPLAY QUEUE"};
	
	int choice;
	populateSpace(&vh,&list,&q); //if kapoy mag populate sa space
	do{
		system("cls");
		int i;
	
		for(i=0;i<9;++i){
			printf("[%d] %s\n",i+1,options[i]);
		}
	
		printf("Enter your choice <0 to EXIT> : ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				visualizeSpace(vh,list);
				break;
			case 2:
				printf("Enter details: \n");
				printf("Enter product ID: "); 
				scanf("%d",&newItem.prodID);
				printf("Enter product Name: ");
				scanf("%s",&newItem.prodName);
				printf("Enter product Price: ");
				scanf("%lf",&newItem.prodPrice);
				printf("Enter product Qty: ");
				scanf("%d",&newItem.prodQty);
				printf("Enter product dd/mm/yy: ");
				scanf("%d",&newItem.prodExp.date);
				scanf("%d",&newItem.prodExp.month);
				scanf("%d",&newItem.prodExp.year);
				
				push(&vh,&list,newItem);
				visualizeSpace(vh,list);
				break;
			case 3:
				pop(&vh,&list);
				visualizeSpace(vh,list);
				break;
			case 4:
				printf("\nTop of Stack:\n");
				peek(vh,list);
				break;
				
			case 5:
				displayStack(vh,list);
				break;
				
			case 6:
				printf("Enter details: \n");
				printf("Enter product ID: "); 
				scanf("%d",&newItem.prodID);
				printf("Enter product Name: ");
				scanf("%s",&newItem.prodName);
				printf("Enter product Price: ");
				scanf("%lf",&newItem.prodPrice);
				printf("Enter product Qty: ");
				scanf("%d",&newItem.prodQty);
				printf("Enter product dd/mm/yy: ");
				scanf("%d",&newItem.prodExp.date);
				scanf("%d",&newItem.prodExp.month);
				scanf("%d",&newItem.prodExp.year);
			
				enqueue(&vh,newItem,&q);
				visualizeSpace(vh,list);
				break;
				
			case 7:
				dequeue(&vh,&q);
				visualizeSpace(vh,list);
				break;
			case 8:
				front(vh,q);
				break;
			case 9:
				displayQueue(vh,q);
				break;
			case 0:
				printf("BYE\n");
				break;
			default:
				printf("INVALID");
		}
		system("pause");
		
	}while(choice!=0);
	
	
	
	return 0;
}
