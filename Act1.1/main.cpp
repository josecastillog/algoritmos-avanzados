// Actividad 1.1
// Mergesort
// Jose M. Castillo A01284149
// Omar Lopez A01284179

#include <iostream>
#include <vector>
using namespace std;

// Comlejidad: O(n) 
void merge(vector<double> &vec, int ini, int mit, int fin) {
  vector<double> aux(vec.size());
  int i=ini, j=mit+1, k=ini;
  while(i<=mit && j<=fin) {
    if (vec[i] >= vec[j]) {
      aux[k++] = vec[i++];
    }
    else {
      aux[k++] = vec[j++];
    }
  }
  if(i>mit) {
    for(int a=j; a<=fin; a++) {
      aux[k++] = vec[a];
    }
  }
  else {
    for (int a=i; a<=mit; a++) {
      aux[k++] = vec[a];
    }
  }
  for(int a=ini; a<=fin; a++) {
    vec[a] = aux[a];
  }
}

// Complejidad: O(n log n)
void mergeSort(vector<double> &vec, int ini, int fin) {
  if (ini < fin) {
    int mit = (ini+fin)/2;
    mergeSort(vec, ini, mit);
    mergeSort(vec, mit+1, fin);
    merge(vec, ini, mit, fin);
  }
}

// Complejidad O(n)
void print(vector<double> &vec, int n) {
  // Imprime arreglo ordenado
  for (int i=0; i<n; i++) {
    cout << vec[i] << endl;
  }
}

int main() {

  int n, busSec, pos;
  double dato;
  vector<double> vec;

  cin >> n;
  for (int i=0; i<n; i++) {
      cin >> dato;
      vec.push_back(dato);
  }

  mergeSort(vec, 0, n-1);
  print(vec, n);

}