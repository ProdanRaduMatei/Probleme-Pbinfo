#include <iostream>
#include <cstring>

using namespace std;

char s[100];

int main()
{
    cin.getline(s, 100);
    int k = 0, ok = 0;
    for (int i = 0; i < strlen(s); ++i) {
        ++k;
        if (i == strlen(s) - 1 or s[i + 1] == ' ') {
            if (k % 2 == 0) {
                s[i - k + 1] =  '#';
                strcpy(s + i - k + 2, s + i + 1);
                ok = 1;
            }
            i -= k - 1;
            k = -1;
        }
    }
    if (ok)
        cout << s;
    else
        cout << "nu exista";
    return 0;
}
