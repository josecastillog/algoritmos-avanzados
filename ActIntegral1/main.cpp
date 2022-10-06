#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> lps(string p){
    int n = p.length();
    vector<int> lpsv(n, 0);
    int j = 0, i = 1;
    while(i < n){
        if(p[i] == p[j]){
            lpsv[i] = j+1;
            i++;
            j++;
        }
        else{
            if(j==0){
                lpsv[i] = 0;
                i++;
            }
            else{
                j = lpsv[j-1];
            }
        }
    }
    return lpsv;
}

// Algoritmo Knuth-Morris-Pratt
// Complejidad O(n+k)
vector<int> kmp(string texto, string patron){
    vector<int> posMatch;
    vector<int> lpsv = lps(patron);
    int j=0, i=0;
    int n = texto.length();
    int m = patron.length();
    while(i<n){
        if (texto[i]==patron[j]){
            i++;
            j++;
            if(j == m){
                posMatch.push_back(i-m);
                j = lpsv[j-1];

            }
        }
        else{
            if(j==0){
                i++;
            }
            else{
                j = lpsv[j-1];
            }
        }
    }

    return posMatch;
}

string stringVector(vector<int> miVector){
    string res;
    for(int i =0; i<miVector.size(); i++){
        res = res + to_string(miVector[i]);
        if(i< miVector.size() - 1){
            res = res + " ";
        }
    }
    return res;
}

// Algoritmo de Manacher
// Complejidad O(n)
pair<int,int> manacher(string texto, string &retorno){
    int inicio;
	string T = "";
	int n = texto.length();
	for (int i=0; i<n; i++){
		T += "|";
		T += texto[i];
	}
	T += "|";
	n = T.length();
	vector<int> L(n);
	L[0] = 0;
	L[1] = 1;
	int maxLong=0, maxCentro=0;
	bool exp;
	for (int c=1, li=0, ri=2; ri<n; ri++){
		li = c-(ri-c);
		exp = false;
		if (c-maxLong <= ri && ri >= c+maxLong){
			if (L[li] < (c+L[c]-ri)){
				L[ri] = L[li];
			}
			else if(L[li] == (c + L[c]) - ri && (c + L[c]) == 2*n){
				L[ri] = L[li];
			}
			else if(L[li] == (c + L[c]) - ri && (c + L[c]) < 2*n){
				L[ri] = L[li];
				exp = true;
			}
			else if(L[li] > (c + L[c]) - ri && (c + L[c]) < 2*n){
				L[ri] = (c+L[c]) - ri;
				exp = true;
			}
		}
		else{
			L[ri] = 0;
			exp = true;
		}
		if (exp){
			while((ri + L[ri] < n) && (ri - L[ri] > 0) && (T[ri - L[ri] - 1] == T[ri + L[ri] + 1])){
				L[ri]++;
			}
		}
		c = ri;
		if (L[ri] > maxLong){
	    	maxLong = L[ri];
	    	maxCentro = ri;
	    }
	}
	inicio = (maxCentro - maxLong) / 2;
	string salida = "";
	for (int i=inicio; i<(inicio+maxLong); i++){
		salida+=texto[i];
	}
    retorno = salida;
    pair<int, int> result;
    result.first = inicio;
    result.second = maxLong;
	return result;
}

// Algoritmo Longest Common Substring
// Complejidad O(m*n)
string LCSubStr(string X, string Y, int m, int n){
    int LCSuff[m + 1][n + 1];
    int result = 0;
    int index = 0;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                if (LCSuff[i][j] > result) {
                    index = i;
                    result = LCSuff[i][j];
                }
            }
            else
                LCSuff[i][j] = 0;
        }
    }

    // Regresa string en formato: indice indice substring
    string toReturn = to_string(index - result) + " " + to_string(index-1) + " " + X.substr(index - result, result);
    return toReturn;
}

int main()
{

    // Lectura de archivos
  
    string malware1, malware2, malware3;
    ifstream transmission1("transmission1.txt"), transmission2("transmission2.txt"), mcode1("mcode1.txt"), mcode2("mcode2.txt"), mcode3("mcode3.txt");
    string linea, lect1, lect2;
    getline(mcode1, malware1);
    mcode1.close();
    getline(mcode2, malware2);
    mcode2.close();
    getline(mcode3, malware3);
    mcode3.close();
    
    getline(transmission1, lect1);
    getline(transmission2, lect2);

    // Búsqueda de malware

    cout << "Parte 1" << endl;

    vector<int> coincidencias;

    coincidencias = kmp(lect1, malware1);
    cout << ((coincidencias.size() > 0) ? "true " : "false " ) << stringVector(coincidencias) << endl;

    coincidencias = kmp(lect2, malware1);
    cout << ((coincidencias.size() > 0) ? "true " : "false " ) << stringVector(coincidencias) << endl;

    coincidencias = kmp(lect1, malware2);
    cout << ((coincidencias.size() > 0) ? "true " : "false " ) << stringVector(coincidencias) << endl;

    coincidencias = kmp(lect2, malware2);
    cout << ((coincidencias.size() > 0) ? "true " : "false " ) << stringVector(coincidencias) << endl;

    coincidencias = kmp(lect1, malware3);
    cout << ((coincidencias.size() > 0) ? "true " : "false " ) << stringVector(coincidencias) << endl;

    coincidencias = kmp(lect2, malware3);
    cout << ((coincidencias.size() > 0) ? "true " : "false " ) << stringVector(coincidencias) << endl;

    // Búsqueda de palíndromos

    cout << "Parte 2" << endl;

    string palindromo;
    pair<int, int> posPalindromo;

    posPalindromo = manacher(lect1, palindromo);
    cout << posPalindromo.first << " " << posPalindromo.second << " " << palindromo << endl;

    posPalindromo = manacher(lect2, palindromo);
    cout << posPalindromo.first << " " << posPalindromo.second << " " << palindromo << endl;

    // Busqueda de substring más largo
    cout << "Parte3" << endl;
    cout << LCSubStr(lect1, lect2, lect1.size(), lect2.size()) << endl;

    transmission1.close();
    transmission2.close();
    return 0;
}