#include <bits/stdc++.h>
using namespace std;

ifstream fin("tai.in");
ofstream fout("tai.out");

int n , x , cer , rez , maxi , maxi1;

int prim (int n)
{
    if(n == 0 || n == 1) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    for(int i = 3 ; i * i <= n ; i += 2)
        if(n % i == 0) return 0;
    return 1;
}

void desc(int x)
{
    int aux = x , p = 1 , c = 0;
    while(x != 0)
    {
        c = (x % 10) * p + c;
        x /= 10;
        p *= 10;
        if(prim(x))
        {
            if(x > maxi1 && aux != x) maxi1 = x;
        }
        if(prim(c))
        {
            if(c > maxi1 && aux != c) maxi1 = c;
        }
    }
}

int main()
{
    fin >> cer >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        fin >> x;
        if(prim(x)) if(x > rez) rez = x;
        int aux = x , p = 1 , c = 0;
        while(x != 0)
        {
            c = x % 10 * p + c;
            x /= 10;
            p *= 10;
            desc(x);
            if(c != aux)desc(c);
            if(prim(x))
            {
                if(x > maxi && aux != x) maxi = x;
            }
            if(prim(c))
            {
                if(c > maxi && aux != c) maxi = c;
            }
        }
    }
    if(cer == 1) fout << rez;
    else if(cer == 2) fout << maxi;
    else fout << maxi1;
}
