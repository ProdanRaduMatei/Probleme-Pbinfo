#include <iostream>
using namespace std;
int main(){
    int n,i,j;
    int a[30][30];
    cin>>n;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if(i+j<n){
                a[i][j]=i+j+1;
            }
            else{
                a[i][j]=2*n-1-(i+j);
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
