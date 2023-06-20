#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	List empList;
	List femList;
	
	initList(&empList);
	initList(&femList);
//	displayEmployeeList(empList);

	addEmployee(&empList,newEmployee(1001,"Maria Dela Cruz","female",40.0f));
	addEmployee(&empList,newEmployee(1002,"Kon De Nor","male",40.0f));
	addEmployee(&empList,newEmployee(1023,"Lop DCAN Mab","female",40.0f));
	
	displayEmployeeList(empList);
	
	femList=getFemaleEmployees(empList);
	displayEmployeeList(femList);
	
	
	
	return 0;
}
