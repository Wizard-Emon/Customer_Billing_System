#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct items
{
    char item_one[50];
    float price;
    int quantity;
};
struct orders
{
    char customer[50];
    char date[40];
    int itemNum;
    struct items item[50];
};
void showBillDetails(char name[100], char date[50])
{
    printf("\n\n");
    printf("\t\t Restaurant X.");
    printf("\n\t    -----------------------");
    printf("\nDate: %s", date);
    printf("\nInvoice for : %s", name);
    printf("\n");
    printf("------------------------------------------------\n");
    printf("Items \t\t");
    printf("Qantity\t\t");
    printf("Total\t\t");
    printf("\n------------------------------------------------\n");
    printf("\n\n");
}
void showBillBody(char item[50], int quantity, float price)
{
    printf("%s\t\t", item);
    printf("%d\t\t", quantity);
    printf("%.2f\t\t", quantity * price);
    printf("\n");
}
void endBillDetails(float total)
{
    printf("\n");
    float discount = 0.1 * total;
    float netTotal = total - discount;
    printf("Sub Total = \t\t\t%.2f", total);
    printf("\nDiscount @10%s\t\t\t%.2f", "%", discount);
    printf("\n\t\t\t\t----------");
    printf("\nNet Total\t\t\t%.2f", netTotal);
}
int main()
{
    int option, numberOfItems;
    float total;
    struct orders order;
    // Dashboard
    printf("\t============  Resturant X. =============");
    printf("Select Your prefered operation : ");

    printf("\n1. Generate Invoices");
    printf("\n2. Show all invoices");
    printf("\n3. Search Invoices");
    printf("\n4. Exit\n\n");
    printf(" Choose : ");
    scanf("%d", &option);
    fgetc(stdin);
    switch (option)
    {
    case 1:
        printf("\nPlease Enter the name of the customer : ");
        fgets(order.customer, 50, stdin);
        order.customer[strlen(order.customer) - 1] = 0;
        strcpy(order.date, __DATE__);
        printf("\nPlease Enter the number of items : \n");
        scanf("%d", &numberOfItems);
        order.itemNum = numberOfItems;
        for (int i = 0; i < numberOfItems; i++)
        {
            fgetc(stdin);
            printf("\n\n");
            printf("Please enter the item %d name :\t ", i + 1);
            fgets(order.item[i].item_one, 50, stdin);
            order.item[i].item_one[strlen(order.item[i].item_one) - 1] = 0;
            printf("Please Enter the quantity : \t");
            scanf("%d", &order.item[i].quantity);
            printf("Please Enter the unit price : \t");
            scanf("%f", &order.item[i].price);
            total += order.item[i].quantity * order.item[i].price;
        }

        showBillDetails(order.customer, order.date);
        for (int i = 0; i < order.itemNum; i++)
        {
            showBillBody(order.item[i].item_one, order.item[i].quantity, order.item[i].price);
        }

        endBillDetails(total);
        break;

    default:
        break;
    }

    printf("\n\n");

    return 0;
}