#include <stdio.h>
#include <string.h>
typedef struct
{
    int Samosa;
    int Dosa;
    int Tea;
} Hotel;
Hotel hoteel= {0,0,0};
int main()
{
    int Cash;
    int choice=1;
    int TotalCost=0;
    char*Sor[3];
    int count=0;
    int NumbersOfPlates;
    printf("***** Welcome to XYZ Hotel! *****\n");
    while(choice)
    {
        printf("Menu:\n1 Samosa 20/-\n2 Dosa 30/-\n3 Tea 10/-\n0 Exit\n");
        printf("Enter your Choice : ");
        scanf("%i",&choice);
        if(choice == 1)
        {
            Sor[count++]="Samosa";
            printf("Enter number of plats : ");
            scanf("%i",&NumbersOfPlates);
            hoteel.Samosa=NumbersOfPlates;
        }
        else if (choice == 2)
        {
            Sor[count++]="Dosa";
            printf("Enter number of plats : ");
            scanf("%i",&NumbersOfPlates);
            hoteel.Dosa=NumbersOfPlates;
        }
        else if (choice == 3)
        {
            Sor[count++]="Tea";
            printf("Enter number of plats : ");
            scanf("%i",&NumbersOfPlates);
            hoteel.Tea=NumbersOfPlates;
        }
        else
        {
            printf("::Your Bill::\n");
            printf("Sr.No. | Item | Qty | Rate | Sub Total\n-------------------------------------------------------------------\n");
            for(int i =0 ; i<count; ++i)
            {
                if(Sor[i]=="Samosa")
                {
                    printf("%i | %s | %i | 20 | %i/-\n",i+1,Sor[i],hoteel.Samosa,hoteel.Samosa*20);
                    TotalCost+=hoteel.Samosa*20;
                }
                else if(Sor[i]=="Dosa")
                {
                    printf("%i | %s | %i | 30 | %i/-\n",i+1,Sor[i],hoteel.Dosa,hoteel.Dosa*30);
                    TotalCost+=hoteel.Dosa*30;
                }
                else if(Sor[i]=="Tea")
                {
                    printf("%i | %s | %i | 10 | %i/-\n",i+1,Sor[i],hoteel.Tea,hoteel.Tea*10);
                    TotalCost+=hoteel.Tea*10;
                }
            }
            printf("-----------------------------------------------------------------\n");
            printf("         Grand Total: %i/-       \n",TotalCost);
            printf("Enter Your Cash: ");
            scanf("%i",&Cash);
            if(Cash > TotalCost)
                printf("Return Amount : %i\n",Cash-TotalCost);
            else if(Cash < TotalCost)
                while(Cash < TotalCost)
                {
                    int CashAlready=Cash;
                    printf("Please pay %i Rs. more\n",TotalCost-Cash);
                    printf("Enter Your Cash: ");
                    scanf("%i",&Cash);
                    Cash+=CashAlready;
                }
            printf("----- T H A N K Y O U! -------\n*********************** VISIT AGAIN *******************");
        }

    }

    return 0;
}
