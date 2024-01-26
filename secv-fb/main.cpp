#ifdef EZ
   #include "./ez/ez.h"
#else
   #include <bits/stdc++.h>
#endif
#include <ext/pb_ds/assoc_container.hpp>
#define mp make_pair
#define mt make_tuple
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
const string FILE_NAME = "secv_fb";
ifstream fin (FILE_NAME + ".in");
ofstream fout (FILE_NAME + ".out");

const int nMAX = 100e3;

int n, k;
int v[nMAX + 1];
gp_hash_table<int, int> m;
int identice = 0;
int secvente = 0;

int main()
{
    fin >> n >> k;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int i = 1; i <= k; ++i)
        if (++m[v[i]] == 2)
            identice ++;
    if (identice == 0)
        secvente ++;
    for (int i = k+1; i <= n; ++i)
    {
        if (++m[v[i]] == 2)
            identice ++;
        if (--m[v[i-k]] == 1)
            identice --;
        
        if (identice == 0)
            secvente ++;
    }
    fout << secvente;
}