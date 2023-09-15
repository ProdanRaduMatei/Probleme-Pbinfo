#include <iostream>
#include <cstring>

using namespace std;

void Trim(char s[]) {
    int i = 0;
    while (s[0] == ' ')
        strcpy(s, s + 1);
    while (s[strlen(s) - 1] == ' ')
        s[strlen(s) - 1] = '\0';

}

int main()
{
    char s[101];
    cin.getline(s, 101);
    Trim(s);
    for (int i = 0; i < strlen(s); ++i)
        cout << s[i];
    return 0;
}
