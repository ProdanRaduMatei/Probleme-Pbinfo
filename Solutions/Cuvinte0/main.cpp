#include <bits/stdc++.h>
using namespace std;
int main() {
    map <string, int> M;
    string s;
    while(cin >> s)
        M[s]=1;
    for(auto x:M)
        cout << x.first << '\n';
    return 0;
}
