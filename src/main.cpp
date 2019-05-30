#include <iostream>
#include "quicksort.h"
#include "resultado.h"
#include "gerador_vetor.h"
#include "pilha.h"

void print_vetor(int* vetor, int n) {
    std::cout << "[";
    for (int i = 0; i < n - 1; i++) {
        std::cout << vetor[i] << ", ";
    }
    std::cout << vetor[n - 1] << "]" << std::endl;
}

int main(int argc, char* argv[]) {
    
    int* vetor = GeradorVetor::aleatorio(100, 200);
    print_vetor(vetor, 20);
    auto resultado = Quicksort::nao_recursivo(vetor, 100);
    print_vetor(vetor, 20);

    std::cout << resultado.get_num_comparacoes() << " comparações | "
              << resultado.get_num_movimentacoes() << " movimentações | "
              << resultado.get_tempo_microseg() << " µs " << std::endl;
    
    return 0;
}
