#include <bits/stdc++.h>
#include <string>

using namespace std;

string n;

void modf(int v) {
    for (int i = v; i < n.length(); i = i + 2) {
        if (n[i] == '0' && n[i + 1] == '0')
            cout << 0;
        else if (n[i] == '0' && n[i + 1] == '1')
            cout << 1;
        else if (n[i] == '1' && n[i + 1] == '0')
            cout << 2;
        else
            cout << 3;
    }
}

int main() {
    cin >> n;
    if (n.length() & 1) {
        cout << 1;
        modf(1);
    }
    else
        modf(0);
    return 0;
}
