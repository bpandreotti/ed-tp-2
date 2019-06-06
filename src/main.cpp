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

    int* vetores[20];
    int tempos[20]; // Como desejamos calcular a mediana dos tempos, é necessário armazená-los

    long int total_comparacoes = 0;
    long int total_movimentacoes = 0;

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

        Resultado res;
        if (tipo_algoritmo == "QC")
            res = Quicksort::classico(vetor, n, EscolhaPivo::central);
        else if (tipo_algoritmo == "QM3")
            res = Quicksort::classico(vetor, n, EscolhaPivo::mediana_de_tres);
        else if (tipo_algoritmo == "QPE")
            res = Quicksort::classico(vetor, n, EscolhaPivo::primeiro);
        else if (tipo_algoritmo == "QI1")
            res = Quicksort::com_insercao(vetor, n, 1);
        else if (tipo_algoritmo == "QI5")
            res = Quicksort::com_insercao(vetor, n, 5);
        else if (tipo_algoritmo == "QI10")
            res = Quicksort::com_insercao(vetor, n, 10);
        else if (tipo_algoritmo == "QNR")
            res = Quicksort::nao_recursivo(vetor, n);
        else
            throw std::invalid_argument("Algoritmo inválido!");

        total_comparacoes += res.get_num_comparacoes();
        total_movimentacoes += res.get_num_movimentacoes();
        tempos[i] = (int)res.get_tempo_microseg();
        delete[] vetor;
    }
    
    // Para computar a mediana dos tempos, temos que ordenar o vetor. Felizmente, temos uma
    // variedade de algoritmos de ordenação implementados. No caso, escolhi o quicksort clássico.
    Quicksort::classico(tempos, 20, EscolhaPivo::central);
    int mediana_tempo = tempos[10];
    
    std::cout << tipo_algoritmo  << " " << tipo_vetor << " " << n << " "
              << (total_comparacoes / 20) << " "
              << (total_movimentacoes / 20) << " "
              << mediana_tempo << std::endl;

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
