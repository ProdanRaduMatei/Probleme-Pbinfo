#include <bits/stdc++.h>

using namespace std;

ifstream fin("sort2.in");
ofstream fout("sort2.out");

int x,nr,a[101];

int main()
{
    while (fin >> x)
        if (x<=99)
            a[nr++]=x;
    if(nr==0)
        fout << "NU EXISTA";
    else
    {
        sort(a,a+nr);
        for(int i=0;i<nr;i++)
            fout << a[i] << " ";
    }
    return 0;
}
