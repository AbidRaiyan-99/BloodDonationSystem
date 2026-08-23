#include <stdio.h>
#include <string.h>
#include "login.h"

int login()
{
    char userId[20];
    char password[20];

    printf("\n=====================================\n");
    printf("       BLOOD DONATION SYSTEM\n");
    printf("              LOGIN\n");
    printf("=====================================\n");

    printf("Enter User ID: ");
    scanf("%19s", userId);

    printf("Enter Password: ");
    scanf("%19s", password);

    if (strcmp(userId, "admin") == 0 &&
        strcmp(password, "1234") == 0)
    {
        printf("\nLogin Successful!\n");
        return 1;
    }

    printf("\nInvalid User ID or Password!\n");

    return 0;
}