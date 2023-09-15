#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("lipsa.in");
ofstream fout("lipsa.out");

int main()
{
    int n, x;
    long long v[1000001] = {0};
    fin >> n;
    for (int i = 1; i < n; ++i) {
        fin >> x;
        v[x] = 1;
    }
    int i = 1;
    while (v[i] == 1)
        ++i;
    fout << v[i];
    return 0;
}
