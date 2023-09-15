#include <iostream>

using namespace std;

int main() {
    int a, b, c, s1 = 0, s2 = 0;
    cin >> a >> b >> c;
    for (int i = a; i <= b; ++i)
        s1 = s1 + i;
    cout << s1 << " ";
    for (int i = b; i <= c; ++i)
        s2 = s2 + i;
    cout << s2 << " " << s1 + s2 - b;
    return 0;
}
