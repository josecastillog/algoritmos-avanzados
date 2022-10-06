/**
 * Ejemplo que implementa un Trie (Arbol de prefijos)
 *
 * Compilacion para debug:
 *    g++ -std=c++17 -g -o main *.cpp
 * Ejecucion con valgrind:
 *    nix-env -iA nixpkgs.valgrind
 *    valgrind --leak-check=full ./main
 *
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -O3 -o main *.cpp
 * Ejecucion:
 *    ./main
 **/

/**
 * Jose M. Castillo A01284149
 * Omar Lopez A01284179
 * Natalia Gonzalez A01283809
 *
 * Complejidades:
 * DFS: O(n)
 * Destructor: O(n)
 **/

#include <iostream>
// #include <iomanip>
#include "trie.h"

int main() {

  trie T;
  int N, M;
  std::string in;

  N = 0;
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> in;
    T.insert(in);
  }

  T.dfs();

  M = 0;
  std::cin >> M;
  for (int i = 0; i < M; i++) {
    std::cin >> in;
    std::cout << std::boolalpha << T.search(in) << std::endl;
  }

  return 0;
}