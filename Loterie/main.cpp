#include <iostream>
#include <limits.h>
#include <fstream>

using namespace std;

ifstream fin("bac.in");
ofstream fout("bac.out");

int v, n;
int min1 = INT_MAX, maxim = INT_MIN, min2 = INT_MAX;

int invers(int x)
{
    int inv = x % 10 * 1000 + (x / 10) % 10 * 100 + (x / 100) % 10 * 10 + x / 1000;
    return inv;
}

void read()
{
    while (fin >> v)
    {
        v = invers(v);
        // cout << v << " " << min1 << " " << maxim << " " << min2 << endl;
        if (v < min1)
        {
            min2 = min1;
            min1 = v;
        }
        if (v > maxim)
            maxim = v;
        if (v < min2 && v > min1)
            min2 = v;
    }
}

void write()
{
    if (min2 == INT_MAX || maxim == INT_MIN || min1 == INT_MAX || min1 == maxim || min2 == maxim || min2 == min1)
    {
        fout << "nu exista";
        return;
    }
    fout << min1 << " " << maxim << " " << min2;
}

int main()
{
    read();
    write();
    return 0;
}