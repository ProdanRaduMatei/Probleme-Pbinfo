#include <iostream>

using namespace std;

int fr_pozpare[128], fr_pozimpare[128];

int main() {
    char s1[101], s2[101];
    cin >> s1 >> s2;
    for (int i = 0; s1[i] != '\0'; i++) {
        int a = s1[i];
        if (i % 2 == 0)
            fr_pozpare[a]++;
        else
            fr_pozimpare[a]++; 
    }
    bool ok = 1;
    for (int i = 0; i < s2[i] != '\0'; i++) {
        int a = s2[i];
        if (i % 2 == 0) {
            if (fr_pozpare[a])
                fr_pozpare[a]--;
            else {
                ok = 0;
                break;
            }
        }
        else {
            if (fr_pozimpare[a])
                fr_pozimpare[a]--;
            else {
                ok = 0;
                break;
            }
        }
    }
    if (ok)
        cout << "PRIETENE";
    else
        cout << "NU SUNT PRIETENE";
}