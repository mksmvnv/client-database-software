#ifndef STRUCT_CLIENT_H
#define STRUCT_CLIENT_H

struct Client {
    int client_id;
    char first_name[32];
    char last_name[32];
    int age;
    char country[64];
    char phone_number[20];
    char email[64];
};

#endif