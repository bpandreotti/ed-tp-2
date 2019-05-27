#ifndef GERADOR_VETOR_H
#define GERADOR_VETOR_H

// Classe estática com métodos para gerar vetores. Pode gerar vetores aleatórios, ordenados de
// forma crescente, e ordenados de forma decrescente.
class GeradorVetor {
private:
    static bool _rng_seedado;

    GeradorVetor() {} // Construtor private garante que a classe não pode ser instanciada.

public:
    static int* aleatorio(int n, int valor_max);
    static int* crescente(int n);
    static int* decrescente(int n);    
};

#endif
