#include <fstream>

using namespace std;

ifstream fin("distanta.in");
ofstream fout("distanta.out");

int aparitii[1005];

int main()
{
    int n, dmax = 0;
    for (int i = 1; fin >> n; ++i)
    {
        if (!aparitii[n])
            aparitii[n] = i;
        else if (i - aparitii[n] > dmax)
            dmax = i - aparitii[n];
    }
    fout << dmax;
    return 0;
}