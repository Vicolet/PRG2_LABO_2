/*
 -----------------------------------------------------------------------------------
 Nom du fichier : listes_dynamiques.c
 Auteur(s)      : Romain Fleury, Victor Nicolet
 Date creation  : 26.04.2023

 Description    : Librairie permettant la gestion de listes doublement chaînées
                  non circulaires

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 12.2.0
 -----------------------------------------------------------------------------------
*/
#include <stdlib.h>
#include "listes_dynamiques.h"

Liste* initialiser(void){
   Liste* l = (Liste*) calloc(1, sizeof(Liste));

   return l;
}

bool estVide(const Liste* liste){
   if(liste->tete == NULL && liste->queue == NULL){
      return true;
   }

   return false;
}

size_t longueur(const Liste* liste){

}

void afficher(const Liste* liste, Mode mode){

}

Status insererEnTete(Liste* liste, const Info* info){
   // vérifier si la liste est vide
   // si liste vide calloc un "Elements" et tete = calloc

   // si liste non vide, calloc un "Elements" et tmp = tete, tete = calloc, tete
   // .suivant = tmp

   Element* eptr = (Element*) calloc(1, sizeof(Element));
   if(eptr != NULL) {
      if (estVide(liste)) {
         liste->tete = eptr;
         liste->queue = eptr;
         liste->tete->info = *info;

         return OK;
      } else {
         Element *tmp = liste->tete;
         liste->tete = eptr;
         liste->tete->suivant = tmp;
         liste->tete->suivant->precedent = liste->tete;
         liste->tete->info = *info;

         return OK;
      }
   }else{
      return MEMOIRE_INSUFFISANTE;
   }
}

Status insererEnQueue(Liste* liste, const Info* info){
   Element* eptr = (Element*) calloc(1, sizeof(Element));
   if(eptr != NULL){
      if(estVide(liste)){
         liste->tete = eptr;
         liste->queue = eptr;
         liste->queue->info = *info;

         return OK;
      }else{
         Element* tmp = liste->queue;
         liste->queue = eptr;
         liste->queue->precedent = tmp;
         liste->queue->precedent->suivant = liste->queue;
         liste->queue->info = *info;

         return OK;
      }
   }else{
      return MEMOIRE_INSUFFISANTE;
   }
}

Status supprimerEnTete(Liste* liste, Info* info){

}

Status supprimerEnQueue(Liste* liste, Info* info){

}

void supprimerSelonCritere(Liste* liste,
                           bool (*critere)(size_t position, const Info* info)){

}

void vider(Liste* liste, size_t position){

}

bool sontEgales(const Liste* liste1, const Liste* liste2){

}