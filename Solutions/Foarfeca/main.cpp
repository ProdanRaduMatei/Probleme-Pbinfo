#include <iostream>
#include <stack>

using namespace std;

const int NMAX = 1e5;
int v[NMAX], grup[NMAX], n;
stack <int> stiva;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (!stiva.empty()) {
            if (v[stiva.top()] == v[i] - (i - stiva.top())) {
                grup[i] = k;
                while (!stiva.empty() && v[stiva.top()] == v[i] - (i - stiva.top())) {
                    grup[stiva.top()] = k;
                    stiva.pop();
                }
            }
            else
                grup[i] = ++k;
        }
        stiva.push(i);        
    }
    for (int i = 0; i < n; i++)
        cout << ++grup[i] << " ";
}