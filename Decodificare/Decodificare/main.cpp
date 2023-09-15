#include <bits/stdc++.h>

using namespace std;

ifstream fin("decodificare.in");
ofstream fout("decodificare.out");

int a[1501][1501];

int main() {
    int n;
    char c;
    fin >> n;
    for (int i = 1; i <= n / 2; ++i)
        for (int j = 1; j <= n / 2; ++j) {
            fin >> c;
            a[i][j] = c;
        }
    for (int i = 1; i <= n / 2; ++i)
        for (int j = 1; j <= n / 2; ++j)
            if (i + j - 1 == n / 2)
                fout << (char)a[i][j];
    for (int i = 1; i <= n / 2; ++i)
        for (int j = 1; j <= n / 2; ++j)
            if (i == j)
                fout << (char)a[i][j];
    return 0;
}
