#include "quicksort.h"
#include "pilha.h"

Resultado Quicksort::nao_recursivo(int* vetor, int n) {
    auto res = Resultado();
    res.iniciar_timer();
    contador_t contador = Quicksort::_nao_recursivo(vetor, n);
    res.parar_timer();
    res.set_contagem(contador);
    return res;
}

contador_t Quicksort::_nao_recursivo(int* vetor, int n) {
    contador_t contador;
    int i, j;

    auto pilha = Pilha(n * 2);
    int esq = 0;
    int dir = n - 1;

    pilha.push(esq);
    pilha.push(dir);

    while (pilha.num_elementos() != 0) {
        // Empilhando sempre `esq` e depois `dir`, e desempilhando `dir` e depois `esq`.
        dir = pilha.pop();
        esq = pilha.pop();

        if (dir > esq) {
            int pivo = vetor[(esq + dir) / 2];
            contador += Quicksort::_particao(vetor, esq, dir, i, j, pivo);
            
            if (j - esq > dir - i) {
                pilha.push(esq);
                pilha.push(j);
                pilha.push(i);
                pilha.push(dir);
            } else {
                pilha.push(i);
                pilha.push(dir);
                pilha.push(esq);
                pilha.push(j);
            }
        }
    }

    return contador;
}