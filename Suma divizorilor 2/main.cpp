#include <iostream>

using namespace std;

void sum_div(int n, int &s) {
    s = 0;
    for (int d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            if (d * d == n)
                s = s + d;
            else
                s = s + d + n / d;
        }
    }
}

int main()
{
    int n, s;
    cin >> n;
    sum_div(n, s);
    cout << s;
    return 0;
}
