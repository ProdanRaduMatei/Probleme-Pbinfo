#include <iostream>

using namespace std;

int main()
{
    long long n, v[10][10], u, cnt = 0, c;
    cin >> n;
    c = n;
    while (c) {
        c = c / 10;
        ++cnt;
    }
    for (int i = 1; i <= cnt; ++i) {
        c = n;
        while (c) {
            cout << c % 10 << " ";
            c = c / 10;
        }
        cout << endl;
    }
    return 0;
}
