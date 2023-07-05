#ifndef MYHEADER_H
#define MYHEADER_H
#include <stdbool.h>

#define EMPTY 9999
#define DELETED 9988

typedef struct{
	int elem;
	int link;
	
}Data;

typedef struct{
	Data *data;
	int avail;
	int max;
	int count;
}VSpace;


VSpace newVSpace(int max);//size 10
int allocSpace(VSpace *vs);
void freeSpace(VSpace *vs,int loc); //compartment 2 //change the avail to the freedSpace
int hash(VSpace vs,int elem);//modulo of 5
bool addElement(VSpace *vs,int elem);
bool removeElement(VSpace *vs,int elem); //LABEL AS DELETED UNLESS NO SYNONYMS //
void visualize(VSpace vs);
void packingDensity(VSpace *vs);
//first compartment are main values //second are for synonyms 
								


#endif
