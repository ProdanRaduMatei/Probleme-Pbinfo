#include <iostream>
#include <cstring>

using namespace std;

char s[100], acr[100];
short n, j = -1;

int main() {
    cin.getline(s, 100);
    n = strlen(s);
    acr[0] = 0;
    if (s[0] >= 'A' && s[0] <= 'Z') {
        ++j;
        acr[j] = s[0];
    }
    for (int i = 1; i < n; ++i) {
        if (s[i - 1] == ' ' && s[i] >= 'A' && s[i] <= 'Z') {
            ++j;
            acr[j] = s[i];
        }
    }
    ++j;
    acr[j] = '\0';
    cout << acr;
}
