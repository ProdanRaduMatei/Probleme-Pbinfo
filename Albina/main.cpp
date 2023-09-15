#include <iostream>

using namespace std;

int main()
{
    int n, s;
    cin >> n;
    s = 6 * (n * (n - 1) / 2) + 1;
    cout << s;
    return 0;
}
