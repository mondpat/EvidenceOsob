# EvidenceOsob 

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
