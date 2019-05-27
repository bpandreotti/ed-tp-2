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
    
    int* aleatorio = GeradorVetor::aleatorio(10, 100);
    int* cresc = GeradorVetor::crescente(10);
    int* decresc = GeradorVetor::decrescente(10);
    print_vetor(aleatorio, 10);
    print_vetor(cresc, 10);
    print_vetor(decresc, 10);
    
    return 0;
}
