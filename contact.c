/*-----------------------------------------------------------------------
NAME        : D.VENKAT
DATE        : 14/08/2024
DESCRIPTION : ADDRESS BOOK
-------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}
void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */ 
    //addressBook->contactCount = 0;
    if(addressBook->contactCount >= MAX_CONTACTS)
    {
        printf("Contact List is full\n");
    }   

    int ncontact = 0,nemail = 0;
    Contact contact;
    printf("\n\t\t\t\t\t\tENTER CONTACT DETAILS");
    printf("\nEnter Name: ");
    getchar();
    scanf("%[^\n]",contact.name);
    printf("\nEnter Mobile Number: ");
    scanf("%s",contact.phone);
    if(strlen(contact.phone) != 10)
    {
        ncontact = 1;
    }
    else
    {
        for(int val = 0;val < 10;val++)
        {
            if(contact.phone[val] < '0' || contact.phone[val] > '9')
            {
                ncontact = 1;
                break;
            }
        }
    }
    for(int i = 0;i < addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].phone,contact.phone) == 0)
        {
            printf("Mobile Number already exists\n");
            return;
        }
    }
    if(ncontact == 1)
    {
        printf("Invalid Phone Number,Enter 10 digits.\n");
        return;
    }
    printf("\nEnter Gmail ID: ");
    scanf("%s",contact.email);
    for(int mail = 0;mail < strlen(contact.email);mail++)
    {
        if(contact.email[mail] == '@' || contact.email[mail] == '.')
        {
            nemail++;
        }
    }
    if(nemail < 2)
    {
        printf("Invalid Gmail ID\n");
        return;
    }
    if(ncontact == 0 && nemail == 2)
    {
        addressBook->contacts[addressBook->contactCount] = contact;
        addressBook->contactCount++;
        printf("Contact Added Successfully\n");
    }
}

void listContacts(AddressBook *addressBook)
{
    if((addressBook->contactCount) == 0)
    {
        printf("Empty\n");
    }
    printf("-------------------------------------------------------------------------------------------");
    printf("\nIndex\tName\t\t\t\tPhone Number\t\t\tGmail id\n");
    printf("-------------------------------------------------------------------------------------------\n");
    for(int var = 0;var < addressBook->contactCount;var++)
    {
        printf("%d",var+1);
        printf("\t%-18s",addressBook->contacts[var].name);
        printf("\t\t%-8s",addressBook->contacts[var].phone);
        printf("\t\t\t%-20s\n",addressBook->contacts[var].email);
        
    }
    printf("-------------------------------------------------------------------------------------------\n");
}


void searchContact(AddressBook *addressBook)
{
    printf("\n\t\t\t\t\t\tSEARCH CONTACT \n");
    printf("1. Name\n");
    printf("2. Mobile Number\n");
    printf("3. Email id\n");
    printf("Enter your chocie: ");
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
            {
                printf("Enter Name: ");
                char str[20];
                getchar();
                scanf("%[^\n]",str);
                int i,j;
                int arr[MAX_CONTACTS];
                int found = 0;
                printf("\nIndex\tName\t\t\t\t\t\tPhone Number\t\t\tGmail id\n");
                printf("\t----------\t\t\t\t\t----------\t\t\t----------\n");
                for(i = 0;i < addressBook->contactCount;i++)
                {
                    if(choice == 1 && (strstr(addressBook->contacts[i].name,str) != 0))
                    {
                        arr[found++] = i;
                        printf("%d",i+1);
                        printf("\t%-18s",addressBook->contacts[i].name);
                        printf("\t\t\t\t%-8s",addressBook->contacts[i].phone);
                        printf("\t\t\t%-20s\n",addressBook->contacts[i].email);
                    }        
                }
                if(found == 0)
                {
                    printf("\nContact Not Found\n");
                    return;
                }
            }
            break;
        case 2:
            {
                printf("Enter Mobile Number: ");
                char mobile[20];
                scanf("%s",mobile);
                int i,j;
                int arr[MAX_CONTACTS];
                int found = 0;
                printf("\nIndex\tName\t\t\t\t\t\tPhone Number\t\t\tGmail id\n");
                printf("\t----------\t\t\t\t\t----------\t\t\t----------\n");
                for(i = 0;i < addressBook->contactCount;i++)
                {
                    if(choice == 2 && (strstr(addressBook->contacts[i].phone,mobile) != 0))
                    {
                        
                        arr[found++] = i;
                        printf("%d",i+1);
                        printf("\t%-18s",addressBook->contacts[i].name);
                        printf("\t\t\t\t%-8s",addressBook->contacts[i].phone);
                        printf("\t\t\t%-20s\n",addressBook->contacts[i].email);
                    }
                }
                if(found == 0)
                {
                    printf("\nContact Not Found\n");
                    return;
                }
            }
            break;
        case 3:
            {
                printf("Enter email id: ");
                char str1[20];
                scanf("%s",str1);
                int i,j;
                int arr[MAX_CONTACTS];
                int found = 0;
                printf("\nIndex\tName\t\t\t\t\t\tPhone Number\t\t\tGmail id\n");
                printf("\t----------\t\t\t\t\t----------\t\t\t----------\n");
                for(i = 0;i < addressBook->contactCount;i++)
                {
                    
                    if(choice == 3 && (strstr(addressBook->contacts[i].name,str1) != 0))
                    {
                        arr[found++] = i;
                        printf("%d",i+1);
                        printf("\t%-18s",addressBook->contacts[i].name);
                        printf("\t\t\t\t%-8s",addressBook->contacts[i].phone);
                        printf("\t\t\t%-20s\n",addressBook->contacts[i].email);
                    }
                }
                if(found == 0)
                {
                    printf("\nContact Not Found\n");
                    return;
                }
            }
            break;
        default:
                break;
    }
}

void deleteContact(AddressBook *addressBook)
{
    printf("\n\t\t\t\t\t\tDELETE CONTACT  \n");
    printf("1. By name\n");
    printf("2. By Mobile Number\n");
    printf("3. By Email id\n");
    int option;
    printf("Enter your option: ");
    scanf("%d",&option);
    char str[20];
    printf("Enter Name (or) Mobile Number (or) Email id : ");
    getchar();
    scanf("%[^\n]",str);
    int i,j;
    int arr[MAX_CONTACTS];
    int found = 0;
    printf("\nIndex\tName\t\t\t\t\t\tPhone Number\t\t\tGmail id\n");
    printf("\t----------\t\t\t\t\t----------\t\t\t----------\n");
    for(i = 0;i < addressBook->contactCount;i++)
    {
        if(option == 1 && (strstr(addressBook->contacts[i].name,str) != 0))
        {
            arr[found++] = i;
            printf("%d",i+1);
            printf("\t%-18s",addressBook->contacts[i].name);
            printf("\t\t\t\t%-8s",addressBook->contacts[i].phone);
            printf("\t\t\t%-20s\n",addressBook->contacts[i].email);
        }
        else if(option == 2 && (strstr(addressBook->contacts[i].phone,str) != 0))
        {
            arr[found++] = i;
            printf("%d",i+1);
            printf("\t%-18s",addressBook->contacts[i].name);
            printf("\t\t\t\t%-8s",addressBook->contacts[i].phone);
            printf("\t\t\t%-20s\n",addressBook->contacts[i].email);
        }
        else if(option == 3 && (strstr(addressBook->contacts[i].email,str) != 0))
        {
            arr[found++] = i;
            printf("%d",i+1);
            printf("\t%-18s",addressBook->contacts[i].name);
            printf("\t\t\t\t%-8s",addressBook->contacts[i].phone);
            printf("\t\t\t%-20s\n",addressBook->contacts[i].email);
        }
    }
    int index;
    printf("Enter which index you delete: ");
    scanf("%d",&index);
    for(i = index - 1;i < addressBook->contactCount;i++){
        for(j = i;j < addressBook->contactCount - 1;j++)
        {
            addressBook->contacts[j] = addressBook->contacts[j+1];   
        }
        addressBook->contactCount--;
        printf("Contact Deleted Successfully\n");
        return;
    }
    printf("Contact Not Found\n");
}

void editContact(AddressBook *addressBook)
{
    printf("\n\t\t\t\t\t\tEDIT CONTACT  \n");
    printf("1. By Name\n");
    printf("2. By Mobile Number\n");
    printf("3. By Email id\n");
    printf("Enter your option: ");
    int option;
    scanf("%d",&option);

    switch (option)
    {
        case 1:
            {
                printf("Enter Name: ");
                char str[20];
                getchar();
                scanf("%[^\n]",str);
                editedContact(addressBook,str,option);
            }
        break;
        case 2:
            {
                printf("Enter Mobile Number: ");
                char mobile[20];
                scanf("%s",mobile);
                editedContact(addressBook,mobile,option);
            }
        break;
        case 3:
            {
                printf("Enter Email id : ");
                char email[20];
                scanf("%s",email);
                editedContact(addressBook,email,option);
            }
        break;
        default:
            break;
    }
}
void editedContact(AddressBook *addressBook, const char *str,int option)
{
    int arr[MAX_CONTACTS];
    int found = 0,i;
    printf("\nIndex\tName\t\t\t\t\t\tPhone Number\t\t\tGmail id\n");
    printf("\t----------\t\t\t\t\t----------\t\t\t----------\n");
    for(i = 0;i < addressBook->contactCount;i++)
    {
        if(option == 1 && strstr(addressBook->contacts[i].name,str) != 0 )
        {
            arr[found++] = i;
            printf("%d",i+1);
            printf("\t%-18s",addressBook->contacts[i].name);
            printf("\t\t\t\t%-8s",addressBook->contacts[i].phone);
            printf("\t\t\t%-20s\n",addressBook->contacts[i].email);
        }
        else if(option == 2 && strstr(addressBook->contacts[i].phone,str) != 0 )
        {
            arr[found++] = i;
            printf("%d",i+1);
            printf("\t%-18s",addressBook->contacts[i].name);
            printf("\t\t\t\t%-8s",addressBook->contacts[i].phone);
            printf("\t\t\t%-20s\n",addressBook->contacts[i].email);
        }
        else if(option == 3 && strstr(addressBook->contacts[i].email,str) != 0 )
        {
            arr[found++] = i;
            printf("%d",i+1);
            printf("\t%-18s",addressBook->contacts[i].name);
            printf("\t\t\t\t%-8s",addressBook->contacts[i].phone);
            printf("\t\t\t%-20s\n",addressBook->contacts[i].email);
        }

    }
    if(found == 0)
    {
        printf("No Contacts Found\n");
        return;
    }
    int index;
    printf("Enter which index you edit: ");
    scanf("%d",&index);

    if(index < 0 || index > addressBook->contactCount)
    {
        printf("Invalid index\n");
        return;
    }
    int subchoice;
    printf("1. Edit(name)- ?\n");
    printf("2. Edit(phone)- ?\n");
    printf("3. Edit(email)- ?\n");

    printf("Enter your subchoice : ");
    scanf("%d",&subchoice);
    switch (subchoice)
    {
        case 1:
            {
                printf("Enter New Name: ");
                getchar();
                scanf("%[^\n]",addressBook->contacts[index-1].name);
                printf("Contact updated Successfully\n");
            }
        break;
        case 2:
            {
                printf("Enter New Mobile Number: ");
                scanf("%s",addressBook->contacts[index-1].phone);
                printf("Contact updated Successfully\n");
            }
        break;
        case 3:
            {
                int nemail = 0;
                printf("Enter New Email id: ");
                scanf("%s",addressBook->contacts[index-1].email);
                
                printf("Contact updated Successfully\n");
            }
        break;

        default:
             break;
    } 
       
}
/*void saveAndExit(AddressBook *addressBook) {
    //loadContactsFromFile(addressBook);
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}*/