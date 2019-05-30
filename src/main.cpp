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
    
    if (argc < 4) {
        std::cerr << "Número de argumentos incorreto" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[3]); 
    int *vetor = nullptr;
    
    std::string tipo_vetor(argv[2]);
    
    if (tipo_vetor == "Ale")
        vetor = GeradorVetor::aleatorio(n, 2 * n);
    else if (tipo_vetor == "OrdC")
        vetor = GeradorVetor::crescente(n);
    else if (tipo_vetor == "OrdD")
        vetor = GeradorVetor::decrescente(n);

    print_vetor(vetor, 20);

    Resultado resultado;
    
    std::string tipo_algoritmo(argv[1]);

    if (tipo_algoritmo == "QC")
        resultado = Quicksort::classico(vetor, n, EscolhaPivo::central);
    else if (tipo_algoritmo == "QM3")
        resultado = Quicksort::classico(vetor, n, EscolhaPivo::mediana_de_tres);
    else if (tipo_algoritmo == "QPE")
        resultado = Quicksort::classico(vetor, n, EscolhaPivo::primeiro);
    else if (tipo_algoritmo == "QI1")
        resultado = Quicksort::com_insercao(vetor, n, 1);
    else if (tipo_algoritmo == "QI5")
        resultado = Quicksort::com_insercao(vetor, n, 5);
    else if (tipo_algoritmo == "QI10")
        resultado = Quicksort::com_insercao(vetor, n, 10);
    else if (tipo_algoritmo == "QNR")
        resultado = Quicksort::nao_recursivo(vetor, n);

    print_vetor(vetor, 20);
    
    std::cout << resultado.get_num_comparacoes() << " comparações | "
              << resultado.get_num_movimentacoes() << " movimentações | "
              << resultado.get_tempo_microseg() << " µs " << std::endl;
    
    return 0;
}
