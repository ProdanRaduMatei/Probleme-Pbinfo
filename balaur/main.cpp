#include <iostream>

using namespace std;

int main()
{
    int n;
    long long c = 5;
    cin >> n;
    for (int i = 2; i <= n; ++i)
        c = c + 5;
    cout << c;
    return 0;
}
