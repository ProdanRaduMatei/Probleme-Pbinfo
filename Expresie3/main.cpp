#include <iostream>

using namespace std;

int n, s;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0)
            s = s - i * (i + 1);
        else
            s = s + i * (i + 1);
    }
    cout << "Rezultatul este " << s;
    return 0;
}
