#include <iostream>
using namespace std;
long n,y,nr=1,a[1025][1025];
int putere(int x){
    if(x==0)
        return 1;
    else if(x%2==1)
        return 2*putere(x-1);
    else if(x%2==0){
        x/=2;
        int h=2*putere(x-1);
        return h*h;
    }
}
int main(){
    cin>>n;
    y=n;
    n=putere(n);
    if(n==2){
        a[1][1]=1;
        a[1][2]=1;
        a[2][1]=1;
    }
    else{
        if(y%2==0){
            for(int i=1;i<=n;i++,i++)
                for(int j=3;j<=n-4;j+=3){
                    a[i][j]=nr;
                    a[i+1][j]=nr;
                    a[i+1][j-1]=nr;
                    nr++;
                    a[i][j-1]=nr;
                    a[i][j-2]=nr;
                    a[i+1][j-2]=nr;
                    nr++;
                }
            int mr=n-3;
            for(int i=1;i<=n-4;i+=3){
                a[i][mr]=nr;
                a[i+1][mr]=nr;
                a[i][mr+1]=nr;
                nr++;
                a[i+1][mr+1]=nr;
                a[i+2][mr+1]=nr;
                a[i+2][mr]=nr;
                nr++;
                a[i][mr+2]=nr;
                a[i][mr+3]=nr;
                a[i+1][mr+2]=nr;
                nr++;
                a[i+1][mr+3]=nr;
                a[i+2][mr+2]=nr;
                a[i+2][mr+3]=nr;
                nr++;
            }
            a[n-3][n-3]=nr;
            a[n-3][n-2]=nr;
            a[n-2][n-3]=nr;
            nr++;
            a[n][n-3]=nr;
            a[n][n-2]=nr;
            a[n-1][n-3]=nr;
            nr++;
            a[n-3][n]=nr;
            a[n-3][n-1]=nr;
            a[n-2][n]=nr;
            nr++;
            a[n][n]=nr;
            a[n-1][n]=nr;
            a[n][n-1]=nr;
            nr++;
            a[n-2][n-2]=nr;
            a[n-2][n-1]=nr;
            a[n-1][n-2]=nr;
        }
        else if(y%2==1){
            for(int i=1;i<=n;i++,i++)
                for(int j=3;j<=n-2;j+=3){
                    a[i][j]=nr;
                    a[i+1][j]=nr;
                    a[i+1][j-1]=nr;
                    nr++;
                    a[i][j-1]=nr;
                    a[i][j-2]=nr;
                    a[i+1][j-2]=nr;
                    nr++;
                }
            for(int i=1;i<=n;i+=3){
                a[i][n]=nr;
                a[i][n-1]=nr;
                a[i+1][n-1]=nr;
                nr++;
                a[i+1][n]=nr;
                a[i+2][n-1]=nr;
                a[i+2][n]=nr;
                a[i+2][n]=nr;
                nr++;
            }
            a[n][n]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
