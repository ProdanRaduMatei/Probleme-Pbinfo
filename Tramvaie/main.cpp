#include <fstream>
#include <iostream>
using namespace std;

int indicatoare[1000007], i, j, zile;

int main()
{
    ifstream fin("tramvaie.in");
    ofstream fout("tramvaie.out");
    indicatoare[1] = 1;
    for (i = 2; i < 1000007; ++i)
        indicatoare[i] = i - 1;
    for (i = 2; i < 1000007; ++i)
        for (j = i * 2; j < 1000007; j += i)
            indicatoare[j] -= indicatoare[i];
    fin >> zile;
    while (zile--)
    {
        fin >> i;
        fout << indicatoare[i] << ' ';
    }
    return 0;
}