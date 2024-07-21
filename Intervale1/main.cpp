#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

ifstream fin("intervale1.in");
ofstream fout("intervale1.out");

void Intervale1()
{
    int n, intervalMin = INT_MAX;
    double x, y;
    fin >> n;
    fin >> x;
    for (int i = 2; i <= n; ++i)
    {
        fin >> y;
        if ((int)y == (double)y && (int)x == (double)x)
            intervalMin = min(intervalMin, (int)(y - x - 1));
        else
            intervalMin = min(intervalMin, ((int)y - (int)x));
        x = y;
    }
    fout << intervalMin;
}

int main()
{
    Intervale1();
    return 0;
}
