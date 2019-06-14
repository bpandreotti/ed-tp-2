#include "gerador_vetor.h"
#include <cstdlib>
#include <ctime>

bool GeradorVetor::_rng_seedado;

int* GeradorVetor::aleatorio(int n, int valor_max) {
    int* vetor = new int[n];
    
    // Seeda o rng caso necessário.
    if (!GeradorVetor::_rng_seedado) {
        std::srand(std::time(nullptr));
        GeradorVetor::_rng_seedado = true;
    }
    
    // Utilizar `std::rand() % valor_max` pode gerar viés na geração de números aleatórios, além de
    // ser um pouco mais lento. Por isso, para gerar um número aleatório no intervalo desejado,
    // estou usando `std::rand() / ((RAND_MAX + 1u) / valor_max)`. Para mais detalhes, vide:
    // https://stackoverflow.com/a/10984975
    // https://en.cppreference.com/w/cpp/numeric/random/rand
    unsigned int d = (RAND_MAX + 1u) / valor_max;
    for (int i = 0; i < n; i++)
        vetor[i] = std::rand() / d;
    
    return vetor;
}

int* GeradorVetor::crescente(int n) {
    int* vetor = new int[n];
    for (int i = 0; i < n; i++)
        vetor[i] = i;
    
    return vetor;
}

int* GeradorVetor::decrescente(int n) {
    int* vetor = new int[n];
    for (int i = 0; i < n; i++)
        vetor[i] = n - i - 1;
    
    return vetor;
}
