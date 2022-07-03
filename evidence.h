int kolo = 0;
FILE *psoubor;

struct evidence
{
    char jmeno[100];
    char prijmeni[100];
    char telefon [100];
    char narozeniny [100];
    char poznamka [100];
} evd[100];

void nacist()
{
    int a = 0;
    psoubor = fopen("evidence.txt", "r+");
    while (a < 100)
    {
        fscanf(psoubor," %99[^\n]s\n", evd[a].jmeno);
        fscanf(psoubor," %99[^\n]s\n", evd[a].prijmeni);
        fscanf(psoubor," %99[^\n]s\n", evd[a].telefon);
        fscanf(psoubor," %99[^\n]s\n", evd[a].narozeniny);
        fscanf(psoubor," %99[^\n]s\n", evd[a].poznamka);
        if(stricmp(evd[a].jmeno, "\0") == 0)
        {
            break;
        }
        a ++;
    }
    fclose(psoubor);
}

void zobrazit()
{
    if(prazdno() == 1)
    {
        printf("Evidence je prazdna\n\n");
    }
    else
    {
        printf("    Jmeno    Prijmeni    Telefon    Narozeniny    Poznamka\n");
        int a = 0;
        while(stricmp(evd[a].jmeno,"\0")!=0)
        {
            printf("%d    %s  |  %s  |  %s  |  %s  |  %s\n", a, evd[a].jmeno, evd[a].prijmeni, evd[a].telefon, evd[a].narozeniny, evd[a].poznamka);
            a++;
        }
        printf("\n");
    }
}

void zapsat()
{
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    while(stricmp(evd[a].jmeno, "\0") != 0)
    {
        a ++;
        if(a == 100)
        {
            printf("Evidence je plna\n");
            main();
        }
    }
    char pole[100];
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
        scanf(" %99[^\n]s", pole);
        if(stricmp(pole, "exit") == 0)
        {
            break;
        }
        while(b<100)
        {
            if(stricmp(evd[b].jmeno, pole) == 0)
            {
                c ++;
                break;
            }
            b ++;
        }
        d ++;
    }
    if(stricmp(pole, "exit") != 0)
    {
        strcpy(evd[a].jmeno, pole);
        printf("Zadejte prijmeni:\n");
        scanf(" %99[^\n]s", pole);
        if(stricmp(pole, "exit") != 0)
        {
            strcpy(evd[a].prijmeni, pole);
            printf("Telefon:\n");
            scanf(" %99[^\n]s",pole);
            if(stricmp(pole, "exit") != 0)
            {
                strcpy(evd[a].telefon, pole);
                printf("Narozeniny:\n");
                scanf(" %99[^\n]s",pole);
                if(stricmp(pole, "exit") != 0)
                {

                    strcpy(evd[a].narozeniny, pole);
                    if(stricmp(pole, "exit") != 0)
                    {
                        printf("Poznamka:\n");
                        scanf(" %99[^\n]s",pole);
                        if(stricmp(pole, "exit") != 0)
                        {
                            strcpy(evd[a].poznamka, pole);
                            system("cls");
                            printf("    Jmeno    Prijmeni    Telefon    Narozeniny    Poznamka\n");
                            printf("%d    %s  |  %s  |  %s  |  %s  |  %s\n\n", a, evd[a].jmeno, evd[a].prijmeni, evd[a].telefon, evd[a].narozeniny, evd[a].poznamka);
                            psoubor = fopen("historie.txt", "a+");
                            fprintf(psoubor,"%d.\nZapsana osoba\n%d    %s  |  %s  |  %s  |  %s  |  %s\n-------------------------------------------------\n\n",kolo, a, evd[a].jmeno, evd[a].prijmeni, evd[a].telefon, evd[a].narozeniny, evd[a].poznamka);
                            fclose(psoubor);
                            kolo ++;
                            main();
                        }
                    }
                }
            }
        }
    }
    if(stricmp(pole, "exit") == 0)
    {

        strcpy(evd[a].jmeno, "\0");
        strcpy(evd[a].prijmeni, "\0");
        strcpy(evd[a].telefon, "\0");
        strcpy(evd[a].narozeniny, "\0");
        strcpy(evd[a].poznamka, "\0");
        system("cls");
        kolo --;
        main();
    }
}

void ulozit()
{
    int a = 0;
    psoubor = fopen("novy.txt","a+");
    while(stricmp(evd[a].jmeno, "\0") != 0)
    {
        fprintf(psoubor,"%s\n", evd[a].jmeno);
        fprintf(psoubor,"%s\n", evd[a].prijmeni);
        fprintf(psoubor,"%s\n", evd[a].telefon);
        fprintf(psoubor,"%s\n", evd[a].narozeniny);
        fprintf(psoubor,"%s\n", evd[a].poznamka);
        a++;
    }
    fclose(psoubor);
    remove("evidence.txt");
    rename("novy.txt","evidence.txt");
    printf("Ulozeno\n");
    return 0;
}

int prazdno()
{
    int a = 0, b = 0;
    while(a < 100)
    {
        if(stricmp(evd[a].jmeno, "\0") == 0)
        {
            b ++;
        }
        a ++;
    }
    if(b == 100)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void hledat()
{
    int a = 0, b = 0, c = 0;
    char pole[100];
    if(prazdno() == 1)
    {
        printf("Evidence je prazdna, abyste mohli osobu vyhledat, je nutne nejakou osobu zapsat\n");
        zapsat();
    }
    zobrazit();
    printf("Zadejte jmeno osoby:\n");
    while(1)
    {
        scanf(" %99[^\n]s", pole);
        a = 0;
        while(stricmp(evd[a].jmeno, pole) != 0)
        {
            if(a == 100)
            {
                if(stricmp(pole, "exit") == 0)
                {
                    break;
                }
                printf("Osobu se nepodarilo najit\n");
                printf("Zadejte osobu znovu:\n");
                break;
            }
            a ++;
        }
        if(stricmp(evd[a].jmeno, pole) == 0)
        {
            break;
        }
        if(stricmp(pole, "exit") == 0)
        {
            system("cls");

            main();
            break;
        }
    }
    if(stricmp(evd[a].jmeno,pole) == 0)
    {
        int x;
        char y[100];
        printf("    Jmeno    Prijmeni    Telefon    Narozeniny    Poznamka\n");
        printf("%d    %s  |  %s  |  %s  |  %s  |  %s\n", a, evd[a].jmeno, evd[a].prijmeni, evd[a].telefon, evd[a].narozeniny, evd[a].poznamka);
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
            char a[100], pole[100];
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
            if(a[0] == '1')//jmeno
            {
                int b = 0, c = 0, d = 0;
                printf("Puvodni jmeno je \"%s\"\n",evd[x].jmeno);
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
                    scanf(" %99[^\n]s",pole);
                    if(stricmp(pole, "exit") == 0)
                    {
                        break;
                    }
                    while(b < 100)
                    {
                        if(stricmp(evd[b].jmeno, pole) == 0)
                        {
                            if(stricmp(evd[b].jmeno, evd[x].jmeno) != 0)
                            {
                                c++;
                                break;
                            }
                        }
                        b++;
                    }
                    d++;
                }
                if(stricmp(pole, "exit") != 0)
                {
                    psoubor = fopen("historie.txt", "a+");
                    fprintf(psoubor, "%d.\nUpravene jmeno osoby\n%d    %s  |  %s  |  %s  |  %s  |  %s\nz puvodniho \"%s\" na \"%s\"\n-------------------------------------------------\n\n",kolo, x, pole, evd[x].prijmeni, evd[x].telefon, evd[x].narozeniny, evd[x].poznamka, evd[x].jmeno, pole);
                    fclose(psoubor);
                    strcpy(evd[x].jmeno, pole);
                    system("cls");
                    printf("Nove jmeno je \"%s\"\n\n",evd[x].jmeno);
                    kolo ++;
                    main();
                }
                if(stricmp(pole, "exit") == 0)
                {
                    system("cls");
                    main();
                }
            }
            if(a[0] == '2')//prijmeni
            {
                printf("Puvodni prijmeni je \"%s\"\n",evd[x].prijmeni);
                printf("Zadejte nove prijmeni:\n");
                scanf(" %99[^\n]s",pole);
                if(stricmp(pole, "exit") != 0)
                {
                    psoubor = fopen("historie.txt", "a+");
                    fprintf(psoubor, "%d.\nUpravene prijmeni osoby\n%d    %s  |  %s  |  %s  |  %s  |  %s\nz puvodniho \"%s\" na \"%s\"\n-------------------------------------------------\n\n",kolo, x, evd[x].jmeno, pole, evd[x].telefon, evd[x].narozeniny, evd[x].poznamka, evd[x].prijmeni, pole);
                    fclose(psoubor);
                    strcpy(evd[x].prijmeni, pole);
                    system("cls");
                    printf("Nove prijmeni je \"%s\"\n\n",evd[x].prijmeni);
                    kolo ++;
                    main();
                }
                if(stricmp(pole, "exit") == 0)
                {
                    system("cls");
                    main();
                }
            }
            if(a[0] == '3')//telefon
            {
                printf("Puvodni telefon je \"%s\"\n",evd[x].telefon);
                printf("Zadejte novy telefon:\n");
                scanf(" %99[^\n]s",pole);
                if(stricmp(pole, "exit") != 0)
                {
                    psoubor = fopen("historie.txt", "a+");
                    fprintf(psoubor, "%d.\nUpraveny telefon osoby\n%d    %s  |  %s  |  %s  |  %s  |  %s\nz puvodniho \"%s\" na \"%s\"\n-------------------------------------------------\n\n",kolo, x, evd[x].jmeno, evd[x].prijmeni, pole, evd[x].narozeniny, evd[x].poznamka, evd[x].telefon, pole);
                    fclose(psoubor);
                    strcpy(evd[x].telefon, pole);
                    system("cls");
                    printf("Novy telefon je \"%s\"\n\n",evd[x].telefon);
                    kolo ++;
                    main();
                }
                if(stricmp(pole, "exit") == 0)
                {
                    system("cls");
                    main();
                }
            }
            if(a[0] == '4')//narozeniny
            {
                printf("Puvodni narozeniny jsou \"%s\"\n",evd[x].narozeniny);
                printf("Zadejte nove narozeniny:\n");
                scanf(" %99[^\n]s",pole);
                if(stricmp(pole, "exit") != 0)
                {
                    psoubor = fopen("historie.txt", "a+");
                    fprintf(psoubor, "%d.\nUpravene narozeniny osoby\n%d    %s  |  %s  |  %s  |  %s  |  %s\nz puvodnich \"%s\" na \"%s\"\n-------------------------------------------------\n\n",kolo, x, evd[x].jmeno, evd[x].prijmeni, evd[x].telefon, pole, evd[x].poznamka, evd[x].narozeniny, pole);
                    fclose(psoubor);
                    strcpy(evd[x].narozeniny, pole);
                    system("cls");
                    printf("Nove narozeniny jsou \"%s\"\n\n",evd[x].narozeniny);
                    kolo ++;
                    main();
                }
                if(stricmp(pole, "exit") == 0)
                {
                    system("cls");
                    main();
                }
            }
            if(a[0] == '5')//poznamka
            {
                printf("Puvodni poznamka je \"%s\"\n",evd[x].poznamka);
                printf("Zadejte novou poznamku:\n");
                scanf(" %99[^\n]s",pole);
                if(stricmp(pole, "exit") != 0)
                {
                    psoubor = fopen("historie.txt", "a+");
                    fprintf(psoubor, "%d.\nUpravena poznamka osoby\n%d    %s  |  %s  |  %s  |  %s  |  %s\nz puvodni \"%s\" na \"%s\"\n-------------------------------------------------\n\n",kolo, x, evd[x].jmeno, evd[x].prijmeni, evd[x].telefon, evd[x].narozeniny, pole, evd[x].poznamka, pole);
                    fclose(psoubor);
                    strcpy(evd[x].poznamka, pole);
                    system("cls");
                    printf("Nova poznamka je \"%s\"\n\n",evd[x].poznamka);
                    kolo ++;
                    main();
                }
                if(stricmp(pole, "exit") == 0)
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
                psoubor = fopen("historie.txt", "a+");
                fprintf(psoubor, "%d.\nSmazana osoba\n%d    %s  |  %s  |  %s  |  %s  |  %s\n-------------------------------------------------\n\n",kolo, a, evd[a].jmeno, evd[a].prijmeni, evd[a].telefon, evd[a].narozeniny, evd[a].poznamka, evd[a].jmeno, pole);
                fclose(psoubor);
                system("cls");
                printf("Osoba \"%s\" smazana\n\n", evd[a].jmeno);
                strcpy(evd[a].jmeno,"\0");
                strcpy(evd[a].prijmeni,"\0");
                strcpy(evd[a].telefon,"\0");
                strcpy(evd[a].narozeniny,"\0");
                strcpy(evd[a].poznamka,"\0");
                while(stricmp(evd[a+1].jmeno, "\0") != 0)
                {
                    strcpy(evd[a].jmeno,evd[a+1].jmeno);
                    strcpy(evd[a].prijmeni,evd[a+1].prijmeni);
                    strcpy(evd[a].telefon,evd[a+1].telefon);
                    strcpy(evd[a].narozeniny,evd[a+1].narozeniny);
                    strcpy(evd[a].poznamka,evd[a+1].poznamka);
                    a++;
                }
                strcpy(evd[a].jmeno,"\0");
                strcpy(evd[a].prijmeni,"\0");
                strcpy(evd[a].telefon,"\0");
                strcpy(evd[a].narozeniny,"\0");
                strcpy(evd[a].poznamka,"\0");
                kolo ++;
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

void konec()
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
        ulozit();
    }
    if(stricmp(a, "exit") == 0)
    {
        system("cls");

        main();
    }
}

void historie()
{
    int a = 0;
    char ch;
    psoubor = fopen("historie.txt", "a+");
    while((ch = fgetc(psoubor)) != EOF)
    {
        printf("%c", ch);
    }
    if (ftell(psoubor) == 0)
    {
        printf("Historie je prazdna\n\n");
    }
    fclose(psoubor);
    main();
}