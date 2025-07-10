#include <bits/stdc++.h>

using namespace std;

ifstream fin ("memory003.in");
ofstream fout ("memory003.out");

long long prod[1005] , p , n , m;

int main()
{
    long long x;
    fin >> n >> m >> p;
    for(int i = 1 ; i <= m ; i++)
        prod[i] = 1;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
    {
        fin >> x;
        prod[j] = (prod[j] % p * x % p) % p;
    }
    long long sol = 0;
    for(int i = 1 ; i <= m ; i++)
        sol += (prod[i] == 0);
    fout << sol << "\n";
    fin.close();
    fout.close();
    return 0;
}
