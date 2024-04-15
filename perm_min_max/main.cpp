#include <iostream>

using namespace std;

int n, v[11], a[10], x[11], p[11], Min, Max, lim;

void afisare()
{
    int pp = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (v[i] == Min)
            cout << Min << " ";
        else if (v[i] == Max)
            cout << Max << " ";
        else
            cout << a[x[pp++]] << " ";
    }
    cout << '\n';
}

void backtracking(int k)
{
    for (int i = 1; i <= lim; ++i)
        if (!p[i])
        {
            p[i] = 1;
            x[k] = i;
            if (k < lim)
                backtracking(k + 1);
            else
                afisare();
            p[i] = 0;
        }
}

int main()
{
    cin >> n >> v[1];
    Min = Max = v[1];
    for (int i = 2; i <= n; ++i)
    {
        cin >> v[i];
        if (v[i] < Min)
            Min = v[i];
        if (v[i] > Max)
            Max = v[i];
    }
    for (int i = 1; i <= n; ++i)
        if (v[i] != Min && v[i] != Max)
            a[++lim] = v[i];
    for (int i = 1; i <= lim; ++i)
        for (int j = i + 1; j <= lim; ++j)
            if (a[i] > a[j])
                swap(a[i], a[j]);
    backtracking(1);
}