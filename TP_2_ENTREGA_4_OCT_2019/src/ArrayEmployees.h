
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>


#define TRUE 1
#define FALSE 0
#define EXIT_ERROR -1
#define EXIT_SUCCESS 0

struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;



int initEmployees(Employee *list, int len);
int addEmployee(Employee *list, int len,int id, char name [], char lastName [], float salary, int sector);
int findEmployeeById(Employee *list, int len, int id);
int removeEmployee(Employee *list, int len,int id);
int sortEmployees(Employee *list, int len, int order);
int printfEmployees(Employee*list, int len);

#endif /* ARRAYEMPLOYEES_H_ */
