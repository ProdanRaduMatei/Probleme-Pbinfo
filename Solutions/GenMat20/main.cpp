#include <iostream>
using namespace std;
int main(){
    int n,i,j;
    int a[15][15];
    cin>>n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if((i+j)/n==0){
                a[i][j]=i+j+1;
            }
            else{
                a[i][j]=(i+j)%n+1;
            }
        }
    }
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
