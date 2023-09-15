#include <bits/stdc++.h>
using namespace std;
ifstream fin("relativ.in");
ofstream fout("relativ.out");
long long int n,x;
long long int k=1,z,s,summax;
int main()
{
    fin >> n;
    fin >> x;
    s=summax=z=x;
    for(long long int i=1;i<n;i++)
    {
        fin >> x;
        s+=x;
        if(x<=z)
        {
            z=x;
            k++;
            if(s>summax) summax = s;
            s = x;
        }
    }
    fout << k << endl << summax;
    return 0;
}
