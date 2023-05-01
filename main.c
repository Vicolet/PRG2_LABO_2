/*
 -----------------------------------------------------------------------------------
 Nom du fichier : main.h
 Auteur(s)      : Romain Fleury
 Date creation  : 26.04.2023

 Description    : Librairie permettant la gestion de listes doublement chaînées
                  non circulaires

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 12.2.0
 -----------------------------------------------------------------------------------
*/
#include <stdio.h>
#include "listes_dynamiques.h"

bool critere(size_t pos, const Info *n) {
    //return true;
    if (pos % 2 == 0 || *n > 1 && *n < 6) {
        return true;
    }
    return false;
}

int main() {
    printf("INITIALISATION de la liste.\n");
    Liste *lptr1 = initialiser();
    printf("%-20s %-20s %-20s \n", "Variable", "Adresse", "Adresse pointeur");
    printf("%-20s %-20p %-20p \n", "lptr", (void *) &lptr1, (void *) lptr1);
    printf("%-20s %-20p %-20p \n", "lptr->tete", (void *) &(lptr1->tete), lptr1->tete);
    printf("%-20s %-20p %-20p \n", "lptr->queue", (void *) &(lptr1->queue), lptr1->queue);

    printf("INITIALISATION : test des fonctions estVide() et longueur().\n");
    printf("%-20s : %d \n", "Liste est vide", estVide(lptr1));
    printf("%-20s : %lld \n", "Taille de la liste", longueur(lptr1));

    printf("INITIALISATION : Affichage d'une liste vide. (FORWARD et BACKWARD)\n");
    afficher(lptr1, FORWARD);
    afficher(lptr1, BACKWARD);
    printf("\n");


    printf("SUPPRIMER et INSERER en tete.\n");
    printf("SUPPRIMER EN TETE : utiliser supprimerEnTete() sur une liste vide.\n");
    Info x = 0;
    printf("Status : %u\n", supprimerEnTete(lptr1, &x));
    afficher(lptr1, FORWARD);
    printf("INSERER EN TETE : utiliser insererEnTete() sur une liste pour inserer les chiffres de 0 a 5.\n");
    x = 0;
    printf("Status : %u\n", insererEnTete(lptr1, &x));
    for (Info i = 1; i <= 5; ++i)
        insererEnTete(lptr1, &i);
    afficher(lptr1, FORWARD);
    printf("SUPPRIMER EN TETE : utiliser supprimerEnTete() sur une liste non-vide.\n");
    printf("Status : %u", supprimerEnTete(lptr1, &x));
    printf(", Valeur supprimee : %d.\n", x);
    afficher(lptr1, FORWARD);
    printf("\n");


    printf("SUPPRIMER et INSERER en queue.\n");
    Liste *lptr2 = initialiser();
    printf("SUPPRIMER EN QUEUE : utiliser supprimerEnQueue() sur une liste vide.\n");
    Info y = 0;
    printf("Status : %u\n", supprimerEnQueue(lptr2, &y));
    afficher(lptr2, FORWARD);
    printf("INSERER EN QUEUE : utiliser insererEnQueue() sur une liste pour inserer les chiffres de 0 a 5.\n");
    y = 0;
    printf("Status : %u\n", insererEnQueue(lptr2, &y));
    for (Info i = 1; i <= 5; ++i)
        insererEnQueue(lptr2, &i);
    afficher(lptr2, FORWARD);
    printf("SUPPRIMER EN QUEUE : utiliser supprimerEnQueue() sur une liste non-vide.\n");
    printf("Status : %u", supprimerEnQueue(lptr2, &y));
    printf(", Valeur supprimee : %d.\n", y);
    afficher(lptr2, FORWARD);


    return 0;
}
