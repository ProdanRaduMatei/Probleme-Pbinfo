#include <iostream>

using namespace std;

long long n, s, S;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        s = 1;
        for (int j = 1; j <= i; ++j) {
            s = s * j;
        }
        S = S + s;
    }
    cout << "Rezultatul este " << S;
    return 0;
}
