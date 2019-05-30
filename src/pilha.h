#ifndef PILHA_H
#define PILHA_H

// Uma pilha de ints para a variação não-recursiva do quicksort. Talvez seja mais apropriado
// armazenar tuplas de dois ints, já que as elementos só serão colocados e retirados em pares.
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
