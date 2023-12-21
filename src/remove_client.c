#include "remove_client.h"

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