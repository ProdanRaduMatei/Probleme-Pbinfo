#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, p = 1, sum = 0;
    cin >> n;
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            sum += n;
        }
        n /= 10;
    }
    cout << sum << '\n';
    return 0;
}