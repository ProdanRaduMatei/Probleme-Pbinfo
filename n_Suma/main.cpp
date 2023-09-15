#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("n_suma.in");
ofstream fout("n_suma.out");
int main()
{
    int n, s = 0, i, a;
    fin >> n;
    for (i = 1; i <= n; ++i) {
        fin >> a;
        s = s + a;
    }
    fout << s;
    return 0;
}
