#include <iostream>

using namespace std;

int main()
{
    int n, o = 0, u, d, cnt = 0;
    cin >> n;
    while (n > 0) {
        u = n % 10;
        n = n / 10;
        o = o * 10 + u;
    }
    for (d = 1; d * d <= o; ++d){
        if (d * d == o)
            ++cnt;
        else if (o % d == 0)
            cnt = cnt + 2;
    }
    cout << cnt;
    return 0;
}
