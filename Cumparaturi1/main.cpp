#include <iostream>

using namespace std;

int main()
{
    int s, c, n;
    cin >> s >> c >> n;
    if (s % c == 0 && s % n == 0)
        cout << "CN";
    else if (s % c == 0 || s % n == 0) {
        if (s % c == 0)
            cout << "C";
        else
            cout << "N";
    }
    else
        cout << "nimic";
    return 0;
}
