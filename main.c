#include <stdio.h>
#include <stdlib.h>
#include "user_manager.h"

int main()
{
    User* users = NULL;
    int userCount = 0;

    // Adăugăm un utilizator
    addUser(&users, &userCount, "David", READ_PERMISSION);
    addUser(&users, &userCount, "Mihai", WRITE_PERMISSION);
    addUser(&users, &userCount, "Andreea", READ_PERMISSION | WRITE_PERMISSION);
    addUser(&users, &userCount, "Antonia", READ_PERMISSION & WRITE_PERMISSION);
    addUser(&users, &userCount, "Gogu", RANDOM_PERMISSION);
    addUser(&users, &userCount, "Gelu", ALL_PERMISSION);

    // Afișăm numele utilizatorului
    printf("%s\n", users[0].name);

    ShowUsers(&users, &userCount);
    printf("\n");
    deleteUser(&users, &userCount, 103);
    printf("\n");
    ShowUsers(&users, &userCount);
    printf("\n");
    modifyNameUser(&users, &userCount, 101, "Alexandru");
    ShowUsers(&users, &userCount);
    printf("\n");

    int a = 1;
    while(a)
    {
        addUserConsole(&users, &userCount);
        ShowUsers(&users, &userCount);
        printf("\nVrei sa adaugi alt utilitzator? (0 - Nu, 1 - Da)");
       
        scanf("%d", &a);
        scanf("%c");
    }
    
    free(users);
    return 0;
}
