#include <stdio.h>
#include "menu.h"
#include "donor.h"
#include "stock.h"

void mainMenu()
{
    int choice;

    do
    {
        printf("\n==========================================\n");
        printf("         BLOOD DONATION SYSTEM\n");
        printf("==========================================\n");
        printf("1. Add Donor\n");
        printf("2. Display Donors\n");
        printf("3. Search Donor\n");
        printf("4. Update Donor\n");
        printf("5. Delete Donor\n");
        printf("6. Blood Stock\n");
        printf("7. Exit\n");
        printf("==========================================\n");
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
            updateDonor();
            break;

        case 5:
            deleteDonor();
            break;

        case 6:
            stockMenu();
            break;

        case 7:
            printf("\nThank You!\n");
            break;

        default:
            printf("\nInvalid Choice!\n");
        }

    } while (choice != 7);
}