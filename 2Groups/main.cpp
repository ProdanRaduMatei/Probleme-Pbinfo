#include <iostream>

using namespace std;

int main()
{
    long long n, s1 = 0, s2 = 0;
    cin >> n;
    for (int i = n; i > 0; --i) {
        if (s1 < s2) {
            s1 = s1 + i;
            cout << i << " ";
        }
        else
            s2 = s2 + i;
    }
    cout << endl;
    s1 = s2 = 0;
    for (int i = n; i > 0; --i) {
        if (s1 < s2)
            s1 = s1 + i;
        else {
            s2 = s2 + i;
            cout << i << " ";
        }
    }
    return 0;
}
