#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("nraparitii.in");
ofstream fout("nraparitii.out");
int main()
{
    int n, i, v[1000], cnt = 0;
    fin >> n;
    for (i = 1; i <= n; ++i)
        fin >> v[i];
    for (i = 1; i <= n; ++i) {
        if (v[i] == v[n])
            ++cnt;
    }
    fout << cnt;
    return 0;
}
