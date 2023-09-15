#include <iostream>
#include <cstring>

using namespace std;

void Prescurtat(char s[]) {
    char w[100], *p, sep[] = " ", c1[] = "COLEGIUL", c2[] = "LICEUL", c3[] = "NATIONAL", c4[] = "TEORETIC";
    int n;
    p = strtok(s, sep);
    w[0] = '\0';
    while (p) {
        n = strlen(p);
        if (p[n - 1] != '.')
            strcat(w, p);
        else {
            p[n - 1] = '\0';
            if (strstr(c1, p))
                strcat(w, c1);
            if (strstr(c2, p))
                strcat(w, c2);
            if (strstr(c3, p))
                strcat(w, c3);
            if (strstr(c4, p))
                strcat(w, c4);
        }
        p = strtok(NULL, sep);
        if (p)
            strcat(w, " ");

    }
    strcpy(s, w);
}

int main()
{
    char s[101];
    cin.getline(s, 101);
    Prescurtat(s);
    for (int i = 0; i <= strlen(s) - 1; ++i)
        cout << s[i];
    return 0;
}
