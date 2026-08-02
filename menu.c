#include <stdio.h>
#include "menu.h"
#include "donor.h"

void mainMenu()
{
    int choice;

    do
    {
        printf("\n========== BLOOD DONATION SYSTEM ==========\n");
        printf("1. Add Donor\n");
        printf("2. Display Donors\n");
        printf("3. Search Donor\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addDonor();
            break;

        case 2:
            displayDonors();
            break;

        case 3:
            searchDonor();
            break;

        case 4:
            printf("\nThank You!\n");
            break;

        default:
            printf("\nInvalid Choice!\n");
        }

    } while (choice != 4);
}