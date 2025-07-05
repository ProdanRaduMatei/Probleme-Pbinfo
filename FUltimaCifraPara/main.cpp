#include <iostream>

using namespace std;

int UCP(long long n) {
    int u = -1;
    while (n) {
        if ((n % 10) % 2 == 0)
            u = n % 10;
        n = n / 10;
    }
    return u;
}

int main()
{
    long long n;
    cin >> n;
    cout << UCP(n);
    return 0;
}
