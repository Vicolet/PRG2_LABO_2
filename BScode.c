//BScode

#include <stdio.h>
#include "listes_dynamiques.h"

int main() {
	size_t position = 0;
	int tailleListe = 0;

	Liste *lptr1 = initialiser();
	Liste *lptr2 = initialiser();

	printf("===### EGALITE ###===\n");

	printf("\nEGALITE : Valeur qui affiche l'egalite 1 = egales / 0 = non-egales\n");
	vider(lptr1, 0);
	vider(lptr2, 0);
	afficher(lptr1,FORWARD);
	afficher(lptr2, FORWARD);
	printf("%s %d\n","-Egalite de deux listes vides ->",
			 sontEgales(lptr1, lptr2));
	for (Info i = 0; i < 4; ++i)
		insererEnTete(lptr2, &i);
	for (Info i = 0; i < 4; ++i)
		insererEnTete(lptr1, &i);
	printf("%-30s %d\n", "Meme infos, meme ordre",
			 sontEgales(lptr1, lptr2));
	for (Info i = 5; i < 10; ++i)
		insererEnTete(lptr2, &i);
	for (Info i = 10; i > 5; --i)
		insererEnTete(lptr1, &i);
	printf("%-30s %d\n", "Meme infos, ordre different", sontEgales(lptr1, lptr2));
	vider(lptr2, 0);
	printf("%-30s %d\n", "Differente taille", sontEgales(lptr1, lptr2));
	printf("\n");





	return 0;
}
