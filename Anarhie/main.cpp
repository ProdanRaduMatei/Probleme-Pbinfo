#include <bits/stdc++.h>

using namespace std;

ifstream fin("anarhie.in");
ofstream fout("anarhie.out");

int n , m , p , q , x , y , r , k , X[12] , P[101] , S[101] , A[101][101] , mini = 999999999 , s;

int dfs(int c)
{
    P[c] = 1;
    for(int i = 1 ; i <= n ; i++)
        if(!P[i] && S[A[c][i]] && A[c][i])
            dfs(i);
}

int verif(int k)
{
    for(int i = 1 ; i <= n ; i++)
        S[i] = P[i] = 0;

    for(int i = 1 ; i <= k ; i++)
        S[X[i]] = 1;

    dfs(p);
    return P[q];
}

void back(int k)
{
    for(int i = X[k - 1] + 1 ; i <= s ; i++)
    {
        X[k] = i;
        if(verif(k))
            if(k < mini) mini = k;
        back(k + 1);
    }
}

int main()
{
    fin >> n >> m >> s;
    fin >> p >> q;
    for(int i = 1 ; i <= m ; i++)
    {
        fin >> x >> y >> r;
        A[x][y] = r;
    }
    back(1);
    fout << mini;
}
