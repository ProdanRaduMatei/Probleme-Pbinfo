#include <iostream>

using namespace std;

int main() {
    long long a, b, s;
    cin >> a >> b;
    s = a + b;
    while (a && b) {
        if (a % 10 + b % 10 > 9) {
            cout << "Gigel nu stie! El poate cumpara " << s << " bomboane!";
            return 0;
        }
        a = a / 10;
        b = b / 10;
    }
    cout << "Gigel stie!";
    return 0;
}
