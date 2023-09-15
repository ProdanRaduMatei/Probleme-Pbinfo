#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("baza.in");
ofstream fout("baza.out");

int main()
{
    char s[50], l[] = "abcdefghijklmnopqrstuvwxyz";
    int n = 0;
    cin.getline(s, 50);
    for (int i = strlen(s) - 1; i >= 0; --i) {
        int j = 0;
        while (j <= 26 && s[i] != l[j])
            ++j;
        int c = i, p = j * 26, pr = 1;
        if (c == 0)
            n = n + 1;
        else {
            while (c > 0) {
                pr = pr * p;
                --c;
            }
            n = n + pr;
        }
    }
    cout << n;
    return 0;
}
