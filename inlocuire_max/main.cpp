#include <iostream>

using namespace std;

int n, v[201], fr[10], nr;

int main()
{
    int i, j;
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> v[i];
    for (i = n; i >= 1; --i)
    {
        nr = v[i];
        do
        {
            fr[nr % 10]++;
            nr /= 10;
        } while (nr);
        for (j = 9; j >= 0; --j)
            if (fr[j])
                while (fr[j])
                {
                    cout << j;
                    fr[j]--;
                }
        cout << " ";
    }
    return 0;
}