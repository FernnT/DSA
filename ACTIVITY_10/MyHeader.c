#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyHeader.h"

VSpace newVSpace(int max) {
    VSpace vs;
    
    vs.max = max%2 == 0? max: max + 1;
    vs.count = 0;
    vs.data = malloc(sizeof(Data) * vs.max);
    vs.avail = vs.max/2;
    
    int i;
    for(i = 0; i < vs.avail; ++i) {
        vs.data[i].elem = EMPTY;
        vs.data[i].link = -1;
    }
    
    for(; i < vs.max-1; ++i) {
        vs.data[i].elem = EMPTY;
        vs.data[i].link = i + 1;    
    }
    vs.data[i].elem = EMPTY;
    vs.data[i].link = -1;
    
    return vs;
}
int allocSpace(VSpace *vs){
	int retVal=vs->avail;
	
	vs->avail=vs->data[vs->avail].link;
	
	return retVal;
}
void freeSpace(VSpace *vs,int loc){
	int index=hash(*vs,vs->data[loc].elem);
	
	vs->data[loc].elem=EMPTY;
	vs->avail=loc;
	vs->data[index].link=vs->data[loc].link;
		vs->count--;
	
}

int hash(VSpace vs,int elem){
	
	return (elem+31)%(vs.max/2);
	
}
bool addElement(VSpace *vs,int elem){
	int index=hash(*vs,elem);
	if(vs->avail==-1){
		packingDensity(vs);
	}
	if(vs->data[index].elem==EMPTY){
		vs->data[index].elem=elem;
		vs->count++;
	}else{
		int retVal=allocSpace(vs);
		
		vs->data[retVal].elem=elem;
		vs->data[retVal].link=-1;
		
		int prev=index;
		
		while(vs->data[prev].link!=-1){
			prev=vs->data[prev].link;
		}
		vs->data[prev].link=retVal;
			vs->count++;
	}
	

	if(vs->count>=(vs->max*.7)){
		packingDensity(vs);
	}
	
	
}
bool removeElement(VSpace *vs,int elem){
	int index=hash(*vs,elem);
	
	if(vs->data[index].elem!=EMPTY && vs->data[index].elem!=DELETED){

		if(vs->data[index].link==-1){
		vs->data[index].elem=EMPTY;
		vs->count--;
		}else{
		vs->data[index].elem=DELETED;
		vs->count--;
	}
		
	}
	else if(vs->data[index].elem==DELETED){
		int trav=index,loc,prev;
		while(loc!=elem){
			prev=trav;
			loc=vs->data[trav].elem;
			trav=vs->data[trav].link;
		}
		freeSpace(vs,prev);
	}
	
}

void visualize(VSpace vs) {
    int i, half = vs.max/2;
    printf("%5s | %5s | %5s %10s %5s | %5s | %5s \n", "INDEX", "DATA", "LINK", "","INDEX", "DATA", "LINK");
    printf("----------------------          ----------------------\n");    
    for(i = 0; i < half; ++i) {
        printf("%5d | %5d | %5d %10s %5d | %5d | %5d \n", 
                i, vs.data[i].elem, vs.data[i].link, "",
                i + half, vs.data[i+half].elem, vs.data[i+half].link);
    }
    printf("AVAIL: %d \n",vs.avail);
     printf("MAX: %d \n",vs.max);
      printf("COUNT: %d \n",vs.count);
}

void packingDensity(VSpace *vs){
	Data* newData =malloc(sizeof(Data)*(vs->max*2));
	Data *temp=vs->data;
	vs->data=newData;
	int oldMax=vs->max;
	//initialize new date
	
    
    int i,newHalf=(vs->max*2)/2;
    
    for(i = 0; i < newHalf; ++i) {
      	newData[i].elem=EMPTY;
        newData[i].link = -1;
    }
    
    for(; i < (vs->max*2)-1; ++i) {
        newData[i].elem=EMPTY;
        newData[i].link = i + 1;    
    }
    newData[i].elem = EMPTY;
    newData[i].link = -1;
	
	vs->max*=2;
	vs->avail = vs->max/2;
	vs->count = 0;

	
	for(i=0;i<oldMax;++i){
		 if (temp[i].elem != EMPTY && temp[i].elem != DELETED){
		 		addElement(vs,temp[i].elem);
		 }

	}


free(temp);
}
