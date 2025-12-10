#include "Vetor_2D.hpp"
#include "Particulas.hpp"

using namespace std;

Particula::Particula(float x, float y, float massa_inicial) : posicao(x, y), massa(massa_inicial), velocidade(0, 0), aceleracao(0, 0) {}

void Particula::movimentar()
{
    velocidade = velocidade + aceleracao;
    posicao = velocidade + posicao;
}

void Particula::aplicarForca(const Vetor2D &forca)
{
    aceleracao = aceleracao + forca * (1 / massa);
}

Vetor2D Particula::get_posicao() const
{
    return posicao;
}

float Particula::get_massa() const
{
    return massa;
}

void Particula::zerarAceleracao()
{
    Vetor2D ace_zero(0, 0);
    aceleracao = ace_zero;
}