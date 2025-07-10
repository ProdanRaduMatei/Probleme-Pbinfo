#include <bits/stdc++.h>

using namespace std;

ifstream fin("kruskal.in");
ofstream fout("kruskal.out");

int n , m , x , y , w , T[1001] , rez , cnt;
struct poz
{
    int i , j , c;
}M[1001];

poz A[1001];

int leaga(int a , int b)
{
    T[a] = T[b];
}

int radacina(int a)
{
    if(a == T[a]) return a;
    else return T[a] = radacina(T[a]);
}

void kruskal()
{
    int r1 , r2;
    for(int i = 1 ; i <= m ; i++)
    {
        r1 = radacina(M[i].i);
        r2 = radacina(M[i].j);
        if(r1 != r2)
        {
            rez += M[i].c;
            A[++cnt] = M[i];
            leaga(r1 , r2);
        }
    }
}

int comp(poz a , poz b)
{
    return a.c < b.c;
}

void init()
{
    for(int i = 1 ; i <= n ; i++)
        T[i] = i;
}

int main()
{
    fin >> n >> m;
    for(int i = 1 ; i <= m ; i++)
    {
        fin >> x >> y >> w;
        M[i].i = x , M[i].j = y , M[i].c = w;
    }
    sort(M + 1 , M + m + 1 , comp);
    init();
    kruskal();
    fout << rez << '\n';
    for(int i = 1 ; i < n ; i++)
        fout << A[i].i << " " << A[i].j << '\n';
}
