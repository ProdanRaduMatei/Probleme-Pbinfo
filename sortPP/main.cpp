#include <iostream>
using namespace std;
int n,v[1005];
bool pp(int x)
{
    for (int i=0;i*i<=x;i++)
        if (i*i==x) return true;
    return false;
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>v[i];
    for (int i=1;i<n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            if (pp(v[i]) && pp(v[j]) && v[i]>v[j])
            {
                int t=v[i];
                v[i]=v[j];
                v[j]=t;
            }
        }
    }
    for (int i=1;i<=n;i++) cout<<v[i]<<" ";
    return 0;
}
