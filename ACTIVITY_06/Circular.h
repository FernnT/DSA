#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <stdbool.h>
#define MAX 10
#define EMPTY 9999

typedef char String[30];

typedef struct{
	int elems[MAX];
	int front;
	int rear;
}Queue;

void initQueue(Queue *q);
void enqueue(Queue *q, int item); //push
int dequeue(Queue *q;);  //pop
int front(Queue q);  //peek
bool isEmpty(Queue q);
bool isFull(Queue q);
void display(Queue q);
bool removeItem(Queue *q, int item); //no element traversal
Queue removeEven(Queue *q);  //remove all even and return all deleted item sotred in Q
int doubleTheValue(Queue *q, int value);  //doubles the value of the multiple of value //and return how many changed

#endif
