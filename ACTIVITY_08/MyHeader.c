#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MyHeader.h"




Set newSet(){
	Set set2;
		
	set2.count=0;
	int i;
	for(i=0;i<MAX;++i){
		set2.elems[i]=false;
	}
	
	return set2;
}
bool addElement(Set *s,int item){
	
	s->elems[item]=true;
	s->count++;
	
	return true;
}
bool removeElement(Set *s,int item){

	s->elems[item]=false;
	s->count--;

}
void displaySet(Set s){
	int i;
	
	for(i=0;i<MAX;++i){
		if(s.elems[i]==true){
			printf("%d | ",i);
		}
	}	
	printf("Cardinality: %d \n\n",s.count);
	
		
}
Set unionSet(Set a,Set b){
	Set uni;
	uni=newSet();
	int i;
	
	for(i=0;i<MAX;++i){
		if(a.elems[i]==true){
			addElement(&uni,i);
		}else if(b.elems[i]==true){
			addElement(&uni,i);
		}
	}
		

	return uni;
	
}
Set intersectionSet(Set a,Set b){
	Set in;
	in=newSet();
	int i;
	
	for(i=0;i<MAX;++i){
		if(a.elems[i]==true&&b.elems[i]==true){
			addElement(&in,i);
		}
	}
	return in;
	
	
}
Set differenceSet(Set a,Set b){
	Set ds;
	ds=newSet();
	int i;
		
	for(i=0;i<MAX;++i){
		if(a.elems[i]==true&&b.elems[i]==false){
			addElement(&ds,i);
		}
	}
	return ds;
}
Set symetricDiffSet(Set a, Set b){
	Set sds;
	sds=newSet();
	int i;
	//(A-B)
	for(i=0;i<MAX;++i){
		if(a.elems[i]!=b.elems[i]){
			addElement(&sds,i);
		}else if(a.elems[i]!=b.elems[i]){
			addElement(&sds,i);
		}
	}
	
	
	return sds;
}

