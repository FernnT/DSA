#include <stdio.h>
#include <stdlib.h>
#include "Circular.h"

void initQueue(Queue *q){
	q->front=7;
	q->rear=6;
	int i;
		for(i=0;i<MAX;++i){
			q->elems[i]=EMPTY;
		}
}
void enqueue(Queue *q, int item){
	if(!isFull(*q)){ // moves rear around the circle //if 1 elem rear and front will be the same
		q->rear=(q->rear+1)%MAX;
		q->elems[q->rear]=item;

	}
}

int dequeue(Queue *q){
	if(!isEmpty(*q)){
		q->elems[q->front]=EMPTY;
		q->front=(q->front+1)%MAX;
	}
}
int front(Queue q){
	if(!isEmpty(q)) {
		return q.elems[q.front];
	}
	return EMPTY;
}
bool isEmpty(Queue q){
	//	printf("EMPTY");
	return (q.rear+1)%MAX==q.front;
}
bool isFull(Queue q){
	return (q.rear+2)%MAX==q.front;
}
//void visualize(Queue q){
//	int i;
//	
//	printf("%5s | %5s | %s\n","INDEX","VALUE","POSITION");
//	printf("-------------------------\n");
//	
//	for(i=0;i<MAX;++i){
//		printf("%5d | ",i);
//		if(q.elems[i]!=EMPTY){
//		}else{
//			printf("%5d | ",q.elems[i]);
//			if(i==q.front){
//				printf("FRONT");
//			}else if(i==q.rear){
//				printf("REAR");
//			}
//			printf("\n");
//		}
//	}	
//	
//		printf("-------------------------\n");
//	
//}

void visualize(Queue q){
	int i;
	
	printf("%5s | %5s | %s\n","INDEX","VALUE","POSITION");
	printf("-------------------------\n");
	
	for(i=0;i<MAX;++i){
		printf("%5d | ",i);
		if(q.elems[i]!=EMPTY){
				printf("%5d | ",q.elems[i]);
		}else{
			printf("%5s | ", " ");
			
		}
		if(i==q.front){
			printf("FRONT ");
		}if(i==q.rear){
			printf("REAR ");
		}
		printf("\n");
		
	}	
	
		printf("-------------------------\n");
	
}

void display(Queue q){
	int i;
	int j=(q.rear+1)%MAX;
	
	for(i=q.front;i!=j;i=(i+1)%MAX){
		printf(" %d |",front(q));
		dequeue(&q);
	}

}
bool removeItem(Queue *q, int item){
	int i;
	Queue temp;
	initQueue(&temp);
	int j=(q->rear+1)%MAX;
	
	for(i=q->front;i!=j;i=(i+1)%MAX){	
		if(q->elems[i]!=item){
			enqueue(&temp,q->elems[i]);
			dequeue(q);
		}else{
			dequeue(q);
		}
}
	j=(temp.rear+1)%MAX;
	for(i=temp.front;i!=j;i=(i+1)%MAX){
		enqueue(q,temp.elems[i]);
		dequeue(&temp);
	}
	
	return true;
}


Queue removeEven(Queue *q) {
    int i = q->front;
    int j = (q->rear+1)%MAX;
    Queue temp;
    initQueue(&temp);

    while (i!=j) {
        if (q->elems[i]%2== 0) {
            enqueue(&temp,q->elems[i]);
            removeItem(q,q->elems[i]);
            j = (q->rear+1)%MAX;
        } else {
            i = (i+1)%MAX;
        }
    }

    return temp;
}

int doubleTheValue(Queue *q, int value) { //doubles the value of the multiple of value //and return how many changed
		int i,changed=0;
		int j=(q->rear+1)%MAX;
		for(i=q->front;i!=j;i=(i+1)%MAX){
			if(q->elems[i]%value==0){
				q->elems[i]=q->elems[i]*2;
				changed++;
			}
		}
		return changed;
		
		
}
