#include <iostream>

using namespace std;

int main()
{
    int a[1001], n;
    bool cr, de;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cr = de = false;
    for (int i = 1; i <= n; ++i)
        if (a[i] == a[i + 1]) {
            cout << "NU";
            return 0;
        }
        else
            if (a[i] > a[i + 1])
                if (cr)
                    de = true;
                else {
                    cout << "NU";
                    return 0;
                }
            else
                if (a[i] < a[i + 1])
                    if (!de)
                        cr = true;
                    else {
                        cout << "NU";
                        return 0;
                    }
    if (cr && de)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
