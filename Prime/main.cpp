#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("prime.in");
ofstream fout("prime.out");

int prim(int n) {
    if (n <= 1)
        return 0;
    if (n % 2 == 0) {
        if (n == 2)
            return 1;
        else
            return 0;
    }
    for (int i = 3; i * i <= n; i = i + 2)
        if (n % i == 0)
            return 0;
    return 1;
}

int main()
{
    int n, v[1001];
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i];
        if (prim(v[i]) == 1)
            fout << v[i] << " ";
    }
    return 0;
}
