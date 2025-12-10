#ifndef PARTICULAS_HPP
#define PARTICULAS_HPP

#include "Vetor_2D.hpp"

class Particula
{

private:
    Vetor2D posicao;
    Vetor2D velocidade;
    Vetor2D aceleracao;
    float massa;

public:
    Particula(float x, float y, float massa);

    void movimentar();
    void aplicarForca(const Vetor2D &forca);

    Vetor2D get_posicao() const;
    float get_massa() const;

    void zerarAceleracao();
};

#endif