#include <bits/stdc++.h>
using namespace std;

ifstream fin("bibinar.in");
ofstream fout("bibinar.out");

int r[100000];

int main()
{
    int n;
    fin >> n;
    int x;
    for(int i = 0 ; i < n ; ++i)
    {
        fin >> x;
        int cnt1=0 , cnt0=0;
        int v[100];
        int p = 0;
        while(x)
        {
            v[p]=x%2;
            p++;
            x/=2;
        }
        for(int j = p-1 ; j >= 0 ; --j)
        {
            if(v[j]==1)
            {
                r[i]+=cnt1*3+cnt0;
                cnt1++;
            }
            else
            {
                r[i]+=cnt1*2;
                cnt0++;
            }
        }
    }
    for(int i = 0 ; i < n ; ++i)
        fout << r[i] << ' ';
    return 0;
}
