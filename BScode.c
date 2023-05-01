//BScode

#include <stdio.h>
#include "listes_dynamiques.h"

int main() {
    Liste *lptr = initialiser();

    Info x;
    printf("%s", supprimerEnQueue(lptr, &x));


}
