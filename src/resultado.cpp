#include "resultado.h"

contador_t::contador_t() {
    this->_num_comparacoes = 0;
    this->_num_movimentacoes = 0;
}

contador_t& contador_t::operator+=(const contador_t& outro) {
    this->_num_comparacoes += outro._num_comparacoes;
    this->_num_movimentacoes += outro._num_movimentacoes;
    return *this;
}

Resultado::Resultado() {
    this->_num_comparacoes = 0;
    this->_num_movimentacoes = 0;
    this->_tempo_microseg = 0.0;
}

void Resultado::set_contagem(const contador_t& contador) {
    this->_num_comparacoes = contador._num_comparacoes;
    this->_num_movimentacoes = contador._num_movimentacoes;
}

int Resultado::get_num_comparacoes() {
    return this->_num_comparacoes;
}
int Resultado::get_num_movimentacoes() {
    return this->_num_movimentacoes;
}