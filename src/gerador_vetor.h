#ifndef GERADOR_VETOR_H
#define GERADOR_VETOR_H

// Classe estática com métodos para gerar vetores. Pode gerar vetores aleatórios, ordenados de
// forma crescente, e ordenados de forma decrescente.
class GeradorVetor {
private:
    static bool _rng_seedado;

    GeradorVetor() {} // Construtor private garante que a classe não pode ser instanciada.

public:
    // Gera um vetor de `n` elementos selecionados aleatoriamente no intervalo 0..`valor_max`.
    static int* aleatorio(int n, int valor_max);

    // Gera um vetor de `n` elementos ordenados de forma crescente.
    static int* crescente(int n);

    // Gera um vetor de `n` elementos ordenados de forma decrescente.
    static int* decrescente(int n);    
};

#endif
