#ifndef PILHA_H
#define PILHA_H

// Uma pilha de ints para a variação não-recursiva do quicksort.
class Pilha {
private:
    const int capacidade;
    int* array;
    int topo;

public:
    Pilha(int capacidade);
    ~Pilha();
    void push(int elemento);
    int pop();
    int num_elementos();
};

#endif
