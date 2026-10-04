#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100

typedef struct
{
    int employeeID;
    char name[100];
    char department[50];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
}Employee;

void addEmployee(Employee employees[], int *numEmployees);
void displayEmployees(Employee employees[], int employeeCount);
void searchEmployee(Employee employees[], int employeeCount, int employeeID);
float calculateSalary(Employee employee);

#endif