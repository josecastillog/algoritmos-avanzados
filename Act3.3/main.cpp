/**
 * Jose M. Castillo A01284149
 * Omar Lopez A01284179
 * Natalia Gonzalez A01283809
 *
 * Complejidades:
 * grafoBiparita() = O(V+E)
 **/

/**
 * Ejemplo que implementa Grafos no dirigidos con una
 * Lista de adyacencia
 *
 * Compilacion para debug:
 *    g++ -std=c++17 -g -o main *.cpp
 * Ejecucion con valgrind:
 *    nix-env -iA nixpkgs.valgrind
 *    valgrind --leak-check=full ./main < TestCases/test01.txt
 *
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -O3 -o main *.cpp
 * Ejecucion:
 *    ./main < TestCases/test01.txt
 **/

#include "Graph.h"
#include <iostream>

int main() {
    std::stringstream inputInfo;
    inputInfo << std::cin.rdbuf();
    // Construye un grafo a partir de la consola usando
    // representacion de Lista de adyacencia
    Graph g1;
    // Lee sin ignorar primera linea, por los casos de prueba dados
    g1.readGraph(inputInfo);
    // Regresa true si grafo es biparita o false de lo contrario
    std::cout << std::boolalpha << g1.grafoBiparita() << std::endl;
}