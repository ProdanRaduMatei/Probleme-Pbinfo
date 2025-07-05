#include <iostream>
#include <fstream>
#include <cmath>
#include <bitset>
#include <cstring>
#include <algorithm>

using namespace std;

ifstream fin("eratostene5.in");
ofstream fout("eratostene5.out");

typedef unsigned long long ull;

const int MAX = 1000000;
int len = 0;
int frecv[MAX / 6] = { 0 };
bool ciur[MAX];
int nrPrime[MAX / 6];

void CIUR() {
    ciur[2] = 1;
    for (int i = 3; i < MAX; i += 2)
        ciur[i] = 1;
    for (int i = 3; i * i < MAX; i += 2)
        if (ciur[i])
            for (int j = i * i; j < MAX; j += i)
                ciur[j] = 0;
    for (int i = 2; i < MAX; i++)
        if (ciur[i])
            nrPrime[++len] = i;
}

int main() {
    CIUR();
    int n, var;
    fin >> n; 
    for (int i = 1; i <= n; i++) {
        fin >> var;
        for (int j = 1; nrPrime[j] * nrPrime[j] <= var; j++)
            while (var % nrPrime[j] == 0) {
                var /= nrPrime[j];
                frecv[j]++;
            }
        if (var != 1) {
            int left = 1, right = len;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (nrPrime[mid] == var) {
                    frecv[mid]++;
                    break;
                }
                if (nrPrime[mid] < var)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
    }
        for (int i = 1; i <= len; i++)
            if (frecv[i])
                fout << nrPrime[i] << " " << frecv[i] << '\n';
}