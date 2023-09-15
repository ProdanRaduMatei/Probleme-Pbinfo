#include <iostream>
#include <cstring>

using namespace std;

char s[256];
long long suma = 0, termen, i, lung;

int main()
{
    cin.getline(s, 256);
    lung = strlen(s);
    for (int i = 0; i < lung; ++i) {
        if (isdigit(s[i])) {
            termen = termen * 10 + (s[i] - '0');
        }
        else {
            suma = suma + termen;
            termen = 0;
        }
    }
    cout << suma;
    return 0;
}
