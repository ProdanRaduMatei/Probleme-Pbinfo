#include <iostream>
#include <cstring>

using namespace std;

int n, m, x[11];
char s[11];

void citire()
{
    cin >> s;
    n = strlen(s);
    cin >> m;
}

void sortare()
{
    char aux;
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (s[i] > s[j])
            {
                aux = s[i];
                s[i] = s[j];
                s[j] = aux;
            }
}

void afisare(int k)
{
    for (int i = 1; i <= k; ++i)
        cout << s[x[i] - 1];
    cout << "\n";
}

int vocala(char c)
{
    if (strchr("aeiou", c))
        return 1;
    return 0;
}

int consoana(char c)
{
    if (!strchr("aeiou", c))
        return 1;
    return 0;
}

int valid(int k)
{
    for (int i = 1; i < k; ++i)
        if (x[i] == x[k] || s[x[i] - 1] > s[x[i + 1] - 1])
            return 0;
    if (k > 1 && vocala(s[x[k - 1] - 1]) && vocala(s[x[k] - 1]))
        return 0;
    return 1;
}

void back(int k)
{
    if (k <= n)
    {
        for (int i = 1; i <= n; ++i)
        {
            x[k] = i;
            if (valid(k))
            {
                if (k >= m && consoana(s[x[k] - 1]))
                    afisare(k);
                back(k + 1);
            }
        }
    }
}

int main()
{
    citire();
    sortare();
    back(1);
    return 0;
}