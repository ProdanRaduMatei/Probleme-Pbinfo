#include <iostream>
#include <cmath>

using namespace std;

int consecutiv(int n, int x)
{
    int x = sqrt(n);
    if ((x - 1) * x <= n && n <= x * (root + 1))
    {
        return root;
    }
    else
    {
        return root + 1;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << consecutiv(n);
    return 0;
}