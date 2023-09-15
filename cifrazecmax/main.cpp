#include <bits/stdc++.h>

using namespace std;

ifstream fin("cifrazecmax.in");
ofstream fout("cifrazecmax.out");

#define frq fr[x/10%10]

int main()
{
    int fr[10000] = {0}, i = 0, poz = 0, maxi = 0, x;
    while (fin >> x) {
        ++i;
        ++frq;
        if(frq > maxi)
            maxi = frq, poz = i;
    }
    fout << poz;
    return 0;
}
