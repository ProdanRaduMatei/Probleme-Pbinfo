#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("smartphone.in");
ofstream fout("smartphone.out");

int n, c, m1, m2;
long long a;
int main()
{
    fin >> c >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> a;
        if (a > m2) {
            if (a > m1) {
                m2 = m1;
                m1 = a;
            }
            else
                m2 = a;
        }
    }
    if (c == 1)
        fout << m1;
    else
        fout << m2;
    return 0;
}
