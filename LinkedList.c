#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
/////////////////////////////////////DISPLAY
void displayList(List list){
	
	while(list!=NULL){
		printf("%d| ",list->data);
		list=list->next;
	}
}
//////////////////////////////////////////////// INITIALIZATION
void initList(List *list){
		*list=NULL;
}

List newList(){
	List list=NULL;
	
	return list;
}
///////////////////////////////////////////////////////////////////NODE CREATOR
NodeType *createNode(DATA data){
	NodeType* newNode = (NodePtr)malloc(sizeof(NodeType));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

/////////////////////////////////////////////////////////////////
bool insertFront(List *list, DATA item){
	 NodeType* newNode = createNode(item);
	 
    if (newNode == NULL) {
        return false; // Failed to create a new node
    }

    newNode->next = *list; // Set the next pointer of the new node to the current first node
    *list = newNode; // Update the list pointer to point to the new node

    return true; 

}

bool insertRear(List *list, DATA item){
	NodePtr curr;
	NodeType *newNode = createNode(item);
	
	 if (newNode == NULL) {
        return false; // Failed to create a new node
    }
	
	if(*list==NULL){
		*list=newNode;
	}else{	
	for(curr=*list;curr->next!=NULL;curr=curr->next){   //Another way to traverse the linked list
	}
	curr->next=newNode;
}
return true;
	
}

bool insertAt(List *list, DATA item, int loc){
	NodePtr curr;
	NodeType *newNode = createNode(item);
	
	 if (newNode == NULL) {
        return false; // Failed to create a new node
    }
    
    curr=*list;
    int i;
    
    if(loc==0){
    	insertFront(list,item);
    	
	}else{
	
    for(i=0;i<loc-1;i++){   	
    	curr=curr->next;
	}
	
	
	
	
	if(curr->next==NULL){  //If we traverse to the end of the linked list
		insertRear(list,item);
	}else{
		newNode->next=curr->next;
		curr->next=newNode;
	}
}
    return true;
    
	
}

bool insertSorted(List *list, DATA data){
	NodePtr curr;
	NodeType *newNode = createNode(data);
	
	 if (newNode == NULL) {
	 	printf("FAILED");
        return false; // Failed to create a new node
    }
    
    if(*list==NULL || newNode->data < (*list)->data){  //If list is empty(NULL) or the new data is less than the 1st data
    	newNode->next=*list;
    	*list=newNode;
    	
    	return true;
	}

    curr=*list;
    while(curr->next!=NULL && newNode->data > curr->next->data){
    	curr=curr->next;
	}
	
	newNode->next=curr->next;
	curr->next=newNode;
	
	return true;
    
}

bool searchItem(List list, DATA key){
	NodePtr curr;
	int counter=0;
	curr=list;

	
	while(curr!=NULL){
		if(curr->data==key){
				printf("\nKey:%d is found at %d of the linked list\n", key, counter);
				return true;
		}
		curr=curr->next;
		counter++;		
	}
	
	printf("\nKey:%d is not in linked list\n", key);
	return false;
	

	
}

int getItem(List list, DATA key){
	NodePtr curr;
	curr=list;

	
	while(curr!=NULL){
		if(curr->data==key){
				printf("\nItem:%d \n", key);
				return key;
		}
		curr=curr->next;	
	}
	
	
	
}

bool deleteFront(List *list){	
	NodePtr temp=*list;
	
	(*list)=(*list)->next;
	
	free(temp);
	return true;
}

bool deleteRear(List *list){
	NodePtr curr;
	curr=*list;
	
	while(curr->next->next!=NULL){
		curr=curr->next;
	}
	
	NodePtr temp=curr->next;	
	curr->next=NULL;
	
	free(temp);
}

int deleteAt(List *list, int loc){
	NodePtr curr;
	curr=*list;
	int i;
	
	if(loc==0){  //If you delete the first node in the list
		deleteFront(list);
	}else{  //If somewhere else
		for(i=0;i<loc-1;i++){
		curr=curr->next;
	}
	
	NodePtr temp=curr->next;
	curr->next=curr->next->next;
		free(temp);
	}
}

bool deleteItem(List *list, DATA key){
	NodePtr curr;
	curr=*list;
	

	if(curr->data==key){ //if the item is found the first node
		NodePtr temp=*list;
		(*list)=(*list)->next;	
		free(temp);
		
	}else{
	
	
	while(curr->next!=NULL){
		if(curr->next->data==key){
			NodePtr temp=curr->next;
			curr->next=curr->next->next;
			free(temp);
			return true;
		}
		curr=curr->next;
		
	}

}

}

int deleteAllItem(List *list, DATA key){
	NodePtr curr;
	curr=*list;
	
	while(curr->next!=NULL){
		deleteItem(list,13);
		curr=curr->next;
	}

	
}
