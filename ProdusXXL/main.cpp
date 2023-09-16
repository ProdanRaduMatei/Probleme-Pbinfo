#include <fstream>
#include <vector>
#include <stack>
#define ll unsigned long long

using namespace std;

ifstream cin("produsxxl.in");
ofstream cout("produsxxl.out");

stack <int> stiva;
vector <int> temp, v, idk, show, sum;
ll n, cif, x;
bool global;

void add() {
    int s = 0;
    bool used = 0;
    int r = 0;
    sum.clear();
    if (idk.size() > temp.size()) {
        for (int i = 0; i < idk.size(); i++) {
            s = idk[i];
            if (!used) {
                s += r;
                r = 0;
                used = 1;
            }
            if (i < temp.size())
                s += temp[i];
            if (s < 10)
                sum.push_back(s);
            else {
                sum.push_back(s % 10);
                r = s / 10;
                used = 0;
            }
        }
    }
    else {
        for (int i = 0; i < temp.size(); i++) {
            s = temp[i];
            if (!used) {
                s += r;
                r = 0;
                used = 1;
            }
            if (i < idk.size())
                s += idk[i];
            if (s < 10)
                sum.push_back(s);
            else {
                sum.push_back(s % 10);
                r = s / 10;
                used = 0;
            }
        }
    }
    while (r) {
        sum.push_back(r % 10);
        r /= 10;
    }
    idk.clear();
    for (auto e : sum)
        idk.push_back(e);

}

void produs(ll c, ll zeroes) {
    bool used = 0;
    int r = 0;
    temp.clear();
    while (zeroes) {
        temp.push_back(0);
        zeroes--;
    }
    for (int i = 0; i < v.size(); i++) {
        int p = v[i] * c;
        if (!used) {
            p += r;
            r = 0;
            used = 1;
        }
        if (p < 10)
            temp.push_back(p);
        else {
            temp.push_back(p % 10);
            r = p / 10;
            used = 0;
        }
    }
    while (r) {
        temp.push_back(r % 10);
        r /= 10;
    }
    if (idk.empty()) {
        for (auto e : temp)
            idk.push_back(e);
    }
    else
        add();
}

void read() {
    cin >> cif;
    while (cif) {
        cin >> x;
        temp.push_back(x);
        cif--;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
        v.push_back(temp[i]);
    temp.clear();
    cin >> cif;
    while (cif) {
        cin >> x;
        stiva.push(x);
        cif--;
    }
    if (stiva.size() == 1 && !stiva.top()) {
        cout << 0;
        global = 1;
    }
    else {
        ll k = 0;
        int i = 0;
        while (!stiva.empty()) {
            produs(stiva.top(), k);
            stiva.pop();
            k++;
        }
    }
}

int main() {
    read();
    if (!global) {
        for (int i = idk.size() - 1; i >= 0; i--)
            show.push_back(idk[i]);
        for (auto e : show)
            cout << e;
    }
}