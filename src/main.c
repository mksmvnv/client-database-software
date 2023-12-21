#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "add_client.h"
#include "view_client_list.h"
#include "search_client.h"
#include "remove_client.h"

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
