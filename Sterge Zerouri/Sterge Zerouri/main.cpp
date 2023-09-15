#include <iostream>
#include <string>

using namespace std;

int main() {
    char x[11];
    cin >> x;
    int i = strlen(x) - 1;
    while (x[i] == '0') {
        x[i] = x[i + 1];
        --i;
    }
    cout << x;
    return 0;
}
