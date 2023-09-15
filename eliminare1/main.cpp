#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[51];
    cin.getline(s, 50);
    for (int i = 0; i < strlen(s); ++i)
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            cout << s[i];
    return 0;
}
