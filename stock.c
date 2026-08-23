#include <stdio.h>
#include <string.h>
#include "stock.h"

void addStock()
{
    FILE *fp;
    Stock s;
    Stock temp;
    int found = 0;

    printf("\nEnter Blood Group: ");
    scanf("%4s", s.bloodGroup);

    printf("Enter Units to Add: ");
    scanf("%d", &s.units);

    fp = fopen("stock.dat", "rb+");

    if (fp == NULL)
    {
        fp = fopen("stock.dat", "wb");

        if (fp == NULL)
        {
            printf("\nFile Error!\n");
            return;
        }

        fwrite(&s, sizeof(Stock), 1, fp);
        fclose(fp);

        printf("\nBlood Stock Added Successfully!\n");
        return;
    }

    while (fread(&temp, sizeof(Stock), 1, fp) == 1)
    {
        if (strcmp(temp.bloodGroup, s.bloodGroup) == 0)
        {
            temp.units += s.units;

            fseek(fp, -(long)sizeof(Stock), SEEK_CUR);

            fwrite(&temp, sizeof(Stock), 1, fp);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        fseek(fp, 0, SEEK_END);
        fwrite(&s, sizeof(Stock), 1, fp);
    }

    fclose(fp);

    printf("\nBlood Stock Updated Successfully!\n");
}

void viewStock()
{
    FILE *fp;
    Stock s;

    fp = fopen("stock.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo Blood Stock Found!\n");
        return;
    }

    printf("\n====================================\n");
    printf("         AVAILABLE BLOOD STOCK\n");
    printf("====================================\n");
    printf("Blood Group\tUnits\n");
    printf("------------------------------------\n");

    while (fread(&s, sizeof(Stock), 1, fp) == 1)
    {
        printf("%-15s%d\n", s.bloodGroup, s.units);
    }

    fclose(fp);
}

void requestBlood()
{
    FILE *fp;
    Stock s;
    char group[5];
    int units;
    int found = 0;

    printf("\nEnter Blood Group: ");
    scanf("%4s", group);

    printf("Enter Required Units: ");
    scanf("%d", &units);

    fp = fopen("stock.dat", "rb+");

    if (fp == NULL)
    {
        printf("\nNo Blood Stock Found!\n");
        return;
    }

    while (fread(&s, sizeof(Stock), 1, fp) == 1)
    {
        if (strcmp(s.bloodGroup, group) == 0)
        {
            found = 1;

            if (s.units >= units)
            {
                s.units -= units;

                fseek(fp, -(long)sizeof(Stock), SEEK_CUR);

                fwrite(&s, sizeof(Stock), 1, fp);

                printf("\nBlood Request Successful!\n");
                printf("Remaining Units: %d\n", s.units);
            }
            else
            {
                printf("\nNot Enough Blood Available!\n");
                printf("Available Units: %d\n", s.units);
            }

            break;
        }
    }

    if (found == 0)
    {
        printf("\nBlood Group Not Found!\n");
    }

    fclose(fp);
}

void stockMenu()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("          BLOOD STOCK MENU\n");
        printf("====================================\n");
        printf("1. Add Blood Stock\n");
        printf("2. View Blood Stock\n");
        printf("3. Request Blood\n");
        printf("4. Back to Main Menu\n");
        printf("====================================\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStock();
            break;

        case 2:
            viewStock();
            break;

        case 3:
            requestBlood();
            break;

        case 4:
            printf("\nReturning to Main Menu...\n");
            break;

        default:
            printf("\nInvalid Choice!\n");
        }

    } while (choice != 4);
}