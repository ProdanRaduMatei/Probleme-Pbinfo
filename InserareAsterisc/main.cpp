#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char v[101];
    cin.getline(v, 101);
    int n = strlen(v);
    if (strchr(v, 'a') || strchr(v, 'e') || strchr(v, 'i') || strchr(v, 'u')) {
        for (int i = 0; i < n; ++i) {
            cout << v[i];
            if (strchr("aeiou", v[i] != 0))
                cout << "*";
        }
    }
    else
        cout << "FARA VOCALE";
    return 0;
}
