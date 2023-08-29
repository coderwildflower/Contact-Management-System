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
    char phNumber[10];
} uData;

int totalUsers = 0;

void LoginUser();
void RegisterUser();
//--------------------------

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
    char temp_phNumber[10];

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
        LimitInput(50, _contact.name);

        printf("Enter a Phone Number: \n");
        LimitInput(11, _contact.phone);

        printf("Enter an Email Address: \n");
        LimitInput(50, _contact.email);

        printf("Enter an Address: \n");
        LimitInput(50, _contact.address);

        printf("Enter Gender [M/F/O] \n");
        _contact.gender = getche();
        printf("\n\n");

        printf("Enter a Profession \n");
        LimitInput(50, _contact.profession);

        // Validate datas---------------

        if (isValidName(_contact.name) == 1 && isValidName(_contact.address) == 1 && isValidName(_contact.profession) == 1 && isValidNumber(_contact.phone) == 1)
        {
            // fwrite(_contact.name,sizeof(int),50,contactFile);
            // fwrite(_contact.phone,sizeof(int),20,contactFile);
            // fwrite(_contact.email,sizeof(int),50,contactFile);
            // fwrite(_contact.address,sizeof(int),50,contactFile;
            // fwrite(_contact.gender,sizeof(int),2,contactFile);
            // fwrite(_contact.profession,sizeof(int),50,contactFile);

            fprintf(contactFile, "%s\n", _contact.name);
            fprintf(contactFile, "%s\n", _contact.phone);
            fprintf(contactFile, "%s\n", _contact.email);
            fprintf(contactFile, "%s\n", _contact.address);
            fprintf(contactFile, "%c\n", _contact.gender);
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
    printf("--------------------------------- \n");
    printf("    Reomve All Contacts  \n");
    printf("--------------------------------- \n\n");
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

    if (fscanf(contactFile, "%s %s %s %s %c %s", _contact.name, _contact.phone, _contact.email, _contact.address,&_contact.gender, _contact.profession) != EOF)
    {
        printf("\t\t|=============================================================================================================================================================================|\n");
        printf("\t\t| ID  | %-35s| %-15s| %-35s| %-35s| %-6s  | %s", "Name", "Phone", "Email", "Address", "Gender", "Profession                  |\n");
        printf("\t\t|=============================================================================================================================================================================|\n");

        do
        {
            printf("\t\t| %d   | %-35.25s| %-15.10s| %-35.25s| %-35.20s| %c\t| %.35s \t\t      |\n", counter++, _contact.name, _contact.phone, _contact.email, _contact.address, &_contact.gender, _contact.profession);

        } while (fscanf(contactFile, "%s %s %s %s %c %s\n", _contact.name, _contact.phone, _contact.email, _contact.address, &_contact.gender, _contact.profession) != EOF);

        printf("\t\t|=============================================================================================================================================================================| \n\n");
        fclose(contactFile);
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

//-----------------------------------INPUT VALIDATION-----------------------------------------------
void LimitInput(int targetCount, char input[])
{
    if (input == NULL)
    {
        printf("Invalid Input.\n");
        return;
    }
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
    printf("\n\n");
}

int isValidName(char name[])
{

    if (name == NULL || name[0] == '\0')
    {
        printf("------------------------------------------ \n");
        printf("ERROR: Name Cannot Be Empty. \n");
        printf("------------------------------------------ \n");
        return 0;
    }

    size_t length = strlen(name);

    for (int i = 0; i < length; i++)
    {
        if (!isalpha(name[i]))
        {
            printf("------------------------------------------ \n");
            printf("ERROR: Please Enter Alphabets Only. \n");
            printf("------------------------------------------ \n");
            return 0;
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