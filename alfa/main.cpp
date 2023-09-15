#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("alfa.in");
ofstream fout("alfa.out");

int main()
{
    int n, x, v[1001];
    fin >> n >> x;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    int in = 0, fn = 0;
    for (int i = 1; i <= n; ++i) {
        if (v[i] == x) {
            if (in == 0)
                in = i;
            else {
                fn = i;
                sort(v + 1 + in, v + fn);
                in = i;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        fout << v[i] << " ";
    return 0;
}
