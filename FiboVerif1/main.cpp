#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("fiboverif1.in");
ofstream fout("fiboverif1.out");

int fibo(int n) {
    int a = 1, b = 1, c = 0;
    if (n == 1)
        return 1;
    do {
        c = a + b;
        a = b;
        b = c;
    } while (c < n);
    if (n == c)
        return 1;
    return 0;
}

int main()
{
    int n, v[11];
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i];
        if (fibo(v[i]) == 1)
            fout << v[i] << " ";
    }
    return 0;
}
