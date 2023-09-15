#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("tort.in");
ofstream fout("tort.out");

int tort(int a, int b) {
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int n, m, nr, p;
    fin >> m >> n;
    p = tort(m,n);
    nr = (m * n) / (p * p);
    fout << nr << " " << p;
    return 0;
}
