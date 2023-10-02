#include <fstream>
#include <queue>

using namespace std;

ifstream cin("munte.in");
ofstream cout("munte.out");

bool first;
int v[101], secvente;

void print1(int st[], int dr[], int n) {
    for (int i = 1; i <= n; i++)
        cout << st[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++)
        cout << dr[i] << " "; 
    cout << "\n";
}

void print2(int &n) {
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    cout << "\n";
}


void build(queue <int> q, int &n) {
    int remove = 0;
    int k = 0;
    for (int i = 1; i <= n; i++)
        if ((!q.empty() && i != q.front()) || q.empty())
            v[++k] = v[i];
        else if (!q.empty()) {
            q.pop();
            remove++;
        }
    n -= remove;
}

int ok(int &n) {
    int st[105], dr[105], ans = 0;
    queue <int> q;
    st[0] = -1;
    dr[n + 1] = -1;
    for (int i = 1; i <= n; i++)
        if (v[i] > v[i - 1])
            st[i] = st[i - 1] + 1;
        else
            st[i] = 0;
    for (int i = n; i >= 1; i--)
        if (v[i] > v[i + 1])
            dr[i] = dr[i + 1] + 1;
        else
            dr[i] = 0;
    for (int i = 1; i <= n; i++)
        if (st[i] && dr[i]) {
            ans++;
            secvente++;
            q.push(i);
        }
    if (!first)
        cout << ans << "\n", first = 1;
    build(q, n);
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    while (n && ok(n));
    cout << secvente << "\n" << n;
}