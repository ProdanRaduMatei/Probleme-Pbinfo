#include <fstream>
#define ll long long

using namespace std;

ifstream cin("twoop.in");
ofstream cout("twoop.out");

int n,st,dr,poz;
long long a[100001], val, mars[100001], op1, op2;

void prelucrare1() {
    for (int i = 1; i <= n; i++) {
        mars[i] += mars[i - 1];
        a[i] += mars[i];
    }
}

void citire() {
    cin >> n >> op1 >> op2;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (long long i = 1; i <= op1; i++) {
        cin >> st >> dr >> val;
        mars[st] += val;
        mars[dr + 1] -= val;
    }
    prelucrare1();
    for (int i = 1; i <= op2; i++) {
        cin >> poz;
        cout << a[poz] << "\n";
    }
}

int main() {
    citire();
}