#include <iostream>
#include "quicksort.h"

Resultado Quicksort::com_insercao(int* vetor, int n, int porcentagem_insercao) {

    // Esse valor indica o quão pequeno deve ser o subvetor para que comecemos a usar o insertion
    // sort ao invés do quicksort. Como o método `Quicksort::_com_insercao` não sabe o tamanho
    // total do vetor, calculamos esse cutoff aqui, usando a porcentagem passada.
    int cutoff = (porcentagem_insercao * n) / 100;
    
    auto res = Resultado();
    res.iniciar_timer();
    contador_t contador = Quicksort::_com_insercao(vetor, 0, n - 1, cutoff);
    res.parar_timer();
    res.set_contagem(contador);
    return res;
}

contador_t Quicksort::_com_insercao(int* vetor, int esq, int dir, int cutoff_insercao) {
    contador_t contador;
    
    // Usamos o insertion sort quando o subvetor for menor que `cutoff_insercao`.
    if (dir - esq + 1 <= cutoff_insercao) {
        contador += Quicksort::_insertion_sort(vetor, esq, dir);
        return contador;
    }
    
    int i, j;

    // Usamos a escolha de pivô 'mediana de três'.
    int pivo = Quicksort::_mediana_de_tres(
        vetor[esq],
        vetor[(esq + dir) / 2],
        vetor[dir],
        contador
    );

    contador += Quicksort::_particao(vetor, esq, dir, i, j, pivo);
    if (esq < j)
        contador += Quicksort::_com_insercao(vetor, esq, j, cutoff_insercao);
    if (dir > i)
        contador += Quicksort::_com_insercao(vetor, i, dir, cutoff_insercao);
    
    return contador;
}

contador_t Quicksort::_insertion_sort(int* vetor, int esq, int dir) {
    contador_t contador;

    for (int i = esq + 1; i <= dir; i++) {
        int x = vetor[i];
        contador._num_movimentacoes++;
        int j = i - 1;
        
        while(j >= esq) {
            contador._num_comparacoes++;
            if (vetor[j] > x) {
                contador._num_movimentacoes++;
                vetor[j + 1] = vetor[j];
                j--;
            } else break;
        }
        vetor[j + 1] = x;
        contador._num_movimentacoes++;
    }
    return contador;
}
