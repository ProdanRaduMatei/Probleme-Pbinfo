#include<iostream>
#include<cstring>
using namespace std;

char s[11];
int n,m,x[11];

void Sortare()
{
    int i,j;
    char aux;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(s[i]>s[j])
                aux=s[i],s[i]=s[j],s[j]=aux;
}

void Afisare(int k)
{
    int i;
    for(i=1;i<=k;i++)
        cout<<s[x[i]-1];
    cout<<"\n";
}

int Vocala(char c)
{
    if(strchr("aeiou",c))
        return 1;
    return 0;
}

int Consoana(char c)
{
    if(!strchr("aeiou",c))
        return 1;
    return 0;
}

int Valid(int k)
{
    int i;
    for(i=1;i<k;i++)
        if(x[i]==x[k] || x[i]>x[i+1])
            return 0;
    if(k>m)
        return 0;
    if(k==1 && !Vocala(s[x[k]-1]))
        return 0;
    if(k>1 && Consoana(s[x[k-1]-1]) && Consoana(s[x[k]-1]))
        return 0;
    return 1;
}

void Backtracking(int k)
{
    int i;
    for(i=1;i<=n;i++)
    {
        x[k]=i;
        if(Valid(k))
        {
            Afisare(k);
            Backtracking(k+1);
        }
    }
}

int main()
{
    cin>>s>>m;
    n=strlen(s);
    Sortare();
    Backtracking(1);
    return 0;
}