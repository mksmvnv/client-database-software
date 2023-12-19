#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generate_id(int num, char* id);
void add_client();
void view_client_list();
void search_client();
void remove_client();

struct Client {
    char client_id[10];
    char first_name[32];
    char last_name[32];
    int age;
    char address[64];
    int phone_number;
    char email[64];
};

int main() {
    int choice = 0;
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

void generate_id(int num, char* id) {
    sprintf(id, "%X", num);
}

void add_client() {
    char another;
    char client_id[10];
    FILE *fp;
    struct Client info;
    srand(time(NULL));

    do {
        system("clear");
        printf("ADD NEW CLIENT INFO\n");
        fp = fopen("client_info", "a");

        int client_num = rand();
        generate_id(client_num, client_id);
        strcpy(info.client_id, client_id);
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
    FILE *fp;
    struct Client info;
    fp = fopen("client_info", "r");
    printf("VIEW CLIENT LIST\n");
    if (fp == NULL) {
        fprintf(stderr, "Can't open file\n");
    } else {
        printf("Scanning...\n");
    }
    
    while (fread(&info, sizeof(struct Client), 1, fp)) {
        printf("Client ID: %s\n", info.client_id);
        printf("Name: %s %s\n", info.first_name, info.last_name);
        printf("Age: %d\n", info.age);
        printf("Adress: %s\n", info.address);
        printf("Phone Number: %d\n", info.phone_number);
        printf("Email: %s\n", info.email);
    }
    fclose(fp);
    getchar();
}