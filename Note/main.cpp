#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[101], *p;
    cin.getline(s, 101);
    char s1[] = "DO";
    char s2[] = "RE";
    char s3[] = "MI";
    char s4[] = "FA";
    char s5[] = "SOL";
    char s6[] = "LA";
    char s7[] = "SI";
    char b[50][50];
    char c[50][50];
    p = strtok(s, " ");
    int k = 0;
    while (p) {
        strcpy(b[k], p);
        ++k;
        p = strtok(NULL, " ");
    }
    int j = 0;
    bool ok = false;
    for (int i = 0; i < k; ++i) {
        ok = false;
        if (strstr(b[i], s1))
            ok = true;
        if (strstr(b[i], s2))
            ok = true;
        if (strstr(b[i], s3))
            ok = true;
        if (strstr(b[i], s4))
            ok = true;
        if (strstr(b[i], s5))
            ok = true;
        if (strstr(b[i], s6))
            ok = true;
        if (strstr(b[i], s7))
            ok = true;
        if (ok == true) {
            strcpy(c[j], b[i]);
            ++j;
        }
    }
    if (j == 0)
        cout << "nu exista";
    else
        for (int i = 0; i < j; ++i)
        cout << c[i] << endl;
    return 0;
}
