#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[256];
    int k;
    cin.getline(s, 256);
    s[0] = s[0] - 32;
    for (int i = 1; i < strlen(s) - 1; ++i)
        if (s[i] != ' ' && (s[i + 1] == ' ' || s[i - 1] == ' '))
            s[i] = s[i] - 32;
    k = strlen(s) - 1;
    s[k] = s[k] - 32;
    cout << s;
    return 0;
}
