#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define NB_LIGNE 10
#define NB_COLONE 30


void dessinerGrille_debut_partie(char grille[][30])
{
    for (int i = 0; i < NB_LIGNE; i++)
    {
        for (int j = 0; j < NB_COLONE; j++)
        {
            grille[i][j] = '.';
            printf("|%c", grille[i][j]);
        }
        printf("\n");
    }
}


void dessinerGrille_en_partie(char grille[][30])
{
    for (int i = 0; i < NB_LIGNE; i++)
    {
        for (int j = 0; j < NB_COLONE; j++)
        {
            printf("|%c", grille[i][j]);
        }
        printf("\n");
    }
}


int saisieUtilisateur(char grille[][30], int coord_x, int coord_y, char joueur, char joueur2, int nombre)
{
    while (nombre > 0)
    {
        nombre--;

        printf("Saisissez la ligne ou vous voulez le mettre :\n");
        fflush(stdin);
        scanf("%d", &coord_x);

        int* p_coord_x = (int*)malloc(coord_x * sizeof(int));

        printf("Saisissez la colonne ou vous voulez le mettre :\n");
        fflush(stdin);
        scanf("%d", &coord_y);

        int* p_coord_y = (int*)malloc(coord_y * sizeof(int));

        if (grille[coord_x][coord_y] == '.')
        {
            grille[coord_x][coord_y] = joueur;
        }
        if (grille[*p_coord_x+1][*p_coord_y] == 'X' && grille[*p_coord_x-1][*p_coord_y] == 'X' && grille[*p_coord_x][*p_coord_y] == 'X')
        {
            grille[*p_coord_x][*p_coord_y+1] = joueur2;
            grille[*p_coord_x][*p_coord_y-1] = joueur2;
        }
        
    }
    dessinerGrille_en_partie(grille);
}


int main()
{
    char grille[10][30] = {
        {"."}
    };
    char joueur = 'X', joueur2 = 'i';
    int coord_x, coord_y, nombre = 0;

    printf("entrez le nombre de case que vous voulez mettre : \n");
    scanf("%d", &nombre);


    dessinerGrille_debut_partie(grille);


    saisieUtilisateur(grille, coord_x, coord_y, joueur, joueur2, nombre);


    return 0;
}