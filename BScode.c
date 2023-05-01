//BScode

#include <stdio.h>
#include "listes_dynamiques.h"

int main() {
    Liste *lptr = initialiser();
    Info i = 1;
    insererEnTete(lptr, &i);
    afficher(lptr, FORWARD);

    i++;
    insererEnTete(lptr, &i);
    afficher(lptr, FORWARD);

    i++;
    insererEnTete(lptr, &i);
    afficher(lptr, FORWARD);

    Liste *rtpl = initialiser();
    Info j = 1;
    insererEnQueue(rtpl, &j);
    afficher(rtpl, FORWARD);

    j++;
    insererEnQueue(rtpl, &j);
    afficher(rtpl, FORWARD);

    j++;
    insererEnQueue(rtpl, &j);
    afficher(rtpl, FORWARD);
}
