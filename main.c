#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evidence.h"

int main()
{
    if(kolo == 0)
    {
        printf("Pro navrat do menu nebo ukonceni programu napiste \"exit\"\n\n");
        nacist();
        kolo ++;
    }
    char a[100];
    printf("1 - Zapsat novou osobu\n\n");
    printf("2 - Zobrazit evidenci\n\n");
    printf("3 - Vyhledat osobu (upravit, smazat)\n\n");
    printf("4 - Historie operaci\n\n");
    printf("5 - Ulozit a ukoncit\n\n");
    printf("6 - Ukoncit\n\n");
    scanf(" %99[^\n]s",a);
    while(stricmp(a, "1") != 0 && stricmp(a, "2") != 0 && stricmp(a, "3") != 0 && stricmp(a, "4") != 0 && stricmp(a, "5") != 0 && stricmp(a, "6") && stricmp(a, "exit"))
    {

        printf("Lze zadat pouze cislo 1 - 6\n");
        scanf(" %99[^\n]s",a);
    }

    switch (a[0])
    {
    case '1':
        system("cls");
        zapsat();
        break;
    case '2':
        system("cls");
        zobrazit();
        main();
        break;
    case '3':
        system("cls");
        hledat();
        break;
    case '4':
        system("cls");
        historie();
        break;
    case '5':
        system("cls");
        ulozit();
        break;
    case '6':
        system("cls");
        konec();
        break;
    }
    if(stricmp(a, "exit") == 0)
    {
        system("cls");
        return 0;
    }
}