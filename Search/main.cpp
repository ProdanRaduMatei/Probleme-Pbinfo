#include <iostream>

using namespace std;

int IndexOf(char s[], char ch) {
    for (int i = 0; s[i] != NULL; ++i)
        if (s[i] = ch)
            return i;
    return -1;
}

int LastIndexOf(char s[], char ch) {
    int aux = -1;
    for (int i = 0; s[i] != NULL; ++i)
        if (s[i] == ch)
            aux = i;
    return aux;
}

int NthIndex(char s[], char ch, int k) {
    for (int i = 0; s[i] != NULL; ++i)
        if (s[i] == ch) {
            --k;
            if (!k)
                return i;
        }
        return -1;
}

int main()
{
    char s[250];
    cin.getline(s, 250);
    cout << IndexOf(s, 'a') << endl;
    cout << LastIndexOf(s, 'e') << endl;
    cout << NthIndex(s, 'e', 20) << endl;
    cout << NthIndex(s, 'a', 2) << endl;
    return 0;
}
