#ifndef RESULTADO_H
#define RESULTADO_H

#include <chrono>

struct contador_t {
    long int _num_comparacoes;
    long int _num_movimentacoes;

    contador_t();
    contador_t& operator+=(const contador_t& outro);
};

class Resultado {
private:
    long int _num_comparacoes;
    long int _num_movimentacoes;
    std::chrono::system_clock::time_point _inicio_timer;
    std::chrono::duration<double> _duracao_timer;

public:
    Resultado();
    void iniciar_timer();
    void parar_timer();
    void set_contagem(const contador_t& contador);
    long int get_num_comparacoes();
    long int get_num_movimentacoes();
    long int get_tempo_microseg();
};


#endif
