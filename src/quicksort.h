#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "resultado.h"

// Classe Quicksort. Esta é uma classe "estática", ou seja, não pode ser instanciada, e apenas
// expõe métodos estáticos. Essa classe implementa as diversas variações do quicksort utilizadas
// nesse TP.
class Quicksort {
public:
    static Resultado classico(int* vetor, int n);

private:
    Quicksort() {}

    static contador_t _classico(int esq, int dir, int* vetor);
    static contador_t _particao(int esq, int dir, int& i, int& j, int pivo, int* vetor);
};

#endif