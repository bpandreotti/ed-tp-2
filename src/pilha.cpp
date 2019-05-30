#include "pilha.h"
#include <stdexcept>

Pilha::Pilha(int capacidade): capacidade(capacidade) {
    this->array = new int[capacidade];
    this->topo = 0;
}

Pilha::~Pilha() {
    delete[] this->array;
}

void Pilha::push(int elemento) {
    if (this->topo == this->capacidade)
        throw std::length_error("Pilha cheia!");

    this->array[this->topo] = elemento;
    this->topo++;
}

int Pilha::pop() {
    if (this->topo == 0)
        throw std::length_error("Pilha vazia!");

    this->topo--;
    return this->array[this->topo];
}

int Pilha::num_elementos() {
    return this->topo;
}