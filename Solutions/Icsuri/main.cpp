#include <iostream>
#include <fstream>
using namespace std;

int a[10002][10002];
int main(){
    int n,M,i0,j0,k,i,j,p,nr=0;
    cin>>n>>M;
    while(M>0){
        cin>>i0>>j0>>p;
        a[i0][j0]++;
        for(k=1;k<=p;k++){
            if((i0-k)>0&&(j0-k)>0){
                a[i0-k][j0-k]++;
            }
            if((i0-k)>0&&(j0+k)<n+1){
                a[i0-k][j0+k]++;
            }
            if((i0+k)<n+1&&(j0-k)>0){
                a[i0+k][j0-k]++;
            }
            if((i0+k)<n+1&&(j0+k)<n+1){
                a[i0+k][j0+k]++;
            }
        }
        M--;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(a[i][j]==0)
                nr++;
    cout<<nr;
    return 0;
}
