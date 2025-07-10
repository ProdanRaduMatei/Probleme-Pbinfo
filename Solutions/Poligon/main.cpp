#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    long long suma = 0;
    int maxLatura = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        suma += x;
        if (x > maxLatura)
            maxLatura = x;
    }
    if (suma > 2LL * maxLatura)
        cout << "DA\n";
    else
        cout << "NU\n";
    return 0;
}