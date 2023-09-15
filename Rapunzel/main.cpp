#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("rapunzel.in");
ofstream fout("rapunzel.out");

int main()
{
    long long n, m1, m2, t;
    fin >> n >> m1 >> m2;
    t = m1 + m2;
    if (n % t == 0)
        fout << n / t;
    else
        fout << n / t + 1;
    return 0;
}
