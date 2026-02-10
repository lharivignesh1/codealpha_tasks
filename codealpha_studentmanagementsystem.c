#include <stdio.h>
#include <stdlib.h>

struct student {
    int roll;
    char name[20];
};

int main() {
    FILE *fp;
    struct student s;
    int choice;

    while (1) {
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            fp = fopen("student.txt", "a");
 
            if(fp==NULL){
                printf("File error!\n");
                continue;
            }
            printf("Enter Roll No: ");
            scanf("%d", &s.roll);
            printf("Enter Name: ");
            scanf("%s", s.name);
            fprintf(fp, "%d %s\n", s.roll, s.name);
            fclose(fp);
            printf("Student Added\n");
        }

        else if (choice == 2) {
            fp = fopen("student.txt", "r");
            if (fp == NULL) {
                printf("No Records Found\n");
            } else {
                while (fscanf(fp, "%d %s", &s.roll, s.name) != EOF) {
                    printf("Roll: %d  Name: %s\n", s.roll, s.name);
                }
                fclose(fp);
            }
        }

        else if (choice == 3) {
            exit(0);
        }

        else {
           printf("Invalid Choice\n");
        }
    }
    return 0;
}
