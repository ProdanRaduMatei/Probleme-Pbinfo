#include <bits/stdc++.h>
#define NMAX 100001
using namespace std;
ifstream fin("adobe.in");
char sir[NMAX];
int n;

bool searchanagram(int position)
{
    int i, j;
    char c,s[]="bdaeo", aux[6];
    for(i=0; i<5; ++i)
        aux[i]=sir[position+i];
    aux[5]='\0';
    for(j=0; j<5; ++j)
    {
        c=s[j];
        for(i=0; i<5 && c!=aux[i];++i)
            ;
        if(i<5)
            aux[i]='.';
        else
        {
            if(j<2)
                c='+';
            else
                c='-';
            for(i=0; i<5 && c!=aux[i];++i)
                ;
            if(i<5)
                aux[i]='.';
            else
            {
                c='*';
                for (i=0; i<5 && c!=aux[i];++i)
                    ;
                if(i<5)
                    aux[i]='.';
                else
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    cin>>sir;
    for(n=0;sir[n]!='\0';++n)
        if(sir[n]>='A' && sir[n]<='Z')
            sir[n]+=32;
    int nr=0;
    for(int i=0;i<n-4;++i)
        nr+=searchanagram(i);
    cout<<nr;
    return 0;
}
