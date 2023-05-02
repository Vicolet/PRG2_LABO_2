//BScode

#include <stdio.h>
#include "listes_dynamiques.h"

int main(void) {
    size_t position = 0;
    int tailleListe = 0;
    Info x = 0;

    printf("### INITIALISATION ###\n");
    Liste *lptr1 = initialiser();
    printf("%-20s %-20s %-20s \n", "Variable", "Adresse", "Adresse pointeur");
    printf("%-20s %-20p %-20p \n", "lptr", (void *) &lptr1, (void *) lptr1);
    printf("%-20s %-20p %-20p \n", "lptr->tete", (void *) &(lptr1->tete),
           lptr1->tete);
    printf("%-20s %-20p %-20p \n", "lptr->queue", (void *) &(lptr1->queue),
           lptr1->queue);

    printf("INITIALISATION : test des fonctions estVide() et longueur().\n");
    printf("%-20s : %d \n", "Liste est vide", estVide(lptr1));
    printf("%-20s : %lld \n", "Taille de la liste", longueur(lptr1));

    printf("INITIALISATION : Affichage d'une liste vide. (FORWARD et BACKWARD)\n");
    afficher(lptr1, FORWARD);
    afficher(lptr1, BACKWARD);
    printf("\n");

    return 0;
}