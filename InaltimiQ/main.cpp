#include <iostream>

using namespace std;
int n,a[1001],x[1001];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)//memorez indicii initiali
        x[i]=i;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int gata;
    for(int i=1;i<n;i++)
        {
            gata=1;
            for(int j=i+1;j<=n;j++)
                if(a[i]>a[j])
                {
                    swap(a[i],a[j]);
                    swap(x[i],x[j]);
                    gata=0;
                }
            if(gata)
                break;
        }
    for(int i=1;i<=n;i++)
        cout<<x[i]<<' ';
    return 0;
}
