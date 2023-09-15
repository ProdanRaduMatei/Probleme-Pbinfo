#include <iostream>
#include <stack>

using namespace std;

int n, x[100001], fr[100001], c;
stack<int>s;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    for (int i = n; i >= 1; --i)
        s.push(x[i]);
    for (int i = 1; i <= n; ++i) {
        cin >> c;
        int cn = 0;
        if (fr[c] == 0) {
            while (s.top() != c) {
                ++cn;
                ++fr[s.top()];
                s.pop();
            }
            ++cn;
            s.pop();
            cout << cn << " ";
        }
        else
            cout << cn << " ";
    }
    return 0;
}
