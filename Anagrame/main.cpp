#include <iostream>
#include <cstring>

using namespace std;

int main () {
    char a[21], b[21];
    int ok = 1;
    cin >> a >> b;
    if (strlen(a) != strlen(b))
        cout << 0;
    else {
        while (strcmp(a, b) != 0 && ok) {
        	if (strchr(b, a[0]) != 0) {
                strcpy(strchr(b, a[0]), strchr(b, a[0]) + 1);
                strcpy(a, a + 1);
            }
            else
                ok = 0;
        }
        if (ok)
            cout << 1;
        else
            cout << 0;
    }
    return 0;
}
