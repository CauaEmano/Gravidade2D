#include <iostream>
#include <cmath>
#include "Vetor_2D.hpp"

using namespace std;

Vetor2D::Vetor2D(float x, float y) : x(x), y(y) {} // Constructor

float Vetor2D::get_x() const
{
    return x; // Pegar o x
}
float Vetor2D::get_y() const
{
    return y; // pegar o y
}

Vetor2D Vetor2D::operator+(const Vetor2D &v2) const
{ // Fzr soma vetorial e guarda
    float y_vetor_novo = y + v2.get_y();
    float x_vetor_novo = x + v2.get_x();
    return Vetor2D(x_vetor_novo, y_vetor_novo);
}

Vetor2D Vetor2D::operator-(const Vetor2D &v2) const
{
    float y_vetor_novo = y - v2.get_y();
    float x_vetor_novo = x - v2.get_x();
    return Vetor2D(x_vetor_novo, y_vetor_novo);
}

Vetor2D Vetor2D::operator*(const float m) const
{ // Fzr multiplicação vetorial
    float y_vetor_novo = y * m;
    float x_vetor_novo = x * m;
    return Vetor2D(x_vetor_novo, y_vetor_novo);
}

float Vetor2D::dot(const Vetor2D &v2) const
{ // Produto escalar
    return (x * v2.get_x()) + (y * v2.get_y());
}

float Vetor2D::magnitude() const
{ // Calcula a maginitude do vetor
    return sqrt(pow(x, 2) + pow(y, 2));
}

Vetor2D Vetor2D::normalize() const
{ // Normalizando o vetor
    float mag = magnitude();
    return Vetor2D(x / mag, y / mag);
}

float Vetor2D::angulo(const Vetor2D &v2) const
{ // Extraindo o ângulo
    float produto_escalar = dot(v2);
    float mag = magnitude();
    float mag2 = v2.magnitude();
    float produto_escalar_modulo = mag * mag2;
    float valor = acos(produto_escalar / produto_escalar_modulo);
    return valor * 180 / M_PI;
}

ostream &operator<<(ostream &saida, const Vetor2D &valor)
{
    return saida << '(' << valor.get_x() << ", " << valor.get_y() << ')';
}