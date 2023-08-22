#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
// lOGIN SYSTEM-------------
struct userData
{
    const char userName[20];
    const char password[20];
    const char email[20];
    const char phNumber[20];
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

    printf("\t\t\t\tREGISTER USER\n");

    FILE *file_W;
    file_W = fopen("RegisterUserData.txt", "w");

    if (file_W == NULL)
    {
        printf("Error Creating File.");
    }
    else
        printf("File creation successful\n");

    // Get Input
    printf("Please Enter Your Username\n");
    scanf("%s", &uData.userName);
    fprintf(file_W, "Username: %s\n", uData.userName);

    printf("Please Enter Your Password\n");
    scanf("%d", &uData.password);
    fprintf(file_W, "Password: %s\n", uData.password);

    printf("Please Enter Your Email Address\n");
    scanf("%s", &uData.email);
    fprintf(file_W, "Email Address: %s\n", uData.email);

    fflush(stdin);

    printf("Please Enter Your Phone Number\n");
    scanf("%s", &uData.phNumber);
    fprintf(file_W, "Phone Number: %s\n", uData.phNumber);

    fclose(file_W);

    printf("Registration Successful !!! Press Any Key to Continue.\n");
    getch();

    DisplayLoginMenu();
}

void LoginUser()
{
    system("cls");

    printf("\t\t\t\tLOGIN USER\n");

    FILE *file_R;
    file_R = fopen("RegisterUserData.txt", "r");

    if (file_R == NULL)
    {
        printf("Error Opening File");
    }

    // temporary data holder
    char temp_name[20];
    char temp_pw[20];
    char temp_email[20];
    char temp_phNumber[20];

    printf("Please Enter Your Username\n");
    scanf("%s", temp_name);

    printf("Please Enter Your Email Address\n");
    scanf("%s", temp_email);

    printf("Please Enter Your Phone Number\n");
    scanf("%s", temp_phNumber);

    printf("Please Enter Your password\n");
    scanf("%s", temp_pw);

    while (fscanf(file_R, "%s %s %s %s", uData.userName, uData.password, uData.email, uData.phNumber) != EOF)
    {
        if (strcmp(uData.userName, temp_name) == 0 || strcmp(uData.email, temp_email) == 0 || strcmp(uData.phNumber, temp_phNumber) == 0)
        {
            if (strcmp(uData.password, temp_phNumber) == 0)
            {
                printf("Login Successful !! Press any key to Continue\n");
                getch();

                DisplayAdminMenu();
            }
        }
    }
    printf("Login Failed!!! Please Enter correct credentials.\n");
    printf("Press any key to go to login menu");
    getch();
    DisplayLoginMenu();
}

//------------------------------------MENU HANDLERS---------------------------------------------------------------
void DisplayLoginInfo()
{
    printf("\n\t\t\t\t------------------------------------------- \n");
    printf("\t\t\t\t\tAdmin Login \n");
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
    printf("\t\t\t\t\tContact Management System \n");
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
    printf("1. Search Contacts\n");
    printf("2. Display All Contacts\n");

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
    printf("\t\t\tCREATE CONTACT\n");

    FILE *contactFile;

    contactFile = fopen("contacts.txt", "a");
    if (contactFile == NULL)
    {
        printf("Error opening file.\n");
    }
    else
    {
        printf("Enter the Name: \n");
        gets(_contact.name);

        fflush(stdin);

        printf("Enter a Phone Number: \n");
        scanf("%s", &_contact.phone);

        printf("Enter an Email Address: \n");
        scanf("%s", &_contact.email);

        printf("Enter an Address: \n");
        scanf("%s", &_contact.address);

        printf("Enter Gender \n");
        scanf("%s", &_contact.gender);

        printf("Enter a Profession \n");
        scanf("%s", &_contact.profession);

        fclose(contactFile);

        // Validate datas
        if (isValidName(_contact.name) == 1 && isValidName(_contact.address == 1) && isValidName(_contact.profession == 1) && isValidNumber(_contact.phone) == 1)
        {
            fprintf(contactFile, "Name: %s\n", _contact.name);
            fprintf(contactFile, "Phone Number: %s\n", _contact.phone);
            fprintf(contactFile, "Email: %s\n", _contact.email);
            fprintf(contactFile, "Address: %s\n", _contact.address);
            fprintf(contactFile, "Gender: %s\n", _contact.gender);
            fprintf(contactFile, "Profession: %s\n", _contact.gender);

            printf("New Contact Created. Press Anykey to Continue\n");
            getch();
            DisplayAdminMenu();
        }
        else
        {
            printf("Contact Creation Failed.Please Input Right Information.\n");
            printf("Press Any key To Go To Menu\n");
            getch();
            DisplayAdminMenu();
        }
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
    system("title Display All Contact");
    printf("\n\n\t\t\t\t---------------------------- \n");
    printf("\t\t\t\t   >>> Contacts List <<< \n");
    printf("\t\t\t\t---------------------------- \n\n");

    FILE *contactFile;
    contactFile = fopen("contacts.txt", "r");

    if (fscanf(contactFile, "%s %s %s %s %s %s\n", _contact.name, _contact.phone, _contact.email, _contact.address, _contact.gender, _contact.profession) != EOF)
    {
        printf("\t\t|===============================================================| \n");
        printf("\t\t|ID| \tName\t\t| Phone Number\t\t | Email\t| Address\t\t| Gender | Profession \n");
        printf("\t\t|===============================================================| \n");

        do
        {
            printf("\t\t| %d| %s %s \t| %s |\t %s \t| %s \t| \n", counter++, _contact.name, _contact.phone, _contact.email, _contact.address, _contact.gender, _contact.profession);

        } while (fscanf(contactFile, "%s %s %s %s %s %s\n", _contact.name, _contact.phone, _contact.email, _contact.address, _contact.gender, _contact.profession) != EOF);

        printf("\t\t|===============================================================| \n\n");
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