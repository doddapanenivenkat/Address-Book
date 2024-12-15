/*-----------------------------------------------------------------------
NAME        : D.VENKAT
DATE        : 14/08/2024
DESCRIPTION : ADDRESS BOOK
-------------------------------------------------------------------------*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) 
{
    FILE *fp;
    fp = fopen("contacts.csv","w+");

    if(fp == NULL)
    {
        printf("Can't open the file contacts.csv\n");
        return;
    }
    fprintf(fp,"%c%d\n",'#',addressBook->contactCount);
    
    for(int i = 0; i < addressBook->contactCount;i++)
    {
        fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fp);
    exit(EXIT_SUCCESS);
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fp;
    fp = fopen("contacts.csv","r");

    if(fp == NULL)
    {
        printf("Can't open file contacts.csv\n");
        return;
    }

    //fseek(fp,1,SEEK_SET);
    //printf("%d\n",addressBook->contactCount);

    char str[5];
    if(fgets(str, sizeof(str), fp) != NULL && str[0] == '#')
    {
        addressBook->contactCount = atoi(str + 1);
    }
    //fscanf(fp,"%d\n",addressBook->contactCount);

    for(int i = 0;i < addressBook->contactCount;i++)
    {
        fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

    fclose(fp);
}
