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

bool critere(size_t pos, const Info *n) {
    //return true;
    if (pos % 2 == 0 || *n > 1 && *n < 6) {
        return true;
    }
    return false;
}

int main() {

    Liste *lptr = initialiser();

    printf("Initialisation de Liste à 0 :\n");
    printf("%-25s %-15s %-15s \n", "Variable", "Adresse", "Adresse pointeur");
    printf("%-25s %-#15x %-#15x \n", "lptr", (void *) &lptr, (void *) lptr);
    printf("%-25s %-#15x %-#15x \n", "lptr->tete", (void *) &(lptr->tete), lptr->tete);
    printf("%-25s %-#15x %-#15x \n", "lptr->queue", (void *) &(lptr->queue), lptr->queue);

    printf("\n");

    printf("Test des fonctions estVide() et longueur() :\n");
    printf("%-25s : %d \n", "Liste est vide", estVide(lptr));
    printf("%-25s : %lld \n", "Taille de la liste", longueur(lptr));

    printf("\n");

    // Insérer en tête
    const Info i = 7;
    insererEnTete(lptr, &i);

    printf("%-25s %-15s %-15s \n", "Variable", "Adresse", "Valeur");
    printf("%-25s %-#15x %-15d \n", "Element de tête", lptr->tete, lptr->tete->info);
    printf("%-25s %-#15x %-20s \n", "Element suivant", lptr->tete->suivant, "-"); // TODO voir si c'est possible le "-"
    printf("%-25s %-#15x %-20s \n", "Element precedent", lptr->tete->precedent, "-");

    printf("\n");

    printf("Contrôle avec les fonctions estVide() et longueur() :\n");
    printf("%-25s : %d \n", "Liste est vide", estVide(lptr));
    printf("%-25s : %lld \n", "Taille de la liste", longueur(lptr));

    printf("\n");

    const Info j = 6;
    insererEnTete(lptr, &j);

    printf("%-25s %-15s %-15s \n", "Variable", "Adresse", "Valeur");
    printf("%-25s %-#15x %-15d \n", "Element de tête", lptr->tete, lptr->tete->info);
    printf("%-25s %-#15x %-15d \n", "Element suivant", lptr->tete->suivant, lptr->tete->suivant->info);
    printf("%-25s %-#15x %-20s \n", "Element precedent", lptr->tete->precedent, "-");

    printf("\n");

    printf("Contrôle avec les fonctions estVide() et longueur() :\n");
    printf("%-25s : %d \n", "Liste est vide", estVide(lptr));
    printf("%-25s : %lld \n", "Taille de la liste", longueur(lptr));

    printf("\n");

    const Info y = 2;
    insererEnQueue(lptr, &y);

    printf("%-25s %-15s %-15s \n", "Variable", "Adresse", "Valeur");
    printf("%-25s %-#15x %-15d \n", "Élément de tête", lptr->tete, lptr->tete->info);
    printf("%-25s %-#15x %-15d \n", "Élément suivant", lptr->tete->suivant, lptr->tete->suivant->info);
    printf("%-25s %-#15x %-20s \n", "Élément précédent", lptr->tete->precedent, "-");
    printf("%-25s %-#15x %-15d \n", "Suivant précédent", lptr->tete->suivant->precedent,
           lptr->tete->suivant->precedent->info);
    printf("%-25s %-#15x %-15d \n", "Suivant ", lptr->tete->suivant, lptr->tete->suivant->info);
    printf("%-25s %-#15x %-15d \n", "Suivant suivant", lptr->tete->suivant->suivant,
           lptr->tete->suivant->suivant->info);
    printf("%-25s %-#15x %-15d \n", "Queue ", lptr->queue, lptr->queue->info);

    printf("\n");

    printf("Contrôle avec les fonctions estVide() et longueur() :\n");
    printf("%-25s : %d \n", "Liste est vide", estVide(lptr));
    printf("%-25s : %lld \n", "Taille de la liste", longueur(lptr));

    printf("\n");

    // Supprimer tete
    Info x;
    supprimerEnTete(lptr, &x);

    printf("%-25s %-15s %-15s \n", "Variable", "Adresse", "Valeur");
    printf("%-25s %-#15x %-15s \n", "Élément précédent", lptr->tete->precedent, "-");
    printf("%-25s %-#15x %-15d \n", "Élément de tête", lptr->tete, lptr->tete->info);
    printf("%-25s %-#15x %-15d \n", "Élément suivant", lptr->tete->suivant, lptr->tete->suivant->info);
    printf("%-41s %lld \n", "Nouvelle taille de la liste :", longueur(lptr));

    printf("\n");

    // Supprimer queue
    supprimerEnQueue(lptr, &x);

    printf("%-25s %-15s %-15s \n", "Variable", "Adresse", "Valeur");
    printf("%-25s %-#15x %-15s \n", "Élément précédent", lptr->tete->precedent, "-");
    printf("%-25s %-#15x %-15d \n", "Élément de tête", lptr->tete, lptr->tete->info);
    printf("%-25s %-#15x %-15s \n", "Élément suivant", lptr->tete->suivant, "-");
    printf("%-41s %lld \n", "Nouvelle taille de la liste :", longueur(lptr));

    printf("\n");

    // Vider
    insererEnTete(lptr, &i);
    insererEnTete(lptr, &j);
    insererEnTete(lptr, &y);
    insererEnTete(lptr, &j);
    insererEnTete(lptr, &y);

    printf("%-41s %lld \n", "Longueur avant la fonction vider() :", longueur(lptr));
    vider(lptr, 0);
    printf("%-41s %lld \n", "Longueur après la fonction vider() :", longueur(lptr));

    printf("\n");

    // égalité
    Liste *l2ptr = initialiser();
    Liste *l3ptr = initialiser();
    insererEnTete(l2ptr, &i);
    insererEnTete(l2ptr, &j);
    insererEnTete(l2ptr, &y);
    insererEnTete(l2ptr, &j);
    insererEnTete(l2ptr, &y);

    insererEnTete(l3ptr, &i);
    insererEnTete(l3ptr, &j);
    insererEnTete(l3ptr, &y);
    insererEnTete(l3ptr, &j);
    insererEnTete(l3ptr, &y);

    printf("Initialisation de 2 Listes pour tester la fonction sontEgales() : \n");
    printf("%-41s %-10s \n", "Action", "Sont égale");
    printf("%-41s %d \n", "Initialisation de deux listes identiques", sontEgales(l2ptr, l3ptr));
    supprimerEnTete(l2ptr, &x);
    printf("%-41s %d \n", "Après supprimerEnTete() sur la liste 2", sontEgales(l2ptr, l3ptr));
    insererEnTete(l2ptr, &y);
    printf("%-41s %d \n", "Après insererEnTete() sur la liste 2", sontEgales(l2ptr, l3ptr));

    printf("\n");

    // Affichage
    printf("Affichage de la Liste à l'endroit puis à l'envers :\n");
    afficher(l2ptr, FORWARD);
    afficher(l2ptr, BACKWARD);

    printf("\n");
    // SupprimerCritère
    printf("Test de la fonction supprimerSelonCritere() :\n"); //TODO probleme avec la fonction supprimerSelonCritere()
    supprimerSelonCritere(l2ptr, critere);
    afficher(l2ptr, FORWARD);

    return 0;
}