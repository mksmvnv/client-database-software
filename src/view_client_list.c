#include "view_client_list.h"

#include "struct_client.h"

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
        printf("Country: %s\n", info.country);
        printf("Phone Number: %s\n", info.phone_number);
        printf("Email: %s\n\n", info.email);
    }
    fclose(fp);
    getchar();
}