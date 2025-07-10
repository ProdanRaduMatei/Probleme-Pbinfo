#include <iostream>
#include <cmath>

using namespace std;

void consecutiv(int n, int &x)
{
    x = sqrt(n);
    if ((x - 1) * x <= n && n <= x * (x + 1))
    {
        return;
    }
    else
    {
        ++x;
    }
}

int main()
{
    int n, x;
    cin >> n;
    consecutiv(n, x);
    cout << x << endl;
    return 0;
}