#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("submultimiinterval.in");
ofstream fout("submultimiinterval.out");

int a, b, v[24], vs = 0;

void afis()
{
    if (!vs)
        return;
    for (int i = 0; i < vs; i++)
        fout << v[i] << ' ';
    fout << '\n';
}

void gen(int k)
{
    afis();
    for (int i = k + 1; i <= b; i++)
    {
        v[vs] = i;
        vs++;
        gen(i);
        vs--;
    }
}

int main()
{
    fin >> a >> b;
    gen(a - 1);
    return 0;
}