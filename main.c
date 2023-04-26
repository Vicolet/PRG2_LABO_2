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

int main() {
   // Initialiser
   Liste* lptr = initialiser();

   printf("lptr : 0x%p \n", lptr);
   printf("lptr.tete : 0x%p \n", lptr->tete);
   printf("lptr.queue : 0x%p \n", lptr->queue);

   printf("Liste est vide : %d \n", estVide(lptr));

   // Insérer en tête
   const Info i = 7;
   insererEnTete(lptr, &i);

   printf("Element de tete : 0x%p , Valeur : %d\n", lptr->tete, lptr->tete->info);
   printf("Element suivant : 0x%p \n", lptr->tete->suivant);
   printf("Element precedent : 0x%p \n", lptr->tete->suivant);
   printf("Liste est vide : %d \n", estVide(lptr));

   const Info j = 6;
   insererEnTete(lptr, &j);

   printf("Element de tete : 0x%p , Valeur : %d\n", lptr->tete, lptr->tete->info);
   printf("Element suivant : 0x%p , Valeur : %d \n", lptr->tete->suivant,
          lptr->tete->suivant->info);
   printf("Element precedent : 0x%p \n", lptr->tete->precedent);
   printf("Liste est vide : %d \n", estVide(lptr));

   const Info y = 2;
   insererEnTete(lptr, &y);

   printf("Element de tete : 0x%p , Valeur : %d\n", lptr->tete, lptr->tete->info);
   printf("Element suivant : 0x%p , Valeur : %d \n", lptr->tete->suivant,
          lptr->tete->suivant->info);
   printf("Element precedent : 0x%p \n", lptr->tete->precedent);
   printf("suive prec : 0x%p, %d\n", lptr->tete->suivant->precedent,
          lptr->tete->suivant->precedent->info);
   printf("suiv : 0x%p, %d\n", lptr->tete->suivant, lptr->tete->suivant->info);
   printf("suive suiv : 0x%p, %d\n", lptr->tete->suivant->suivant,
          lptr->tete->suivant->suivant->info);
   printf("Queue : 0x%p, %d\n", lptr->queue, lptr->queue->info);
   printf("Liste est vide : %d \n", estVide(lptr));

   return 0;
}
