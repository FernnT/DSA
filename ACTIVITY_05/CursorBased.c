#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "CursorBased.h"
#define MAX 10

Student newStudent(int StudId,String studName,char sex,String program){ 
	Student s;
	
	s.StudId=StudId;
	strcpy(s.studName,studName);
	s.sex=sex;
	strcpy(s.program,program);
	
	return s;
}

VirtualHeap newVirtualHeap(){
	VirtualHeap vh;
	int i;
	for(i=0;i<MAX;++i){
	vh.elems[i].elem=newStudent(0,"",' ',"");  //	vh.elems[i].elem.StudId=0;// you can also do this;
		vh.elems[i].next=i-1;
	}
	vh.avail=MAX-1;
	
	return vh;
}
int allocSpace(VirtualHeap *vh){
	int retVal=vh->avail;
	
	if(retVal!=-1){
		vh->avail=vh->elems[retVal].next;  
	}
	
	return retVal; //
}
void insertFront(VirtualHeap *vh, List *list,Student s){	 
	List temp=allocSpace(vh);

	if(temp!=-1){          
		vh->elems[temp].elem=s;
		vh->elems[temp].next=*list;      
		*list=temp;   
	}
	
}
 ////
void displayList(VirtualHeap vh,List list){
	int i=list;
	printf("\n\n Items in the List: \n");
	while(i!=MAX){
		printf(" %d | ",vh.elems[i].elem.StudId);
		printf(" %s | ",vh.elems[i].elem.studName);
		printf(" %s  \n",vh.elems[i].elem.program);
		i++;
	}
		printf("\n\n");
}

void visualizeSpace(VirtualHeap vh){
	int i;
	printf("%5s | %30s | %s\n","INDEX", "ELEMENTS", "NEXT");
	printf("---------------------------------------------\n");
	for(i=0;i<MAX;++i){
		printf("%5d | ",i);
		if(vh.elems[i].elem.StudId==0){
			printf("%30s | ","EMPTY");
		}else{
			printf("%4d - %23s | ",vh.elems[i].elem.StudId,vh.elems[i].elem.studName);
		}
		printf("%d\n",vh.elems[i].next);
	}
	printf("---------------------------------------------\n");
	printf("AVAILABLE: %d\n\n",vh.avail);

}
void deallocSpace(VirtualHeap *vh, int index){
	if(index !=-1 && index < MAX ){ //index !=-1 index < MAX
		vh->elems[index].next=vh->avail;
		vh->elems[index].elem=newStudent(0,"",' ',"");
		vh->avail=index;
	}
	
}	

Student removeStudent(VirtualHeap *vh,List *list, String keyword){
	List trav;
	
	for(trav=*list;trav!=-1;trav=vh->elems[trav].next){
		if(strcmp(vh->elems[trav].elem.studName,keyword)==0){
			deallocSpace(vh,trav);
			return vh->elems[trav].elem;
		}
		
	}
	
}

