#include <bits/stdc++.h>
#define RUP ios::sync_with_stdio(false); fin.tie(0); fout.tie(0);
#define TOT fin.close(); fout.close();
using namespace std;

ifstream fin("fibo_gcd.in");
ofstream fout("fibo_gcd.out");

int n , x , y , c;

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
    RUP

    fin >> n;

    for(int i = 1 ; i <= n ; i++)
    {
        fin >> x >> y;

        if(cmmdc(x , y) == 1 || cmmdc(x , y) == 2)
            c++;
    }

    fout << c;

    TOT
}