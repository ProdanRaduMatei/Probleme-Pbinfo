#include <iostream>

using namespace std;

int main()
{
    int a, b, i, cnt = 0, c = 0, d;
    cin >> a >> b;
    for (i = a; i <= b; ++i) {
        cnt = 0;
        for (d = 2; d * d <= i; ++d) {
            if (i % d == 0) {
                if (d * d == 0)
                    ++cnt;
                else
                    cnt = cnt + 2;
            }
        }
        if (cnt == 0) {
            ++c;
        }
    }
    cout << c;
    return 0;
}
