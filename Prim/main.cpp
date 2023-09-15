#include <bits/stdc++.h>


using namespace std;

ifstream fin("prim.in");
ofstream fout("prim.out");

vector <pair<int , int>> G[101];

int n , m , x , y , c , S;
vector<int> T , D;
vector<bool>V;

int main()
{
    for(fin >> n >> m ; m ; --m)
    {
        fin >> x >> y >> c;
        G[x].push_back({c , y});
        G[y].push_back({c , x});
    }

    priority_queue <
        pair<int , int>  ,
        vector<pair<int , int>> ,
        greater<pair<int , int>>
    >Q;

    V.resize(n + 1 , false);
    T.resize(n + 1 , -1);
    D.resize(n + 1 , 0x3f3f3f3f);

    V[1] = true;
    T[1] = 0;
    D[1] = 0;

    for(auto x : G[1])
    {
        T[x.second] = 1;
        D[x.second] = x.first;
        Q.push(x);
    }

    for(int k = 1 ; k < n ; k++)
    {
        pair<int , int> P;
        do{
            P = Q.top();
            Q.pop();
        }while(V[P.second]);

        V[P.second] = true;
        S += P.first;

        for(auto x : G[P.second])
            if(V[x.second] == false && D[x.second] > x.first)
            {
                T[x.second] = P.second;
                D[x.second] = x.first;
                Q.push(x);
            }
    }

    fout << S << '\n';
    for(int i = 1  ;i <= n ; i++)
        fout << T[i] << " ";
}
