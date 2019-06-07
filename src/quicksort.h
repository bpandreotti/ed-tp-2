#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "resultado.h"

enum class EscolhaPivo { central, primeiro, mediana_de_tres };

// Classe Quicksort. Esta é uma classe "estática", ou seja, não pode ser instanciada, e apenas
// expõe métodos estáticos. Essa classe implementa as diversas variações do quicksort utilizadas
// nesse TP.
class Quicksort {
private:
    Quicksort() {} // Construtor private garante que a classe não pode ser instanciada.

    // Método auxiliar para encontrar a mediana de três inteiros.
    static int _mediana_de_tres(int a, int b, int c, contador_t& contador);

    // Método de partição. A escolha de pivô deve ser realizada fora desse método e passada pelo
    // argumento `pivo`. Isso torna esse método geral, e ele pode ser utilizado por qualquer
    // variante do quicksort.
    static contador_t _particao(int* vetor, int esq, int dir, int& i, int& j, int pivo);
    
    // Esse método implementa o algoritmo de ordenação insertion sort.
    static contador_t _insertion_sort(int* vetor, int esq, int dir);

    static contador_t _classico(int* vetor, int esq, int dir, EscolhaPivo escolha_pivo);
    
    static contador_t _com_insercao(int* vetor, int esq, int dir, int cutoff_insercao);

    static contador_t _nao_recursivo(int* vetor, int n);
public:

    // Variante clássica do quicksort. Aceita três alternativas de escolha de pivô: central,
    // primeiro elemento, ou mediana de três. Vide o enum `EscolhaPivo`.
    static Resultado classico(int* vetor, int n, EscolhaPivo escolha_pivo);

    // Variante do quicksort que utiliza ordenação por inserção a partir de certo ponto, definido
    // pelo argumento `porcentagem_insercao`.
    static Resultado com_insercao(int* vetor, int n, int porcentagem_insercao);

    static Resultado nao_recursivo(int* vetor, int n);
};

#endif
