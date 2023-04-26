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
   Liste* lptr = initialiser();

   printf("lptr : 0x%p \n", lptr);
   printf("lptr.tete : 0x%p \n", lptr->tete);
   printf("lptr.queue : 0x%p \n", lptr->queue);

   return 0;
}
