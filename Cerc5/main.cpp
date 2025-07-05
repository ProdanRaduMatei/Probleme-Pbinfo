#include <iostream>
#include <cmath>

using namespace std;

int st[1001], n, uz[1001], cnt;

void afis()
{
    cnt = 1;
    for (int i = 1; i <= n; ++i)
        cout << st[i] << " ";
}

int verificare(int x, int y)
{
    int s = x + y;
    int f = (int)sqrt(s);
    return s == f * f;
}

void back(int k)
{
    for (int i = 1; i <= n && !cnt; ++i)
        if (!uz[i])
            if (k == 1 || (k < n && verificare(i, st[k - 1])) || (k == n && verificare(st[k - 1], i) && verificare(st[1], i)))
            {
                uz[i] = 1;
                st[k] = i;
                if (k == n)
                    afis();
                else
                    back(k + 1);
                uz[i] = 0;
            }
}

int main()
{
    cin >> n;
    back(1);
    if (!cnt)
        cout << "nu exista";
}