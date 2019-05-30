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
    auto p = Pilha(4);

    p.push(1);
    p.push(2);
    p.push(3);
    p.push(4);

    std::cout << p.pop() << " "
              << p.pop() << " "
              << p.pop() << " "
              << p.pop() << std::endl;

    p.pop(); // Should throw

    //  std::cout << resultado.get_num_comparacoes() << " comparações | "
    //            << resultado.get_num_movimentacoes() << " movimentações | "
    //            << resultado.get_tempo_microseg() << " µs " << std::endl;
    
    return 0;
}
