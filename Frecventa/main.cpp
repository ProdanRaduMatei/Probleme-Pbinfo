#include <iostream>
#include <cstring>

using namespace std;

int f[256];
char s[256];
int i, maxim = 0;

int main()
{
    cin.getline(s, 256);
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            ++f[s[i]];
            maxim = max(maxim, f[s[i]]);
        }
    }
    for (i = (int)'a'; i <= (int)'z'; ++i) {
        if (f[i] == maxim) {
            cout << (char)i;
            return 0;
        }
    }
    return 0;
}
