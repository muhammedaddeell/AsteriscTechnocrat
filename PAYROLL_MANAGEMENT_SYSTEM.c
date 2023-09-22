#include<stdio.h>
unsigned char choice =1;
typedef struct
{
    unsigned int EmployeeID;
    char EmployeeName[20];
    float EmployeeFixedSalary;
    float EmployeeBounSalary;
} payrol;
payrol payroll[1000];
void menu(void)
{
    printf("::::::MENU::::::\n1. Insert Employee\n2. Calculate Salary\n3. Generate Payslip\n0. Exit\n");
    printf("Enter your choice: ");
    scanf("%i",&choice);
}
int main()
{
    unsigned int countActualStudents=0;
    unsigned int extra_working_hours;
    float SalaryPerHour;
    int flag=-1;
    unsigned int Employee_ID;
    char Employee_Name[20];
    int Employee_Salary;
    printf("********** PAYROLL MANAGEMENT SYSTEM *************\n");
    while(choice)
    {
        menu();
        if(choice==1)
        {
            printf("Enter employee ID: ");
            scanf("%i",&Employee_ID);
            payroll[countActualStudents].EmployeeID=Employee_ID;
            fflush(stdin);
            printf("Enter employee name: ");
            gets(Employee_Name);
            strcpy(payroll[countActualStudents].EmployeeName,Employee_Name);
            fflush(stdin);
            printf("Enter employee fixed salary: ");
            scanf("%i",&Employee_Salary);
            payroll[countActualStudents].EmployeeFixedSalary=Employee_Salary;
            countActualStudents++;
            printf("EMPLOYEE ADDED SUCCESSFULL!\n");
        }
        else if (choice==2)
        {
            if(countActualStudents==0)
                printf("No Employees available");
            for(int i =0 ; i<countActualStudents ; ++i)
            {
                printf("::Employee ID %i::\n",payroll[i].EmployeeID);
                printf("Enter extra working hours : ");
                scanf("%i",&extra_working_hours);
                printf("Enter salary per hours: ");
                scanf("%f",&SalaryPerHour);
                payroll[i].EmployeeBounSalary=extra_working_hours*SalaryPerHour;
                if(i+1==countActualStudents)
                    printf("SALARY CALCULATION COMPLETED!\n");
            }
        }
        else if(choice==3)
        {
            if(countActualStudents==0)
                printf("No Employees available");

            else
            {
                printf("*************** All Employee Payslip ***************");
                for(int i =0 ; i<countActualStudents ; ++i)
                {
                    printf("Employee ID: %i\nName: %s\nSalary: $%.02f\n*************************\n",payroll[i].EmployeeID,payroll[i].EmployeeName,
                           payroll[i].EmployeeFixedSalary+payroll[i].EmployeeBounSalary);
                }
            }
        }
        else if(choice==0)
            printf("*********************PROGRAM EXIT*********************");

        else
            printf("SORRY INVALID CHOICE... TRY AGAIN...\n");

    }

    return 0;
}
