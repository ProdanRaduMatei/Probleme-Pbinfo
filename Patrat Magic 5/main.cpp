#include <iostream>

using namespace std;

int main()
{
    int n, s = 0, m;
    cin >> n;
    m = n * n;
    s = (m * (m + 1)) / 2;
    cout << s / n;
    return 0;
}
