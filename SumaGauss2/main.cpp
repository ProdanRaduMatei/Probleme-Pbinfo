#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sumagauss2.in");
ofstream fout("sumagauss2.out");

long long s, n1, m1, n2, m2;
int main()
{
    fin >> s;
    n1 = s;
    m1 = s - 1;
    n2 = 2 * s;
    for (int d = 1; d * d <= n2; ++d) {
        if (n2 % d == 0) {
            if ((d + 1) * d == n2) {
                n2 = d;
                break;
            }
        }
    }
    m2 = 0;
    if (n1 > n2)
        fout << n1 << " " << m1 << "\n" << n2 << " " << m2;
    else
        fout << n2 << " " << m2 << "\n" << n1 << " " << m1;
    return 0;
}
