#include <bits/stdc++.h>

using namespace std;

ifstream fin("spion.in");
ofstream fout("spion.out");

bitset <50000001>F;
int n , val , st , dr , c;

int main()
{
    fin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        fin >> val >> st >> dr;
        if(F[st] == 1 && F[dr] == 1)
            c--;
        else if(F[st] == 0 && F[dr] == 0)
            c++;
        F[val] = 1;
        fout << c << '\n';
    }
}
