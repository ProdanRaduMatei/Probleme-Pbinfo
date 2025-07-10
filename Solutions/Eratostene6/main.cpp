#include <iostream> 
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

ifstream fin("eratostene6.in");
ofstream fout("eratostene6.out");

typedef unsigned long long int ull;


int main() {
    int v[100001];
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> v[i];
    int contor = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
            if (v[i] != 0) {
                if (v[j] % v[i] == 0)
                    contor++;
            }
            else if (v[j] == 0)
                contor++;
    fout << contor;
}