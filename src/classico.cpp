#include "quicksort.h"

void Quicksort::classico(int* vetor, int n) {
    Quicksort::_classico(0, n - 1, vetor);
}

void Quicksort::_classico(int esq, int dir, int* vetor) {
    int i, j;
    
    // No algoritmo clássico, o pivô é escolhido como o elemento central do vetor.
    int pivo = vetor[(esq + dir) / 2];

    Quicksort::_particao(esq, dir, i, j, pivo, vetor);
    if (esq < j)
        Quicksort::_classico(esq, j, vetor);
    if (dir > i)
        Quicksort::_classico(i, dir, vetor);
}


// O método de partição independe da escolha de algoritmo, e pode ser utilizado por todas as
// variações do quicksort. Para tornar esse método verdadeiramente geral, a escolha de pivô deve
// ser feita fora dele, e passada pelo argumento `pivo`.
void Quicksort::_particao(int esq, int dir, int& i, int& j, int pivo, int* vetor) {
    i = esq; j = dir;

    do {
        while (vetor[i] < pivo) i++; // Encontra o primeiro elemento que é >= ao pivô.
        while (vetor[j] > pivo) j--; // Encontra o primeiro elemento que é <= ao pivô.

        // Troca esses dois elementos, mas apenas se os indíces `i` e `j` ainda não tiverem se
        // cruzado.
        if (i <= j) {
            int tmp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = tmp;

            i++; j--; // Após a troca, `i` e `j` devem progredir em uma posição.
        }
    } while (i <= j);
}