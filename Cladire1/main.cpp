#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cladire1.in");
ofstream fout("cladire1.out");

int main(){
    int n, m, k, a[1001][1001];
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = -1;
    for (int i = 0; i < n; i++)
        a[i][m - 1] = 1;
    for (int j = 0;j<m;j++)
        a[n - 1][j] = 1;
    for (int in = 0; in < k; in++) {
        int i, j;
        cin >> i >> j;
        a[i - 1][j - 1] = 0;
    }
    for (int i = n-2;i>=0;i--){
for(j=m-2;j>=0;j--){

if(a[i][j]!=0){
a[i][j]=a[i+1][j]+a[i][j+1];
}

}
}

for(i=0;i<n;i++){
for(j=0;j<m;j++){

cout<<a[i][j]<<" ";
}
cout<<endl;
}
cout<<a[0][0]<<endl;
return 0;
}
