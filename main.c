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
	size_t position = 0;
	int tailleListe = 0;

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


	printf("### SUPPRIMER ET INSERER EN TETE ###\n");
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
	printf("%-10s = ", "FORWARD");
	afficher(lptr1, FORWARD);
	printf("%-10s = ", "BACKWARD");
	afficher(lptr1, BACKWARD);
	printf("\n");


	printf("===### SUPPRIMER ET INSERER EN QUEUE ###===\n");
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
	printf("%-10s = ", "FORWARD");
	afficher(lptr2, FORWARD);
	printf("%-10s = ", "BACKWARD");
	afficher(lptr2, BACKWARD);
	printf("\n");

    printf("-----====### VIDER ###====-----");

    printf("\n\nVIDER : utiliser vider() sur une liste vide.\n");
    Liste *listeTestVider = initialiser();
    printf("%-45s : ", "-Initilisation d'une liste vide");
    afficher(listeTestVider, FORWARD);
    vider(listeTestVider, position);
    printf("\n%s %-3zu : ", "-Apres utilisation de vider() en position", position);
    afficher(listeTestVider, FORWARD);

    printf("\n\nVIDER : utiliser vider() sur une liste de un element.\n");
    printf("%-45s : ", "-Ajout d'un element dans la liste");
    x = 0;
    insererEnQueue(listeTestVider, &x);
    afficher(listeTestVider, FORWARD);
    printf("\n%s %-3zu : ", "-Apres utilisation de vider() en position", position);
    vider(listeTestVider, position);
    afficher(listeTestVider, FORWARD);

    printf("\n\nVIDER : utiliser vider() sur une liste de plusieurs elements.\n");
    printf("%-45s : ", "-Ajout de plusieurs elements dans la liste");
    tailleListe = 10;
    for (Info i = 0; i < tailleListe; ++i)
        insererEnQueue(listeTestVider, &i);
    afficher(listeTestVider, FORWARD);
    position = 5;
    printf("\n%s %-3zu : ", "-Apres utilisation de vider() en position", position);
    vider(listeTestVider, position);
    afficher(listeTestVider, FORWARD);
    position = 2;
    printf("\n%s %-3zu : ", "-Apres utilisation de vider() en position", position);
    vider(listeTestVider, position);
    afficher(listeTestVider, FORWARD);
    position = 0;
    printf("\n%s %-3zu : ", "-Apres utilisation de vider() en position", position);
    vider(listeTestVider, position);
    afficher(listeTestVider, FORWARD);

    printf("\n\nVIDER : utiliser une position plus grande que la taille de la liste\n");
    tailleListe = 5;
    position = 6;
    for (Info i = 0; i < tailleListe; ++i)
        insererEnQueue(listeTestVider, &i);
    printf("%-59s : ", "-Liste de base");
    afficher(listeTestVider, FORWARD);
    printf("\n%s %zu %s %d : ", "-Utiliser vider() en position",
           position, "sur une liste de longueur", tailleListe);
    vider(listeTestVider, position);
    afficher(listeTestVider, FORWARD);
    printf("\n%-59s : ", "-Vider completement la liste");
    position = 0;
    vider(listeTestVider, position);
    afficher(listeTestVider, FORWARD);
    position = 3;
    printf("\n%s %zu %-27s : ", "-Utiliser vider() en position",
           position, "sur une liste vide");
    vider(listeTestVider, position);
    afficher(listeTestVider, FORWARD);
    printf("\n");

	printf("===### ELEMENTS ###===\n");

	tailleListe = 5;
	printf("\nELEMENT : initialisation et ajout de %d valeur dans une liste.\n",
			 tailleListe );
	Liste *lptr3 = initialiser();
	for (Info i = 0; i < tailleListe; ++i)
		insererEnTete(lptr3, &i);
	printf("%s : ", "-Liste apres initialisation et ajouts d'elements");
	afficher(lptr3, FORWARD);
	printf("%-48s : %d \n",
			 "-Element de tete", lptr3->tete->info);
	printf("%-48s : %d \n",
			 "-Element suivant de tete", lptr3->tete->suivant->info);
	printf("%-48s : %d \n",
			 "-Element de queue", lptr3->queue->info);
	printf("%-48s : %d \n",
			 "-Element precedent de queue", lptr3->queue->precedent->info);
	printf("\n");

    printf("===### EGALITE ###===\n");

    printf("\nEGALITE : 1 = egales / 0 = non-egales\n");
    vider(lptr1, 0);
    vider(lptr2, 0);

    printf("%-60s : ", "-Egalite de deux listes vides");
    afficher(lptr1, FORWARD);
    printf(" et ");
    afficher(lptr2, FORWARD);
    printf(" = %d", sontEgales(lptr2, lptr1));
    printf("\n");

    for (Info i = 0; i < 4; ++i)
        insererEnTete(lptr2, &i);
    for (Info i = 0; i < 4; ++i)
        insererEnTete(lptr1, &i);
    printf("%-60s : ", "-Egalite de deux listes de memes infos et meme ordre");
    afficher(lptr1, FORWARD);
    printf(" et ");
    afficher(lptr2, FORWARD);
    printf(" = %d", sontEgales(lptr2, lptr1));
    printf("\n");

    vider(lptr1, 0);
    for (Info i = 4; i > 0; --i)
        insererEnTete(lptr1, &i);
    printf("%-60s : ", "-Egalite de deux listes de memes infos et d'ordre different");
    afficher(lptr1, FORWARD);
    printf(" et ");
    afficher(lptr2, FORWARD);
    printf(" = %d", sontEgales(lptr2, lptr1));
    printf("\n");

    vider(lptr2, 2);
    printf("%-60s : ", "-Egalite de deux listes de differente taille");
    afficher(lptr1, FORWARD);
    printf(" et ");
    afficher(lptr2, FORWARD);
    printf(" = %d", sontEgales(lptr2, lptr1));
    printf("\n");

	//TODO tester supprimer critère avec un élément
	//TODO implementer les tests pour supprimer selon critère
	//TODO faire la boucle 0 à 4 et 5 à 9

	printf("### SUPPRIMER SELON CRITERE ###\n");

	return 0;
}
