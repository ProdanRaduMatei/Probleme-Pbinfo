#include <bits/stdc++.h>
using namespace std;

ifstream fin("aur.in");
ofstream fout("aur.out");

unsigned char a[900001];
int ind;
unsigned long long maxi;

int nrcif(int n)
{
    int c = 0;
    while(n != 0)
    {
        c++;
        n /= 10;
    }
    return c;
}

int ogl(int n)
{
    int ogl = 0;
    while(n != 0)
    {
        ogl = ogl * 10 + n % 10;
        n /= 10;
    }
    return ogl;
}
int main()
{
    long long cer , n , k , p , cnt = 0 , x;
    fin >> cer;
    if(cer == 1)
    {
        int sum = 0;
        fin >> n;
        for(int i = 1 ; i <= n ; i++)
            fin >> x , sum += nrcif(x);
        fout << sum;
    }
    else if(cer == 2)
    {
        fin >> n >> k;
        for(int i = 1 ; i <= n ; i++)
        {
            fin >> x;
            int og = ogl(x);
            while(x % 10 == 0)
            {
                cnt++;
                x /= 10;
                if(cnt == k) fout << 0;
            }
            while(og != 0)
            {
                cnt++;
                if(cnt == k) fout << og % 10;
                og /= 10;
            }
        }
    }
    else
    {
        fin >> n >> p;
        for(int i = 1 ; i <= n ; i++)
        {
            fin >> x;
            int og = ogl(x) , l = 0;
            while(x % 10 == 0) l++ , x /= 10;
            while(og != 0)
            {
                a[++ind] = og % 10;
                og /= 10;
            }
            while(l)
                a[++ind] = 0 , l--;
        }
        for(int i = 1 ; i <= ind - p + 1; i++)
        {
            unsigned long long rez = 0;
            for(int j = 1 ; j <= p ; j++)
                    rez = rez * 10 + a[i+j-1];
            if(rez > maxi) maxi = rez;
        }
        fout << maxi;
    }
}
