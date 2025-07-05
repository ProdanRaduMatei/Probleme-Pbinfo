#include <bits/stdc++.h>

using namespace std;

int n , m , x , y , p[101] , v;
vector <int> G[101];

void dfs(int d)
{
    p[d] = 1;
    for(int i :G[d])
        if(!p[i])
            dfs(i);
}

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> x >> y;
        G[y].push_back(x);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++) p[j] = 0;

        dfs(i);
        int ok = 1;
        for(int j = 1 ; j <= n ; j++)
            if(p[j] == 0)
                ok = 0;
        if(ok == 1 && v == 0)
            v = i;
    }
    if(v == 0) cout << "NU EXISTA";
    else cout << v;
}
