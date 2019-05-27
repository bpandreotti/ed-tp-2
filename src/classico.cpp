#include "quicksort.h"

Resultado Quicksort::classico(int* vetor, int n) {
    auto res = Resultado();
    //TODO: iniciar e parar timer.
    contador_t contador = Quicksort::_classico(0, n - 1, vetor);
    res.set_contagem(contador);
    return res;
}

contador_t Quicksort::_classico(int esq, int dir, int* vetor) {
    contador_t contador;
    int i, j;
    
    // No algoritmo clássico, o pivô é escolhido como o elemento central do vetor.
    int pivo = vetor[(esq + dir) / 2];

    contador += Quicksort::_particao(esq, dir, i, j, pivo, vetor);
    if (esq < j)
        contador += Quicksort::_classico(esq, j, vetor);
    if (dir > i)
        contador += Quicksort::_classico(i, dir, vetor);
    
    return contador;
}


// O método de partição independe da escolha de algoritmo, e pode ser utilizado por todas as
// variações do quicksort. Para tornar esse método verdadeiramente geral, a escolha de pivô deve
// ser feita fora dele, e passada pelo argumento `pivo`.
contador_t Quicksort::_particao(int esq, int dir, int& i, int& j, int pivo, int* vetor) {
    contador_t contador;
    i = esq; j = dir;

    do {
        while (vetor[i] < pivo) {
            i++; // Encontra o primeiro elemento que é >= ao pivô.
            contador._num_comparacoes++;
        }

        while (vetor[j] > pivo) {
            j--; // Encontra o primeiro elemento que é <= ao pivô.
            contador._num_comparacoes++;
        }

        // Compensando, porque os whiles incrementam uma vez a menos.
        contador._num_comparacoes += 2;

        // Troca esses dois elementos, mas apenas se os indíces `i` e `j` ainda não tiverem se
        // cruzado.
        if (i <= j) {
            int tmp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = tmp;
            contador._num_movimentacoes += 2;

            i++; j--; // Após a troca, `i` e `j` devem progredir em uma posição.
        }
    } while (i <= j);

    return contador;
}