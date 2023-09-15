#include <iostream>
using namespace std;
int n, v[100001],l[100001],siruri,f[500000],i,j,k=1;
long long mx=-1000000000;
void citire(int v[],int &n)
{
    int i;
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>v[i];
}
int main()
{
    citire(v,n);
    for(i=1; i<=n; i++) {
        mx=v[i];
        f[v[i]]++;
        if(f[v[i]]<2) {
            l[k++]=v[i];
            for(j=i+1; j<=n; j++) {
                if(v[j]>=mx) {
                    f[v[j]]++;
                    if(f[v[j]]<2 || v[j]==mx) {
                        mx=v[j];
                        l[k++]=v[j];
                    }
                }
            }
            siruri++;
        }
    }
    cout<<siruri<<endl;
    for(i=1;i<k;i++)
        cout<<l[i]<<' ';
    return 0;
}
