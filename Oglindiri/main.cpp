#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("oglindiri.in");
ofstream fout("oglindiri.out");

int main() {
    int n, m, v[101], a, b;
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> v[i];
    fin >> m;
    while (m--) {
        fin >> a >> b;
        for (int i = 1; i <= (b - a) / 2 + 1; i++)
            swap(v[a + i - 1], v[b - i + 1]);
    }
    for (int i = 1; i <= n; i++)
        fout << v[i] << " ";
    return 0;
}