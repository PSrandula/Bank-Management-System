#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// variables
char name[20];
int dip_amt, amt = 10000, acc_no, ac, count = 0;
int trans_amt;
int with_amt;

// function 
void deposit_money();
void withdraw_money();
void transfer_money();
void checkDetail();
void LastDetail();
void transaction_details();
void menu();
void divider();

// Main function
int main()
{
    FILE *ptr = fopen("Account.txt", "w");

    if (ptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int ch;

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    fprintf(ptr, "\nName : %s\n", name);

    printf("Enter your account no.: ");
    scanf("%d", &acc_no);
    fprintf(ptr, "Account no.: %d\n", acc_no);

    fclose(ptr);

    while (1)
    {
        menu();
        printf("\nEnter your choice: \n");
        if (scanf("%d", &ch) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (ch)
        {
        case 1:
            deposit_money();
            break;
        case 2:
            withdraw_money();
            break;
        case 3:
            transfer_money();
            break;
        case 4:
            checkDetail();
            break;
        case 5:
            transaction_details();
            break;
        case 6:
            LastDetail();
            exit(0);
        default:
            printf("*****Invalid choice*****\n");
        }
    }

    return 0;
}

// menu function
void menu()
{
    system("cls || clear");
    divider();
    printf("\n\t              * MENU *\n\n");
    divider();
    printf("\n1. Deposit Money\n");
    printf("2. Withdraw Money\n");
    printf("3. Transfer Money\n");
    printf("4. Account Details\n");
    printf("5. Transaction Details\n");
    printf("6. Exit\n\n");
    divider();
}

// divider function
void divider()
{
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
    printf("\n");
}

// deposit money function
void deposit_money()
{
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");

    if (ptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\n        *****DEPOSITING MONEY*****\n\n");
    divider();

    printf("Enter the amount you want to deposit: \n");
    scanf("%d", &dip_amt);

    if (dip_amt <= 0) {
        printf("Invalid amount. Please enter a positive number.\n");
        return;
    }

    amt += dip_amt;
    printf("\n****Money Deposited****\n");
    printf("New balance: %d\n", amt);

    fprintf(ptr, "\nRs%d has been deposited to your account.\n", dip_amt);
    fprintf(ptr, "Date/Time of transaction: %s\n", ctime(&tm));

    count++;
    fclose(ptr);
    printf("Press any key to continue...\n");
    getchar(); getchar();
}

// withdraw money
void withdraw_money()
{
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");

    if (ptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\n        *****WITHDRAWING MONEY*****\n\n");
    divider();

    printf("Enter the amount you want to withdraw: \n");
    scanf("%d", &with_amt);

    if (with_amt <= 0) {
        printf("Invalid amount. Please enter a positive number.\n");
        return;
    }

    if (amt < with_amt)
    {
        printf("****Insufficient balance****\n");
    }
    else
    {
        amt -= with_amt;
        printf("\n*****Money withdrawn*****\n");
        printf("Current balance: %d\n", amt);

        fprintf(ptr, "\nRs%d has been withdrawn from your account.\n", with_amt);
        fprintf(ptr, "Date/Time of transaction: %s\n", ctime(&tm));

        count++;
    }
    fclose(ptr);
    printf("Press any key to continue...\n");
    getchar(); getchar();
}

// transfer money
void transfer_money()
{
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");

    if (ptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\n        *****TRANSFERRING MONEY*****\n\n");
    divider();

    printf("\nEnter the account number to transfer to: ");
    scanf("%d", &ac);
    printf("Enter the amount you want to transfer: ");
    scanf("%d", &trans_amt);

    if (trans_amt <= 0) {
        printf("Invalid amount. Please enter a positive number.\n");
        return;
    }

    if (amt < trans_amt)
    {
        printf("****You have insufficient balance****\n");
    }
    else
    {
        amt -= trans_amt;
        printf("\n****Money Transferred****\n");
        printf("Current balance: %d\n", amt);

        fprintf(ptr, "\nRs%d has been transferred to account no. %d.\n", trans_amt, ac);
        fprintf(ptr, "Date/Time of transaction: %s\n", ctime(&tm));

        count++;
    }
    fclose(ptr);
    printf("Press any key to continue...\n");
    getchar(); getchar(); 
}

// check account details
void checkDetail()
{
    printf("\n        *****ACCOUNT DETAILS*****\n\n");
    divider();
    printf("Name: %s\n", name);
    printf("Account No.: %d\n", acc_no);
    printf("Total balance: %d\n", amt);
    printf("%d transactions have been made from your account.\n", count);
    printf("Press any key to continue...\n");
    getchar(); getchar();
}

//show transaction details
void transaction_details()
{
    system("cls || clear");

    FILE *ptr = fopen("Account.txt", "r");
    if (ptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\n       *****TRANSACTION DETAILS*****\n\n");
    divider();
    printf("%d transactions have been made from your account.\n", count);

    char c = fgetc(ptr);
    if (c == EOF)
    {
        printf("\n*******NO RECENT TRANSACTION*******\n");
    }
    else
    {
        while (c != EOF)
        {
            printf("%c", c);
            c = fgetc(ptr);
        }
    }

    fclose(ptr);
    printf("Press any key to continue...\n");
    getchar(); getchar();
}

// show last account details and exit
void LastDetail()
{
    printf("\n        *****ACCOUNT DETAILS*****\n\n");
    divider();
    printf("Name: %s\n", name);
    printf("Account No.: %d\n", acc_no);
    printf("Total balance: %d\n", amt);
    printf("\n\nPress any key to exit...\n");
    getchar(); getchar();
}
