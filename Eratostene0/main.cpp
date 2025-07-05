#include <cstring>
#include <iostream> 
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

ifstream fin("eratostene0.in");
ofstream fout("eratostene0.out");

typedef unsigned long long int ull;
const int MAX = 1000001;
const int MOD = 1000000007;
int suma[MAX];
ull sumaPartiala[MAX];

void CIUR() {
    for (int i = 1; i < MAX; i++)
        for (int j = 1; i * j < MAX; j++)
            suma[i * j] += i;
    for (int i = 1; i < MAX; i++)
        sumaPartiala[i] += sumaPartiala[i - 1] + suma[i];
}

int main() {
    CIUR();
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++) {
        int st, dr;
        fin >> st >> dr;
        fout << sumaPartiala[dr] - sumaPartiala[st - 1] << '\n';
    }
}