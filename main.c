#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// lOGIN SYSTEM-------------
struct userData
{
    const char userName[20];
    const char password[20];
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
};
//--------------------------------

// Function Prototype-----------------
void DisplayLoginMenu();

void DisplayAdminMenu();

void DisplayUserMenu();

void CreateContact();

void EditContact();

void RemoveContact();

void RemoveAllContacts();

void SearchContact();

void DisplayAllContacts();

void ExitApplication();

void GetInput_AdminMenu();

void GetInput_UserMenu();

void GetInput_LoginMenu();
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
    fprintf(file_W, "%s\n", uData.userName);

    printf("Please Enter Your Password\n");
    scanf("%s", &uData.password);
    fprintf(file_W, "%s", uData.password);

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

    printf("Please Enter Your Username\n");
    scanf("%s", temp_name);
    printf("Please Enter Your password\n");
    scanf("%s", temp_pw);

    while (fscanf(file_R, "%s %s", uData.userName, uData.password) != EOF)
    {
        if (strcmp(uData.userName, temp_name) == 0 && strcmp(uData.password, temp_pw) == 0)
        {
            printf("Login Successful !! Press any key to Continue\n");
            getch();

            DisplayAdminMenu();
        }
    }
    printf("Login Failed!!! Please Enter correct credentials.\n");
    printf("Press any key to go to login menu");
    getch();
    main();
}

//------------------------------------MENU HANDLERS---------------------------------------------------------------
void DisplayLoginMenu()
{
    system("cls");
    printf("\t\t\t\t- - - - - - - - - - - - - \n");
    printf("\t\t\t\tCONTACT MANAGEMENT SYSTEM\n");
    printf("\t\t\t\t- - - - - - - - - - - - - \n\n");
    printf("Please Choose an Option\n");

    printf("1. Login\n");
    printf("2. Register\n");

    GetInput_LoginMenu();
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

    GetInput_AdminMenu();
}

void DisplayUserMenu()
{
    system("cls");
    printf("1. Search Contacts\n");
    printf("2. Display All Contacts\n");

    GetInput_UserMenu();
}

// Data Creation and Management Starts from here----------------------------------------------------------------
void CreateContact()
{
    system("cls");
    printf("\t\t\tCREATE CONTACT\n");

    int contactIndex = 0;
    int maxContact = 100;
    struct Contact _contact[100];
    FILE *contactFile;

    contactFile = fopen("contacts.txt", "a");
    if (contactFile == NULL)
    {
        printf("Error opening file.\n");
    }

    printf("Enter the Name: \n");
    scanf("%s", &_contact[contactIndex].name);
    fprintf(contactFile, "Name: %s\n",_contact[contactIndex].name);

    printf("Enter a Phone Number: \n");
    scanf("%s", &_contact[contactIndex].phone);
    fprintf(contactFile, "Phone Number: %s\n", _contact[contactIndex].phone);

    printf("Enter an Email Address: \n");
    scanf("%s", &_contact[contactIndex].email);
    fprintf(contactFile, "Email: %s\n", _contact[contactIndex].email);

    printf("Enter an Address: \n");
    scanf("%s", &_contact[contactIndex].address);
    fprintf(contactFile, "Address: %s\n", _contact[contactIndex].address);

    printf("Enter Gender \n");
    scanf("%s", &_contact[contactIndex].gender);
    fprintf(contactFile, "Gender: %s\n", _contact[contactIndex].gender);

    fclose(contactFile);
    contactIndex++;
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

    fflush(stdin);
}

void GetInput_UserMenu()
{
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
     fflush(stdin);
}

void GetInput_LoginMenu()
{
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

    default:
        printf("Please Enter Valid Option");
        break;
    }
     fflush(stdin);
}
