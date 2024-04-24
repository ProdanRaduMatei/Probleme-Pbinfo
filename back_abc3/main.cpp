#include <iostream>
#include <cstring>

using namespace std;

char voc[] = "AEIOU";
int st[1001], n, cnt;

int verificare(int k)
{
    int c = 0, v = 0;
    for (int i = 1; i <= k; i++)
    {
        if (strchr(voc, (char)(st[i] + 64)))
            v++;
        else
            c++;
    }
    if (v > c)
        return 1;
    return 0;
}

void afis()
{
    cnt++;
    for (int i = 1; i <= n; i++)
        cout << (char)(st[i] + 64);
    cout << '\n';
}

void back(int k)
{
    for (int i = st[k - 1] + 1; i <= 26; i++)
    {
        st[k] = i;
        if (k == n)
        {
            if (verificare(k))
                afis();
        }
        else
            back(k + 1);
    }
}

int main()
{
    cin >> n;
    back(1);
    return 0;
}