#include <bits/stdc++.h>
using namespace std;
int n , put2[105] , k;
int main()
{
    int i;
    cin >> n;
    while(n > 0)
    {
        for(i = 0 ; ( 1LL * 1 << i ) <= n ; i++)
                ;
        i--;
        ++k;
        put2[k] = ( 1 << i);
        n -= ( 1 << i);
    }
    for(int i = k ; i >= 1 ; i--)
        cout << put2[i] << " ";
    return 0;
}
