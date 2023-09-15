#include <iostream>

using namespace std;

unsigned long long n, A, R, scor=0, i, t;

int main() {
    cin >> n;
    for (i=1; i<=n; ++i) {
        cin >> A >> R;
        t=A*A+3*A+1;
        if (t==R)
            ++scor;
    }
    cout << scor;
    return 0;
}
