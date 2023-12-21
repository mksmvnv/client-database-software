#include "add_client.h"

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