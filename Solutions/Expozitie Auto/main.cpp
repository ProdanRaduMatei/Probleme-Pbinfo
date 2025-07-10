#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    cin >> x;
    int code;
    int lastCollector = -1, secondLastCollector = -1;
    bool found = false;
    int prevCode = -1;
    bool hasPrev = false;
    while (cin >> code)
    {
        int year = code % 10000;
        if (year == x)
        {
            if (hasPrev)
            {
                int prevYear = prevCode % 10000;
                if (prevYear == x)
                {
                    secondLastCollector = prevCode / 10000;
                    lastCollector = code / 10000;
                    found = true;
                }
            }
        }
        prevCode = code;
        hasPrev = true;
    }
    if (found)
        cout << secondLastCollector << " " << lastCollector << '\n';
    else
        cout << "nu exista\n";
    return 0;
}