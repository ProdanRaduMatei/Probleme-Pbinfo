#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

long long n, num, s, i;
float m;

int main() {
    cin >> n;
    for (i=1; i<=n; ++i) {
        cin >> num;
        s=s+num*num;
    }
    m=sqrt((float)s/n);
    cout << fixed << setprecision(2) << m;
    return 0;
}
