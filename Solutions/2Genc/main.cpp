#include<algorithm>
#include<fstream>
#include <iostream>
using namespace std;
ifstream in("2genc.in");
ofstream out("2genc.out");
int st[30], v[30], uz[30], n,m;
void init() {
    in >> n >> m;
}                    
void afis() {
    for (int i = 1; i <= m; i++)
        out << st[i] << " ";
    out << '\n';
}
void back(int k) {
    for (int i = 1; i <= n; i++) {
        st[k] = i;
        if ((st[k] < st[k - 1] && st[k - 1] - st[k] != 1) && k > 1);
        else {
            if (k == m) afis();
            else back(k + 1);
        }
    }
}
int main() {
    init();
    back(1);
    return 0;
}