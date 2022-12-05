#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void showBillDetails(char name[100], char date[50])
{
    printf("\n\n");
    printf("\t Restaurant X.");
    printf("\n\t    -----------------------");
    printf("\nDate: %s", date);
    printf("Invoice for : %s", name);
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
    printf("Discount @10%s\t\t\t%.2f", "%", discount);
    printf("\n\t\t\t\t-----------");
    printf("Net Total\t\t\t%.2f", netTotal);
}
int main()
{
    // Dashboard
    printf("\t============  Resturant X. =============");
    printf("\n1. Generate Invoices");
    printf("\n2. Show all invoices");
    printf("\n3. Search Invoices");
    printf("\n4. Exit");
    return 0;
}