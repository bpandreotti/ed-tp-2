#include "quicksort.h"

Resultado Quicksort::classico(int* vetor, int n, EscolhaPivo escolha_pivo) {
    auto res = Resultado();
    res.iniciar_timer();
    contador_t contador = Quicksort::_classico(vetor, 0, n - 1, escolha_pivo);
    res.parar_timer();
    res.set_contagem(contador);
    return res;
}

int Quicksort::_mediana_de_tres(int a, int b, int c, contador_t& contador) {
    // Não é a mais eficiente ou elegante das implementações, mas funciona.
    contador._num_comparacoes += 2; // `if` externo e primeiro `if` interno.
    if (a >= b) {
        if (c >= a) return a; // c >= a >= b
        contador._num_comparacoes++; // Se não retornou até aqui, mais uma comparação será feita.
        if (b >= c) return b; // a >= b >= c
        return c; // a > c > b
    } else {
        if (c >= b) return b; // c >= b > a
        contador._num_comparacoes++;
        if (a >= c) return a; // b > a >= c
        return c; // a > c > b
    }
}

contador_t Quicksort::_classico(int* vetor, int esq, int dir, EscolhaPivo escolha_pivo) {
    contador_t contador;
    int i, j;
    int pivo = -1;
    switch (escolha_pivo) {
        case EscolhaPivo::central:
            pivo = vetor[(esq + dir) / 2];
            break;
        case EscolhaPivo::primeiro:
            pivo = vetor[esq];
            break;
        case EscolhaPivo::mediana_de_tres:
            pivo = Quicksort::_mediana_de_tres(
                vetor[esq],
                vetor[(esq + dir) / 2],
                vetor[dir],
                contador
            );
            break;
        default:
            throw; // Escolha de pivô inválida
            break;
    }

    contador += Quicksort::_particao(vetor, esq, dir, i, j, pivo);
    if (esq < j)
        contador += Quicksort::_classico(vetor, esq, j, escolha_pivo);
    if (dir > i)
        contador += Quicksort::_classico(vetor, i, dir, escolha_pivo);
    
    return contador;
}

contador_t Quicksort::_particao(int* vetor, int esq, int dir, int& i, int& j, int pivo) {
    contador_t contador;
    i = esq; j = dir;

    do {
        while (vetor[i] < pivo) {
            i++; // Encontra o primeiro elemento que é >= ao pivô.
            contador._num_comparacoes++;
        }

        while (vetor[j] > pivo) {
            j--; // Encontra o primeiro elemento que é <= ao pivô.
            contador._num_comparacoes++;
        }

        // Compensando, porque os whiles incrementam uma vez a menos.
        contador._num_comparacoes += 2;

        // Troca esses dois elementos, mas apenas se os indíces `i` e `j` ainda não tiverem se
        // cruzado.
        if (i <= j) {
            int tmp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = tmp;
            // Considerando troca como duas movimentações. Vide documentação.
            contador._num_movimentacoes += 2;

            i++; j--;
        }
    } while (i <= j);

    return contador;
}
