#ifndef MYHEADER_H
#define MYHEADER_H

#include <stdbool.h>

typedef struct{
	int prodID;
	char prodName[20];
	int prodQty;
	float prodPrice;
	
}Product;

typedef struct node{
	Product data;
	struct node *left;
	struct node *right;
	
}NodeType,*NodePtr,*BSTptr,BST;

//add element to the BST base on product ID
BST *addElement(BST *list,Product item);	  //using recursive
void insertBST(BSTptr *list,Product item); //using iterative method

//Delete element in the BST base on the product ID
void removeElement(BST **list,int prodID); //iterative
BST *deleteElement(BST *list,int prodID);//recursive

//Display BST all in recursive method
void inorderBST(BST *list); // ascending result
void preorderBST(BST *list); //idk 
void postOrderBST(BST *list); //

//Other funcction
BST *newBST();
void initBST(BST **list);
bool isEmpty(BST *list);
Product createProduct(int id,char *name,int qty,float price);

//use the following format ( <id> | <prodName>) replacing the angualar brackets with data
void displayProduct(Product prod); //display only node
BST *max(BST *list);
BST *min(BST *list);
bool isMember(BST *list,int prodID);

#endif


