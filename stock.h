#ifndef STOCK_H
#define STOCK_H

typedef struct
{
    char bloodGroup[5];
    int units;
} Stock;

void stockMenu();
void addStock();
void viewStock();
void requestBlood();

#endif