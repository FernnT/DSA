 #include<stdio.h>
 #include<stdbool.h>
 #include<stdlib.h>
 #include<string.h>
 #include<time.h>
 #include "HashTable.h"

//CAN BE IMPLEMENT IN ARRAYS,LINKED LIST,CURSOR BASED,BIT VECTOR
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
Dictionary D;
	initDict(&D,10);
	
//display(D);
	
insertTable(&D,newStud("22103274",newName("TJ","Esca","Nak"),'M',newDate(18,11,2003),"BSCS",2));
insertTable(&D,newStud("22103274",newName("TJ","Esca","Nak"),'M',newDate(18,11,2003),"BSCS",2));
insertTable(&D,newStud("23235423",newName("Ailes","Per","Hour"),'M',newDate(1,1,2023),"BSCS",2));
		
display(D);
	
	
	
	return 0;
}
