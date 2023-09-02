#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define ENTER 13
#define TAB 9
#define BKSPC 8
#define ESCAPE 27

// Enum to check whether the current user is admin or basic user, so the program flows accordingly
enum UserState
{
    Admin,
    Basic
};
enum UserState _uState;

// lOGIN SYSTEM VARIABLES----------------
struct userData
{
    char userName[30];
    char password[30];
    char email[30];
    char phNumber[10];
} uData;

int totalUsers = 0;

void LoginUser();
void RegisterUser();
//----------------------------------

// STORE CONTACT-----------------
struct Contact
{
    char name[50];
    char phone[11];
    char email[50];
    char address[50];
    char gender;
    char profession[50];
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

void SearchContactByPhone();

void SearchContactByName();

void DisplayAllContacts();

void ExitApplication();

void GetInput(int, char[]);

int isValidNumber(char[]);

int isValidName(char *name);

void ReturnToMenu();
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
    file_W = fopen("RegisterUserData.txt", "w");

    if (file_W == NULL)
    {
        printf("Error durring Register. Press Any key To Return To Menu");
        getch();
        DisplayLoginInfo();
    }
    else
    {
        // Get Input
        printf("Please Enter Your Username\n");
        scanf("%s", &uData.userName);
        printf("\n");

        fflush(stdin);
        printf("Please Enter Your Email Address\n");
        scanf("%s", &uData.email);
        printf("\n");

        fflush(stdin);
        printf("Please Enter Your Phone Number\n");
        scanf("%s", &uData.phNumber);
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
                    printf("\b \b");
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
        fprintf(file_W, "%s %s %s %s", uData.userName, uData.email, uData.phNumber, uData.password);
    }
    fclose(file_W);
    printf("\n");
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
        printf("Error: Admin Not Registered. Press Any key to go the Registration Menu");
        getch();
        DisplayLoginInfo();
    }

    // temporary data holder
    char temp_pw[30];
    char input[30];

    fflush(stdin);

    printf("Please Enter Your Username OR Email Address OR Phone Number\n");

    scanf("%s", input);
    printf("\n");

    printf("Please Enter Your password\n");
    scanf("%s", temp_pw);
    printf("\n");

    while (fscanf(file_R, "%s %s %s %s", uData.userName, uData.phNumber, uData.email, uData.password) != EOF)
    {
        if (strcmp(uData.userName, input) == 0 || strcmp(uData.email, input) == 0 || strcmp(uData.phNumber, input) == 0)
        {
            if (strcmp(uData.password, temp_pw) == 0)
            {
                printf("Login Successful !! Press any key to Continue\n");
                getch();
                _uState = Admin;
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
    printf("\t\t\t\t\t     Login or Register \n");
    printf("\t\t\t\t------------------------------------------- \n\n");

    printf("[1] Login. \n");
    printf("[2] Register. \n");
    printf("[3] Return To Main Menu. \n");

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
    printf("7. Return To Login Menu\n");
    printf("8. Exit\n");

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
        DisplayLoginMenu();
    case 8:
        ExitApplication();
        break;

    default:
        printf("Please Enter Valid Option");
        getch();
        DisplayAdminMenu();
        break;
    }
}

void DisplayUserMenu()
{
    system("cls");
    _uState = Basic;
    printf("\n\t\t\t\t------------------------------------------- \n");
    printf("\t\t\t\t\t         USER MENU \n");
    printf("\t\t\t\t------------------------------------------- \n\n");

    printf("1. Search Contacts\n");
    printf("2. Display All Contacts\n");
    printf("3. Return to Login Menu\n");

    int num;
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        SearchContact();
        break;
    case 2:
        DisplayAllContacts();
        break;
    case 3:
        DisplayLoginMenu();
        break;

    default:
        printf("Please Enter Valid Option");
        getch();
        ReturnToMenu();
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

    contactFile = fopen("contacts.txt", "a");
    if (contactFile == NULL)
    {
        printf("Error !! Press Any key to go the Menu");
        getch();
        DisplayAdminMenu();
    }
    else
    {
        printf("Enter the Name: \n");
        GetInput(sizeof(_contact.name), _contact.name);

        printf("Enter a Phone Number: \n");
        GetInput(sizeof(_contact.phone), _contact.phone);

        printf("Enter an Email Address: \n");
        GetInput(sizeof(_contact.email), _contact.email);

        printf("Enter an Address: \n");
        GetInput(sizeof(_contact.address), _contact.address);

        printf("Enter Gender [M/F/O] \n");
        _contact.gender = getche();
        printf("\n\n");

        printf("Enter a Profession \n");
        GetInput(sizeof(_contact.profession), _contact.profession);

        // Validate datas---------------

        if (isValidName(_contact.name) == 1 && isValidName(_contact.address) == 1 && isValidName(_contact.profession) == 1 && isValidNumber(_contact.phone) == 1)
        {
            // fwrite(_contact.name,sizeof(int),50,contactFile);
            // fwrite(_contact.phone,sizeof(int),20,contactFile);
            // fwrite(_contact.email,sizeof(int),50,contactFile);
            // fwrite(_contact.address,sizeof(int),50,contactFile;
            // fwrite(_contact.gender,sizeof(int),2,contactFile);
            // fwrite(_contact.profession,sizeof(int),50,contactFile);

            fprintf(contactFile, "%s ", _contact.name);
            fprintf(contactFile, "%s ", _contact.phone);
            fprintf(contactFile, "%s ", _contact.email);
            fprintf(contactFile, "%s ", _contact.address);
            fprintf(contactFile, "%c ", _contact.gender);
            fprintf(contactFile, "%s\n", _contact.profession);

            fclose(contactFile);
            printf("New Contact Created Successfully. Press Anykey To Go To Admin Menu\n");
            getch();
            DisplayAdminMenu();
        }
        else
        {
            fclose(contactFile);
            printf("Press Any key To Go Admin Menu\n");
            getch();
            DisplayAdminMenu();
        }
    }
}

void EditContact()
{
    system("cls");
    printf("\n\t\t\t\t------------------------------------------- \n");
    printf("\t\t\t\t\t         EDIT CONTACT \n");
    printf("\t\t\t\t------------------------------------------- \n\n");

    int found = 0;
    int counter = 1;
    char num[15];

    printf("Please Enter a Phone Number\n");
    GetInput(sizeof(num), num);

    printf("\n");
    if (isValidNumber(num) != 1)
    {
        printf("Error: Press Any Key To Return To Menu.\n");
        getch();
        ReturnToMenu();
    }
    else
    {
        FILE *file, *temp;
        file = fopen("contacts.txt", "r");
        temp = fopen("EditTemp.txt", "w");

        while (fscanf(file, "%s %s %s %s %c %s", _contact.name, _contact.phone, _contact.email, _contact.address, &_contact.gender, _contact.profession) != EOF)
        {
            if (strcmp(num, _contact.phone) == 0)
            {
                if (counter == 1)
                {
                    printf("\t\t|=============================================================================================================================================================================|\n");
                    printf("\t\t| ID  | %-35s| %-15s| %-35s| %-35s| %-6s  | %s", "Name", "Phone", "Email", "Address", "Gender", "Profession                  |\n");
                    printf("\t\t|=============================================================================================================================================================================|\n");
                }
                printf("\t\t| %d   | %-35.25s| %-15.10s| %-35.25s| %-35.20s| %c\t| %.35s \t\t      |\n", counter++, _contact.name, _contact.phone, _contact.email, _contact.address, &_contact.gender, _contact.profession);
                printf("\t\t|=============================================================================================================================================================================|\n");
                found++;

                printf("Enter a New Name: \n");
                GetInput(sizeof(_contact.name), _contact.name);

                printf("Enter a New Phone Number: \n");
                GetInput(sizeof(_contact.phone), _contact.phone);

                printf("Enter a New Email Address: \n");
                GetInput(sizeof(_contact.email), _contact.email);

                printf("Enter a New Address: \n");
                GetInput(sizeof(_contact.address), _contact.address);

                printf("Enter New Gender [M/F/O] \n");
                _contact.gender = getche();
                printf("\n\n");

                printf("Enter a New Profession \n");
                GetInput(sizeof(_contact.profession), _contact.profession);

                // Validate datas------------------

                if (isValidName(_contact.name) == 1 && isValidName(_contact.address) == 1 && isValidName(_contact.profession) == 1 && isValidNumber(_contact.phone) == 1)
                {
                    fprintf(temp, "%s ", _contact.name);
                    fprintf(temp, "%s ", _contact.phone);
                    fprintf(temp, "%s ", _contact.email);
                    fprintf(temp, "%s ", _contact.address);
                    fprintf(temp, "%c ", _contact.gender);
                    fprintf(temp, "%s\n", _contact.profession);
                }
                else
                {
                    printf("Press Any key To Go Admin Menu\n");
                    getch();
                    DisplayAdminMenu();
                }
            }
            else

                fprintf(temp, "%s %s %s %s %c %s\n", _contact.name, _contact.phone, _contact.email, _contact.address, &_contact.gender, _contact.profession);
        }

        fclose(file);
        fclose(temp);

        if (found == 0)
        {
            printf("----------------------------------------- \n");
            printf("  Error: No contacts found. Press Enter Key To Return To Menu \n");
            printf("----------------------------------------- \n");

            getch();
            ReturnToMenu();
        }
        file = fopen("contacts.txt", "w");
        temp = fopen("EditTemp.txt", "r");

        while (fscanf(temp, "%s %s %s %s %c %s", _contact.name, _contact.phone, _contact.email, _contact.address, &_contact.gender, _contact.profession) != EOF)
            fprintf(file, "%s %s %s %s %c %s\n", _contact.name, _contact.phone, _contact.email, _contact.address, &_contact.gender, _contact.profession);

        fclose(file);
        fclose(temp);

        printf("Contact Edited Successfully. Press Anykey To Go To Admin Menu\n");
        getch();
        DisplayAdminMenu();
    }
}

void RemoveContact()
{
    system("cls");

    char number[11];
    int found = 0;
    int counter = 1;
    char num[15];

    printf("Please Enter a Phone Number to search\n");
    GetInput(sizeof(num), num);

    printf("\n");
    if (isValidNumber(num) != 1)
    {
        printf("Error: Press Any Key To Return To Menu.\n");
        getch();
        ReturnToMenu();
    }

    FILE *file, *tempDelete;
    file = fopen("contacts.txt", "r");
    tempDelete = fopen("tempDelete.txt", "w");

    while (fscanf(file, "%s %s %s %s %c %s", _contact.name, _contact.phone, _contact.email, _contact.address, &_contact.gender, _contact.profession) != EOF)
    {
        if (strcmp(num, _contact.phone) == 0)
        {
            if (counter == 1)
            {
                printf("\t\t|=============================================================================================================================================================================|\n");
                printf("\t\t| ID  | %-35s| %-15s| %-35s| %-35s| %-6s  | %s", "Name", "Phone", "Email", "Address", "Gender", "Profession                  |\n");
                printf("\t\t|=============================================================================================================================================================================|\n");
            }
            printf("\t\t| %d   | %-35.25s| %-15.10s| %-35.25s| %-35.20s| %c\t| %.35s \t\t      |\n", counter++, _contact.name, _contact.phone, _contact.email, _contact.address, &_contact.gender, _contact.profession);
            found++;

            printf("Do You Want To Delete This Contact? (Y/N)\n");
            char ch = getch();
            if (ch == 'Y' || ch == 'y')
            {
                printf("Deleting Contacts ...\n");
            }
            else if (ch == 'N' || ch == 'n')
            {
                printf("Contact Deletion is Canceled\n");
            }
            else
                printf("Please Input Valid Option\n");
        }
        else
            fprintf(tempDelete, "%s %s %s %s %c %s\n", _contact.name, _contact.phone, _contact.email, _contact.address, &_contact.gender, _contact.profession);
    }
    fclose(file);
    fclose(tempDelete);

    if (found == 0)
    {
        printf("----------------------------------------- \n");
        printf("  Error: No contacts found. Press Enter Key To Return To Menu \n");
        printf("----------------------------------------- \n");

        getch();
        ReturnToMenu();
    }

    file = fopen("contacts.txt", "w");
    tempDelete = fopen("tempDelete.txt", "r");

    while (fscanf(tempDelete, "%s %s %s %s %c %s", _contact.name, _contact.phone, _contact.email, _contact.address, &_contact.gender, _contact.profession) != EOF)
        fprintf(file, "%s %s %s %s %c %s\n", _contact.name, _contact.phone, _contact.email, _contact.address, &_contact.gender, _contact.profession);

    fclose(file);
    fclose(tempDelete);

    printf("Contact Deleted Successfully. Press Anykey To Go To Admin Menu\n");
    getch();
    DisplayAdminMenu();
}

void RemoveAllContacts()
{
    system("cls");
    printf("--------------------------------- \n");
    printf("    Remove All Contacts  \n");
    printf("--------------------------------- \n\n");

    fflush(stdin);
    char confirmDelete[10];

    printf("Type `CONFIRM` to delete all the contacts: \n");
    gets(confirmDelete);
    printf("\n");

    FILE *contactFile;
    // checks for the confirmation message
    int choice = strcmp(confirmDelete, "CONFIRM");
    if (choice == 0)
    {
        contactFile = fopen("contacts.txt", "w"); // erases everything from file and then save it
        fclose(contactFile);
        printf("------------------------------------------- \n");
        printf("Success: All the contact details are deleted. \n");
        printf("------------------------------------------- \n");
    }
    else
    {
        printf("----------------------------------------- \n");
        printf("ERROR: Invalid message. \n");
        printf("----------------------------------------- \n");
    }

    printf("Press Any Key To Return To Admin Menu");
    getch();
    DisplayAdminMenu();
}

void SearchContact()
{
    system("cls");

    printf("\n\n\t\t\t\t    ------------------------------------ \n");
    printf("\t\t\t\t               Search Contacts\n");
    printf("\t\t\t\t    ------------------------------------ \n\n");

    printf("1. Search By Phone Number\n");
    printf("2. Search By Address\n");
    printf("3. Return To Menu\n");

    int num;
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        SearchContactByPhone();
        break;
    case 2:
        SearchContactByName();
        break;
    case 3:
        ReturnToMenu();
        break;

    default:
        printf("Error: Please Enter Valid Option");
        getch();
        DisplayUserMenu();
    }
}

void SearchContactByPhone()
{
    system("cls");

    printf("\n\n\t\t\t\t    ------------------------------------ \n");
    printf("\t\t\t\t        Search Contacts By Phone Number\n");
    printf("\t\t\t\t    ------------------------------------ \n\n");

    int found = 0;
    int counter = 1;
    char num[15];

    printf("Please Enter a Phone Number to search\n");
    GetInput(sizeof(num), num);

    printf("\n");
    if (isValidNumber(num) != 1)
    {
        printf("Error: Press Any Key To Return To Menu.\n");
        getch();
        ReturnToMenu();
    }

    FILE *file;
    file = fopen("contacts.txt", "r");
    while (fscanf(file, "%s %s %s %s %c %s", _contact.name, _contact.phone, _contact.email, _contact.address, &_contact.gender, _contact.profession) != EOF)
    {
        if (strcmp(num, _contact.phone) == 0)
        {
            if (counter == 1)
            {
                printf("\t\t|=============================================================================================================================================================================|\n");
                printf("\t\t| ID  | %-35s| %-15s| %-35s| %-35s| %-6s  | %s", "Name", "Phone", "Email", "Address", "Gender", "Profession                  |\n");
                printf("\t\t|=============================================================================================================================================================================|\n");
            }
            printf("\t\t| %d   | %-35.25s| %-15.10s| %-35.25s| %-35.20s| %c\t| %.35s \t\t      |\n", counter++, _contact.name, _contact.phone, _contact.email, _contact.address, &_contact.gender, _contact.profession);
            found++;
        }
    }
    fclose(file);

    if (found == 0)
    {
        printf("----------------------------------------- \n");
        printf("    Error: No contacts found. \n");
        printf("----------------------------------------- \n");
    }

    printf("Press Any Key To Return To Menu.\n");
    getch();
    ReturnToMenu();
}

void SearchContactByName()
{
    system("cls");

    printf("\n\n\t\t\t\t    ------------------------------------ \n");
    printf("\t\t\t\t        Search Contacts By Address\n");
    printf("\t\t\t\t    ------------------------------------ \n\n");

    int found = 0;
    int counter = 1;
    char Address[50];

    printf("Please Enter an Address to search\n");
    GetInput(sizeof(Address), Address);

    printf("\n");
    if (isValidName(Address) != 1)
    {
        printf("Error: Press Any Key To Return To Menu.\n");
        getch();
        ReturnToMenu();
    }

    FILE *file;
    file = fopen("contacts.txt", "r");
    while (fscanf(file, "%s %s %s %s %c %s", _contact.name, _contact.phone, _contact.email, _contact.address, &_contact.gender, _contact.profession) != EOF)
    {
        if (strcmp(Address, _contact.address) == 0)
        {
            if (counter == 1)
            {
                printf("\t\t|=============================================================================================================================================================================|\n");
                printf("\t\t| ID  | %-35s| %-15s| %-35s| %-35s| %-6s  | %s", "Name", "Phone", "Email", "Address", "Gender", "Profession                  |\n");
                printf("\t\t|=============================================================================================================================================================================|\n");
            }
            printf("\t\t| %d   | %-35.25s| %-15.10s| %-35.25s| %-35.20s| %c\t| %.35s \t\t      |\n", counter++, _contact.name, _contact.phone, _contact.email, _contact.address, &_contact.gender, _contact.profession);
            found++;
        }
    }
    fclose(file);

    if (counter > 1)
        printf("\t\t|=============================================================================================================================================================================| \n\n");

    if (found == 0)
    {
        printf("----------------------------------------- \n");
        printf("    Error: No contacts found. \n");
        printf("----------------------------------------- \n");
    }

    printf("Press Any Key To Return To Menu.\n");
    getch();
    ReturnToMenu();
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

    if (fscanf(contactFile, "%s %s %s %s %c %s", _contact.name, _contact.phone, _contact.email, _contact.address, &_contact.gender, _contact.profession) != EOF)
    {
        printf("\t\t|=============================================================================================================================================================================|\n");
        printf("\t\t| ID  | %-35s| %-15s| %-35s| %-35s| %-6s  | %s", "Name", "Phone", "Email", "Address", "Gender", "Profession                  |\n");
        printf("\t\t|=============================================================================================================================================================================|\n");

        do
        {
            printf("\t\t| %d   | %-35.30s| %-15.10s| %-35.30s| %-35.30s| %c\t| %.35s \t\t      |\n", counter++, _contact.name, _contact.phone, _contact.email, _contact.address, &_contact.gender, _contact.profession);

        } while (fscanf(contactFile, "%s %s %s %s %c %s\n", _contact.name, _contact.phone, _contact.email, _contact.address, &_contact.gender, _contact.profession) != EOF);

        printf("\t\t|=============================================================================================================================================================================| \n\n");
        fclose(contactFile);
    }
    else
        printf(" ERROR:There are no contacts saved in the file. \n\n");

    fclose(contactFile);
    printf("Press Any key To Return To Menu");
    getch();
    ReturnToMenu();
}

void ExitApplication()
{
    exit(0);
}

//-----------------------------------INPUT VALIDATION-----------------------------------------------

void GetInput(int targetCount, char input[])
{

    char c;
    int i = 0;

    while (i < targetCount - 1)
    {
        c = getche();
        fflush(stdin);
        if (c == ENTER || c == ESCAPE || c == TAB)
        {
            break;
        }
        else if (c == BKSPC)
        {
            if (i > 0)
            {
                printf("\b \b");
                i--;
            }
        }
        else if (c >= 32 && c <= 126)
        {
            input[i] = c;
            i++;
        }
    }

    input[i] = '\0';

    if (input == NULL)
    {
        printf("Error: Invalid Input. Press Any key To Go To Admin Menu\n");
        getch();
        DisplayAdminMenu();
    }
    printf("\n\n");
}

int isValidName(char name[])
{

    if (name == NULL)
    {
        printf("------------------------------------------ \n");
        printf("ERROR: Name Cannot Be Empty. \n");
        printf("------------------------------------------ \n");
        return 0;
    }

    size_t length = strlen(name);

    for (int i = 0; i < length; i++)
    {
        if (name[i] != ' ')
        {
            if (!isalpha(name[i]))
            {
                printf("------------------------------------------ \n");
                printf("ERROR: Please Enter Alphabets Only. \n");
                printf("------------------------------------------ \n");
                return 0;
            }
        }
    }
    return 1;
}

int isValidNumber(char num[])
{
    for (int i = 0; i < 10; i++)
    {
        if (num[i] == '\0')
        {
            printf("------------------------------------------\n");
            printf("ERROR: Phone number must be of 10 digits.\n");
            printf("------------------------------------------\n");
            return 0;
        }
        else if (num[i] == NULL)
        {
            printf("------------------------------------------\n");
            printf("ERROR: Phone number must not be empty.\n");
            printf("------------------------------------------\n");
            return 0;
        }
        else if (!isdigit(num[i]))
        {
            printf("------------------------------------------\n");
            printf("ERROR: Phone number must contain only digits.\n");
            printf("------------------------------------------\n");
            return 0;
        }
    }
    return 1;
}

void ReturnToMenu()
{
    if (_uState == Admin)
    {
        DisplayAdminMenu();
    }
    else
        DisplayUserMenu();
}