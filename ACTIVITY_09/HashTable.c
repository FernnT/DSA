 #include<stdio.h>
 #include<stdbool.h>
 #include<stdlib.h>
 #include<string.h>
 #include<time.h>
 #include "HashTable.h"
 
MyDate newDate(int date, int month,int year){
	MyDate dating;
	dating.date=date;
	dating.month=month;
	dating.year=year;
	
	return dating;
}
 
 
 StudName newName(String fName,String mName,String lName){
 	StudName naming;
 	strcpy(naming.fName,fName);
 	strcpy(naming.mName,mName);
 	strcpy(naming.lName,lName);
 	
 	return naming;
 }
 
 Student newStud(String id, StudName name, char sex, MyDate bday, String program, int year) {
    Student student;
    strcpy(student.id, id);
    strcpy(student.name.fName, name.fName);
    strcpy(student.name.mName, name.mName);
    strcpy(student.name.lName, name.lName);
    student.sex = sex;
    student.bday = bday;
    strcpy(student.program, program);
    student.year = year;
    
    return student;
}
 
void initDict(Dictionary* D, int size) {
	int i;
	D->elem=malloc(sizeof(Ptr)*size);
	D->count=0;
	D->max=size;
	
	for(i=0;i<size;++i){
		D->elem[i]=NULL;
	}

}


unsigned int Hash(String lName,int size){

	return (int)(lName[0]+31)%size;	
}

void display(Dictionary D) {
	int i;
	for(i=0;i<D.max;++i){
		Ptr current=D.elem[i];
			printf("INDEX %d: \n",i);
		if(D.elem[i]==NULL){
			printf("EMPTY\n\n");
		}
	 while (current != NULL) {

                printf("Student ID: %s\n", current->elems.id);
                printf("First Name: %s\n", current->elems.name.fName);
                printf("Middle Name: %s\n", current->elems.name.mName);
                printf("Last Name: %s\n", current->elems.name.lName);
                printf("Sex: %c\n", current->elems.sex);
                printf("Birthday: %d/%d/%d\n", current->elems.bday.date, current->elems.bday.month, current->elems.bday.year);
                printf("Program: %s\n", current->elems.program);
                printf("Year: %d\n\n", current->elems.year);
                current = current->next;
            }
            printf("---------------------");
	}
		
}

void insertTable(Dictionary *D,Student stud){
	int i;
	int hashVal=Hash(stud.name.lName,D->max);
	
	Ptr newNode=(Ptr)malloc(sizeof(SType));
	newNode->elems=stud;
	newNode->next=NULL;
	
	if(D->elem[hashVal]==NULL){
		D->elem[hashVal]=newNode;
	}else{
		Ptr current=D->elem[hashVal];
		Ptr prev=NULL;
		
		while(current!=NULL&&strcmp(current->elems.name.lName,stud.name.lName)<0){
			prev=current;
			current=current->next;
		}
		if(prev==NULL){
			newNode->next=D->elem[hashVal];
			D->elem[hashVal]=newNode;
		}else{	
			prev->next=newNode;
			newNode->next=current;
		}
		
	}
}

//void deleteTable(Dictionary *D,String lName){
//	
//	
//}




