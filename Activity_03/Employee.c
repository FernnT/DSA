#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

HourlyEmployee newEmployee(int id, String name, String gender ,float hours){
	HourlyEmployee he;
	
	he.idNumber=id;
	strcpy(he.name,name);
	strcpy(he.gender,gender);
	he.totalHourseWorked=hours;
	
	return he;
	
}
void displayEmployee(HourlyEmployee he){
	printf("ID: %d\n", he.idNumber);
	printf("NAME: %s\n", he.name);
	printf("GENDER: %c\n",he.gender);
	printf("HOURSE WORKED: %.2f",he.totalHourseWorked);
}

void initList(List *list){
	list->max=2;
	list->employee=malloc(sizeof(HourlyEmployee)*list->max);
	list->count=0; 
}
void addEmployee(List *list,HourlyEmployee emp) {// use insert rear;
	if(list->count==list->max){
		//do realloc if max
		list->max *=2;
		 list->employee = realloc(list->employee, sizeof(HourlyEmployee) * list->max);
	}
	list->employee[(list->count)++]=emp;
}
void displayEmployeeList(List list){
	printf("%10s | %30s | %10s \n", "ID", "NAME", "GENDER");
	int i;
	for(i=0;i<list.count;++i){
			printf("%10d | %30s | %10s \n", list.employee[i].idNumber, list.employee[i].name, list.employee[i].gender);
	}
	printf("\nEND\n");
}
List getFemaleEmployees(List list){
	List femaleList;
	initList(&femaleList);
	
	//add a loop
	int i;
	for(i=0;i<list.count;++i){
	if(strcmp(list.employee[i].gender,"female")==0){
		addEmployee(&femaleList, list.employee[i]);
	}
} 

	return femaleList;
}


