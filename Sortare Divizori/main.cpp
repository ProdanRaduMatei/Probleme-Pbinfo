#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sortare_divizori.in");
ofstream fout("sortare_divizori.out");

int n, cnt, v[1001], c[1001] = {0}, aux;
int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i];
        for (int d = 1; d * d <= v[i]; ++d) {
            if (v[i] % d == 0) {
                if (d * d == v[i])
                    ++c[i];
                else
                    c[i] = c[i] + 2;
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (c[i] < c[j]) {
                aux = c[i];
                c[i] = c[j];
                c[j] = aux;
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
            else if (c[i] == c[j]) {
                if (v[i] > v[j]) {
                    aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        fout << v[i] << " ";
    return 0;
}
