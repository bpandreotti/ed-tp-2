#ifndef RESULTADO_H
#define RESULTADO_H

#include <chrono>

// Struct para contar o número de comparações e de movimentações de um teste.
struct contador_t {
    long int _num_comparacoes;
    long int _num_movimentacoes;

    contador_t();
    contador_t& operator+=(const contador_t& outro);
};

// Uma classe para armazenar os resultados de um teste. Contabiliza o número de comparações, o 
// número de movimentações, e o tempo decorrido. O timer deve ser iniciado com o método
// `Resultado::iniciar_timer`, e interrompido com `Resultado::parar_timer`. As contagens devem ser
// feitas usando o struct `contador_t`, e carregadas com o método `Resultado::set_contagem`.
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
