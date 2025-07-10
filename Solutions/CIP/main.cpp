#include <iostream>

using namespace std;

int a, b, c, n, v[20], x, y, z;
char C[5];

bool Valid(int i)
{
    if (v[i] == 1 and v[i - 1] == 2 and v[i - 2] == 1)
        return 0;
    if (x > a or y > b or z > c)
        return 0;
    return 1;
}

void Afisare()
{
    int i;
    for (i = 1; i <= n; i++)
        cout << C[v[i]];
    cout << 'P' << '\n';
}

int main()
{
    int i;
    cin >> a >> b >> c;
    c--;
    n = a + b + c;
    C[1] = 'C';
    C[2] = 'I';
    C[3] = 'P';

    x = 1;
    y = z = 0;
    v[1] = 1;
    i = 2;
    while (i > 1)
    {
        if (v[i] == 1)
            x--;
        else if (v[i] == 2)
            y--;
        else if (v[i] == 3)
            z--;

        v[i]++;

        if (v[i] == 1)
            x++;
        else if (v[i] == 2)
            y++;
        else if (v[i] == 3)
            z++;
        if (v[i] <= 3)
        {
            if (Valid(i))
            {
                if (i == n)
                    Afisare();
                else
                {
                    i++;
                    v[i] = 0;
                }
            }
        }
        else
            i--;
    }
    return 0;
}