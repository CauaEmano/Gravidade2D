#include <cmath>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Vetor_2D.hpp"
#include "Particulas.hpp"

int main()
{
    vector<Particula> particulas;
    particulas.push_back(Particula(0, 0, pow(10, 10)));
    particulas.push_back(Particula(9, -6, pow(10, 3)));

    int tamanho = particulas.size();
    while (true)
    {
        for (int l = 0; l < tamanho; l++)
        { // zerar acelerações
            particulas[l].zerarAceleracao();
        }

        for (int i = 0; i < tamanho; i++)
        { // Calcular forças entre particulas
            for (int j = 0; j < tamanho; j++)
            {
                if (i == j)
                {
                    continue;
                }

                Vetor2D vetor_distancia = particulas[j].get_posicao() - particulas[i].get_posicao(); // Pegando a distância entre as partículas
                float massas_multiplicadas = particulas[i].get_massa() * particulas[j].get_massa();  // Pegando a mul das massas
                float GxMs_d = 0.5f * (massas_multiplicadas / pow(vetor_distancia.magnitude(), 2));  // Fórmula da gravitação universal
                Vetor2D forca = vetor_distancia.normalize() * GxMs_d;                                // Aplicando ao vetor normalizado
                particulas[i].aplicarForca(forca);                                                   // Aplicando força à particula em análise
            }
        }

        for (int c = 0; c < tamanho; c++)
        { // Mover as partículas
            particulas[c].movimentar();
            cout << particulas[1].get_posicao();
        }
    }

    return 0;
}