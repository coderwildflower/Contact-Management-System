#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Menu.h"

// lOGIN SYSTEM-----------
struct userData
{
    const char userName[20];
    const char password[20];
} uData;

int totalUsers = 0;

void LoginUser();
void RegisterUser();
//------------------------

// Function Prototype-----------------
void GetInput_LoginMenu(int);
void GetInput_AdminMenu(int);
void GetInput_UserMenu(int);
void GetInput();

//*********************************************************MAIN FUNCTION*************************************************************************************//

int main()
{
    DisplayLoginMenu();
    GetInput();

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

    fflush(stdout);
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
            printf("Login Successful!\n");
            fflush(stdin);
            DisplayAdminMenu();

            GetInput();
        }
    }
    printf("Login Failed!!!");
}

//------------------------------------------------------------HANDLE USER INPUT---------------------------------------------------------------
void GetInput()
{
    int num;
    scanf("%d", &num);

    if (uState == LoginMenu)
    {
        GetInput_LoginMenu(num);
    }
    else if (uState == AdminMenu)
    {
        GetInput_AdminMenu(num);
    }
    else
        GetInput_UserMenu(num);
}

void GetInput_LoginMenu(int num)
{
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
}

void GetInput_AdminMenu(int num)
{
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

void GetInput_UserMenu(int num)
{
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
