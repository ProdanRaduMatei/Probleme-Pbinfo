#include <iostream>

using namespace std;

bool pal(int x) {
    int c = x, y = 0;
    while (c) {
        y = y * 10 + c % 10;
        c = c / 10;
    }
    if (x == y)
        return 1;
    return 0;
}

int main()
{
    int x, y, xy, yx, px = 1, py = 1, cx, cy, c = 0;
    do {
        cin >> x >> y;
        if (x != 0 && y != 0) {
            cx = x;
            cy = y;
            px = 1;
            py = 1;
            while (cx) {
                px = px * 10;
                cx = cx / 10;
            }
            while (cy) {
                py = py * 10;
                cy = cy / 10;
            }
            xy = x * py + y;
            yx = y * px + x;
            if (pal(xy) == 1 || pal(yx) == 1)
                ++c;
        }
    } while (x != 0 && y != 0);
    cout << c;
    return 0;
}
