#include "Graph.h"

Graph::Graph() {
  numNodes = 0;
  numEdges = 0;
}

Graph::~Graph() {
  adjList.clear();
  grados.clear();
  numNodes = 0;
  numEdges = 0;
}

void Graph::split(std::string line, std::vector<int> &res) {
    size_t strPos = line.find(" ");
    size_t lastPos = 0;
    while (strPos != std::string::npos) {
      res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
      lastPos = strPos + 1;
      strPos = line.find(" ", lastPos);
    }
    res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

void Graph::readGraph(std::istream &input) {
  std::string line;
  int i = 1; // i=0 para ignorar primera linea
  while (std::getline(input, line)) {
    // if (i == 0) { // Ignorar primera linea de texto
    //   i++;
    //   continue;
    // }
    if (i == 1) {
      std::vector<int> res;
      split(line, res);
      numNodes = res[0];
      numEdges = res[2];
      // Reservar memoria para los renglones 
      // de la lista de adyacencia (renglon 0 no utilizado) 
      adjList.resize(numNodes+1);
      grados.resize(numNodes+1);
      // Declara una lista vacia para cada renglon y 
      // la almacena en el vector
      for (int k = 0; k <= numNodes; k++) {
        std::set<int> tmpSet; // set de int (vertices)
        adjList[k] = tmpSet;
        // Inicializa los pares (grado, vertice)
        grados[k].first = 0;
        grados[k].second = k;
      }
      i++;
      continue; 
    }
    std::vector<int> res;
    split(line, res);
    int u = res[0];
    int v = res[1];
    // Grafos no dirigidos agrega la arista (u,v) y la (v,u)
    adjList[u].insert(v);
    adjList[v].insert(u);
    // El vertice u tiene una arista mas (u,v)
    grados[u].first++;
    // El vertice v tiene una arista mas (v,u)
    grados[v].first++;
    i++;
  }
}

void Graph::print() {
  std::cout << "Adjacency List" << std::endl;
  for (int u = 1; u <= numNodes; u++){
    std::cout << "vertex " << u << ":";
    std::set<int> g = adjList[u];
    std::set<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it) {
      int w = *it;
      std::cout << '\t' << w << ",";
    }
    std::cout << std::endl;
  }
}

bool Graph::grafoBiparita() {
  // vector para almacenar colores
  // iniciando con -1
  // los colores son 0 o 1
  std::vector<int> col(numNodes+1, -1);

  // queue como BFS {vertice , color}
  std::queue<std::pair<int, int>> q;

  // loop, asegura si el grafo no esta conectado
  for (int i = 1; i <= numNodes; i++) {

    // si no esta coloreado
    if (col[i] == -1) {

      // colorear con 0
      q.push({i, 0});
      col[i] = 0;

      while (!q.empty()) {
        std::pair<int, int> p = q.front();
        q.pop();

        // vertice actual
        int v = p.first;
        // color de vertice actual
        int c = p.second;

        // Recorrer lista de adjaencia en nodo
        std::set<int> g = adjList[v];
        std::set<int>::iterator it;
        for (it = g.begin(); it != g.end(); ++it) {
          int w = *it;
          // si ya esta coloreada con el color del padre
          // la biparita no es posible, regresa false.
          if (col[w] == c)
            return 0;

          // si no esta coloreada
          if (col[w] == -1) {
            // colorear con el opuesto al padre
            col[w] = (c) ? 0 : 1;
            q.push({w, col[w]});
          }
        }
      }
    }
  }
  // si todas estan coloreadas correctamente
  return 1;
}