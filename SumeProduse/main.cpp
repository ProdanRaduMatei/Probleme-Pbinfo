#include <iostream>

using namespace std;

int main()
{
    long long n, a, s1 = 0, s2 = 0;
    cin >> n;
    for (int i = 0; i < n / 2; ++i) {
        cin >> a;
        s1 = s1 + a;
    }
    for (int i = 0; i < n / 2; ++i) {
        cin >> a;
        s2 = s2 + a;
    }
    cout << s1*s2;
    return 0;
}
