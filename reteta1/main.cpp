#include <bits/stdc++.h>

using namespace std;

ifstream in("reteta1.in");
ofstream out("reteta1.out");

int n , m , A[21] , X[21];
double mini = 10000001;

struct poz
{
    int c , n , a[21];
    double val;
}r[21];

int afisare(int k)
{
    for(int i = 1 ; i <= k ; i++)
        out << X[i] << " ";
    out << '\n';
}

void alegemin(int k)
{
    /*for(int i = 1 ; i <= k ; i++)
        cout << X[i] << " ";
    cout << endl;*/
    double v = 0;
    int ok = 0 , f[21] = {0};
    for(int i = 1 ; i <= k ; i++)
    {
        v += r[X[i]].val;
        for(int j = 1 ; j <= r[X[i]].n ; j++)
            f[r[X[i]].a[j]]++;
    }
    /*for(int j = 1 ; j <= n ; j++)
        cout << f[j] << " ";
    cout << endl;*/
    for(int j = 1 ; j <= n ; j++)
        if(f[j] != 1) ok = 1;
    if(ok == 0 && v < mini) mini = v;
}
void back(int k)
{
    for(int i = X[k - 1] + 1 ; i <= m ; i++)
    {
        X[k] = i;
        alegemin(k);
        back(k + 1);
    }
}

int main()
{
    in >> n >> m;

    for(int i = 1 ; i <= m ; i++)
    {
        in >> r[i].c >> r[i].n;
        for(int j = 1 ; j <= r[i].n ; j++)
            in >> r[i].a[j];
    }

    for(int i = 1 ; i <= n ; i++)
        in >> A[i];

    for(int i = 1 ; i <= m ; i++)
    {
        r[i].val = 0;
        for(int j = 1 ; j <= r[i].n ; j++)
            if(r[i].c == 1)
                r[i].val += A[r[i].a[j]];
            else
                r[i].val += A[r[i].a[j]] / 2.0;
    }
    back(1);
    out << fixed << setprecision(1) << mini;
}