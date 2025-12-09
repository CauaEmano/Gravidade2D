#include <vector>
#include "Vetor_2D.hpp"

using namespace std;

class Particula{
private:
    Vetor2D posicao;
    Vetor2D velocidade;
    Vetor2D aceleracao;
    float massa;
};

int main(){

    vector<Particula> particulas;

    int tamanho = particulas.size();
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            if (i == j){
                continue;
            }
            //Vetor2D vetor_distancia = particulas[j].posicao - particulas[i].posicao;
            //Resto do código
        }
    }

    return 0;
}