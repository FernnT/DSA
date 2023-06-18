#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int main(int argc, char *argv[]) {

List list,list2;	
	
initList(&list);///list1

list2=newList();///list2
	
insertFront(&list,81);
insertFront(&list,69);
insertFront(&list,13);
insertFront(&list,6);
insertRear(&list,13);
                               

								
insertAt(&list,25,2);
                                

insertSorted(&list,13);

displayList(list);

searchItem(list,32);

int itemm=getItem(list,42);
printf("recieved item: %d\n",itemm);

deleteFront(&list);
printf("\nAfter delete Front\n");
displayList(list);

printf("\nAfter delete Rear\n");
deleteRear(&list);
displayList(list);

printf("\nAfter delete At\n");
deleteAt(&list,2);
displayList(list);

printf("\nAfter delete Item\n");
deleteItem(&list,420);
displayList(list);

printf("\nAfter delete ALLItem\n");
deleteAllItem(&list,13);
displayList(list);
	
	
	
	
	
	
	
	
	
	
	return 0;
}
