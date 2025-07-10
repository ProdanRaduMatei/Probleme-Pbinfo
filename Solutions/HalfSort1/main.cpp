#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("halfsort1.in");
ofstream fout("halfsort1.out");

void citire(int &n, int v[]) {
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
}

void sortare(int n, int v[]) {
    for (int i = 1; i < n / 2; ++i)
        for (int j = i + 1; j <= n / 2; ++j)
            if (v[i] > v[j])
                swap(v[i], v[j]);
    for (int i = n / 2 + 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (v[i] < v[j])
                swap(v[i], v[j]);
}

void afisare(int n, int v[]) {
    for (int i = 1; i <= n; ++i)
        fout << v[i] << " ";
}

int main()
{
    int n, v[101];
    citire(n, v);
    sortare(n, v);
    afisare(n, v);
    return 0;
}
