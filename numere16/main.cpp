#include <bits/stdc++.h>

using namespace std;

ifstream fin("numere16.in");
ofstream fout("numere16.out");

unsigned long long int n,a[17],q,j;

unsigned long long int nrcifre(unsigned long long int k);
unsigned long long int Nod(unsigned long long int a, unsigned long long int b);

int main()
{
    fin >> n;
    while(q!=nrcifre(n))
    {
        int s=0;
        unsigned long long int n1=0,x=n,k=1;
        q++;
        while(x!=0)
        {
            s++;
            if(s!=q) n1+=(x%10)*k, k*=10;
            x/=10;
        }
        if (Nod(n,n1)==1) a[j++]=n1;
    }
    sort(a,a+j);
    if(j==0)
        fout << "NU EXISTA";
    else
        for(int i=0;i<j;i++)
            fout << a[i] << " ";
    return 0;
}

unsigned long long int nrcifre(unsigned long long int k)
{
    if(k<10) return 1;
    int s=0;
    while(k!=0)
    {
        s++;
        k/=10;
    }
    return s;
}

unsigned long long int Nod(unsigned long long int a, unsigned long long int b) {
    return b ? Nod (b, a % b) : a;
}
