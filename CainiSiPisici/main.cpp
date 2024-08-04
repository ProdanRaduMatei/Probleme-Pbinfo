#include <iostream>

using namespace std;

char p[20];
int n, m;
char c[2] = {'C', 'P'};

inline bool valid(int k)
{
    if(k > n + m - 3)
        return false;

    int pc = 0, pp = 0, i;

    for(i = 0; i <= k; i++)
        if(p[i] == 'C')
            pc++;
        else
            pp++;

    if(pc <= n - 1 && pp <= m - 1) {
        for(i = 0; i < k; i++)
            if(p[i] == 'P' && ((i == 0 && p[i + 1] == 'C') || (i && p[i - 1] == 'C' && p[i + 1] == 'C')))
                return false;

        return true;
    }

    return false;
}

static void backtrack(int k)
{
    int i, j;

    for(i = 0; i < 2; i++) {
        p[k] = c[i];

        if(valid(k)) {
            if(k == n + m - 3) {
                cout << 'C';
                for(j = 0; j < n + m - 2; j++)
                    cout << p[j];
                cout << 'P' << '\n';
            } else
                backtrack(k + 1);
        }
    }
}

int main(void)
{
    cin >> n >> m;

    if(n == 1 && m == 1)
        cout << "CP" << endl;
    else
        backtrack(0);

    return 0;
}