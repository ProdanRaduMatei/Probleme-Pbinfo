#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[101], c[101];
    cin >> s >> c;
    if (strlen(s) != strlen(c))
        cout << "cod incorect";
    else {
        int l = 0;
        char ci[101];
        char cf[101];
        for (int i = strlen(c); i >= 0; --i) {
            int cc = c[i] - 48;
            if (cc % 2 == 1) {
                ci[l] = s[i];
                ++l;
            }
        }
        ci[l] = s[0];
        ++l;
        for (int i = 1; i < strlen(c); ++i) {
            int cc = c[i] - 48;
            if (cc % 2 == 0) {
                ci[l] = s[i];
                ++l;
            }
        }
        for (int i = 0; i < l; ++i)
            cf[i] = ci[l - i - 1];
        cout << cf;
    }
    return 0;
}
