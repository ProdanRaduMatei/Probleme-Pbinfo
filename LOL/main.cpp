#include <iostream>

using namespace std;

int c[106], v[106], n;
char x, y;

int main()
{
    for (int i = 65; i < 106; ++i)
        v[i] = 300;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        int pozX, pozY;
        pozX = x;
        pozY = y;
        c[pozX] += v[pozY];
        if (v[pozX] <= 950)
            v[pozX] += 50;
        if (v[pozY] >= 50)
            v[pozY] -= 50;
    }
    for (int i = 65; i < 70; ++i)
        cout << (char)i << " " << c[i] << endl;
    for (int i = 97; i < 102; ++i)
        cout << (char)i << " " << c[i] << endl;
    return 0;
}
