/*
 -----------------------------------------------------------------------------------
 Nom du fichier : main.c
 Auteur(s)      : Romain Fleury, Victor Nicolet
 Date creation  : 26.04.2023

 Description    : Programme principal permettant de faire tous les tests de la
 						librairie "liste_dynamique.h".

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 12.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include "listes_dynamiques.h"

int main() {
    Liste *lptr1 = initialiser();
    printf("Initialisation de la liste.\n");
    printf("%-20s %-20s %-20s \n", "Variable", "Adresse", "Adresse pointeur");
    printf("%-20s %-20p %-20p \n", "lptr", (void *) &lptr1, (void *) lptr1);
    printf("%-20s %-20p %-20p \n", "lptr->tete", (void *) &(lptr1->tete), lptr1->tete);
    printf("%-20s %-20p %-20p \n", "lptr->queue", (void *) &(lptr1->queue), lptr1->queue);
    printf("\n");

    printf("Test des fonctions estVide() et longueur() a l'initialisation de la liste.\n");
    printf("%-20s : %d \n", "Liste est vide", estVide(lptr1));
    printf("%-20s : %lld \n", "Taille de la liste", longueur(lptr1));
    printf("\n");

    printf("Affichage d'une liste a l'initialisation. (FORWARD puis BACKWARD)\n");
    afficher(lptr1, FORWARD);
    afficher(lptr1, BACKWARD);
    printf("\n");

    for (Info i = 3; i < 11; ++i)
        insererEnTete(lptr1, &i);
    printf("Insertion en tete des chiffres allant de 5 a 9.\n");
    afficher(lptr1, FORWARD);
    printf("\n");

    printf("Vider les chiffres 3 et 4 de la liste. (position 6)\n");
    vider(lptr1, 6);
    afficher(lptr1, FORWARD);
    printf("\n");

    for (Info i = 4; i >= -1; --i)
        insererEnQueue(lptr1, &i);
    printf("Insertion en Queue des chiffres allant de -1 a 4.\n");
    afficher(lptr1, FORWARD);
    printf("\n");

    printf("Suppression des valeur en queue et en tete.\n");
    Info x, y;
    supprimerEnTete(lptr1, &x);
    supprimerEnQueue(lptr1, &y);
    printf("Les valeurs supprimees sont %d et %d\n", y, x);
    afficher(lptr1, FORWARD);
    printf("\n");

    printf("Test de l'affichage BACKWARD d'une liste non vide.\n");
    afficher(lptr1, BACKWARD);
    printf("\n");

    printf("Vider completement lptr1.\n");
    vider(lptr1, 0);
    afficher(lptr1, FORWARD);
    printf("\n");

    printf("Test de la fonction sontEgale().\nInitialisation de deux listes vides.\n");
    Liste *lptr2 = initialiser();

    printf("%-30s : %d\n", "Vide", sontEgales(lptr1, lptr2));
    for (Info i = 0; i < 4; ++i)
        insererEnTete(lptr2, &i);
    printf("%-30s : %d\n", "Meme infos, pas meme ordre", sontEgales(lptr1, lptr2));


}