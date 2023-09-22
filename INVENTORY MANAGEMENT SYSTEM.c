#include <stdio.h>
int choice=1;
typedef struct{
int ProductID;
char Name[20];
int Quantity;
int Price;
}inventory;
void menu(void)
{    printf("<<<< INVENTORY MANAGEMENT SYSTEM >>>>\n");
    printf("1. Add Product\n2. Update Quantity\n3. Display Inventory\n4. Search Product\n0. Exit\n");
    printf("Enter your choice: ");
    scanf("%i",&choice);
}
inventory inventoryBegin[1000];
int main()
{   int countActualStudents=0;
   int flag=-1;
    int product_id;
    char product_name[20];
    int product_quantity;
  while(choice)
{   flag=-1;
    menu();
if(choice==1)
{
            printf("Enter product ID: ");
            scanf("%i",&product_id);
            inventoryBegin[countActualStudents].ProductID=product_id;
            fflush(stdin);
            printf("Enter product name: ");
            gets(product_name);
            strcpy(inventoryBegin[countActualStudents].Name,product_name);
            fflush(stdin);
            printf("Enter product quantity: ");
            scanf("%i",&product_quantity);
            inventoryBegin[countActualStudents].Quantity=product_quantity;
            countActualStudents++;
            printf("Product added successfully!\n");
}
else if(choice==2)
{
 printf("Enter product ID to update quantity: ");
 scanf("%i",&product_id);
                for(int i =0 ; i < countActualStudents; i++)
                if(inventoryBegin[i].ProductID==product_id)
                {
                    flag=i;
                    break;
                }
            if(flag== -1)
                printf("The Product is not available..!!!\n");
            else
            {
                printf("Enter updated quantity: ");
                scanf("%i",&product_quantity);
                inventoryBegin[flag].Quantity+=product_quantity;
                printf("Quantity updated successfully!\n");
            }

}
else if(choice==3)
{
            printf("--- Inventory ---\n");
            for(int i =0 ; i < countActualStudents; i++)
            {
                printf("Product ID: %i\n",inventoryBegin[i].ProductID);
                printf("Product Name: %s\n",inventoryBegin[i].Name);
                printf("Quantity: %i\n----------------\n",inventoryBegin[i].Quantity);
            }

}
else if(choice==4)
{
     printf("Enter product ID to search: ");
            scanf("%i",&product_id);
            for(int i =0 ; i < countActualStudents; i++)
                if(inventoryBegin[i].ProductID==product_id)
                {
                    flag=i;
                    break;
                }
            if(flag== -1)
                printf("The Product is not available..!!!\n");
            else
            {
                printf("Product ID: %i\nProduct Name: %s\nQuantity: %i\n,",inventoryBegin[flag].ProductID,
                       inventoryBegin[flag].Name,
                       inventoryBegin[flag].Quantity);
            }
  }
if(!choice)
             printf("*************** EXIT PROGRAM **********************");
}




    return 0;
}

