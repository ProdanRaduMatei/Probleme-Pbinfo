#include <fstream>
#define ll unsigned long long

using namespace std;

ifstream cin("qtsume.in");
ofstream cout("qtsume.out");

int n, q, x , y;
long long v[100001], sp[100001], sp_2[100001];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sp[i] = sp[i - 1] + v[i];
        sp_2[i] = sp_2[i - 1] + sp[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> x >> y;
        if (x != 1)
            cout << (y - x + 1) * sp[y] - (sp_2[y - 1] - sp_2[x - 2]) << "\n";
        else
            cout << (y - x + 1) * sp[y] - sp_2[y - 1] << "\n";
    }
    
}