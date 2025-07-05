#include <iostream>

using namespace std;

int main ()
{
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (i * (n / i) == n)
        cnt += 2;
        if (i * i == n)
            cnt--;
    }
    if (cnt == 4)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
