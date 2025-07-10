#include <iostream> 
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

ifstream fin("eratostene7.in");
ofstream fout("eratostene7.out");

typedef unsigned long long int ull;

const int MAX = 1000000;
int ciur[MAX + 1];
int nrPrime[MAX / 6],len;

void CIUR() {
    for (int i = 2; i <= MAX; i++)
        ciur[i] = 1;
    for (int i = 2; i * i <= MAX; i++)
        if (ciur[i])
            for (int j = i * i; j <= MAX; j += i)
                ciur[j] = 0;
    for (int i = 2; i <= MAX; i++)
        if (ciur[i])
            nrPrime[++len] = i;
}

bool check(int x, int k) {
    int nrFact = 0;
    for (int i = 1; nrPrime[i] * nrPrime[i] <= x; i++) {
        int exp = 0;
        while (x % nrPrime[i] == 0) {
            x /= nrPrime[i];
            exp++;
        }
        if (exp == 1)
            nrFact++;
        else if (exp > 1)
            return 0;
    }
    if (x != 1)
        nrFact++;
    return (nrFact == k);
}

int main() {
    CIUR();
    int n;
    fin >> n;
    int x, k;
    for (int i = 1; i <= n; i++) {
        fin >> x >> k;
        if (check(x, k))
            fout << "DA";
        else
            fout << "NU";
        fout << '\n';
    }
}