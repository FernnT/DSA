#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "MYHEADER.h"


//add element to the BST base on product ID
BST *addElement(BST *list,Product item){
	NodePtr newNode=malloc(sizeof(NodeType));
	newNode->data=item;
	newNode->left=NULL;
	newNode->right=NULL;
	
	if(list==NULL){
		return newNode;
	}else if(item.prodID < list->data.prodID){
		list->left=addElement(list->left,newNode->data);
	}else if(item.prodID > list->data.prodID){
		list->right=addElement(list->right,newNode->data);
	}
	return list;



}
void insertBST(BSTptr *list, Product item) {
    NodePtr newNode = malloc(sizeof(NodeType));
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;

    if (*list == NULL) {
        *list = newNode;
        return;
    }

    NodePtr trav = *list;
    NodePtr parent = NULL;

    while (trav != NULL) {
        parent = trav;
        if (item.prodID < trav->data.prodID) {
            trav = trav->left;
        } else {
            trav = trav->right;
        }
    }

    if (item.prodID < parent->data.prodID) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

//Delete element in the BST base on the product ID
void removeElement(BST **list, int prodID) {
    if (*list == NULL) {
        printf("Element with product ID %d not found.\n", prodID);
        return;
    }

    NodePtr curr = *list;
    NodePtr parent = NULL;

    while (curr != NULL && curr->data.prodID != prodID) {
        parent = curr;
        if (prodID < curr->data.prodID) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    if (curr==NULL) {
        printf("Element with product ID %d not found.\n", prodID);
        return;
    }
    if (curr->left==NULL && curr->right==NULL) {
        if (parent != NULL) {
            if (parent->left == curr) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        } else {
            *list = NULL;
        }
        free(curr);
    }
    else if (curr->left==NULL || curr->right==NULL) {
        NodePtr child = (curr->left != NULL) ? curr->left : curr->right;

        if (parent!=NULL) {
            if (parent->left == curr) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        } else {
            *list = child;
        }
        free(curr);
    }

    else {
        NodePtr successor = min(curr->right);
        curr->data = successor->data;
        removeElement(&(curr->right), successor->data.prodID);
    }
}


BST *deleteElement(BST *list, int prodID) {
    if (list == NULL) {
        printf("Element with product ID %d not found.\n", prodID);
        return NULL;
    }
    if (prodID < list->data.prodID) {
        list->left = deleteElement(list->left,prodID);
    } else if (prodID > list->data.prodID) {
        list->right = deleteElement(list->right,prodID);
    } else {
        if (list->left == NULL) {
            BST *temp = list->right;
            free(list);
            return temp;
        } else if (list->right == NULL) {
            BST *temp = list->left;
            free(list);
            return temp;
        }
        
        BST *successor = min(list->right);
        list->data = successor->data;
        list->right = deleteElement(list->right, successor->data.prodID);
    }

    return list;
}







//Display BST all in recursive method
void inorderBST(BST *list) {
    if (list == NULL) {
        return;
    }

    inorderBST(list->left);
    displayProduct(list->data);
    inorderBST(list->right);
}





void preorderBST(BST *list){
	 if (list == NULL) {
        return;
    }
    
     displayProduct(list->data);
     preorderBST(list->left);
      preorderBST(list->right);
    
    
    
    
}
void postOrderBST(BST *list){
	 if (list == NULL) {
        return;
    }
    
    postOrderBST(list->left);
    postOrderBST(list->right);
	displayProduct(list->data);
}

//Other funcction
BST *newBST(){
	NodePtr BSTnew=NULL;
	
	return BSTnew; 
	
}
void initBST(BST **list);
bool isEmpty(BST *list);
Product createProduct(int id,char *name,int qty,float price){
	Product newProd;
	
	newProd.prodID=id;
	strcpy(newProd.prodName,name);
	newProd.prodPrice=price;
	newProd.prodQty=qty;
	
	return newProd;
}

//use the following format (id | prodname) replacing the angualar brackets with data
void displayProduct(Product prod){
	    printf("%d | %s\n", prod.prodID, prod.prodName);

}
BST *max(BST *list){
  if (list == NULL)
        return NULL;

    while (list->right != NULL)
        list = list->right;

    return list;
//displayProduct(list->data);
	
}
BST *min(BST *list){
	  if (list == NULL)
        return NULL;

    while (list->left != NULL)
        list = list->left;

    return list;
  //displayProduct(list->data);
}
bool isMember(BST *list, int prodID) {
    if (list == NULL) {
        return false;
    }

    if (prodID == list->data.prodID) {
        return true;
    } else if (prodID < list->data.prodID) {
        return isMember(list->left, prodID);
    } else {
        return isMember(list->right, prodID);
    }
}
