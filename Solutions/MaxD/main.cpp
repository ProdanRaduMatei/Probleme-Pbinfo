#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("maxd.in");
ofstream fout("maxd.out");

int NrDiv(int n);
int a, b, Min, nr, c;

int main()
{
    fin >> a >> b;
    for (; a <= b; ++a) {
        int Max = NrDiv(a);
        if (Max > nr) {
            nr = Max;
            Min = a;
            c = 1;
        }
        else {
            if (Max == nr)
                ++c;
        }
    }
    fout << Min << " " << nr << " " << c;
    return 0;
}

int NrDiv(int n) {
    int count = 1, k = 0;
    while (n % 2 == 0) {
        ++k;
        n = n / 2;
    }
    count = k + 1;
    for (int i = 3; i * i <= n; i = i + 2) {
        k = 0;
        while (n % i == 0) {
            ++k;
            n = n / i;
        }
        count = count * (k + 1);
    }
    if (n > 1)
        count <<= 1;
    return count;
}
