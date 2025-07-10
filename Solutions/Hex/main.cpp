#include <bits/stdc++.h>

using namespace std;

ifstream fin ("hex.in");
ofstream fout ("hex.out");

char hx[ ] = "0123456789ABCDEF", a[10000001];
int sum[10000001], ind=0;
int n;

int main()
{
    fin >> a;
    n = strlen(a);
    for (int i = n-1; i >= n%4; i-=4)
       sum[++ind] = (a[i-3]- '0')*8 + (a[i-2]- '0')*4  + (a[i-1]- '0')*2 + a[i]- '0';

    switch(n%4)
    {
        case 1: sum[++ind] = a[0] -'0';break;
        case 2: sum[++ind] = (a[0] - '0')*2 + (a[1] - '0');break;
        case 3: sum[++ind] = (a[0] - '0')*4 + (a[1] - '0')*2 + a[2] - '0';break;
    }
    for (int i = ind; i >= 1; --i)
        fout << hx[sum[i]];
    return 0;
}
