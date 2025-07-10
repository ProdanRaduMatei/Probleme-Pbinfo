#include <fstream>
#define ll long long

using namespace std;

ifstream cin("miny.in");
ofstream cout("miny.out");

ll p = 1;
int n, x;

int eratostene[10001];
int prime[10001], m;
int fr[10001];
int ct = 0;
int minim = 10000, maxim;

void ciur() {
  eratostene[1] = 1;
  for (int i = 2; i <= 10000; i++) {
    if (!eratostene[i]) 
    prime[++m] = i;
    for (int j = 2; i * j <= 10000; j++) 
      eratostene[i * j] = 1;
  }
}

void desc(int x) {
  int d = 1;
  while (x != 1) {
    int putere = 0;
    while (x % prime[d] == 0) {
      x /= prime[d];
      putere++;
    }
    if (putere) {
      if (fr[prime[d]] == 0) 
        ct++;
      if (minim > prime[d]) 
        minim = prime[d];
      fr[prime[d]] += putere;
    }
    d++;
  }
}

void citire() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (eratostene[x])
      desc(x);
    else {
      if (!fr[x]) 
        ct++;
      if (minim > x) 
        minim = x;
      fr[x]++;
    }
    p = (p % 100 * x % 100) % 100;
  }
  cout << p / 10 << "\n";
}

int cmmdc(int a, int b) {
  int r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

void c2() {
  int c = fr[minim];
  for (int i = minim; i <= 10000; i++) {
    if (fr[i]) {
      c = cmmdc(c, fr[i]);
      maxim = max(maxim, i);
    }
  }
  cout << ct << "\n";
  for (int i = minim; i <= maxim; i++) 
    if (fr[i]) 
      cout << i << " " << fr[i] / c << "\n";
}

int main() {
  ciur();
  citire();
  c2();
}