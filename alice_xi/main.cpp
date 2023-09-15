#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("alice_xi.in");
ofstream fout("alice_xi.out");

int n, s;

int main()
{
    fin >> n;
    if (n == 1) {
        fout << 1;
        return 0;
    }
    if (n == 2) {
        fout << 3;
        return 0;
    }
    if (n > 1)
        s = 2;
    for (int i = 2; i < n; ++i)
        s = s + 3;
    fout << s;
    return 0;
}
