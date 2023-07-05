#include <stdio.h>
#include <stdlib.h>
#include "MyHeader.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	VSpace vs=newVSpace(10);
	visualize(vs);
	
	addElement(&vs,11);
	addElement(&vs,22);
	addElement(&vs,33);
	addElement(&vs,44);
	addElement(&vs,55);
	addElement(&vs,66);
		visualize(vs);
addElement(&vs,77);
addElement(&vs,77);
removeElement(&vs,22);
	visualize(vs);
	
	
	


	
	return 0;
}
