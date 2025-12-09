#ifndef VETOR_2D_HPP
#define VETOR_2D_HPP

#include <iostream>

using namespace std;

struct Vetor2D{
private:
    float x;
    float y;
    
public:
    Vetor2D(float x, float y);
    float get_x() const;
    float get_y() const;

    Vetor2D operator+ (const Vetor2D& v2) const;

    Vetor2D operator* (const float m) const;
    
    float dot(const Vetor2D& v2) const;

    float magnitude () const;
    
    Vetor2D normalize () const;

    float angulo(const Vetor2D& v2) const;
};
ostream& operator<< (ostream& saida, const Vetor2D& valor);

#endif 