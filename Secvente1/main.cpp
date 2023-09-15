#include <iostream>
using namespace std;

int k, n, x, c = 1, nr, i;

int main()
{
    cin >> n >> k;
    for(i = 1; i <= n; i++) {
        cin >> x;
        if(x % 2 != 0)
            nr++;
        if(nr > k) {
            c++;
            nr = 1;
        }
    }
    cout << c;
    return 0;
}
