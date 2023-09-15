#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[1000], sep[] = " ", *p, c[50];
    cin.getline(s, 1000);
    p = strtok(s, sep);
    while (p != NULL) {
        strcpy(c, p);
        cout << c << " ";
        p = strtok(NULL, sep);
    }
    return 0;
}
