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
#include <iostream>
// #include <iomanip>
#include "trie.h"

int main() {
  // trie T;
  // std::cout << "Insert: hola, holamundo y ab" << std::endl;
  // T.insert("hola");
  // T.insert("holamundo");
  // T.insert("ab");
  
  // T.dfs();
  // std::cout << "search(hola) " << std::boolalpha << T.search("hola") << std::endl;
  // std::cout << "search(hole) " << std::boolalpha << T.search("hole") << std::endl;
  // std::cout << "search(holamundo) " << std::boolalpha << T.search("holamundo") << std::endl;
  // std::cout << "search(holam) " << std::boolalpha << T.search("holam") << std::endl;
  // std::cout << "search(ab) " << std::boolalpha << T.search("ab") << std::endl;

  trie T;
  int N, M;
  std::string in;

  std::cin >> N;
  for (int i=0; i<N; i++) {
    std::cin >> in;
    T.insert(in);
  }

  T.dfs();

  std::cin >> M;
  for (int i=0; i<M; i++) {
    std::cin >> in;
    std::cout << std::boolalpha << T.search(in) << std::endl;
  }

  return 0;
}