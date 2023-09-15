#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nrdiv9.in");
ofstream fout("nrdiv9.out");

int prim(int x) {
    int c = 0;
    if (x < 2)
        return 0;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0)
            if (i * i == x)
                ++c;
            else
                c = c + 2;
    }
    if (c == 9)
        return 1;
    return 0;
}

int main()
{
    int x, c = 0;
    fin >> x;
    for (int i = 1; i * i <= x; ++i)
        if (prim(i * i) == 1)
            ++c;
    fout << c;
    return 0;
}
