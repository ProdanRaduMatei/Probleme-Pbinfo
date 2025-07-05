#include <bits/stdc++.h>
using namespace std;

ifstream fin("cartonase1.in");
ofstream fout("cartonase1.out");

int cmmdc(int a , int b)
{
    while(b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n;
    fin >> n;
    int x , y;
    fin >> x;
    bool ok = true;
    for(int i = 2 ; i <= n && ok; ++i)
    {
        fin >> y;
        x = cmmdc(x , y);
        if(x == 1)
            fout << i , ok = false;
    }
    if(ok)
        fout << -1;
    return 0;
}
