#include <bits/stdc++.h>
using namespace std;

int A[101], c;

int main(){
    int n;
    cin >> n;
    while(n){
        A[++c] = n % 2;
        n/=2;
    }
    int put = 1;
    for(int i = 1; i <= c; ++i){
        if(A[i] == 1)
            cout << put << ' ';
        put*=2;
    }
    return 0;
}
