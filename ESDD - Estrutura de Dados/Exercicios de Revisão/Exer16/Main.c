#include "ConjuntoInt.h"

int main()
{
    ConjuntoInt conjunto1;
    ConjuntoInt conjunto2;
    ConjuntoInt conjunto3;

    conjunto1 = creatSet();
    conjunto2 = creatSet();

    printf("\n%s", isEmpty(conjunto1) ? "Eh vazio!" : "Nao eh vazio!");
    printf("\n%s\n", isEmpty(conjunto2) ? "Eh vazio!" : "Nao eh vazio!");

    insertInt(conjunto1, 5);
    insertInt(conjunto1, 2);
    insertInt(conjunto1, 3);
    insertInt(conjunto1, 4);
    insertInt(conjunto1, 2);
    insertInt(conjunto1, 6);
    insertInt(conjunto1, 21389);
    insertInt(conjunto1, 43);
      
    insertInt(conjunto2, 26);
    insertInt(conjunto2, 21389);
    insertInt(conjunto2, 43);
    insertInt(conjunto2, 32);
    insertInt(conjunto2, 2);
    insertInt(conjunto2, 6);
    insertInt(conjunto2, 54);

    printSet(conjunto1);
    printSet(conjunto2);

    removeInt(conjunto1, 5);
    removeInt(conjunto2, 5);

    printf("\n%s", isEmpty(conjunto1) ? "Eh vazio!" : "Nao eh vazio!");
    printf("\n%s\n", isEmpty(conjunto2) ? "Eh vazio!" : "Nao eh vazio!");

    printf("\n%s", isOnSet(conjunto1, 2) ? "Numero encontrado!" : "Nao esta no conjunto!" );
    printf("\n%s\n", isOnSet(conjunto1, 5) ? "Numero encontrado!" : "Nao esta no conjunto!" );

    printf("\n%s", isEqual(conjunto1, conjunto2) ? "Eh igual!" : "Eh diferente!");

    conjunto3 = unite(conjunto1, conjunto2);
    printSet(conjunto3);
    
    destroySet(conjunto3);
    conjunto3 = intersection(conjunto1, conjunto2);
    printSet(conjunto3);

    destroySet(conjunto3);
    conjunto3 = difference(conjunto1, conjunto2);
    printSet(conjunto3);

    destroySet(conjunto1);
    destroySet(conjunto2);

    return 0;
}
