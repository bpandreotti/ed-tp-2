#include <iostream>
#include "quicksort.h"
#include "resultado.h"

void print_vetor(int* vetor, int n) {
    std::cout << "[";
    for (int i = 0; i < n - 1; i++) {
        std::cout << vetor[i] << ", ";
    }
    std::cout << vetor[n - 1] << "]" << std::endl;
}

int main(int argc, char* argv[]) {
    std::cout << "Hello, world!" << std::endl;

    int* vetor = new int[10] { 8, 7, 1, 3, 4, 9, 6, 5, 0, 2 };
    print_vetor(vetor, 10);
    auto resultado = Quicksort::classico(vetor, 10);
    print_vetor(vetor, 10);
    std::cout << resultado.get_num_comparacoes() << " comparações" << std::endl;
    std::cout << resultado.get_num_movimentacoes() << " movimentações" << std::endl;
    return 0;
}
