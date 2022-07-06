int round = 0;
FILE *pfile;

struct records
{
    char name[100];
    char surname[100];
    char PhoneNo[100];
    char birthday[100];
    char note[100];
} evd[100];

void LoadFromFile()
{
    int PersonNo = 0;
    pfile = fopen("records.txt", "r+");
    while (PersonNo < 100)
    {
        fscanf(pfile, " %99[^\n]s\n", evd[PersonNo].name);
        fscanf(pfile, " %99[^\n]s\n", evd[PersonNo].surname);
        fscanf(pfile, " %99[^\n]s\n", evd[PersonNo].PhoneNo);
        fscanf(pfile, " %99[^\n]s\n", evd[PersonNo].birthday);
        fscanf(pfile, " %99[^\n]s\n", evd[PersonNo].note);
        if (stricmp(evd[PersonNo].name, "\0") == 0)
        {
            break;
        }
        PersonNo++;
    }
    fclose(pfile);
}

void Display()
{
    if (IsTableEmpty() == 1)
    {
        printf("There are no records in the table\n\n");
    }
    else
    {
        printf("    Name    Surname    Phone No    Birthday    Note\n");
        int PersonNo = 0;
        while (stricmp(evd[PersonNo].name, "\0") != 0)
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
    while (stricmp(evd[a].name, "\0") != 0)
    {
        a++;
        if (a == 100)
        {
            printf("The table is full\n");
            main();
        }
    }
    char arr[100];
    printf("Enter a person's name\n");
    while (1)
    {
        if (c == 1)
        {
            printf("The name is already in use\n");
        }
        if (c == 0 && b == 100)
        {
            break;
        }
        c = 0;
        b = 0;
        if (d >= 1)
        {
            printf("Enter a different name:\n");
        }
        scanf(" %99[^\n]s", arr);
        if (stricmp(arr, "exit") == 0)
        {
            break;
        }
        while (b < 100)
        {
            if (stricmp(evd[b].name, arr) == 0)
            {
                c++;
                break;
            }
            b++;
        }
        d++;
    }
    if (stricmp(arr, "exit") != 0)
    {
        strcpy(evd[a].name, arr);
        printf("Enter a surname:\n");
        scanf(" %99[^\n]s", arr);
        if (stricmp(arr, "exit") != 0)
        {
            strcpy(evd[a].surname, arr);
            printf("Phone No:\n");
            scanf(" %99[^\n]s", arr);
            if (stricmp(arr, "exit") != 0)
            {
                strcpy(evd[a].PhoneNo, arr);
                printf("Birthday:\n");
                scanf(" %99[^\n]s", arr);
                if (stricmp(arr, "exit") != 0)
                {
                    strcpy(evd[a].birthday, arr);
                    if (stricmp(arr, "exit") != 0)
                    {
                        printf("Note:\n");
                        scanf(" %99[^\n]s", arr);
                        if (stricmp(arr, "exit") != 0)
                        {
                            strcpy(evd[a].note, arr);
                            system("cls");
                            printf("    Name    Surname    Phone No    Birthday    Note\n");
                            printf("%d    %s  |  %s  |  %s  |  %s  |  %s\n\n", a, evd[a].name, evd[a].surname, evd[a].PhoneNo, evd[a].birthday, evd[a].note);
                            pfile = fopen("history.txt", "a+");
                            fprintf(pfile, "%d.\nA person entered\n%d    %s  |  %s  |  %s  |  %s  |  %s\n-------------------------------------------------\n\n", round, a, evd[a].name, evd[a].surname, evd[a].PhoneNo, evd[a].birthday, evd[a].note);
                            fclose(pfile);
                            round++;
                            main();
                        }
                    }
                }
            }
        }
    }
    if (stricmp(arr, "exit") == 0)
    {

        strcpy(evd[a].name, "\0");
        strcpy(evd[a].surname, "\0");
        strcpy(evd[a].PhoneNo, "\0");
        strcpy(evd[a].birthday, "\0");
        strcpy(evd[a].note, "\0");
        system("cls");
        round--;
        main();
    }
}

void Save()
{
    int PersonNo = 0;
    pfile = fopen("temp.txt", "a+");
    while (stricmp(evd[PersonNo].name, "\0") != 0)
    {
        fprintf(pfile, "%s\n", evd[PersonNo].name);
        fprintf(pfile, "%s\n", evd[PersonNo].surname);
        fprintf(pfile, "%s\n", evd[PersonNo].PhoneNo);
        fprintf(pfile, "%s\n", evd[PersonNo].birthday);
        fprintf(pfile, "%s\n", evd[PersonNo].note);
        PersonNo++;
    }
    fclose(pfile);
    remove("records.txt");
    rename("temp.txt", "records.txt");
    printf("Saved\n");
    return 0;
}

int IsTableEmpty()
{
    int a = 0, b = 0;
    while (a < 100)
    {
        if (stricmp(evd[a].name, "\0") == 0)
        {
            b++;
        }
        a++;
    }
    if (b == 100)
    {
        return 1;
    }
    return 0;
}

void Search()
{
    int a = 0, b = 0, c = 0;
    char arr[100];
    if (IsTableEmpty() == 1)
    {
        printf("The table is empty, before you can search for a person, a one have to be created\n");
        InsertPerson();
    }
    Display();
    printf("Enter a person's name:\n");
    while (1)
    {
        scanf(" %99[^\n]s", arr);
        a = 0;
        while (stricmp(evd[a].name, arr) != 0)
        {
            if (a == 100)
            {
                if (stricmp(arr, "exit") == 0)
                {
                    break;
                }
                printf("The person could not be found\n");
                printf("Enter the person's name again:\n");
                break;
            }
            a++;
        }
        if (stricmp(evd[a].name, arr) == 0)
        {
            break;
        }
        if (stricmp(arr, "exit") == 0)
        {
            system("cls");

            main();
            break;
        }
    }
    if (stricmp(evd[a].name, arr) == 0)
    {
        int x;
        char y[100];
        printf("    Name    Surname    Phone No    Birthday    Note\n");
        printf("%d    %s  |  %s  |  %s  |  %s  |  %s\n", a, evd[a].name, evd[a].surname, evd[a].PhoneNo, evd[a].birthday, evd[a].note);
        printf("  Options:\n");
        printf("    1 - Edit\n");
        printf("    2 - Delete\n");
        x = a;
        scanf(" %99[^\n]s", y);
        while (stricmp(y, "1") != 0 && stricmp(y, "2") != 0 && stricmp(y, "exit") != 0)
        {
            printf("Ony a number 1 - 2 can be entered\n");
            scanf(" %99[^\n]s", y);
        }
        if (stricmp(y, "exit") == 0)
        {
            system("cls");
            main();
        }
        if (stricmp(y, "1") == 0)
        {
            int b = 0;
            char a[100], arr[100];
            printf("  Select the parameter you want to edit:\n");
            printf("    1 - Name\n");
            printf("    2 - Surname\n");
            printf("    3 - Phone No\n");
            printf("    4 - Birthday\n");
            printf("    5 - Note\n");
            scanf(" %99[^\n]s", a);
            while (stricmp(a, "1") != 0 && stricmp(a, "2") != 0 && stricmp(a, "3") != 0 && stricmp(a, "4") != 0 && stricmp(a, "5") != 0 && stricmp(a, "exit"))
            {
                printf("A number 1 - 6 can be entered\n");
                scanf(" %99[^\n]s", a);
            }
            if (a[0] == '1') // name
            {
                int b = 0, c = 0, d = 0;
                printf("The original name is \"%s\"\n", evd[x].name);
                printf("Enter a new name:\n");
                while (1)
                {
                    if (c == 1)
                    {
                        printf("The name is already in use\n");
                    }
                    if (c == 0 && b == 100)
                    {
                        break;
                    }
                    c = 0;
                    b = 0;
                    if (d >= 1)
                    {
                        printf("Enter a different name:\n");
                    }
                    scanf(" %99[^\n]s", arr);
                    if (stricmp(arr, "exit") == 0)
                    {
                        break;
                    }
                    while (b < 100)
                    {
                        if (stricmp(evd[b].name, arr) == 0)
                        {
                            if (stricmp(evd[b].name, evd[x].name) != 0)
                            {
                                c++;
                                break;
                            }
                        }
                        b++;
                    }
                    d++;
                }
                if (stricmp(arr, "exit") != 0)
                {
                    pfile = fopen("history.txt", "a+");
                    fprintf(pfile, "%d.\nEdited person's name\n%d    %s  |  %s  |  %s  |  %s  |  %s\nfrom original \"%s\" to \"%s\"\n-------------------------------------------------\n\n", round, x, arr, evd[x].surname, evd[x].PhoneNo, evd[x].birthday, evd[x].note, evd[x].name, arr);
                    fclose(pfile);
                    strcpy(evd[x].name, arr);
                    system("cls");
                    printf("The new name is \"%s\"\n\n", evd[x].name);
                    round++;
                    main();
                }
                if (stricmp(arr, "exit") == 0)
                {
                    system("cls");
                    main();
                }
            }
            if (a[0] == '2') // surname
            {
                printf("The original surname is \"%s\"\n", evd[x].surname);
                printf("Enter a new surname:\n");
                scanf(" %99[^\n]s", arr);
                if (stricmp(arr, "exit") != 0)
                {
                    pfile = fopen("history.txt", "a+");
                    fprintf(pfile, "%d.\nEdited person's surname\n%d    %s  |  %s  |  %s  |  %s  |  %s\nfrom original \"%s\" to \"%s\"\n-------------------------------------------------\n\n", round, x, evd[x].name, arr, evd[x].PhoneNo, evd[x].birthday, evd[x].note, evd[x].surname, arr);
                    fclose(pfile);
                    strcpy(evd[x].surname, arr);
                    system("cls");
                    printf("The new surname is \"%s\"\n\n", evd[x].surname);
                    round++;
                    main();
                }
                if (stricmp(arr, "exit") == 0)
                {
                    system("cls");
                    main();
                }
            }
            if (a[0] == '3') // phone number
            {
                printf("The original phone no is \"%s\"\n", evd[x].PhoneNo);
                printf("Enter a new phone no:\n");
                scanf(" %99[^\n]s", arr);
                if (stricmp(arr, "exit") != 0)
                {
                    pfile = fopen("history.txt", "a+");
                    fprintf(pfile, "%d.\nEdited person's phone no\n%d    %s  |  %s  |  %s  |  %s  |  %s\nfrom original \"%s\" to \"%s\"\n-------------------------------------------------\n\n", round, x, evd[x].name, evd[x].surname, arr, evd[x].birthday, evd[x].note, evd[x].PhoneNo, arr);
                    fclose(pfile);
                    strcpy(evd[x].PhoneNo, arr);
                    system("cls");
                    printf("The new phone no is \"%s\"\n\n", evd[x].PhoneNo);
                    round++;
                    main();
                }
                if (stricmp(arr, "exit") == 0)
                {
                    system("cls");
                    main();
                }
            }
            if (a[0] == '4') // birthday
            {
                printf("The original birthday is \"%s\"\n", evd[x].birthday);
                printf("Enter a new birthday:\n");
                scanf(" %99[^\n]s", arr);
                if (stricmp(arr, "exit") != 0)
                {
                    pfile = fopen("history.txt", "a+");
                    fprintf(pfile, "%d.\nEdited person's birthday\n%d    %s  |  %s  |  %s  |  %s  |  %s\nfrom original \"%s\" to \"%s\"\n-------------------------------------------------\n\n", round, x, evd[x].name, evd[x].surname, evd[x].PhoneNo, arr, evd[x].note, evd[x].birthday, arr);
                    fclose(pfile);
                    strcpy(evd[x].birthday, arr);
                    system("cls");
                    printf("The new birthday is \"%s\"\n\n", evd[x].birthday);
                    round++;
                    main();
                }
                if (stricmp(arr, "exit") == 0)
                {
                    system("cls");
                    main();
                }
            }
            if (a[0] == '5') // note
            {
                printf("The original note is \"%s\"\n", evd[x].note);
                printf("Enter a new note:\n");
                scanf(" %99[^\n]s", arr);
                if (stricmp(arr, "exit") != 0)
                {
                    pfile = fopen("history.txt", "a+");
                    fprintf(pfile, "%d.\nEdited person's note\n%d    %s  |  %s  |  %s  |  %s  |  %s\nfrom original \"%s\" to \"%s\"\n-------------------------------------------------\n\n", round, x, evd[x].name, evd[x].surname, evd[x].PhoneNo, evd[x].birthday, arr, evd[x].note, arr);
                    fclose(pfile);
                    strcpy(evd[x].note, arr);
                    system("cls");
                    printf("The new note is \"%s\"\n\n", evd[x].note);
                    round++;
                    main();
                }
                if (stricmp(arr, "exit") == 0)
                {
                    system("cls");
                    main();
                }
            }
            if (stricmp(a, "exit") == 0)
            {
                system("cls");
                main();
            }
        }
        if (stricmp(y, "2") == 0)
        {
            char z[100];
            printf("  Do you really want to delete the person?\n");
            printf("    1 - Yes\n");
            printf("    2 - No\n");
            scanf(" %99[^\n]s", z);
            while (stricmp(z, "1") != 0 && stricmp(z, "2") != 0 && stricmp(z, "exit") != 0)
            {
                printf("Only a number 1 - 2 can be entered\n");
                scanf(" %99[^\n]s", z);
            }
            if (z[0] == '1')
            {
                pfile = fopen("history.txt", "a+");
                fprintf(pfile, "%d.\nDeleted person\n%d    %s  |  %s  |  %s  |  %s  |  %s\n-------------------------------------------------\n\n", round, a, evd[a].name, evd[a].surname, evd[a].PhoneNo, evd[a].birthday, evd[a].note, evd[a].name, arr);
                fclose(pfile);
                system("cls");
                printf("Person \"%s\" deleted\n\n", evd[a].name);
                strcpy(evd[a].name, "\0");
                strcpy(evd[a].surname, "\0");
                strcpy(evd[a].PhoneNo, "\0");
                strcpy(evd[a].birthday, "\0");
                strcpy(evd[a].note, "\0");
                while (stricmp(evd[a + 1].name, "\0") != 0)
                {
                    strcpy(evd[a].name, evd[a + 1].name);
                    strcpy(evd[a].surname, evd[a + 1].surname);
                    strcpy(evd[a].PhoneNo, evd[a + 1].PhoneNo);
                    strcpy(evd[a].birthday, evd[a + 1].birthday);
                    strcpy(evd[a].note, evd[a + 1].note);
                    a++;
                }
                strcpy(evd[a].name, "\0");
                strcpy(evd[a].surname, "\0");
                strcpy(evd[a].PhoneNo, "\0");
                strcpy(evd[a].birthday, "\0");
                strcpy(evd[a].note, "\0");
                round++;
                main();
            }
            if (z[0] == '2' || stricmp(z, "exit") == 0)
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
    printf("Do you want to save before exit?\n");
    printf("  1 - Yes\n");
    printf("  2 - No\n");
    scanf(" %99[^\n]s", a);
    ;
    while (stricmp(a, "1") != 0 && stricmp(a, "2") && stricmp(a, "exit") != 0)
    {
        printf("Only a number 1 - 2 can be entered\n");
        scanf(" %99[^\n]s", a);
    }
    if (a[0] == '1')
    {
        Save();
    }
    if (a[0] == '2')
    {
        return 0;
    }
    if (stricmp(a, "exit") == 0)
    {
        system("cls");

        main();
    }
}

void DisplayHistory()
{
    int a = 0;
    char ch;
    pfile = fopen("history.txt", "a+");
    while ((ch = fgetc(pfile)) != EOF)
    {
        printf("%c", ch);
    }
    if (ftell(pfile) == 0)
    {
        printf("The history is empty\n\n");
    }
    fclose(pfile);
    main();
}