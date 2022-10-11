#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <list>

class Graph {
private:
  int numNodes;
  int numEdges;
  // Lista de adyacencia
  // vector de sets (vertice)
  std::vector<std::set<int>> adjList;
  // vector de pares (grado, vertice)
  std::vector<std::pair<int, int>> grados;
  
  void split(std::string line, std::vector<int> &res);
  
public:
  Graph();
  ~Graph();
  void readGraph(std::istream &input);
  void print();
  bool grafoBiparita();
};


#endif // _GRAPH_H_