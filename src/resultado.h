#ifndef RESULTADO_H
#define RESULTADO_H

struct contador_t {
    int _num_comparacoes;
    int _num_movimentacoes;

    contador_t();
    contador_t& operator+=(const contador_t& outro);
};

class Resultado {
private:
    int _num_comparacoes;
    int _num_movimentacoes;
    double _tempo_microseg; //TODO: implementar o timer.

public:
    Resultado();
    void set_contagem(const contador_t& contador);
    int get_num_comparacoes();
    int get_num_movimentacoes();
};

#endif
