#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

void arrow_here(int current_optiune_selectata, int arrow_optiune_selectata)
{
    if(current_optiune_selectata == arrow_optiune_selectata)
        printf("  >>  ");
    else
        printf("      ");
}
int numar_poze;
char nume_poza[15][11];
double dimensiune_poza[15];
void CITIRE_POZE_DIMENSIUNE()
{   int i;
    FILE * fp = fopen("poze.txt", "r");
    fscanf(fp, "%d", &numar_poze);
    for(i = 0; i < numar_poze; i++)
    {
        fscanf(fp, "%s%lf", nume_poza[i], &dimensiune_poza[i]);
    }
    fclose(fp);
}
int numar_albume;
char nume_album[20][10];
int numar_poze_album[20];
char nume_poza_album[20][15][11];
double dimensiune_poza_[20][15];
void CITIRE_ALBUME_POZE()
{
    int i,j;
    FILE * fp2 = fopen("albume.txt", "r");
    fscanf(fp2, "%d", &numar_albume);
    for(i = 0; i < numar_albume; i++)
    {
        fscanf(fp2, "%s", nume_album[i]);
        fscanf(fp2, "%d", &numar_poze_album[i]);
        for(j = 0; j < numar_poze_album[i]; j++){
            fscanf(fp2, "%s", nume_poza_album[i][j]);
            fscanf(fp2, "%lf", &dimensiune_poza_[i][j]);
        }

    }
    fclose(fp2);
}
void SELECTARE_POZA_ALBUM(int j)
{
    system("cls");
    int optiune_selectata = 1, key_pressed = 0, k = 1;
    system("cls");
    printf("\n---------------------------------------------------------------------------------------------------------\n");
    printf("                                              POZE %s                                          \n", nume_album[j-1]);
    printf("---------------------------------------------------------------------------------------------------------\n\n");
    if(numar_poze_album[j-1] == 0)
    {
        printf("                              Albumul '%s' nu contine fotografii!!                                          ", nume_album[j-1]);
        printf("\n\n\n                    ***Apasati orice tasta pentru a revenii inapoi la 'Albume'***");
        getch();
        ALBUMELE_MELE();
    }
    while(key_pressed != 13)
    {
        system("cls");
        printf("\n---------------------------------------------------------------------------------------------------------\n");
        printf("                                              POZE %s                                          \n", nume_album[j-1]);
        printf("---------------------------------------------------------------------------------------------------------\n\n");
        printf("  ***Selectati poza dorita navigand in meniu cu ajutorul sagetilor (up/down) si apasand ENTER***\n\n");
        k = 1;
        for(int i = 0; i < numar_poze_album[j-1]; i++)
        {

            arrow_here(k++, optiune_selectata);
            printf("\t%s\n", nume_poza_album[j-1][i]);
        }

        key_pressed = getch();
        if (key_pressed == 80 && optiune_selectata <= numar_poze_album[j-1] - 1 )
        {
            optiune_selectata ++;
        }
        else if (key_pressed == 72 && optiune_selectata != 1)
        {
            optiune_selectata --;
        }
        else
        {
            optiune_selectata = optiune_selectata;
        }
        system("cls");
    }
        int z = optiune_selectata;
        key_pressed = 1;
        optiune_selectata = 1;

        while(key_pressed != 13)

    {
        system("cls");
        printf("\n-------------------------------------------------------------------------------------------------------\n\n");
        printf("\n     Sunteti sigur ca doriti sa stergeti '%s' din '%s'? ", nume_poza_album[j-1][z-1], nume_album[j-1]);
        printf("\n\n");
        arrow_here(1, optiune_selectata);
        printf(" Da\n");
        arrow_here(2, optiune_selectata);
        printf(" Anulati\n");
        printf("\n  ***Selectati optiunea dorita navigand in meniu cu ajutorul sagetilor (up/down) si apasand ENTER*** ");

        key_pressed = getch();

        if (key_pressed == 80 && optiune_selectata != 2)
        {
            optiune_selectata = 2;
        }
        else if (key_pressed == 72 && optiune_selectata != 1)
        {
            optiune_selectata = 1;
        }
        else
        {
            optiune_selectata = optiune_selectata;
        }
        system("cls");
    }
    if(optiune_selectata == 1)
    {  // STERGERE_POZA(/*nume album selectat, nume poza*/);
        printf("\n---------------------------------------------------------------------");
        printf("\n\n  Poza selectata a fost stearsa cu succes din albumul selectat!");
        printf("\n\n  ***Apasati orice tasta pentru a revenii inapoi la 'Albume'***");
        getch();
    }
        ALBUME();
}
void DIMENSIUNE_ALBUM(int j)
{
    double dimensiune_album = 0;
    printf("\n--------------------------------------------------------------------\n\n");
    for (int i = 0; i < numar_poze_album[j-1]; i++)
    {
        dimensiune_album += dimensiune_poza_[j-1][i];
    }
    printf("     Dimeniunea albumului '%s' este de: %.1lfMB\n",nume_album[j-1], dimensiune_album);
    printf("\n\n  ***Apasati orice tasta pentru a revenii inapoi la 'Albume'***");
    getch();
    ALBUME();
}
void VIZUALIZARE_POZE_SAU_DIMENSIUNE_ALBUM(int j)
{

    system("cls");
    int optiune_selectata = 1, key_pressed = 0;
    while(key_pressed != 13)
    {
        printf("\n-------------------------------------------------------------------------------------------------------\n\n");
        printf("   ***Selectati optiunea dorita navigand in meniu cu ajutorul sagetilor (up/down) si apasand ENTER*** \n\n");
        arrow_here(1, optiune_selectata);
        printf(" Stergere poza din '%s'\n", nume_album[j-1]);
        arrow_here(2, optiune_selectata);
        printf(" Vizualizare dimeniune '%s'\n", nume_album[j-1]);
        arrow_here(3, optiune_selectata);
        printf(" Inapoi la 'Afisare albume'\n");

        key_pressed = getch();

        if (key_pressed == 80 && optiune_selectata != 3)
        {
            optiune_selectata++;
        }
        else if (key_pressed == 72 && optiune_selectata != 1)
        {
            optiune_selectata--;
        }
        else
        {
            optiune_selectata = optiune_selectata;
        }
        system("cls");
    }
    if (optiune_selectata == 1)
    {
        SELECTARE_POZA_ALBUM(j);
    }

    else if (optiune_selectata == 2)
    {
        DIMENSIUNE_ALBUM(j);
    }
    else
    {
        ALBUMELE_MELE();
    }
}
void ALBUMELE_MELE()
{
    system("cls");
    int optiune_selectata = 1, key_pressed = 0, k = 1;
    while(key_pressed != 13)
    {
        system("cls");
        printf("\n---------------------------------------------------------------------------------------------------------\n");
        printf("                                               ALBUMELE MELE                                               \n");
        printf("---------------------------------------------------------------------------------------------------------\n\n");
        printf("  ***Selectati albumul dorit navigand in meniu cu ajutorul sagetilor (up/down) si apasand ENTER***\n\n");
        k = 1;
        for(int i = 0; i < numar_albume; i++)
        {
            arrow_here(k++, optiune_selectata);
            printf("\t%s\n", nume_album[i]);
        }

        key_pressed = getch();

        if (key_pressed == 80 && optiune_selectata <= numar_albume - 1)
        {
            optiune_selectata ++;
        }
        else if (key_pressed == 72 && optiune_selectata >= 2)
        {
            optiune_selectata --;
        }
        else
        {
            optiune_selectata = optiune_selectata;
        }

    }
    VIZUALIZARE_POZE_SAU_DIMENSIUNE_ALBUM(optiune_selectata);


}
void ALBUME()
{

    system("cls");
    int optiune_selectata = 1, key_pressed = 0;

    while(key_pressed != 13)
    {
        printf("\n-----------------------------------------------------------------------------------------------------\n");
        printf("                                                  ALBUME                                             \n");
        printf("-----------------------------------------------------------------------------------------------------\n\n");
        arrow_here(1, optiune_selectata);
        printf(" Afisare albume\n");
        arrow_here(2, optiune_selectata);
        printf(" Inapoi la 'MENIU PRINCIPAL'\n");
        printf("\n   ***Selectati optiunea dorita navigand in meniu cu ajutorul sagetilor (up/down) si apasand ENTER*** ");

        key_pressed = getch();

        if (key_pressed == 80 && optiune_selectata != 2)
        {
            optiune_selectata = 2;
        }
        else if (key_pressed == 72 && optiune_selectata != 1)
        {
            optiune_selectata = 1;
        }
        else
        {
            optiune_selectata = optiune_selectata;
        }
        system("cls");

    }

    if(optiune_selectata == 1)
    {
        if(numar_albume == 0)
        {
            printf("\n-----------------------------------------------------------------------------------------------------\n\n");
            printf("                                   NU EXISTA ALBUME IN GALERIE!                                            ");
            printf("\n\n               ***Apasati orice tasta pentru a revenii inapoi la 'MENIU PRINCIPAL'***");
            getch();
            MENIU_PRINCIPAL();


        }
        else
            ALBUMELE_MELE();
    }
    else if (optiune_selectata == 2)
    {
        MENIU_PRINCIPAL();
    }


}
void ALBUM_NOU(int x)
{
    char nume_album_nou[10],ch;
    int optiune_selectata = 1;
    system("cls");
    printf("\n-------------------------------------------------------------------------------------------------------\n");
    printf("\n     Introduceti un nume pentru noul album: ");
    int i = 0, key_pressed = 0;
    while(1)
    {
        ch = getch();
        if(ch == 13)
        {
            nume_album_nou[i] = '\0';
            break;
        }
        else if(ch == 8)
        {
            if(i > 0)
            {
                i--;
                printf("\b \b");
            }

        }
        else
        {
            nume_album_nou[i++] = ch;
            printf("%c", ch);
        }
    }

    while(key_pressed != 13)

    {
        system("cls");
        printf("\n-------------------------------------------------------------------------------------------------------\n");
        printf("\n     Introduceti un nume pentru noul album: ");
        for (int j = 0; j <= i; j++)
            printf("%c", nume_album_nou[j]);
        printf("\n\n");
        arrow_here(1, optiune_selectata);
        printf(" Salvati\n");
        arrow_here(2, optiune_selectata);
        printf(" Anulati\n");
        printf("\n  ***Selectati optiunea dorita navigand in meniu cu ajutorul sagetilor (up/down) si apasand ENTER*** ");

        key_pressed = getch();

        if (key_pressed == 80 && optiune_selectata != 2)
        {
            optiune_selectata = 2;
        }
        else if (key_pressed == 72 && optiune_selectata != 1)
        {
            optiune_selectata = 1;
        }
        else
        {
            optiune_selectata = optiune_selectata;
        }
        system("cls");
    }
    if(optiune_selectata == 1)
    {   //ADAUGARE_POZA_ALBUM_NOU(/*nume poza selectata, nume album nou*/)
        printf("\n---------------------------------------------------------------------");
        printf("\n\n     Poza selectata a fost adaugata cu succes in noul album!");
        printf("\n\n  ***Apasati orice tasta pentru a revenii inapoi la 'Biblioteca'***");
        getch();
    }
        BIBLIOTECA();
}
void ALBUM_EXISTENT(int j)
{
    int optiune_selectata = 1, key_pressed = 0, k = 1;
    while(key_pressed != 13)
    {
        system("cls");
        printf("\n-------------------------------------------------------------------------------------------------------\n");
        printf("                                              ALBUMELE MELE                                             \n");
        printf("-------------------------------------------------------------------------------------------------------\n\n");
        printf("  ***Selectati albumul dorit navigand in meniu cu ajutorul sagetilor (up/down) si apasand ENTER***\n\n");
        k = 1;
        for(int i = 0; i < numar_albume; i++)
        {

            arrow_here(k++, optiune_selectata);
            printf("\t%s\n", nume_album[i]);
        }

        key_pressed = getch();

        if (key_pressed == 80 && optiune_selectata <= numar_albume - 1)
        {
            optiune_selectata ++;
        }
        else if (key_pressed == 72 && optiune_selectata >= 2)
        {
            optiune_selectata --;
        }
        else
        {
            optiune_selectata = optiune_selectata;
        }

    }

    // STERGERE_POZA(/*nume poza selectata, nume album*/)
    BIBLIOTECA();



}
void ADAUGARE_POZA_ALBUM(int j)
{
    int optiune_selectata = 1, key_pressed = 0;

    while(key_pressed != 13)
    {
        printf("\n-------------------------------------------------------------------------------------------------------\n\n");
        printf("    Adaugati '%s' intr-un album:\n\n", nume_poza[j-1]);
        arrow_here(1, optiune_selectata);
        printf(" Existent\n");
        arrow_here(2, optiune_selectata);
        printf(" Nou\n");
        printf("\n  ***Selectati optiunea dorita navigand in meniu cu ajutorul sagetilor (up/down) si apasand ENTER*** ");

        key_pressed = getch();

        if (key_pressed == 80 && optiune_selectata != 2)
        {
            optiune_selectata = 2;
        }
        else if (key_pressed == 72 && optiune_selectata != 1)
        {
            optiune_selectata = 1;
        }
        else
        {
            optiune_selectata = optiune_selectata;
        }
        system("cls");
    }
    if (optiune_selectata == 1)
    {
        if(numar_albume == 0)
        {
            printf("\n-----------------------------------------------------------------------------------------------------\n\n");
            printf("                                   NU EXISTA ALBUME IN GALERIE!                                            ");
            printf("\n\n               ***Apasati orice tasta pentru a revenii inapoi la 'BIBLIOTECA'***");
            getch();
            BIBLIOTECA();


        }
        else
            ALBUM_EXISTENT(j);
    }

    else if (optiune_selectata == 2)
    {
        ALBUM_NOU(j);
    }
}
void ADAUGARE_POZA_ALBUM_SAU_INAPOI(int j)
{
    system("cls");
    int optiune_selectata = 1, key_pressed = 0;
    while(key_pressed != 13)
    {
        printf("\n-------------------------------------------------------------------------------------------------------\n\n");
        printf("   ***Selectati optiunea dorita navigand in meniu cu ajutorul sagetilor (up/down) si apasand ENTER*** \n\n");
        arrow_here(1, optiune_selectata);
        printf(" Adaugati '%s' la album\n", nume_poza[j-1]);
        arrow_here(2, optiune_selectata);
        printf(" Inapoi la 'Biblioteca'\n");

        key_pressed = getch();

        if (key_pressed == 80 && optiune_selectata != 2)
        {
            optiune_selectata = 2;
        }
        else if (key_pressed == 72 && optiune_selectata != 1)
        {
            optiune_selectata = 1;
        }
        else
        {
            optiune_selectata = optiune_selectata;
        }
        system("cls");
    }
    if (optiune_selectata == 1)
    {
        ADAUGARE_POZA_ALBUM(j);
    }

    else if (optiune_selectata == 2)
    {
        BIBLIOTECA();
    }
}
void TOATE_POZELE()
{
    system("cls");
    int optiune_selectata = 1, key_pressed = 0, k = 1;
    while(key_pressed != 13)
    {
        system("cls");
        printf("\n---------------------------------------------------------------------------------------------------------\n");
        printf("                                               TOATE POZELE                                              \n");
        printf("---------------------------------------------------------------------------------------------------------\n\n");
        printf("  ***Selectati fotografia dorita navigand in meniu cu ajutorul sagetilor (up/down) si apasand ENTER***\n\n");
        k = 1;
        for(int i = 0; i < numar_poze; i++)
        {
            arrow_here(k++, optiune_selectata);
            printf("\t%s\t%.2lfMB\n", nume_poza[i], dimensiune_poza[i]);
        }

        key_pressed = getch();

        if (key_pressed == 80 && optiune_selectata <= numar_poze - 1)
        {
            optiune_selectata ++;
        }
        else if (key_pressed == 72 && optiune_selectata >= 2)
        {
            optiune_selectata --;
        }
        else
        {
            optiune_selectata = optiune_selectata;
        }

    }
   ADAUGARE_POZA_ALBUM_SAU_INAPOI(optiune_selectata);

}
void BIBLIOTECA()
{

    system("cls");
    int optiune_selectata = 1, key_pressed = 0;

    while(key_pressed != 13)
    {
        printf("\n-----------------------------------------------------------------------------------------------------\n");
        printf("                                             BIBLIOTECA                                            \n");
        printf("-----------------------------------------------------------------------------------------------------\n\n");
        arrow_here(1, optiune_selectata);
        printf(" Afisare fotografii\n");
        arrow_here(2, optiune_selectata);
        printf(" Inapoi la 'MENIU PRINCIPAL'\n");
        printf("\n   ***Selectati optiunea dorita navigand in meniu cu ajutorul sagetilor (up/down) si apasand ENTER*** ");

        key_pressed = getch();

        if (key_pressed == 80 && optiune_selectata != 2)
        {
            optiune_selectata = 2;
        }
        else if (key_pressed == 72 && optiune_selectata != 1)
        {
            optiune_selectata = 1;
        }
        else
        {
            optiune_selectata = optiune_selectata;
        }
        system("cls");

    }

    if(optiune_selectata == 1)
    {
        TOATE_POZELE();
    }
    else if (optiune_selectata == 2)
    {
        MENIU_PRINCIPAL();
    }


}
void MENIU_PRINCIPAL()
{
    system("cls");
    int optiune_selectata = 1, key_pressed = 0;

    while (key_pressed != 13)
    {
        system("cls");
        printf("\n------------------------------------------------------------------------------------------------------\n");
        printf("                                            MENIU PRINCIPAL                                          \n");
        printf("------------------------------------------------------------------------------------------------------\n\n");
        arrow_here(1, optiune_selectata);
        printf(" Biblioteca\n");
        arrow_here(2, optiune_selectata);
        printf(" Albume\n");
        printf("\n  ***Selectati optiunea dorita navigand in meniu cu ajutorul sagetilor (up/down) si apasand ENTER***");

        key_pressed = getch();

        if (key_pressed == 27)
        {
            return;
        }
        else if (key_pressed == 80 && optiune_selectata != 2)
        {
            optiune_selectata = 2;
        }
        else if (key_pressed == 72 && optiune_selectata != 1)
        {
            optiune_selectata = 1;
        }
        else
        {
            optiune_selectata = optiune_selectata;
        }


    }
    if ( optiune_selectata == 1)
        {
            BIBLIOTECA();
        }
    else if (optiune_selectata == 2)
        {
            ALBUME();
        }
}
int main()
{
    CITIRE_POZE_DIMENSIUNE();
    CITIRE_ALBUME_POZE();
    MENIU_PRINCIPAL();
    return 0;
}
