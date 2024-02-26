#include <iostream>

using namespace std;

int n, m, st, dr, s, A[1001];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        st = 0;
        for (int j = 1; j <= m; ++j)
        {
            cin >> A[j];
            st += A[j];
        }
        dr = 0;
        s = m;
        while (st != dr)
        {
            st -= A[s];
            dr += A[s];
            --s;
        }
        cout << s << " " << m - s << "\n";
    }
    return 0;
}