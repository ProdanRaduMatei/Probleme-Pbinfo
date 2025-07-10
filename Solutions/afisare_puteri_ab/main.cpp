#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    cout << 1;
    while (b)
    {
        a *= a;
        b--;
        cout << " " << a;
    }
    return 0;
}