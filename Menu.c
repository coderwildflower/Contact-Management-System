#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

// Store Information
struct Contact
{
    char name[20];
    char phone[10];
    char email[20];
    char address[20];
    char gender[10];
};

// Display Stuffs-------------------------------------------------------------------------------
void DisplayLoginMenu()
{
  
    printf("\t\t\t\t- - - - - - - - - - - - - \n");
    printf("\t\t\t\tCONTACT MANAGEMENT SYSTEM\n");
    printf("\t\t\t\t- - - - - - - - - - - - - \n\n");
    printf("Please Choose an Option\n");

    printf("1. Login\n");
    printf("2. Register\n");

}

void DisplayAdminMenu()
{
  
    system("cls");

    printf("1. Create New Contact\n");
    printf("2. Edit Contact\n");
    printf("3. Remove Contact\n");
    printf("4. Remove All Contacts\n");
    printf("5. Search Contacts\n");
    printf("6. Display All Contacts\n");
    printf("7. Exit\n");
}

void DisplayUserMenu()
{
    system("cls");

    printf("1. Search Contacts\n");
    printf("2. Display All Contacts\n");
}

// Data Creation Starts from here----------------------------------------------------------------
void CreateContact()
{
    system("cls");

    printf("\t\t\tCREATE CONTACT\n");

    struct Contact _contact;
    FILE *contactFile;

    contactFile = fopen("contacts.txt", "a");
    if (contactFile == NULL)
    {
        printf("Error opening file.\n");
    }

    printf("Enter the Name: \n");
    scanf("%s",&_contact.name);
    fprintf(contactFile, "Name: %s\n", _contact.name);

    printf("Enter a Phone Number: \n");
    scanf("%s",&_contact.phone);
    fprintf(contactFile, "Phone Number: %s\n",_contact.phone);

    printf("Enter an Email Address: \n");
    scanf("%s",&_contact.email);
    fprintf(contactFile, "Email: %s\n", _contact.email);

    printf("Enter an Address: \n");
    scanf("%s",&_contact.address);
    fprintf(contactFile, "Address: %s\n", _contact.address);

    printf("Enter Gender \n");
    scanf("%s",&_contact.gender);
    fprintf(contactFile, "Gender: %s\n", _contact.gender);

    fclose(contactFile);

    printf("New Contact Created.\n");
}

void EditContact()
{
    system("cls");

    printf("\t\tEdit Contact\n");
}

void RemoveContact()
{
    system("cls");

    printf("\t\tRemove Contact\n");
}

void RemoveAllContacts()
{
    system("cls");

    printf("\t\tRemove All Contacts\n");
}

void SearchContact()
{
    system("cls");

    printf("\t\tSearch Contact\n");
}

void DisplayAllContacts()
{
    system("cls");

    printf("\t\tDisplay All Contacts\n");
}

void ExitApplication()
{
    system("cls");

    printf("\t\tExit Menu\n");
}

//------------------------------------------------------------HANDLE USER INPUT---------------------------------------------------------------

void GetInput_AdminMenu()
{
    int num;
    scanf("%d",&num);

    switch (num)
    {
    case 1:
        CreateContact();
        break;
    case 2:
        EditContact();
        break;
    case 3:
        RemoveContact();
        break;
    case 4:
        RemoveAllContacts();
        break;
    case 5:
        SearchContact();
        break;
    case 6:
        DisplayAllContacts();
    case 7:
        ExitApplication();
        break;

    default:
        printf("Please Enter Valid Option");
        break;
    }
}

void GetInput_UserMenu()
{
    int num;
    scanf("%d",&num);

    switch (num)
    {
    case 1:
        SearchContact();
        break;
    case 2:
        DisplayAllContacts();
    case 3:
        ExitApplication();
        break;

    default:
        printf("Please Enter Valid Option");
        break;
    }
}
