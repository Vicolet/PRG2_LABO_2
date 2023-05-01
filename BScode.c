//BScode

#include <stdio.h>
#include "listes_dynamiques.h"

int main() {
    Liste *lptr = initialiser();
    for (Info i = 1; i <= 3; ++i)
        insererEnQueue(lptr, &i);
    afficher(lptr, FORWARD);
    vider(lptr, 2);
    afficher(lptr, FORWARD);
}
