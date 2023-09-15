#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cifra2.in");
ofstream fout("cifra2.out");

int cifmin(long long x) {
    int m = 9;
    while (x) {
        if (x % 10 < m)
            m = x % 10;
        x = x / 10;
    }
    return m;
}

long long elimcifmin(long long x) {
    int m = cifmin(x);
    long long c = x, n = 0, p = 1;
    while (c) {
        if (c % 10 != m) {
            n = n + (c % 10 - m) * p;
            p = p * 10;
        }
        c = c / 10;
    }
    return n;
}

int main()
{
    long long n;
    fin >> n;
    fout << cifmin(n) << endl;
    fout << elimcifmin(n) << endl;
    while (n >= 10)
        n = elimcifmin(n);
    fout << n << endl;
    return 0;
}
