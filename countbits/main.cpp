#include <fstream>
#define ll long long
#define L (2<<15)

using namespace std;

ifstream cin("countbits.in");
ofstream cout("countbits.out");

short v[L + 1];
int n;
ll a, b, c, d, e;
ll sol;

short countbits(int x) {

    short k = 0;
    while (x) {
        if ((x & 1))
            k++;

        x = (x >> 1);
    }
    return k;

}

void precalc() {
    for (int i = 1; i <= L; i++)
        v[i] = countbits(i);
}

void read() {

    cin >> n >> a >> b >> c >> d >> e;
    int x, y;
    
    x = a / L; 
    y = a - x * L; 
    sol += v[x];
    sol += v[y];

    x = b / L;
    y = b - x * L;
    sol += v[x];
    sol += v[y];

    for (int i = 3; i <= n; i++) {
        int next = 1 + (a * c + b * d) % e;
        //cout << next << " ";
        x = next / L;
        y = next - x * L;
        sol += v[x];
        sol += v[y];
        a = b;
        b = next;
    }


    cout << sol;
}


int main() {

    precalc();
    read();

}