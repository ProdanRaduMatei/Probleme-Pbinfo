#include <iostream>

using namespace std;

int main()
{
    int c, p, o, g;
    cin >> c >> p;
    o = c;
    g = (c * 4 - p) / 2;
    o = o - g;
    cout << g << " " << o;
    return 0;
}
