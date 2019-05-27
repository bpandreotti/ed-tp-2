#include <iostream>
#include "quicksort.h"
#include "resultado.h"
#include "gerador_vetor.h"

void print_vetor(int* vetor, int n) {
    std::cout << "[";
    for (int i = 0; i < n - 1; i++) {
        std::cout << vetor[i] << ", ";
    }
    std::cout << vetor[n - 1] << "]" << std::endl;
}

int main(int argc, char* argv[]) {

    int* vetor = GeradorVetor::aleatorio(10000000, 10000000);
    auto resultado = Quicksort::classico(vetor, 10000000);

    print_vetor(vetor, 50);
    std::cout << resultado.get_num_comparacoes() << " comparações | "
              << resultado.get_num_movimentacoes() << " movimentações | "
              << resultado.get_tempo_microseg() << " µs " << std::endl;
    
    return 0;
}
