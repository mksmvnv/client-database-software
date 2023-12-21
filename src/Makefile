CC = gcc
CFLAGS = -Wall -Werror -Wextra

OBJ = main.o add_client.o view_client_list.o search_client.o remove_client.o

TARGET = client_database_software

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

main.o: main.c add_client.h view_client_list.h search_client.h remove_client.h
	$(CC) $(CFLAGS) -c main.c

add_client.o: add_client.c add_client.h
	$(CC) $(CFLAGS) -c add_client.c

view_client_list.o: view_client_list.c view_client_list.h
	$(CC) $(CFLAGS) -c view_client_list.c

search_client.o: search_client.c search_client.h
	$(CC) $(CFLAGS) -c search_client.c

remove_client.o: remove_client.c remove_client.h
	$(CC) $(CFLAGS) -c remove_client.c

clean:
	rm -f $(OBJ) $(TARGET)

