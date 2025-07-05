#include <iostream> 
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

ifstream fin("eratostene8.in");
ofstream fout("eratostene8.out");

typedef unsigned long long int ull;

const int MAX = 10000001;
int intervale[MAX];

int main() {
    int nrPrime[10001] = { 0 };
    int n, t;
    fin >> n >> t;
    for (int i = 1; i <= n; i++)
        fin >> nrPrime[i];
    sort(nrPrime + 1, nrPrime + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (nrPrime[i] != nrPrime[i - 1])
        for (int j = nrPrime[i]; j < MAX; j += nrPrime[i])
            intervale[j] = 1;
    }
    for (int i = 1; i < MAX; i++)
        intervale[i] += intervale[i - 1];
    int st, dr;
    for (int i = 1; i <= t; i++) {
        fin >> st >> dr;
        fout << intervale[dr] - intervale[st - 1] << '\n';
    }
}