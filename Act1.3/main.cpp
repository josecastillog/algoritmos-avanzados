// Actividad 1.3
// Implementación de la técnica de programación "backtracking" y "ramificación y poda"
// Jose M. Castillo A01284149
// Omar Lopez A01284179

// Recursos utilizados:
// https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/
// https://ocw.snu.ac.kr/sites/default/files/NOTE/498.pdf

// Complejidades
// Backtracking = O(2^(n^2))
// Ramificacion y Poda = O(n^2)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Variables Globales
int M = 0;
int N = 0;
int default_value = 0;

// Imprime matriz
void printMaze(vector<vector<int> > &maze) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

/* ------------ Backtracking ------------ */

// Checar si x, y son indice valido para la matriz maze
bool isSafe(vector<vector<int> > &maze, int x, int y) {
    if (x >= 0 && x < M && y >= 0 && y < N && maze[x][y] == 1)
        return true;
    return false;
}

// Funcion recursiva para resolver maze complejidad O(2^(n^2))
bool solveMazeUtil(vector<vector<int> > &maze, int x, int y, vector<vector<int> > &sol) {
    // Si x,y es objetivo, regresa true
    if (x == M - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }
    // Checar si maze[x][y] es valido
    if (isSafe(maze, x, y) == true) {
        // Checar si el bloque actual ya es parte de la solucion
        if (sol[x][y] == 1)
            return false;
        // marcar x, y como parte de la solucion
        sol[x][y] = 1;
        // Mover de direccion en x
        if (solveMazeUtil(maze, x + 1, y, sol) == true)
            return true;
        // Si no hay solucion moviendo en x
        // mover en y
        if (solveMazeUtil(maze, x, y + 1, sol) == true)
            return true;
        // Si niguno de los anteriores funciona
        // BACKTRACK: desmarcar x, y como parte de la solucion.
        sol[x][y] = 0;
        return false;
    }
    return false;
}

bool solveMazeBT(vector<vector<int> > &maze) {
    vector<vector<int> > sol(M, vector<int>(N, default_value));
    if (solveMazeUtil(maze, 0, 0, sol) == false) {
        cout << "No hay solucion" << endl;
        return false;
    }
    printMaze(sol);
    return true;
}

/* ------------ Ramificación y Poda ------------ */

// Utilizado en la queue
struct Node {
    int i;
    int j;
    Node *prev;
};

// Resuelve Maze con complejidad O(n^2)
void solveMazeBB(vector<vector<int> > &maze) {

    queue<Node> q;
    int i, j;
    Node current;
    
    current.i = 0;
    current.j = 0;
    current.prev = nullptr;
    q.push(current);

    while(true) {

        // Cargar siguiente en la fila
        i = q.front().i;
        j = q.front().j;

        // Guardar nodo previo
        Node *tmp = new Node;
        *tmp = q.front();

        // Si la queue esta vacia y no en objetivo, no hay solucion
        if (q.empty() && i != M - 1 && j != N - 1) {
            cout << "No hay solucion" << endl;
            return;
        }
        // Si current es objectivo sale del ciclo
        if (i == M - 1 && j == N - 1) {
            break;
        }
        // Busca bloque abajo del current
        if (isSafe(maze, i, j+1) && maze[i][j+1] == 1) { 
            current.i = i;
            current.j = j + 1;
            current.prev = tmp;
            q.push(current);
        }
        // Busca bloque a la derecha de current
        if (isSafe(maze, i+1, j) && maze[i+1][j] == 1) {
            current.i = i + 1;
            current.j = j;
            current.prev = tmp;
            q.push(current);
        }

        // Sacar nodo de queue
        q.pop();

    }

    // Construye matriz de soulucion
    vector<vector<int> > sol(M, vector<int>(N, default_value));
    while (current.prev != nullptr) {
        sol[current.i][current.j] = 1;
        current = *current.prev;
    }
    sol[current.i][current.j] = 1;
    
    // Imprime solucion
    printMaze(sol);

}

int main() {

    // M = numero de filas
    cin >> M;
    // N = numero de columnas
    cin >> N;

    // Vector de vectores de int
    vector<vector<int> > maze(M, vector<int>(N, default_value));

    // Entrada estandar
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    }

    // Resolver maze Back Tracking
    solveMazeBT(maze);
    cout << endl;
    // Resolver maze ramificacion y poda
    solveMazeBB(maze);

}