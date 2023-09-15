#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream fin("undo.in");
ofstream fout("undo.out");

stack<int>s, u;
int fr[200001];

int main()
{
    int n;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        fin >> a >> b;
        if (a == 1) {
            s.push(b);
            ++fr[b];
        }
        else if (a == 2) {
            for (int j = 1; j <= b; ++j) {
                u.push(s.top());
                --fr[s.top()];
                s.pop();
            }
        }
        else if (a == 3) {
            for (int j = 1; j <= b; ++j) {
                s.push(u.top());
                ++fr[u.top()];
                u.pop();
            }
        }
        else if (a == 4) {
            fout << fr[b] << endl;
        }
    }
    return 0;
}
