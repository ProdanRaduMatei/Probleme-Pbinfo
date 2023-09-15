#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("div3.in");
ofstream fout("div3.out");

int suma_cifre(int n) {
    int s = 0;
    while (n) {
        s = s + n % 10;
        n = n / 10;
    }
    return s;
}

int main()
{
    int n, v[1001];
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int i = 1; i <= n; ++i)
        if (suma_cifre(v[i]) % 3 == 0)
            fout << v[i] << " ";
    return 0;
}
