#include <iostream>

using namespace std;

int zerof(int n) {
    int cnt = 0, p = 1;
    for (int i = 1; i <= n; ++i)
        p = p * i;
    while (p) {
        if (p % 10 == 0)
            ++cnt;
        p = p / 10;
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    cout << zerof(n);
    return 0;
}
