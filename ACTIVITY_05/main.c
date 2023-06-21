#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10
#include "CursorBased.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	VirtualHeap myHeap= newVirtualHeap(); //the HEAP
	List myList=-1; //basically the head
	

	visualizeSpace(myHeap);

	insertFront(&myHeap,&myList,newStudent(101,"Mary",'f',"BS CS"));
	insertFront(&myHeap,&myList,newStudent(102,"Fish",'m',"BS CS"));
	insertFront(&myHeap,&myList,newStudent(103,"Vi",'m',"BS CS"));
	insertFront(&myHeap,&myList,newStudent(105,"Bobby",'m',"BS CS"));
	insertFront(&myHeap,&myList,newStudent(110,"Chan",'m',"BS CS"));
	insertFront(&myHeap,&myList,newStudent(120,"Lawrs",'m',"BS CS"));
	
	printf("Before the delete:");	
	displayList(myHeap,myList);
	visualizeSpace(myHeap);
	
	printf("After the delete:");		
	removeStudent(&myHeap,&myList,"Mary");
	displayList(myHeap,myList);
	visualizeSpace(myHeap);
	
	
	
	
	
	
	
	
	
	return 0;
}
