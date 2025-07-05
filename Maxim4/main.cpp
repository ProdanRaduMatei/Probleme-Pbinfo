#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("maxim4.in");
ofstream fout("maxim4.out");

int main()
{
    int n, v[101], m = 0, c = 0;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i];
        if (v[i] > m) {
            m = v[i];
            c = 1;
        }
        else if (v[i] == m)
            ++c;
    }
    fout << m << " " << c;
    return 0;
}
