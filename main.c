#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "records.h"

int main()
{
    if(round == 0)
    {
        printf("For return to the menu or exit the program enter \"exit\"\n\n");
        LoadFromFile();
        round ++;
    }
    char input[100];
    printf("1 - Insert a new person\n\n");
    printf("2 - Display records\n\n");
    printf("3 - Search person (edit, delete)\n\n");
    printf("4 - History of events\n\n");
    printf("5 - Save and exit\n\n");
    printf("6 - Exit\n\n");
    scanf(" %99[^\n]s", input);
    while(stricmp(input, "1") != 0 && stricmp(input, "2") != 0 && stricmp(input, "3") != 0 && stricmp(input, "4") != 0 && stricmp(input, "5") != 0 && stricmp(input, "6") && stricmp(input, "exit"))
    {

        printf("Only numbers 1 - 6 can be entered\n");
        scanf(" %99[^\n]s", input);
    }

    switch (input[0])
    {
    case '1':
        system("cls");
        InsertPerson();
        break;
    case '2':
        system("cls");
        Display();
        main();
        break;
    case '3':
        system("cls");
        Search();
        break;
    case '4':
        system("cls");
        DisplayHistory();
        break;
    case '5':
        system("cls");
        Save();
        break;
    case '6':
        system("cls");
        CloseProgram();
        break;
    }
    if(stricmp(input, "exit") == 0)
    {
        system("cls");
        return 0;
    }
}