#include "search_client.h"

#include "struct_client.h"

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
            printf("Country: %s\n", info.country);
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