#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int v[21], i;

int main()
{
    char s1[21], s2[21], voc[] = "aeiouAEIOU";
    cin >> s1 >> s2;
    for (i = 0; i < strlen(s2); ++i) {
        if (!strchr(voc, s2[i]))
            cout << s2[i];
    }
    cout << " " << s1;
    return 0;
}
