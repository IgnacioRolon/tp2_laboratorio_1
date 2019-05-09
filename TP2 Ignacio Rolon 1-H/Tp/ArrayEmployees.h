#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;

int initEmployees(Employee* list, int len);
int altaEmployee(Employee* list, int len);
int modifyEmployee(Employee* list, int len);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);



#endif // ARRAYEMPLOYEES_H_INCLUDED
