#include <iostream>
#include "quicksort.h"

Resultado Quicksort::com_insercao(int* vetor, int n, int porcentagem_insercao) {
    auto res = Resultado();
    res.iniciar_timer();
    contador_t contador;// = Quicksort::_com_insercao(vetor, 0, n - 1, porcentagem_insercao);
    res.parar_timer();
    res.set_contagem(contador);
    return res;
}

contador_t Quicksort::_com_insercao(int* vetor, int esq, int dir, int porcentagem_insercao) {
    contador_t contador;
    //TODO
    return contador;
}

contador_t Quicksort::_insertion_sort(int* vetor, int esq, int dir) {
    contador_t contador;

    for (int i = esq + 1; i <= dir; i++) {
        int x = vetor[i];
        int j = i - 1;
        
        while(j >= esq && vetor[j] > x) {
            contador._num_comparacoes++;
            contador._num_movimentacoes++;
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j+1] = x;
        contador._num_movimentacoes++;
    }
    return contador;
}