#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nrcurat.in");
ofstream fout("nrcurat.out");

int x, o, u, n;

int main()
{
    while (fin >> x) {
        o = 0;
        n = 0;
        while (x) {
            o = o * 10 + x % 10;
            u = u * 10 + 9;
        }
        if (u - x == o)
            fout << 1;
        else
            fout << 0;
        fout << " ";
    }
    return 0;
}
