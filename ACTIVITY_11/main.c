#include <stdio.h>
#include <stdlib.h>
#include "MYHEADER.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	BSTptr bst = NULL;
	
	bst=addElement(bst,createProduct(21,"Product1",100,20.00));
	bst=addElement(bst,createProduct(80,"Product22",100,20.00));
	bst=addElement(bst,createProduct(10,"Product22",100,20.00));
	bst=addElement(bst,createProduct(1,"Product22",100,20.00));
	
	removeElement(&bst,21);
	
	inorderBST(bst);
	max(bst);
	min(bst);
//	preorderBST(bst);
	
	
	return 0;
}
