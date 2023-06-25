#include <stdio.h>
#include <stdlib.h>
#include "Circular.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choice;
	Queue myQueue;
	String menuOption[10]={"Enqueue","Dequeue","isEmpty","isFull","Display","Visualize","Front","Delete item","Remove Even","Double the value"};
	
	initQueue(&myQueue);
	
	Queue removed;
	int i,value,del,changed;
	do{
		system("cls");
		printf("MENU\n");
		
		for(i=0;i<10;++i){
			printf("[%d] %s \n",i+1,menuOption[i]);
		}
			visualize(myQueue);
		printf("Enter your choice <0 to EXIT> : ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				printf("Enqueue\n");
				printf("Enter a number: ");
				scanf("%d",&value);
				enqueue(&myQueue,value);
				visualize(myQueue);
				break;
			case 2:
				printf("Dequeue\n");
				 dequeue(&myQueue);
				visualize(myQueue);
				break;
			case 3:
				printf("Check if Empty\n");
				break;
			case 4:
				printf("Check if Full\n");
				break;
			case 5:
				printf("Display Queue");
				display(myQueue);
				break;
			case 6:
				printf("Visualize\n");
				visualize(myQueue);
				break;
			case 7:
				printf("Front\n");
				break;
			case 8:
				printf("Input item to delete: ");
				scanf("%d",&del);
				removeItem(&myQueue,del);
				visualize(myQueue);
				break;
			case 9:
				removed=removeEven(&myQueue);
				visualize(myQueue);
				printf("Items removed: ");
				display(removed);
				break;
			case 10:
				printf("Enter a number: ");
				scanf("%d",&value);
				changed=doubleTheValue(&myQueue,value);
				printf("%d|  items changed",changed);
				
				break;
			case 0:
				printf("THANK YOU\n");
			default:
				printf("INVALID");
									
				
		}
		system("pause");
		
	}while(choice !=0);
	
	printf("BYE\n");

	
	
	return 0;
}
