#include <stdio.h>
#include <string.h>
#include "donor.h"

void addDonor()
{
    FILE *fp;
    Donor d;

    fp = fopen("donors.dat", "ab");

    if (fp == NULL)
    {
        printf("File Error!\n");
        return;
    }

    printf("\nEnter ID: ");
    scanf("%d", &d.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", d.name);

    printf("Enter Age: ");
    scanf("%d", &d.age);

    printf("Enter Blood Group: ");
    scanf("%s", d.bloodGroup);

    fwrite(&d, sizeof(Donor), 1, fp);

    fclose(fp);

    printf("\nDonor Added Successfully!\n");
}

void displayDonors()
{
    FILE *fp;
    Donor d;

    fp = fopen("donors.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\n------------------------------------------\n");
    printf("ID\tName\t\tAge\tBlood Group\n");
    printf("------------------------------------------\n");

    while (fread(&d, sizeof(Donor), 1, fp) == 1)
    {
        printf("%d\t%s\t\t%d\t%s\n",
               d.id, d.name, d.age, d.bloodGroup);
    }

    fclose(fp);
}

void searchDonor()
{
    FILE *fp;
    Donor d;
    char group[5];
    int found = 0;

    printf("\nEnter Blood Group: ");
    scanf("%s", group);

    fp = fopen("donors.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo Records Found!\n");
        return;
    }

    while (fread(&d, sizeof(Donor), 1, fp) == 1)
    {
        if (strcmp(d.bloodGroup, group) == 0)
        {
            printf("\nID : %d", d.id);
            printf("\nName : %s", d.name);
            printf("\nAge : %d", d.age);
            printf("\nBlood Group : %s\n", d.bloodGroup);

            found = 1;
        }
    }

    if (found == 0)
        printf("\nNo Donor Found!\n");

    fclose(fp);
}