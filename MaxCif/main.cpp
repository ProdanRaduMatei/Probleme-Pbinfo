#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("maxcif.in");
ofstream fout("maxcif.out");

int main()
{
    int a, v[10] = {0}, m = 0;
    while (fin>>a) {
        ++v[a];
        if (v[a] > m)
            m = v[a];
    }
    for (int i = 0; i <= 9; ++i)
        if (v[i] == m)
            fout << i << " ";
    return 0;
}
