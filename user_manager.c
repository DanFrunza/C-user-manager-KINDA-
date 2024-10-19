#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_manager.h"

void addUser(User** users, int* userCounter, char* name, unsigned char permission)
{
    *users = realloc(*users, (*userCounter + 1) * sizeof(User));
    if (*users == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);  
    }

    (*users)[*userCounter].id = *userCounter + 101;
    strcpy((*users)[*userCounter].name, name);
    (*users)[*userCounter].Permission = permission;
    (*userCounter)++; 
}

void ShowUsers(User** users, int*userCounter)
{
    if(*users == NULL)
    {
        printf("\nNothing to show.");
    }
    else
    {
        for(int i = 0; i < *userCounter; i++)
        {
            printf("\nUser-ul %d, numele %s, si permisiunea %d.", (*users)[i].id, (*users)[i].name, (*users)[i].Permission);
        }
    }

}

void deleteUser(User** users, int* userCounter, int id)
{
    if (*users == NULL || *userCounter == 0) {
        printf("\nNothing to delete.\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < *userCounter; i++) {
        if ((*users)[i].id == id) {
            found = 1;
            // Mutăm utilizatorii rămași pentru a acoperi locul șters
            for (int j = i; j < *userCounter - 1; j++) {
                (*users)[j] = (*users)[j + 1];
            }
            (*userCounter)--; // Decrementăm numărul de utilizatori
            break; // Oprire după ștergerea utilizatorului
        }
    }

    if (found) {
        if (*userCounter > 0) {
            *users = realloc(*users, (*userCounter) * sizeof(User));
            if (*users == NULL) {
                printf("Memory reallocation failed\n");
                exit(1); // În caz de eroare la realocare
            }
        } else {
            free(*users); // Eliberăm memoria completă dacă nu mai sunt utilizatori
            *users = NULL;
        }
    } else {
        printf("User with ID %d not found.\n", id);
    }
}

void modifyNameUser(User** users, int* userCounter, int id, char* name)
{
    if (*users == NULL) {
        printf("Lista este goala.\n");
        return;
    }

    for (int i = 0; i < *userCounter; i++)
    {
        if ((*users)[i].id == id)
        {
            // Alocăm memorie pentru nume vechi
            char numee[30]; // Alocare pe stack, dimensiunea trebuie să fie aceeași cu max dimensiunea numelui
            strcpy(numee, (*users)[i].name); // Copiem numele vechi

            // Modificăm numele utilizatorului
            strcpy((*users)[i].name, name);
            printf("\nNumele user-ului cu id-ul %d a fost modificat de la %s la %s cu succes.\n", id, numee, name);
            return; // Oprirea funcției după modificare
        }
    }

    // Mesaj de eroare dacă utilizatorul nu a fost găsit
    printf("User cu ID-ul %d nu a fost găsit.\n", id);
}

void addUserConsole(User** users, int* userCounter)
{
    char nume[30];
    printf("\nCe nume vrei sa aiba user-ul pe care vrei sa-l adaugi?\n");
    scanf("%s", nume);
    printf("\nCe permisiune vrei sa aiba user-ul? (0 - Full, 1 - Read, 2 - Write, 3 - Random from Read and Write)\n");
    int a;
    scanf("%d",&a);
    addUser(users, userCounter, nume, a);
}

