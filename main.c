#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define ENTER 13
#define TAB 9
#define BKSPC 8
#define ESCAPE 27
// lOGIN SYSTEM-------------
struct userData
{
    char userName[20];
    char password[20];
    char email[20];
    char phNumber[20];
} uData;

int totalUsers = 0;

void LoginUser();
void RegisterUser();
//--------------------------

// STORE CONTACT-----------------
struct Contact
{
    char name[20];
    char phone[10];
    char email[20];
    char address[20];
    char gender[10];
    char profession[100];
};
struct Contact _contact;
//--------------------------------

// Function Prototype-----------------
void DisplayLoginMenu();

void DisplayLoginInfo();

void DisplayAdminMenu();

void DisplayUserMenu();

void CreateContact();

void EditContact();

void RemoveContact();

void RemoveAllContacts();

void SearchContact();

void DisplayAllContacts();

void ExitApplication();

int isValidNumber(char[]);

int isValidName(char *name);
//*********************************************************MAIN FUNCTION*************************************************************************************//

int main()
{
    DisplayLoginMenu();
    return 0;
}

//----------------------------------------------------------USER REGISTER lOGIN SYSTEM-----------------------------------------------------------------------------------
void RegisterUser()
{
    system("cls");

    printf("\n\t\t\t\t------------------------------------------- \n");
    printf("\t\t\t\t\t        Register \n");
    printf("\t\t\t\t------------------------------------------- \n\n");

    FILE *file_W;
    file_W = fopen("RegisterUserData.txt", "wb");

    if (file_W == NULL)
    {
        printf("Error Creating File.");
    }
    else
        printf("File creation successful\n");

    // Get Input
    printf("Please Enter Your Username\n");
    scanf("%s", &uData.userName);
    fprintf(file_W, "%s ", uData.userName);
    printf("\n");

    printf("Please Enter Your Email Address\n");
    scanf("%s", &uData.email);
    fprintf(file_W, "%s ", uData.email);
    printf("\n");

    printf("Please Enter Your Phone Number\n");
    scanf("%s", &uData.phNumber);
    fprintf(file_W, "%s ", uData.phNumber);
    printf("\n");

    printf("Please Enter Your Password\n");
    char c;
    int index = 0;
    while (1)
    {
        c = getch();

        if (c == TAB || c == ESCAPE || c == ENTER)
        {
            uData.password[index] = '\0';
            break;
        }
        else if ((c == BKSPC))
        {
            if (index > 0)
            {
                index--;
                printf("\b");
            }
        }

        else
        {
            uData.password[index] = c;
            index++;
            printf("*");
        }
    }

    // scanf("%s", &uData.password);
    fprintf(file_W, "%s ", uData.password);

    fclose(file_W);

    printf("Registration Successful !!! Press Any Key to Continue.\n");
    getch();

    DisplayLoginInfo();
}

void LoginUser()
{
    system("cls");

    printf("\n\t\t\t\t------------------------------------------- \n");
    printf("\t\t\t\t\t         Login \n");
    printf("\t\t\t\t------------------------------------------- \n\n");

    FILE *file_R;
    file_R = fopen("RegisterUserData.txt", "r");

    if (file_R == NULL)
    {
        printf("Error Opening File!!! Press Any key to go the Menu");
        getch();
        DisplayLoginInfo();
    }

    // temporary data holder
    char temp_name[20];
    char temp_pw[20];
    char temp_email[20];
    char temp_phNumber[20];

    fflush(stdin);

    printf("Please Enter Your Username\n");
    scanf("%s", temp_name);
    printf("\n");

    printf("Please Enter Your Email Address\n");
    scanf("%s", temp_email);
    printf("\n");

    printf("Please Enter Your Phone Number\n");
    scanf("%s", temp_phNumber);
    printf("\n");

    printf("Please Enter Your password\n");
    scanf("%s", temp_pw);
    printf("\n");

    while (fscanf(file_R, "%s %s %s %s", uData.userName, uData.phNumber, uData.email, uData.password) != EOF)
    {
        if (strcmp(uData.userName, temp_name) == 0 || strcmp(uData.email, temp_email) == 0 || strcmp(uData.phNumber, temp_phNumber) == 0)
        {
            if (strcmp(uData.password, temp_pw) == 0)
            {
                printf("Login Successful !! Press any key to Continue\n");
                getch();

                DisplayAdminMenu();
            }
        }
    }

    fclose(file_R);

    printf("Login Failed!!! Please Enter correct credentials.\n");
    printf("Press any key to go to login menu");
    getch();
    DisplayLoginMenu();
}

//------------------------------------MENU HANDLERS---------------------------------------------------------------
void DisplayLoginInfo()
{
    system("cls");

    printf("\n\t\t\t\t------------------------------------------- \n");
    printf("\t\t\t\t\t         Login or Register \n");
    printf("\t\t\t\t------------------------------------------- \n\n");

    printf("[1] Login. \n");
    printf("[2] Register. \n");
    printf("[3] Return. \n");

    int num;
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        LoginUser();
        break;
    case 2:
        RegisterUser();
        break;
    case 3:
        DisplayLoginMenu();
        break;

    default:
        printf("--------------------------------------- \n");
        printf("ERROR: Invalid input. Please try again.  \n");
        printf("--------------------------------------- \n");
        getch();
        DisplayLoginMenu();
        break;
    }
}

void DisplayLoginMenu()
{
    system("cls");

    system("color 3");
    printf("\n\t\t\t\t------------------------------------------- \n");
    printf("\t\t\t\t\t   Contact Management System \n");
    printf("\t\t\t\t------------------------------------------- \n\n");

    printf("Login As: \n\n");
    printf("[1] Administrator. \n");
    printf("[2] User. \n");
    printf("[3] EXIT. \n");
    printf("----------------------------------- \n\n");

    int num;
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        DisplayLoginInfo();
        break;
    case 2:
        DisplayUserMenu();
        break;
    case 3:
        ExitApplication();
        break;

    default:
        printf("--------------------------------------- \n");
        printf("ERROR: Invalid input. Please try again.  \n");
        printf("--------------------------------------- \n");
        getch();
        DisplayLoginMenu();
        break;
    }
}

void DisplayAdminMenu()
{
    system("cls");

    printf("\n\t\t\t\t------------------------------------------- \n");
    printf("\t\t\t\t\t         ADMIN MENU \n");
    printf("\t\t\t\t------------------------------------------- \n\n");

    printf("1. Create New Contact\n");
    printf("2. Edit Contact\n");
    printf("3. Remove Contact\n");
    printf("4. Remove All Contacts\n");
    printf("5. Search Contacts\n");
    printf("6. Display All Contacts\n");
    printf("7. Exit\n");

    int num;
    scanf("%d", &num);

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

void DisplayUserMenu()
{
    system("cls");

    printf("\n\t\t\t\t------------------------------------------- \n");
    printf("\t\t\t\t\t         USER MENU \n");
    printf("\t\t\t\t------------------------------------------- \n\n");

    printf("1. Search Contacts\n");
    printf("2. Display All Contacts\n");
    printf("3. Return to Menu\n");

    int num;
    scanf("%d", &num);

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

// Data Creation and Management Starts from here----------------------------------------------------------------
void CreateContact()
{
    system("cls");
    fflush(stdin);

    printf("\n\t\t\t\t------------------------------------------- \n");
    printf("\t\t\t\t\t         Create Contact \n");
    printf("\t\t\t\t------------------------------------------- \n\n");

    FILE *contactFile;

    contactFile = fopen("contacts.txt", "ab");
    if (contactFile == NULL)
    {
        printf("Error opening file.\n");
    }
    else
    {
        printf("Enter the Name: \n");
        gets(_contact.name);

        printf("\n");

        printf("Enter a Phone Number: \n");
        scanf("%s", &_contact.phone);
        printf("\n");

        printf("Enter an Email Address: \n");
        scanf("%s", &_contact.email);

        printf("\n");

        printf("Enter an Address: \n");
        scanf("%s", &_contact.address);

        printf("\n");

        printf("Enter Gender \n");
        scanf("%s", &_contact.gender);

        printf("\n");

        printf("Enter a Profession \n");
        scanf("%s", &_contact.profession);

        // Validate datas
        fprintf(contactFile, "%s\n", _contact.name);
        fprintf(contactFile, "%s\n", _contact.phone);
        fprintf(contactFile, "%s\n", _contact.email);
        fprintf(contactFile, "%s\n", _contact.address);
        fprintf(contactFile, "%s\n", _contact.gender);
        fprintf(contactFile, "%s\n", _contact.profession);

        // if (isValidName(_contact.name) == 1 && isValidName(_contact.address == 1) && isValidName(_contact.profession == 1) && isValidNumber(_contact.phone) == 1)
        // {
        //     fprintf(contactFile, "Name: %s\n", _contact.name);
        //     fprintf(contactFile, "Phone Number: %s\n", _contact.phone);
        //     fprintf(contactFile, "Email: %s\n", _contact.email);
        //     fprintf(contactFile, "Address: %s\n", _contact.address);
        //     fprintf(contactFile, "Gender: %s\n", _contact.gender);
        //     fprintf(contactFile, "Profession: %s\n", _contact.gender);

        //     printf("New Contact Created. Press Anykey to Continue\n");
        //     getch();
        //     DisplayAdminMenu();
        // }
        // else
        // {
        //     printf("Contact Creation Failed.Please Input Right Information.\n");
        //     printf("Press Any key To Go To Menu\n");
        //     getch();
        //     DisplayAdminMenu();
        // }

        fclose(contactFile);

        printf("Contact Creation Successful. Press Any key");
        getch();
        DisplayAdminMenu();
    }
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
    int counter = 1;

    printf("\n\n\t\t\t\t    ------------------------------------ \n");
    printf("\t\t\t\t              Contacts List \n");
    printf("\t\t\t\t    ------------------------------------ \n\n");

    FILE *contactFile;
    contactFile = fopen("contacts.txt", "r");

    if (fscanf(contactFile, "%s %s %s %s %s %s\n", _contact.name, _contact.phone, _contact.email, _contact.address, _contact.gender, _contact.profession) != EOF)
    {
        printf("\t\t|=========================================================================================================================|\n");
        printf("\t\t|ID| \tName\t\t| Phone Number\t\t| Email\t              | Address\t\t        | Gender | Profession \n");
        printf("\t\t|=========================================================================================================================| \n");

        do
        {
            printf("\t\t| %d| %s \t\t| %s \t\t| %s \t| %s \t\t|%s   |%s \t\t|\n", counter++, _contact.name, _contact.phone, _contact.email, _contact.address, _contact.gender, _contact.profession);

        } while (fscanf(contactFile, "%s %s %s %s %s %s\n", _contact.name, _contact.phone, _contact.email, _contact.address, _contact.gender, _contact.profession) != EOF);

        printf("\t\t|=========================================================================================================================| \n\n");
    }
    else
        printf(" ERROR:There are no contacts saved in the file. \n\n");

    fclose(contactFile);
    printf("Press Any key To Return To Menu");
    getch();
    DisplayAdminMenu();
}

void ExitApplication()
{
    exit(0);
}

//-----------------------------------INPUT VALIDATION-------------------------------------------

int isValidName(char *name)
{
    for (int i = 0; i < strlen(name); i++)
    {
        if (name[i] == '\0')
            break;
        if (!isalpha(name[i]))
        {
            printf("Please Enter Alphabets Only!!!");
            return 0;
        }
    }
    return 1;
}

int isValidNumber(char num[])
{
    int length;
    for (int i = 0; i < 10; i++)
    {
        if (num[i] == '\0')
        {
            length = 0;
            printf("------------------------------------------ \n");
            printf("ERROR: phone number digit must not be empty. \n");
            printf("------------------------------------------ \n");

            return 0;
        }
        if (isdigit(num[i]) == 0)
        {
            length = 0;
            printf("------------------------------------------ \n");
            printf("ERROR: phone number must contain only digits. \n");
            printf("------------------------------------------ \n");

            return 0;
        }

        length++;
    }

    if (length != 10)
    {
        printf("------------------------------------------ \n");
        printf("ERROR: phone number must be of 10 digits. \n");
        printf("------------------------------------------ \n");

        return 0;
    }
    else
        return 1;
}