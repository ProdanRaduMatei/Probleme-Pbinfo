#include <iostream>
using namespace std;
int main()
{
    int n,x[20],k=0,maxim=0,minim=99;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>x[i];
    for(int i=1;i<=n;i++)
    {
        k++;
        if(k%2==0){
            if(x[k]>maxim)
                maxim=x[k];}
            else
            {if(x[k]>=10 and x[k]<=99)
                if(minim>x[k])
                    minim=x[k];}
    }
    if(maxim==0 && minim!=99)
        cout<<-1<<" "<<minim;;
    if(minim==99 && maxim!=0)
        cout<<maxim<<" "<<-1;
    if(minim!=99 && maxim!=0)
        cout<<maxim<<" "<<minim;
    return 0;
}
