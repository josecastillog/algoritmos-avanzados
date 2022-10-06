/*
    Actividad 1.2 - Implementacion de la técnica de programacion "Programación dinamica" y "algoritmos avaros"

    Jose M. Castillo A01284149
    Omar Lopez A01284179

    El programa usa dos algoritmos para computar el menor cambio,
    uno avaro y otro dinamico.

    Se regresa una lista con N valores correspondientes al numero de monedas
    de cada denominacion. Si no hay solucion regresa -1.

    La primera lista es del algoritmo dinamico, la segunda es del avaro.

    Ambos algoritmos tienen una complejidad de O(n).
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Complejidad O(n)
void greedyChangeMaking(int n, int cambio, vector<int> &denom) {

    vector<int> resp;
    int counter = 0;

    for (int i = 0; i < n; i++) {
        counter = 0;
        while (cambio >= denom[i]) {
            cambio -= denom[i];
            counter++;
        }
        resp.push_back(counter);
    }
    
    // Imprime lista de N valores correspondientes 
    // al número de monedas de cada denominación
    if (cambio == 0) {
        for (int i = 0; i < resp.size(); i++)
            cout << resp[i] << endl;
    } else {
        cout << -1 << endl;
    }

}

// Complejidad O(n)
int changeMaking(vector<int>& denom, int cambio, vector<int>& dp) {

    cout << cambio << endl;

    if (cambio < 0) {
        return -1;
    }

    if (cambio == 0) {
        return 0;
    }

    if (dp[cambio] != 0) {
        return dp[cambio];
    }

    int minimum = INT_MAX;
    for (int i=0; i < denom.size(); i++) {
        int changeResult = changeMaking(denom, cambio - denom[i], dp);
        if (changeResult >= 0 && changeResult < minimum) {
            minimum = 1 + changeResult;
        }
    }

    if (minimum == INT_MAX)
        dp[cambio] = -1;
    else
        dp[cambio] = minimum;

    return dp[cambio];

}

// Complejidad O(n)
void dynamicChangeMaking(vector<int>& denom, int amount) {
    if (amount < 1) {
        cout << -1 << endl;
        return;
    }

    vector<int> dp(amount + 1);
    int mindenom = changeMaking(denom, amount, dp);

    // Backtrace computations con formula del libro
    // F(n) = min { F(n - dj)} + 1 for n > 0,
    // F(0) = 0
    int n = amount;
    int fn = mindenom;
    vector<int> resp(denom.size(), 0);
    for (int i=0; i<mindenom; i++) {
        for (int j=0; j<denom.size(); j++) {
            int index = n - denom[j];
            if (index >= 0 && dp[index] + 1 == fn) {
                resp[j] += 1;
                n -= denom[j];
                fn -= 1;
            }
        }
    }

    // Imprime lista de N valores correspondientes
    // al número de monedas de cada denominación
    // for (int i = 0; i < resp.size(); i++)
    //     cout << resp[i] << endl;

}

int main() {

    vector<int> denom;
    int n, dato, P, Q, cambio;

    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> dato;
        denom.push_back(dato);
    }

    cin >> P;
    cin >> Q;

    cambio = Q - P;
    
    cout << "Dynamic" << endl;
    dynamicChangeMaking(denom, cambio);
    cout << "Greedy" << endl;
    greedyChangeMaking(n, cambio, denom);

}