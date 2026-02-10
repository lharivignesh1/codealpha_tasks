#include <stdio.h>
#include <stdlib.h>

struct bank {
    int acc;
    char name[20];
    float bal;
};

int main() {
    struct bank b;
    FILE *fp;
    int choice;
    float amt;
    
    // Create file if not exists
    fp = fopen("bank.txt", "rb");
    if (fp == NULL) {
        fp = fopen("bank.txt", "wb");
        b.acc = 0;
        fwrite(&b, sizeof(b), 1, fp);
        fclose(fp);
    }

    while (1) {
        printf("\n1.Create Account");
        printf("\n2.Deposit");
        printf("\n3.Withdraw");
        printf("\n4.Balance Enquiry");
        printf("\n5.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            fp = fopen("bank.txt", "wb");
            printf("Enter Account No: ");
            scanf("%d", &b.acc);
            printf("Enter Name: ");
            scanf("%19s", b.name);
            printf("Enter Initial Balance: ");
            scanf("%f", &b.bal);
            fwrite(&b, sizeof(b), 1, fp);
            fclose(fp);
            printf("Account Created\n");
        }

        else if (choice == 2) {
            fp = fopen("bank.txt", "rb+");
            fread(&b, sizeof(b), 1, fp);
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amt);
            b.bal += amt;
            fseek(fp, 0, SEEK_SET);
            fwrite(&b, sizeof(b), 1, fp);
            fclose(fp);
            printf("Deposit Successful\n");
        }

        else if (choice == 3) {
            fp = fopen("bank.txt", "rb+");
            fread(&b, sizeof(b), 1, fp);
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amt);

            if (amt <= b.bal) {
                b.bal -= amt;
                fseek(fp, 0, SEEK_SET);
                fwrite(&b, sizeof(b), 1, fp);
                printf("Withdrawal Successful\n");
            } 
            else {
                printf("Insufficient Balance\n");
            }
            fclose(fp);
        }

        else if (choice == 4) {
            fp = fopen("bank.txt", "rb");
            fread(&b, sizeof(b), 1, fp);
            printf("Account No: %d\nName: %s\nBalance: %.2f\n",
                   b.acc, b.name, b.bal);
            fclose(fp);
            }

        else if (choice == 5) {
            exit(0);
        }

        else {
            printf("Invalid Choice\n");
        }
    }
    return 0;
}
