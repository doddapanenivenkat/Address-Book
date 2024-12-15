/*-----------------------------------------------------------------------
NAME        : D.VENKAT
DATE        : 14/08/2024
DESCRIPTION : ADDRESS BOOK
-------------------------------------------------------------------------*/

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "contact.h"


int main() {
    int choice;
    AddressBook addressBook;
    addressBook.contactCount = 0;
    initialize(&addressBook); // Initialize the address book

    char str[100];

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Load Contacts\n");
        printf("7. Save And Exit\n");
        printf("Enter your choice: ");

        scanf("%s",str);

        int choice = atoi(str);


        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
                listContacts(&addressBook);
                break;
            case 6:
                printf("Loading...\n");
                loadContactsFromFile(&addressBook);
                break;
            case 7:
                printf("Saving ...\n");
                saveContactsToFile(&addressBook);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 7);
    
       return 0;
}
