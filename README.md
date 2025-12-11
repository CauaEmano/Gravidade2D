# Simulador Gravitacional 2D
Um motor de física modular escrito em C++ puro, simulando a interação gravitacional de N-corpos em tempo real. Este projeto implementa matemática vetorial personalizada e renderização gráfica via SFML.

##  Sobre o Projeto

Este simulador aplica a **Lei da Gravitação Universal de Newton** para calcular forças de atração mútua entre partículas. O objetivo principal foi criar uma arquitetura modular e orientada a objetos, separando a lógica matemática, a física e a renderização.

### Funcionalidades

  * **Motor de Física Personalizado:** Cálculo de forças, aceleração e velocidade vetorial.
  * **Matemática Vetorial:** Biblioteca `Vetor2D` própria (soma, subtração, produto escalar, normalização, magnitude).
  * **Sistema de Órbita:** Simulação estável de sistemas planetários (ex: Sol e Terra).
  * **Câmera Relativa:** Sistema de visualização fixado no corpo mais massivo (Referencial Inercial).
  * **Renderização:** Interface gráfica utilizando **SFML**.

##  Tecnologias Utilizadas

  * **C++:** Linguagem principal (foco em POO e gerenciamento de memória).
  * **SFML (Simple and Fast Multimedia Library):** Para janelas e gráficos 2D.
  * **GCC/G++:** Compilador.

##  Estrutura do Código

O projeto segue princípios de modularização:

  * `Vetor_2D.hpp/cpp`: A "ferramenta matemática". Define a estrutura vetorial e sobrecarga de operadores (+, -, \*).
  * `Particulas.hpp/cpp`: O "objeto físico". Gerencia posição, massa, velocidade e aplicação de forças ($F = ma$).
  * `main.cpp`: O "gerente". Controla o Game Loop, input do usuário, integração das forças e renderização.

##  Como Rodar

### Pré-requisitos (Linux/Ubuntu)

Você precisa ter o compilador G++ e a biblioteca SFML instalados:

```bash
sudo apt-get update
sudo apt-get install g++ libsfml-dev
```

### Compilação e Execução

Clone este repositório e navegue até a pasta. Compile o projeto linkando as bibliotecas do SFML:

```bash
g++ main.cpp Particulas.cpp Vetor_2D.cpp -o simulando -lsfml-graphics -lsfml-window -lsfml-system
```

Para rodar a simulação:

```bash
./simulando
```

## A Física por trás

A cada quadro (frame), o simulador realiza os seguintes passos:

1.  **Zera a aceleração** de todas as partículas.
2.  Calcula a força gravitacional entre cada par de partículas usando:
    $$F = G \frac{m_1 m_2}{r^2}$$
3.  Aplica a Segunda Lei de Newton para encontrar a aceleração:
    $$\vec{a} = \frac{\vec{F}}{m}$$
4.  Atualiza a velocidade e a posição (Integração de Euler).

## Próximos Passos (Roadmap)

  * [ ] Adicionar colisão elástica (as partículas quicam ao bater).
  * [ ] Criar um gerador aleatório de planetas.
  * [ ] Implementar rastro visual (trilha) por onde o planeta passou.

-----

**Autor:** [Seu Nome Aqui]
*Desenvolvido como estudo de Física Computacional e C++.*