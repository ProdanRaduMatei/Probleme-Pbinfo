#include <bits/stdc++.h>

using namespace std;

ifstream fin("fmi_orase1.in");
ofstream fout("fmi_orase1.out");

int n, maxi, a[101];

int main()
{
    fin >> n;
    for (int i = 1 ; i <= n ; i++)
        fin >> a[i];

    for (int i = 1 ; i <= n ; i++)
        for (int j = i + 1 ; j <= n ; j++)
            if (min(a[i], a[j]) * (j - i) > maxi)
                maxi = min(a[i], a[j]) * (j - i);
    fout << maxi;
}
