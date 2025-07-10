#include <iostream>

using namespace std;

int n, s, u;
int main()
{
    cin >> n;
    while (n > 100)
        n = n / 10;
    s = n % 10;
    n = n / 10;
    s = s + n % 10;
    cout << s;
    return 0;
}
