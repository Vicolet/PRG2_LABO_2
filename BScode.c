//BScode

#include <stdio.h>
#include "listes_dynamiques.h"

bool critere(size_t pos, const Info *n) {
	if (pos % 2 == 0 || *n > 1 && *n < 6)
		return false;
	return true;
}

int main(void) {
	size_t position = 0;
	int tailleListe = 0;
	Info x = 0;


	return 0;
}

//[1,2,3,4,5,6,7,8,9,10]
//[6,9]
//[0,1,2,3,4,5,6,7,8,9]
//[6,9]