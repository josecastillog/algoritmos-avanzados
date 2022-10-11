/**
 * Jose M. Castillo A01284149
 * Omar Lopez A01284179
 * Natalia Gonzalez A01283809
 *
 * Complejidades:
 * Dijkstra: O(|V|+|E|log|V|)
 * Floyd-Warshall: O(n^3)
 **/

/**
 * Ejemplo que implementa Grafos dirigidos ponderados con una
 * Lista de adyacencia y los algoritmos DFS y BFS
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
using namespace std;
#include <sstream>

int main() {
  // std::cout << "Ejemplo de grafos (representacion y recorridos)!" << std::endl;
  std::stringstream inputInfo;
  inputInfo << std::cin.rdbuf();

  int N, M;
  cin >> N;
  cin >> M;

  // Construye un grafo a partir de la consola usando
  // representacion de Lista de adyacencia
  Graph g1;
  g1.readGraph(inputInfo);
  // g1.print();
  // g1.DFS(1);
  // g1.BFS(1);
  g1.Dijkstra(1);
  g1.FloydWarshall();
}