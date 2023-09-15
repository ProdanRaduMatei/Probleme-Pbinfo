#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n, num, i, j, k;
    char s[1001002];
    cin >> s >> n;
    j = strlen(s);
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (num % 2 == 0) {
            for (int k = 0; k < num; ++k)
                s[j++] = s[k];
        }
        else {
            for (k = num - 1; k >= 0; --k)
                s[j++] = s[k];
        }
    }
    s[j] = '\0';
    cout << s;
    return 0;
}
