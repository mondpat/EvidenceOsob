int round = 0;
FILE *pfile;

struct evidence
{
    char name[100];
    char surname[100];
    char PhoneNo [100];
    char birthday [100];
    char note [100];
} evd[100];

void nacist()
{
    int PersonNo = 0;
    pfile = fopen("evidence.txt", "r+");
    while (PersonNo < 100)
    {
        fscanf(pfile," %99[^\n]s\n", evd[PersonNo].name);
        fscanf(pfile," %99[^\n]s\n", evd[PersonNo].surname);
        fscanf(pfile," %99[^\n]s\n", evd[PersonNo].PhoneNo);
        fscanf(pfile," %99[^\n]s\n", evd[PersonNo].birthday);
        fscanf(pfile," %99[^\n]s\n", evd[PersonNo].note);
        if(stricmp(evd[PersonNo].name, "\0") == 0)
        {
            break;
        }
        PersonNo ++;
    }
    fclose(pfile);
}

void Display()
{
    if(IsTableEmpty() == 1)
    {
        printf("Evidence je prazdna\n\n");
    }
    else
    {
        printf("    Jmeno    Prijmeni    Telefon    Narozeniny    Poznamka\n");
        int PersonNo = 0;
        while(stricmp(evd[PersonNo].name,"\0")!=0)
        {
            printf("%d    %s  |  %s  |  %s  |  %s  |  %s\n", PersonNo, evd[PersonNo].name, evd[PersonNo].surname, evd[PersonNo].PhoneNo, evd[PersonNo].birthday, evd[PersonNo].note);
            PersonNo++;
        }
        printf("\n");
    }
}

void InsertPerson()
{
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    while(stricmp(evd[a].name, "\0") != 0)
    {
        a ++;
        if(a == 100)
        {
            printf("Evidence je plna\n");
            main();
        }
    }
    char arr[100];
    printf("Zadejte jmeno pro novou osobu:\n");
    while(1)
    {
        if(c == 1)
        {
            printf("Jmeno je obsazeno\n");
        }
        if(c == 0 && b == 100)
        {
            break;
        }
        c = 0;
        b = 0;
        if(d >= 1)
        {
            printf("Zadejte jine jmeno:\n");
        }
        scanf(" %99[^\n]s", arr);
        if(stricmp(arr, "exit") == 0)
        {
            break;
        }
        while(b<100)
        {
            if(stricmp(evd[b].name, arr) == 0)
            {
                c ++;
                break;
            }
            b ++;
        }
        d ++;
    }
    if(stricmp(arr, "exit") != 0)
    {
        strcpy(evd[a].name, arr);
        printf("Zadejte prijmeni:\n");
        scanf(" %99[^\n]s", arr);
        if(stricmp(arr, "exit") != 0)
        {
            strcpy(evd[a].surname, arr);
            printf("Telefon:\n");
            scanf(" %99[^\n]s",arr);
            if(stricmp(arr, "exit") != 0)
            {
                strcpy(evd[a].PhoneNo, arr);
                printf("Narozeniny:\n");
                scanf(" %99[^\n]s",arr);
                if(stricmp(arr, "exit") != 0)
                {

                    strcpy(evd[a].birthday, arr);
                    if(stricmp(arr, "exit") != 0)
                    {
                        printf("Poznamka:\n");
                        scanf(" %99[^\n]s",arr);
                        if(stricmp(arr, "exit") != 0)
                        {
                            strcpy(evd[a].note, arr);
                            system("cls");
                            printf("    Jmeno    Prijmeni    Telefon    Narozeniny    Poznamka\n");
                            printf("%d    %s  |  %s  |  %s  |  %s  |  %s\n\n", a, evd[a].name, evd[a].surname, evd[a].PhoneNo, evd[a].birthday, evd[a].note);
                            pfile = fopen("historie.txt", "a+");
                            fprintf(pfile,"%d.\nZapsana osoba\n%d    %s  |  %s  |  %s  |  %s  |  %s\n-------------------------------------------------\n\n",round, a, evd[a].name, evd[a].surname, evd[a].PhoneNo, evd[a].birthday, evd[a].note);
                            fclose(pfile);
                            round ++;
                            main();
                        }
                    }
                }
            }
        }
    }
    if(stricmp(arr, "exit") == 0)
    {

        strcpy(evd[a].name, "\0");
        strcpy(evd[a].surname, "\0");
        strcpy(evd[a].PhoneNo, "\0");
        strcpy(evd[a].birthday, "\0");
        strcpy(evd[a].note, "\0");
        system("cls");
        round --;
        main();
    }
}

void Save()
{
    int PersonNo = 0;
    pfile = fopen("novy.txt","a+");
    while(stricmp(evd[PersonNo].name, "\0") != 0)
    {
        fprintf(pfile,"%s\n", evd[PersonNo].name);
        fprintf(pfile,"%s\n", evd[PersonNo].surname);
        fprintf(pfile,"%s\n", evd[PersonNo].PhoneNo);
        fprintf(pfile,"%s\n", evd[PersonNo].birthday);
        fprintf(pfile,"%s\n", evd[PersonNo].note);
        PersonNo++;
    }
    fclose(pfile);
    remove("evidence.txt");
    rename("novy.txt","evidence.txt");
    printf("Ulozeno\n");
    return 0;
}

int IsTableEmpty()
{
    int a = 0, b = 0;
    while(a < 100)
    {
        if(stricmp(evd[a].name, "\0") == 0)
        {
            b ++;
        }
        a ++;
    }
    if(b == 100)
    {
        return 1;
    }
    return 0;
}

void Search()
{
    int a = 0, b = 0, c = 0;
    char arr[100];
    if(IsTableEmpty() == 1)
    {
        printf("Evidence je prazdna, abyste mohli osobu vyhledat, je nutne nejakou osobu zapsat\n");
        InsertPerson();
    }
    Display();
    printf("Zadejte jmeno osoby:\n");
    while(1)
    {
        scanf(" %99[^\n]s", arr);
        a = 0;
        while(stricmp(evd[a].name, arr) != 0)
        {
            if(a == 100)
            {
                if(stricmp(arr, "exit") == 0)
                {
                    break;
                }
                printf("Osobu se nepodarilo najit\n");
                printf("Zadejte osobu znovu:\n");
                break;
            }
            a ++;
        }
        if(stricmp(evd[a].name, arr) == 0)
        {
            break;
        }
        if(stricmp(arr, "exit") == 0)
        {
            system("cls");

            main();
            break;
        }
    }
    if(stricmp(evd[a].name, arr) == 0)
    {
        int x;
        char y[100];
        printf("    Jmeno    Prijmeni    Telefon    Narozeniny    Poznamka\n");
        printf("%d    %s  |  %s  |  %s  |  %s  |  %s\n", a, evd[a].name, evd[a].surname, evd[a].PhoneNo, evd[a].birthday, evd[a].note);
        printf("  Dalsi moznosti:\n");
        printf("    1 - Upravit\n");
        printf("    2 - Smazat\n");
        x = a;
        scanf(" %99[^\n]s",y);
        while(stricmp(y, "1") != 0 && stricmp(y, "2") != 0 && stricmp(y, "exit") != 0)
        {
            printf("Lze zadat cislo 1 - 2\n");
            scanf(" %99[^\n]s",y);
        }
        if(stricmp(y, "exit") == 0)
        {
            system("cls");
            main();
        }
        if(stricmp(y, "1") == 0)
        {
            int b = 0;
            char a[100], arr[100];
            printf("  Zvolte parametr ktery chcete prepsat:\n");
            printf("    1 - Jmeno\n");
            printf("    2 - Prijmeni\n");
            printf("    3 - Telefon\n");
            printf("    4 - Narozeniny\n");
            printf("    5 - Poznamka\n");
            scanf(" %99[^\n]s",a);
            while(stricmp(a, "1") != 0 && stricmp(a, "2") != 0 && stricmp(a, "3") != 0 && stricmp(a, "4") != 0 && stricmp(a, "5") != 0 && stricmp(a, "exit"))
            {
                printf("Cislo musi byt 1 - 6\n");
                scanf(" %99[^\n]s",a);
            }
            if(a[0] == '1')//name
            {
                int b = 0, c = 0, d = 0;
                printf("Puvodni jmeno je \"%s\"\n",evd[x].name);
                printf("Zadejte nove jmeno:\n");
                while(1)
                {
                    if(c == 1)
                    {
                        printf("Jmeno je obsazeno\n");
                    }
                    if(c == 0 && b == 100)
                    {
                        break;
                    }
                    c = 0;
                    b = 0;
                    if(d >= 1)
                    {
                        printf("Zadejte jine jmeno:\n");
                    }
                    scanf(" %99[^\n]s",arr);
                    if(stricmp(arr, "exit") == 0)
                    {
                        break;
                    }
                    while(b < 100)
                    {
                        if(stricmp(evd[b].name, arr) == 0)
                        {
                            if(stricmp(evd[b].name, evd[x].name) != 0)
                            {
                                c++;
                                break;
                            }
                        }
                        b++;
                    }
                    d++;
                }
                if(stricmp(arr, "exit") != 0)
                {
                    pfile = fopen("historie.txt", "a+");
                    fprintf(pfile, "%d.\nUpravene jmeno osoby\n%d    %s  |  %s  |  %s  |  %s  |  %s\nz puvodniho \"%s\" na \"%s\"\n-------------------------------------------------\n\n",round, x, arr, evd[x].surname, evd[x].PhoneNo, evd[x].birthday, evd[x].note, evd[x].name, arr);
                    fclose(pfile);
                    strcpy(evd[x].name, arr);
                    system("cls");
                    printf("Nove jmeno je \"%s\"\n\n",evd[x].name);
                    round ++;
                    main();
                }
                if(stricmp(arr, "exit") == 0)
                {
                    system("cls");
                    main();
                }
            }
            if(a[0] == '2')//surname
            {
                printf("Puvodni prijmeni je \"%s\"\n",evd[x].surname);
                printf("Zadejte nove prijmeni:\n");
                scanf(" %99[^\n]s",arr);
                if(stricmp(arr, "exit") != 0)
                {
                    pfile = fopen("historie.txt", "a+");
                    fprintf(pfile, "%d.\nUpravene prijmeni osoby\n%d    %s  |  %s  |  %s  |  %s  |  %s\nz puvodniho \"%s\" na \"%s\"\n-------------------------------------------------\n\n",round, x, evd[x].name, arr, evd[x].PhoneNo, evd[x].birthday, evd[x].note, evd[x].surname, arr);
                    fclose(pfile);
                    strcpy(evd[x].surname, arr);
                    system("cls");
                    printf("Nove prijmeni je \"%s\"\n\n",evd[x].surname);
                    round ++;
                    main();
                }
                if(stricmp(arr, "exit") == 0)
                {
                    system("cls");
                    main();
                }
            }
            if(a[0] == '3')//phone number
            {
                printf("Puvodni telefon je \"%s\"\n",evd[x].PhoneNo);
                printf("Zadejte novy telefon:\n");
                scanf(" %99[^\n]s",arr);
                if(stricmp(arr, "exit") != 0)
                {
                    pfile = fopen("historie.txt", "a+");
                    fprintf(pfile, "%d.\nUpraveny telefon osoby\n%d    %s  |  %s  |  %s  |  %s  |  %s\nz puvodniho \"%s\" na \"%s\"\n-------------------------------------------------\n\n",round, x, evd[x].name, evd[x].surname, arr, evd[x].birthday, evd[x].note, evd[x].PhoneNo, arr);
                    fclose(pfile);
                    strcpy(evd[x].PhoneNo, arr);
                    system("cls");
                    printf("Novy telefon je \"%s\"\n\n",evd[x].PhoneNo);
                    round ++;
                    main();
                }
                if(stricmp(arr, "exit") == 0)
                {
                    system("cls");
                    main();
                }
            }
            if(a[0] == '4')//birthday
            {
                printf("Puvodni narozeniny jsou \"%s\"\n",evd[x].birthday);
                printf("Zadejte nove narozeniny:\n");
                scanf(" %99[^\n]s",arr);
                if(stricmp(arr, "exit") != 0)
                {
                    pfile = fopen("historie.txt", "a+");
                    fprintf(pfile, "%d.\nUpravene narozeniny osoby\n%d    %s  |  %s  |  %s  |  %s  |  %s\nz puvodnich \"%s\" na \"%s\"\n-------------------------------------------------\n\n",round, x, evd[x].name, evd[x].surname, evd[x].PhoneNo, arr, evd[x].note, evd[x].birthday, arr);
                    fclose(pfile);
                    strcpy(evd[x].birthday, arr);
                    system("cls");
                    printf("Nove narozeniny jsou \"%s\"\n\n",evd[x].birthday);
                    round ++;
                    main();
                }
                if(stricmp(arr, "exit") == 0)
                {
                    system("cls");
                    main();
                }
            }
            if(a[0] == '5')//note
            {
                printf("Puvodni poznamka je \"%s\"\n",evd[x].note);
                printf("Zadejte novou poznamku:\n");
                scanf(" %99[^\n]s",arr);
                if(stricmp(arr, "exit") != 0)
                {
                    pfile = fopen("historie.txt", "a+");
                    fprintf(pfile, "%d.\nUpravena poznamka osoby\n%d    %s  |  %s  |  %s  |  %s  |  %s\nz puvodni \"%s\" na \"%s\"\n-------------------------------------------------\n\n",round, x, evd[x].name, evd[x].surname, evd[x].PhoneNo, evd[x].birthday, arr, evd[x].note, arr);
                    fclose(pfile);
                    strcpy(evd[x].note, arr);
                    system("cls");
                    printf("Nova poznamka je \"%s\"\n\n",evd[x].note);
                    round ++;
                    main();
                }
                if(stricmp(arr, "exit") == 0)
                {
                    system("cls");
                    main();
                }
            }
            if(stricmp(a, "exit") == 0)
            {
                system("cls");
                main();
            }
        }
        if(stricmp(y, "2") == 0)
        {
            char z[100];
            printf("  Opravdu si prejete tuto osobu smazat?\n");
            printf("    1 - Ano\n");
            printf("    2 - Ne\n");
            scanf(" %99[^\n]s",z);
            while(stricmp(z, "1") != 0 && stricmp(z, "2") != 0 && stricmp(z, "exit") != 0)
            {
                printf("Lze zadat cislo 1 - 2\n");
                scanf(" %99[^\n]s",z);
            }
            if(z[0] == '1')
            {
                pfile = fopen("historie.txt", "a+");
                fprintf(pfile, "%d.\nSmazana osoba\n%d    %s  |  %s  |  %s  |  %s  |  %s\n-------------------------------------------------\n\n",round, a, evd[a].name, evd[a].surname, evd[a].PhoneNo, evd[a].birthday, evd[a].note, evd[a].name, arr);
                fclose(pfile);
                system("cls");
                printf("Osoba \"%s\" smazana\n\n", evd[a].name);
                strcpy(evd[a].name,"\0");
                strcpy(evd[a].surname,"\0");
                strcpy(evd[a].PhoneNo,"\0");
                strcpy(evd[a].birthday,"\0");
                strcpy(evd[a].note,"\0");
                while(stricmp(evd[a+1].name, "\0") != 0)
                {
                    strcpy(evd[a].name,evd[a+1].name);
                    strcpy(evd[a].surname,evd[a+1].surname);
                    strcpy(evd[a].PhoneNo,evd[a+1].PhoneNo);
                    strcpy(evd[a].birthday,evd[a+1].birthday);
                    strcpy(evd[a].note,evd[a+1].note);
                    a++;
                }
                strcpy(evd[a].name,"\0");
                strcpy(evd[a].surname,"\0");
                strcpy(evd[a].PhoneNo,"\0");
                strcpy(evd[a].birthday,"\0");
                strcpy(evd[a].note,"\0");
                round ++;
                main();
            }
            if(z[0] == '2' || stricmp(z, "exit") == 0)
            {
                system("cls");
                main();
            }
        }
    }
}

void CloseProgram()
{
    char a[100];
    printf("Opravdu chcete ukoncit program bez ulozeni?\n");
    printf("  1 - Ano\n");
    printf("  2 - Ne\n");
    scanf(" %99[^\n]s",a);;
    while(stricmp(a, "1") != 0 && stricmp(a, "2") && stricmp(a, "exit") != 0)
    {
        printf("Zadejte cislo 1 nebo 2\n");
        scanf(" %99[^\n]s",a);
    }
    if(a[0] == '1')
    {
        return 0;
    }
    if(a[0] == '2')
    {
        Save();
    }
    if(stricmp(a, "exit") == 0)
    {
        system("cls");

        main();
    }
}

void DisplayHistory()
{
    int a = 0;
    char ch;
    pfile = fopen("historie.txt", "a+");
    while((ch = fgetc(pfile)) != EOF)
    {
        printf("%c", ch);
    }
    if (ftell(pfile) == 0)
    {
        printf("Historie je prazdna\n\n");
    }
    fclose(pfile);
    main();
}