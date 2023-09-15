#include <iostream>

using namespace std;

void afisare(int a[100][100],int n,int m){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n,m,k,k0,i,j,trag,nr_lov,a[100][100];
    cin>>n>>m>>k;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    k0=k;
    while(k>0){
        cin>>trag;
        for(j=0;j<m;j++){
            nr_lov=0;
            for(i=n-1;i>=0;i--){
                if(a[i][j]==trag){
                    nr_lov++;
                }
                else{
                    if(nr_lov>0){
                        a[i+nr_lov][j]=a[i][j];
                    }
                }
            }
            for(i=0;i<nr_lov;i++){
                a[i][j]=0;
            }
        }
        k--;
    }
    afisare(a,n,m);
    return 0;
}
