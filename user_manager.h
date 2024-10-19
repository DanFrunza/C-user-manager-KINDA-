#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#define READ_PERMISSION 0x01
#define WRITE_PERMISSION 0x02
#define RANDOM_PERMISSION 0x03
#define ALL_PERMISSION 0x00

typedef struct
{
    int id;
    char name[30];
    unsigned char Permission;

}User ;

void addUser(User** users, int*userCounter, char* name, unsigned char permission);
void ShowUsers(User** users, int*userCounter);
void deleteUser(User** users, int*userCounter, int id);
void modifyNameUser(User** users, int* userCounter, int id, char* name);
void addUserConsole(User** users, int* userCounter);

#endif