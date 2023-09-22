#include <stdio.h>
unsigned char index=1;
typedef struct
{
    int countActualStudents;
    int StudentID;
    char StudentName[20];
    unsigned char StudentAge;
    unsigned char StudentGrade;
} Student;
Student StudentBegin[1000];
void Menu(void)
{
    printf("<<<<<<< Student Management System >>>>>>>>\n");
    printf("1. Insert Student\n2. Update Student\n3. Delete Student\n4. Show Students\n5. Search Student\n0. Exit\n");
    printf("Enter your choice: ");
    scanf("%i",&index);
}
int main()
{
    int countActualStudents=0;
    int flag=-1;
    unsigned char choice=0;
    int Student_ID;
    char Name[20];
    unsigned char Student_Age;
    while(index)
    {
        Menu();
        flag== -1;
        if(index == 1)
        {
            printf("Enter roll number: ");
            scanf("%i",&Student_ID);
            StudentBegin[countActualStudents].StudentID=Student_ID;
            fflush(stdin);
            printf("Enter name: ");
            gets(Name);
            strcpy(StudentBegin[countActualStudents].StudentName,Name);
            fflush(stdin);
            printf("Enter age: ");
            scanf("%i",&Student_Age);
            StudentBegin[countActualStudents].StudentAge=Student_Age;
            countActualStudents++;
            printf("STUDENT INSERTED SUCCESSFULLY!..\n");
        }
        else if (index ==2)
        {
            printf("Enter roll number of the student to update: ");
            scanf("%i",&Student_ID);
            for(int i =0 ; i < countActualStudents; i++)
                if(StudentBegin[i].StudentID==Student_ID)
                {
                    flag=i;
                    break;
                }
            if(flag== -1)
                printf("The Student is not available..!!!\n");

            else
            {
                printf("What you want to update... Please choice...\n1. Name\n2. Age\n0. Menu\nEnter your choice: ");
                scanf("%i",&choice);
                fflush(stdin);
                if(choice == 1)
                {
                    printf("Enter updated name: ");
                    gets(Name);
                    fflush(stdin);
                    strcpy(StudentBegin[flag].StudentName,Name);
                    printf("STUDENT UPDATED SUCCESSFULLY!..\n");
                }
                else if(choice == 2)
                {
                    printf("Enter updated Age: ");
                    scanf("%i",&Student_Age);
                    StudentBegin[flag].StudentAge=Student_Age;
                    printf("STUDENT UPDATED SUCCESSFULLY!..\n");
                }
                else
                {
                    flag== -1;
                    printf("OK... GO TO MENU ....\n");
                }
            }
        }
        else if (index ==4)
        {
            printf("--- Student Records ---\n");
            for(int i =0 ; i < countActualStudents; i++)
            {
                printf("Roll Number: %i\n",StudentBegin[i].StudentID);
                printf("Name: %s\n",StudentBegin[i].StudentName);
                printf("Age: %i\n-----------------------\n",StudentBegin[i].StudentAge);
            }
        }
        else if (index ==5)
        {
            printf("Enter roll number of the student to search: ");
            scanf("%i",&Student_ID);
            for(int i =0 ; i < countActualStudents; i++)
                if(StudentBegin[i].StudentID==Student_ID)
                {
                    flag=i;
                    break;
                }
            if(flag== -1)
                printf("The Student is not available..!!!\n");
            else
            {
                printf("Roll Number: %i\nName: %s\nAge: %i\n,",StudentBegin[flag].StudentID,
                       StudentBegin[flag].StudentName,
                       StudentBegin[flag].StudentAge);
                flag=-1;;
            }
        }
        else if (index ==3)
        {
            printf("Enter roll number of the student to delete: ");
            scanf("%i",&Student_ID);
            for(int i =0 ; i < countActualStudents; i++)
                if(StudentBegin[i].StudentID==Student_ID)
                {
                    flag=i;
                    break;
                }
            if(flag== -1)
                printf("The Student is not available..!!!\n");
            else
            {
                for(int i=flag; i<countActualStudents-1; i++)
                    StudentBegin[i] = StudentBegin[i + 1];
                countActualStudents--;
                printf("Student deleted successfully!\n");
            }
        }
        if(!index)
            printf("********************** EXIT PROGRAM ***************************");
    }
    return 0;
}
