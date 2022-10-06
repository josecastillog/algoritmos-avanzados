#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

// MAX INT
#define INF 0x3f3f3f3f

class Graph {
private:
  int numNodes;
  int numEdges;
  // Lista de adyacencia
  // vector de listas ligadas de pares (vertice, peso)
  std::vector<std::list<std::pair<int, int>>> adjList;

  void split(std::string line, std::vector<int> &res);

  // Construir matriz de adyacencia
  std::vector<std::vector<int>> listToMatrix();
  // Imprimir solucion Floyd-Warshall
  void printSolution(std::vector<std::vector<int>> &sol);

public:
  Graph();
  ~Graph();
  void readGraph(std::istream &input);
  void print();
  void DFS(int v);
  void BFS(int v);
  // Dijkstra
  void Dijkstra(int src);
  // Floyd-Warshall
  void FloydWarshall();
};

#endif // _GRAPH_H_