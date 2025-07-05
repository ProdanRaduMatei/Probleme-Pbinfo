#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cifreord.in");
ofstream fout("cifreord.out");

int main()
{
    int n, a, v[10] = {0}, c = 0;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> a;
        ++v[a];
    }
    for (int i = 0; i <= 9; ++i) {
        while (v[i] > 0) {
            fout << i << " ";
            ++c;
            if (c % 20 == 0)
                fout << endl;
            --v[i];
        }
    }
    return 0;
}
