# Personal-Records
## EN (CZ bellow):
This is a console program for saving personal attributes (name, surname, phone number, birthday, note) into a text file. After starting the program, the content of the text file is loaded to a struct object. In case of no existing file, one will be created. Before closing the program, the changes have to be saved to be reflected in the file. But it is possible to close the program without saving. Each person in the record must have a unique name, because it is used for searching (it is the primary key).

There are 6 options for a user:
- Create a new person
- Display all records
- Search for a person (for edit/delete)
- History of changes
- Save and exit
- Exit

The attributes are printed to the file on separate lines. Therefore, is it possible for each attribute to contain whitespaces. When a person is created, edited or deleted, the change is printed to the History text file and is never deleted by the program itself. History can be viewed by selecting the "History of changes" option in the menu.

## CZ:
Evidence osob je program v terminálu, který umožňuje ukládat do textového souboru parametry osob (jméno, příjmení, telefon, narozeniny, poznámka). Program funguje tak, že se při spuštění do objektu struct nahraje evidence ze souboru, pokud soubor neexistuje, založí se. Před ukončením programu se data musí z objektu struct nahrát zpět do souboru, aby se změny uložily. Každá osoba musí mít unikátní jméno, protože se používá při vyhledávání. 

Program obsahuje 6 možností: 
- Zapsat novou osobu 
- Zobrazit evidenci 
- Vyhledat osobu (pro upravení/smazání) 
- Historie operací 
- Uložit a ukončit 
- Ukončit 
  
Parametry osob se při zapisování do textového souboru ukládají do každého řádku zvlášť, aby se každý parametr mohl obsahovat mezery (nejvíce důležité pro parametr "Poznámka"). Při každém vložení osoby, její úpravě/smazání se akce zapíše do druhého textového souboru Historie. Zobrazit ho lze možností "Historie operací". Do Historie se zapisuje: vytvořená osoba, upravený parametr osoby, smazání osoby. 

Před ukončením (možnost "Ukončit") se program uživatele zeptá, zda nechce před zavřením programu evidenci uložit. Po zvolení možnosti "Uložit a ukončit" se evidence uloží do souboru a program se ukončí.
