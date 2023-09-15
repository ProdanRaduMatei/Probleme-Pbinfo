#include <iostream>

using namespace std;

int main()
{
    int n,m,a[1001], b[1001],ok;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    if(m>n){
        cout<<"NU";
        return 0;
    }
    for(int st=1;st<=n-m+1;st++){
        ok=1;
        for(int i=1;i<=m;i++)
        {
            if(a[st+i-1]!=b[i])
            {
                ok=0;
            }
        }
        if(ok==1){
            cout<<st;
            return 0;
        }
    }
    cout<<"NU";
    return 0;
}
