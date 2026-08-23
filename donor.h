#ifndef DONOR_H
#define DONOR_H

typedef struct
{
    int id;
    char name[50];
    int age;
    char bloodGroup[5];
} Donor;

void addDonor();
void displayDonors();
void searchDonor();
void updateDonor();
void deleteDonor();

#endif