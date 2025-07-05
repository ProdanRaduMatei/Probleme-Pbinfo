#include <bits/stdc++.h>
using namespace std ;
int main () {
    int n , c1 , c2 , p = 1 , x = 0;
    cin >> n >> c1 >> c2 ;
    if ( n==0)
        x=c2;
    else {
        while (n) {
            if (n % 10 == c1) {
                x=x+c2*p;
                p=p*10;
            }
            else {
                x=x+(n%10)*p;
                p=p*10;
            }
            n/=10;
        }
    }
    cout<< x;
    return 0;
}
