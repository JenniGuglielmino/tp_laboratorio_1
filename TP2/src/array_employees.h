
#ifndef ARRAY_EMPLOYEES_H_
#define ARRAY_EMPLOYEES_H_

typedef struct
{
    int id;
    char name[51];
    char lastname[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

int initEmployees(eEmployee list[], int len);
int addEmployee(eEmployee list[], int len, int* pId);
int searchAvailablePlace(eEmployee list[], int len);
int removeEmployee(eEmployee list[], int len);
int printEmployees(eEmployee list[], int len);
int sortEmployees(eEmployee list[], int len, int order);
int menuReports();
int optionReports(eEmployee list[], int len);
int stringToLower(char list[]);
int stringToUpper(char list[]);
void totalSalary(eEmployee list[], int tam);
int countHighestSalary(eEmployee list[], int len, int average);
int harcodeEmployees(eEmployee list[], int tam, int cant, int* pId);
int menuModify();
int modifyEmployee(eEmployee list[], int len);

#endif /* ARRAY_EMPLOYEES_H_ */
