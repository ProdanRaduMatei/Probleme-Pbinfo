#include <iostream>
#include <fstream>
#include <cmath>
#include <bitset>
#include <cstring>
#include <algorithm>

using namespace std;

ifstream fin("eratostene4.in");
ofstream fout("eratostene4.out");

typedef unsigned long long ull;

const int MAX = 10000000;
bool ciur[MAX];
short nrDiv[MAX];

void CIUR() {
    memset(ciur, 1, MAX);
    for (int i = 2; i * i < MAX; i++)
        if (ciur[i])
            for (int j = i * i; j < MAX; j += i)
                ciur[j] = 0;
    for (int i = 2; i < MAX; i++)
        if (ciur[i])
            for (int j = i; j < MAX; j += i)
                nrDiv[j]++;
}

int main() {
    CIUR();
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++) {
        int var;
        fin >> var;
        fout << (1 << nrDiv[var]) << " ";
    }
}