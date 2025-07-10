#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map <unsigned long long, vector <unsigned long long>> m;
unsigned long long n, x, last, task, lmax, k;

void try_push(unsigned long long val, unsigned long long l) {
    if (m[val].size() != k)
        m[val].push_back(l);
    else {
        int poz_mini = 0;
        int mini = 1e6;
    	for (unsigned long long i = 0; i < k; i++) {
        	if (m[val][i] < mini) {
                mini = m[val][i];
                poz_mini = i;
        	}	
    	}
        if (m[val][poz_mini] < l)
            m[val][poz_mini] = l;
    }
    return;
}

void read() {
    cin >> k >> n >> last;
    unsigned long long l = 1;
    for (unsigned long long i = 2; i <= n; i++) {
        cin >> x;
        if (x != last) {
            try_push(last, l);
            l = 1;
        }
        else
            l++;
        last = x;
    }
    try_push(last, l);
    cin >> task;
}

void print() {
    for (auto e : m) {
        cout << "pentru valoarea x = " << e.first << " avem: ";
        for (auto e2 : e.second)
            cout << e2 << " ";
        cout << "\n";
    }
}

bool cmp(unsigned long long a, unsigned long long b) {
    return(a > b);
}

void solve() {
    unsigned long long l = 0, max_x = 0, lmax = 0;
    unsigned long long p = 0;
    for (auto e : m) {
        sort(e.second.begin(), e.second.end(), cmp);
        l = e.second[0];
        p = k - 1;
        for (unsigned long long i = 1; i < e.second.size() && p; i++, p--)
            l += e.second[i];
        if (l > lmax) {
        	lmax = max(lmax, l);
            max_x = e.first;
        }
        else if (l == lmax && max_x < e.first)
            max_x = e.first;
    }
    if (task % 2)
        cout << lmax;
	else 
        cout << max_x;
}

int main() {
    read();
    solve();
}