#include <iostream>
#include <limits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt = 0;
    cin >> n;

    int maxim = numeric_limits<int>::min();
    while (n--)
    {
        int x;
        cin >> x;
        if (x > maxim)
        {
            ++cnt;
            maxim = x;
        }
    }

    cout << cnt << '\n';
    return 0;
}