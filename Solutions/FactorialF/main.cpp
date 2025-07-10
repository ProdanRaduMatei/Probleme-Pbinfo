#include <iostream>

using namespace std;

int fact(int n) {
    long long f = 1;
    for (int i = 1; i <= n; ++i)
        f = f * i;
    if (n == 0)
        return 1;
    return f;
}

int main()
{
    int n;
    cin >> n;
    cout << fact(n);
    return 0;
}
