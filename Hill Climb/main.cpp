#include <iostream>
#include <stack>

using namespace std;

const int NMAX = 1e5;
const int INF = 2e9;
int N;
int a[NMAX + 2];

void Test() {
    cin >> N;
    a[0] = INF;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    stack <int> st;
    st.push(0);
    int l = 0;
    for (int i = 1; i <= N; i++) {
        while (!st.empty() && a[st.top()] < a[i])
            st.pop();
        l = max(l, i - st.top() - 1);
        st.push(i);
    }
    cout << l << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        Test();
    return 0;
}