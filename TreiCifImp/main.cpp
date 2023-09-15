#include <iostream>

using namespace std;

int TreiCifImp(long long n) {
    int cnt = 0;
    while (n) {
        if ((n % 10) % 2 != 0)
            ++cnt;
        else
            cnt = 0;
        if (cnt >= 3)
            return 1;
        n = n / 10;
    }
    return 0;
}

int main()
{
    long long n;
    cin >> n;
    cout << TreiCifImp(n);
    return 0;
}
