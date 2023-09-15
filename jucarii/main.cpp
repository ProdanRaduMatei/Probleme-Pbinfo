#include <iostream>
using namespace std;

int main() {
    long long k, n, sol = 1;
    cin >> k >> n;
    if(k > n)
    sol = 0;
    else {
        for(long long i = n - k + 1; i <= n; i++) {
            sol = sol * i;
            sol = sol % 224737;
        }
    }
    cout << sol;
    return 0;
}
