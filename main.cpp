#include <cmath>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Vetor_2D.hpp"
#include "Particulas.hpp"

using namespace std;

int main()
{
    sf::RenderWindow janela(sf::VideoMode(800, 600), "Simulacao Gravitacional - Orbita");
    janela.setFramerateLimit(60);

    vector<Particula> particulas;

    Particula sol(0, 0, 10000);
    particulas.push_back(sol);

    Particula terra(200, 0, 100);

    terra.setVelocidade(0, 5.0);
    particulas.push_back(terra);

    sf::CircleShape formaSol(15.f);
    formaSol.setFillColor(sf::Color::Yellow);
    formaSol.setOrigin(15.f, 15.f);

    sf::CircleShape formaTerra(5.f);
    formaTerra.setFillColor(sf::Color::Cyan);
    formaTerra.setOrigin(5.f, 5.f);

    int tamanho = particulas.size();

    while (janela.isOpen())
    {

        sf::Event event;
        while (janela.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                janela.close();
        }

        for (int l = 0; l < tamanho; l++)
            particulas[l].zerarAceleracao();

        for (int i = 0; i < tamanho; i++)
        {
            for (int j = 0; j < tamanho; j++)
            {
                if (i == j)
                    continue;

                Vetor2D vetor_distancia = particulas[j].get_posicao() - particulas[i].get_posicao();
                float dist = vetor_distancia.magnitude();

                if (dist < 5.0f)
                    continue;

                float massas = particulas[i].get_massa() * particulas[j].get_massa();

                float forca_mag = 0.5f * (massas / pow(dist, 2));

                Vetor2D forca = vetor_distancia.normalize() * forca_mag;
                particulas[i].aplicarForca(forca);
            }
        }

        for (int c = 0; c < tamanho; c++)
            particulas[c].movimentar();
        janela.clear();

        Vetor2D posicaoCamera = particulas[0].get_posicao();

        for (int k = 0; k < tamanho; k++)
        {
            Vetor2D posRelativa = particulas[k].get_posicao() - posicaoCamera;

            float x_tela = 400 + posRelativa.get_x();
            float y_tela = 300 + posRelativa.get_y();

            if (k == 0)
            {
                formaSol.setPosition(x_tela, y_tela);
                janela.draw(formaSol);
            }
            else
            {
                formaTerra.setPosition(x_tela, y_tela);
                janela.draw(formaTerra);
            }
        }
        janela.display();
    }

    return 0;
}