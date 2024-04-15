#include <iostream>
#include <cstring>

using namespace std;

char s[11], x[11];
int p[11];

bool eVoc(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void afisare(int n)
{
    if (eVoc(x[n]))
    {
        for (int i = 1; i <= n; ++i)
            cout << x[i];
        cout << '\n';
    }
}

void backtracking(int k, int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (!p[i])
        {
            x[k] = s[i];
            p[i] = 1;
            if (eVoc(x[1]))
                if (k == n)
                    afisare(n);
                else
                    backtracking(k + 1, n);
            p[i] = 0;
        }
    }
}

int main()
{
    cin >> s;
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (s[i] > s[j])
            {
                char aux = s[i];
                s[i] = s[j];
                s[j] = aux;
            }
    backtracking(1, n);
    return 0;
}
