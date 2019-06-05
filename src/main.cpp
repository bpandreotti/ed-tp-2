#include <iostream>
#include <stdexcept>
#include "quicksort.h"
#include "resultado.h"
#include "gerador_vetor.h"
#include "pilha.h"

void print_vetor(int* vetor, int n) {
    for (int i = 0; i < n - 1; i++) {
        std::cout << vetor[i] << " ";
    }
    std::cout << vetor[n - 1] << std::endl;
}

int* clonar(int* vetor, int n) {
    int* novo = new int[n];

    for (int i = 0; i < n; i++)
        novo[i] = vetor[i];

    return novo;
}

void realizar_teste(int n, std::string tipo_vetor, std::string tipo_algoritmo,  bool imprimir) {

    Resultado resultado;
    int* vetores[20];

    for (int i = 0; i < 20; i++) {
        int *vetor = nullptr;
        if (tipo_vetor == "Ale")
            vetor = GeradorVetor::aleatorio(n, n);
        else if (tipo_vetor == "OrdC")
            vetor = GeradorVetor::crescente(n);
        else if (tipo_vetor == "OrdD")
            vetor = GeradorVetor::decrescente(n);
        else
            throw std::invalid_argument("Tipo de vetor inválido!");

        // Armazenar o vetor original caso ele tenha que ser impresso.
        if (imprimir) 
            vetores[i] = clonar(vetor, n);

        if (tipo_algoritmo == "QC")
            resultado += Quicksort::classico(vetor, n, EscolhaPivo::central);
        else if (tipo_algoritmo == "QM3")
            resultado += Quicksort::classico(vetor, n, EscolhaPivo::mediana_de_tres);
        else if (tipo_algoritmo == "QPE")
            resultado += Quicksort::classico(vetor, n, EscolhaPivo::primeiro);
        else if (tipo_algoritmo == "QI1")
            resultado += Quicksort::com_insercao(vetor, n, 1);
        else if (tipo_algoritmo == "QI5")
            resultado += Quicksort::com_insercao(vetor, n, 5);
        else if (tipo_algoritmo == "QI10")
            resultado += Quicksort::com_insercao(vetor, n, 10);
        else if (tipo_algoritmo == "QNR")
            resultado += Quicksort::nao_recursivo(vetor, n);
        else
            throw std::invalid_argument("Algoritmo inválido!");

        delete[] vetor;
    }
    
    resultado /= 20;

    std::cout << tipo_algoritmo  << " " << tipo_vetor << " " << n << " "
              << resultado.get_num_comparacoes() << " "
              << resultado.get_num_movimentacoes() << " "
              << resultado.get_tempo_microseg() << std::endl;

    if (imprimir) {
        for (int i = 0; i < 20; i++) {
            print_vetor(vetores[i], n);
            delete[] vetores[i];
        }
    }
}

int main(int argc, char* argv[]) {
    
    if (argc < 4) {
        std::cerr << "Número de argumentos incorreto" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[3]);
    auto tipo_vetor = std::string(argv[2]);
    auto tipo_algoritmo = std::string(argv[1]);
    //TODO: implementar argumento opcional "-p"
    bool imprimir = (argc >= 5 && std::string(argv[4]) == "-p");

    realizar_teste(n, tipo_vetor, tipo_algoritmo, imprimir);

    return 0;
}
