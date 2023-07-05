#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MyHeader.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Set s,b;
	
	s=newSet();
	b=newSet();
	
	addElement(&s,1);
	addElement(&s,2);
	addElement(&s,3);
	addElement(&s,4);	
	
	addElement(&b,4);
	addElement(&b,3);
	addElement(&b,6);

	Set sds=symetricDiffSet(s,b);
	Set ds=differenceSet(s,b);
	Set in=intersectionSet(s,b);
	Set un=unionSet(s,b);
	
	
	displaySet(ds);
	displaySet(sds);
	
	return 0;
}
