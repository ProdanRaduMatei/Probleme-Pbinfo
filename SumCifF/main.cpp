#include <iostream>

using namespace std;

int sumcif(int n) {
    int s = 0;
    while (n) {
        s = s + n % 10;
        n = n / 10;
    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    cout << sumcif(n);
    return 0;
}
