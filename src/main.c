#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    char phone_number[20];
    char email[64];
};

int main() {
    int choice = 0;
    while (choice != 5) {
        printf(
        "CLIENT DATABASE SOFTWARE\n\n"
        "1. Add new client\n"
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
            case 3:
                system("clear");
                search_client();
                printf("Press any key to exit\n");
                getchar();
                system("clear");
                break;
            case 4:
                system("clear");
                remove_client();
                printf("Press any key to exit\n");
                getchar();
                system("clear");
                break;
            case 5:
                printf("Thank you for used the Client Database Software!\n");
                exit(0);
                break;
            default:
                system("clear");
                getchar();
                printf(
                    "Enter a valid command\n\n"
                    "Press any key to continue\n");
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
    srand(time(NULL));

    do {
        system("clear");
        printf("ADD NEW CLIENT INFO\n\n");
        fp = fopen("client_info", "a");

        int client_id = rand() % 100000 + 1;
        info.client_id = client_id;
        printf("Enter first name: ");
        scanf("%s", info.first_name);
        printf("Enter last name: ");
        scanf("%s", info.last_name);
        printf("Enter age: ");
        scanf("%d", &info.age);
        printf("Enter address: ");
        scanf("%s", info.address);
        printf("Enter phone number: ");
        scanf("%s", info.phone_number);
        printf("Enter email: ");
        scanf("%s", info.email);

        if (fp == NULL) {
            fprintf(stderr, "Can't open file\n\n");
        }else{
            printf("Client saved successfully!\n\n");
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
    if (fp == NULL) {
        fprintf(stderr, "Can't open file\n\n");
    }
    printf("VIEW CLIENT LIST\n\n");

    while (fread(&info, sizeof(struct Client), 1, fp)) {
        printf("Client ID: %d\n", info.client_id);
        printf("Name: %s %s\n", info.first_name, info.last_name);
        printf("Age: %d\n", info.age);
        printf("Adress: %s\n", info.address);
        printf("Phone Number: %s\n", info.phone_number);
        printf("Email: %s\n\n", info.email);
    }
    fclose(fp);
    getchar();
}

void search_client() {
    FILE *fp;
    struct Client info;
    int client_id, found = 0;
    fp = fopen("client_info", "r");
    if (fp == NULL) {
        fprintf(stderr, "Can't open file\n\n");
    }
    printf("SEARCH CLIENT\n\n");
    printf("Enter Client ID: ");
    scanf("%d", &client_id);
    printf("\n");

    while (fread(&info, sizeof(struct Client), 1, fp)) {
        if (info.client_id == client_id) {
            found = 1;
            printf("Client ID: %d\n", info.client_id);
            printf("Name: %s %s\n", info.first_name, info.last_name);
            printf("Age: %d\n", info.age);
            printf("Adress: %s\n", info.address);
            printf("Phone Number: %s\n", info.phone_number);
            printf("Email: %s\n\n", info.email);
        }
    }
    if (!found) {
        printf("Client not found\n\n");
    }
    fclose(fp);
    getchar();

}

void remove_client() {
    FILE *fp, *fprem;
    struct Client info;
    int client_id, found = 0;
    printf("REMOVE CLIENT\n\n");
    fp = fopen("client_info", "r");
    fprem = fopen("removed_clients", "w");
    if (fp == NULL) {
        fprintf(stderr, "Can't open file\n\n");
    }
    printf("Enter Client ID: ");
    scanf("%d", &client_id);
    printf("\n");

    while (fread(&info, sizeof(struct Client), 1, fp)) {
        if (info.client_id == client_id) {
            found = 1;
        }else {
            fwrite(&info, sizeof(struct Client), 1, fprem);
        }
    }
    fclose(fp);
    fclose(fprem);

    if (found) {
        remove("client_info");
        rename("removed_clients", "client_info");
        printf("Client removed successfully!\n\n");
    }
    if (!found) {
        printf("Client not found\n\n");
    }
    getchar();
    remove("removed_clients");
}
