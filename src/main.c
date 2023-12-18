#include <stdio.h>
#include <stdlib.h>

void add_client();
void view_client_list();
void search_client();
void remove_client();

struct Client {
    int client_id;
    char first_name[32];
    char last_name[32];
    int age;
    char address[64];
    int phone_number;
    char email[64];
};

int main() {
    int choice;
    while (choice != 5) {
        printf(
        "CLIENT DATABASE SOFTWARE\n"
        "1. Add client\n"
        "2. View client list\n"
        "3. Search client\n"
        "4. Remove client\n"
        "5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("clear");
                add_client();
                system("clear");
                break;
            case 2:
                system("clear");
                view_client_list();
                printf("Press any key to exit\n");
                getchar();
                system("clear");
                break;
        }
    }
    return 0;
}


void add_client() {
    char another;
    FILE *fp;
    struct Client info;

    do {
        system("clear");
        printf("ADD NEW CLIENT INFO\n");
        fp = fopen("client_info.txt", "a");
        printf("Enter first name: ");
        scanf("%s", info.first_name);
        printf("Enter last name: ");
        scanf("%s", info.last_name);
        printf("Enter age: ");
        scanf("%d", &info.age);
        printf("Enter address: ");
        scanf("%s", info.address);
        printf("Enter phone number: ");
        scanf("%d", &info.phone_number);
        printf("Enter email: ");
        scanf("%s", info.email);

        if (fp == NULL) {
            fprintf(stderr, "Can't open file\n");
        }else{
            printf("Client saved successfully!\n");
        }

        fwrite(&info, sizeof(struct Client), 1, fp);
        fclose(fp);

        printf("Do you want to add another client? (y/n): ");
        scanf("%s", &another);

    }while (another == 'y' || another == 'Y');
}


void view_client_list() {

}