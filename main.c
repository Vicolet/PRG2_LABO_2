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

bool critere(size_t pos, const Info *n){
   if(pos % 2 == 0 || *n > 1 && *n < 6){
      return true;
   }
   return false;
}

int main() {
   // Initialiser
   Liste* lptr = initialiser();

   printf("lptr : 0x%p \n", lptr);
   printf("lptr.tete : 0x%p \n", lptr->tete);
   printf("lptr.queue : 0x%p \n", lptr->queue);

   printf("Liste est vide : %d \n", estVide(lptr));
   printf("Taille de la liste : %d\n", longueur(lptr));

   // Insérer en tête
   const Info i = 7;
   insererEnTete(lptr, &i);

   printf("Element de tete : 0x%p , Valeur : %d\n", lptr->tete, lptr->tete->info);
   printf("Element suivant : 0x%p \n", lptr->tete->suivant);
   printf("Element precedent : 0x%p \n", lptr->tete->suivant);
   printf("Liste est vide : %d \n", estVide(lptr));
   printf("Taille de la liste : %d\n", longueur(lptr));

   const Info j = 6;
   insererEnTete(lptr, &j);

   printf("Element de tete : 0x%p , Valeur : %d\n", lptr->tete, lptr->tete->info);
   printf("Element suivant : 0x%p , Valeur : %d \n", lptr->tete->suivant,
          lptr->tete->suivant->info);
   printf("Element precedent : 0x%p \n", lptr->tete->precedent);
   printf("Liste est vide : %d \n", estVide(lptr));
   printf("Taille de la liste : %d\n", longueur(lptr));

   const Info y = 2;
   insererEnQueue(lptr, &y);

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
   printf("Taille de la liste : %d\n", longueur(lptr));

   // Supprimer tete
   Info x;
   supprimerEnTete(lptr, &x);
   printf("\nAncien n : %d\n", x);
   printf("Prec: 0x%p\n", lptr->tete->precedent);
   printf("Tete: 0x%p, %d\n", lptr->tete, lptr->tete->info);
   printf("Suiv: 0x%p, %d\n", lptr->tete->suivant, lptr->tete->suivant->info);
   printf("Taille de la liste : %d\n", longueur(lptr));

   // Supprimer queue
   supprimerEnQueue(lptr, &x);
   printf("\nPrec: 0x%p\n", lptr->tete->precedent);
   printf("Tete: 0x%p, %d\n", lptr->tete, lptr->tete->info);
   printf("Suiv: 0x%p\n", lptr->tete->suivant);
   printf("Taille de la liste : %d\n", longueur(lptr));

   // Vider
   insererEnTete(lptr, &i);
   insererEnTete(lptr, &j);
   insererEnTete(lptr, &y);
   insererEnTete(lptr, &j);
   insererEnTete(lptr, &y);

   /*
   Element* eptr = lptr->tete->suivant->suivant;
   printf("\n3eme: 0x%p\n", eptr);
   printf("queue: 0x%p\n", lptr->queue);
   supprimerEnQueue(lptr,&x);
   printf("queue: 0x%p\n", lptr->queue);
   supprimerEnQueue(lptr,&x);
   printf("queue: 0x%p\n", lptr->queue);
   supprimerEnQueue(lptr,&x);
   printf("queue: 0x%p\n", lptr->queue);
   */

   printf("\ntaille: %d\n", longueur(lptr));
   vider(lptr, 0);
   printf("\ntaille: %d\n", longueur(lptr));

   // égalité
   Liste* l2ptr = initialiser();
   Liste* l3ptr = initialiser();
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

   printf("\nEgale: %d\n", sontEgales(l2ptr, l3ptr));
   supprimerEnTete(l2ptr, &x);
   printf("Egale: %d\n", sontEgales(l2ptr, l3ptr));
   insererEnTete(l2ptr, &y);
   printf("Egale: %d\n", sontEgales(l2ptr, l3ptr));

   // Affichage
   printf("\n");
   afficher(l2ptr, FORWARD);
   afficher(l2ptr, BACKWARD);

   // SupprimerCritère
   supprimerSelonCritere(l2ptr, critere);
   afficher(l2ptr, FORWARD);

   return 0;
}
