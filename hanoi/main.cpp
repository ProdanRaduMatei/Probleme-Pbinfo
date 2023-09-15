#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("hanoi.in");
ofstream fout("hanoi.out");

char a = 'A', b = 'B', c = 'C';
int n, m = 1, C;

void han (int n, char a, char b, char c) {
    if (n == 1)
        fout << a << "->" << b << endl;
    else {
        han(n - 1, a, c, b);
        fout << a << "->" << b << endl;
        han(n - 1, c, b, a);
    }
}

int main ()
{
    fin >> n;
    C = n;
    while (C) {
        --C;
        m = 2 * m;
    }
    fout << m - 1 << endl;
    han(n, a, b, c);
    return 0;
}
