//
// Created by Galas on 26.04.2023.
//
#include <stdlib.h>
#include <malloc.h>
#include "listes_dynamiques.h"

Liste* initialiser(void){
   Liste* l = (Liste*) malloc(1, sizeof(Liste));

   return l;
}

bool estVide(const Liste* liste){

}

size_t longueur(const Liste* liste){

}

void afficher(const Liste* liste, Mode mode){

}

Status insererEnTete(Liste* liste, const Info* info){

}

Status insererEnQueue(Liste* liste, const Info* info){

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
