#include <fstream>
#include <cmath>
#include <climits>
#include <iostream>

#define impar % 2 == 1

using namespace std;

bool *gaseste(bool *sta, bool *end, bool val) {
    for (bool *i = sta; i != end; ++i)
        if (*i == val)
            return i;
    return nullptr;
}

long long suma(int *sta, int *end) {
    long long s;
    int *i;
    s = 0;
    for (i = sta; i != end; ++i)
        s += *i;
    return s;
}

int main() {
    ifstream fin ("tri.in");
    ofstream fout ("tri.out");
    int n;
    fin >> n;
    int *v = new int[n], *i;
    bool *a, *b, *c, *A, *C;
    long long s_ab, s_bc, dezech, DEZECH_MIN = INT_MAX;
    bool *impare = new bool[n];
    for (i = v; i != v + n; ++i)
        fin >> *i;
    for (i = v; i != v+n; ++i)
        *(impare + (i - v)) = (*i impar);
    a = gaseste(impare, impare + n, true);
    b = gaseste(a + 1, impare + n, true);
    c = gaseste(b + 1, impare + n, true);
    do {
        s_ab = suma(v + (a + 1 - impare), v + (b - impare));
        s_bc = suma(v + (b + 1 - impare), v + (c - impare));
        dezech = abs(s_ab - s_bc);
        if (dezech <= DEZECH_MIN) {
            DEZECH_MIN = dezech;
            A = a;
            C = c;
        }
        a = b;
        b = c;
        c = gaseste(c + 1, impare + n, true);
    } while (c != nullptr);
    fout << A - impare + 1 << ' ' << C - impare + 1;
    return 0;
}