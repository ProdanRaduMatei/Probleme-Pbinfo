#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class InParser {
private:
    FILE *fin;
    char *buff;
    int sp;

    char read_ch() {
        ++sp;
        if (sp == 4096) {
            sp = 0;
            fread(buff, 1, 4096, fin);
        }
        return buff[sp];
    }

public:
    InParser(const char* nume) {
        fin = fopen(nume, "r");
        buff = new char[4096]();
        sp = 4095;
    }

    InParser& operator >> (int &n) {
        char c;
        while (!isdigit(c = read_ch()) && c != '-');
        int sgn = 1;
        if (c == '-') {
            n = 0;
            sgn = -1;
        }
        else
            n = c - '0';
        while (isdigit(c = read_ch()))
            n = 10 * n + c - '0';
        n *= sgn;
        return *this;
    }

    InParser& operator >> (long long &n) {
        char c;
        n = 0;
        while (!isdigit(c = read_ch()) && c != '-');
        long long sgn = 1;
        if (c == '-') {
            n = 0;
            sgn = -1;
        }
        else
            n = c - '0';
        while (isdigit(c = read_ch()))
            n = 10 * n + c - '0';
        n *= sgn;
        return *this;
    }
};

InParser fin("bossfight.in");
ofstream fout("bossfight.out");

struct Data{
    int v, i;
    bool operator <(const Data& other) const
    {
        return v<other.v;
    }
}x[10001], y[10001];

int main() {
    int n, s, v;
    long long int sol = 0;
    fin >> n >> s;
    for (int i = 1; i <= n; i++)
    if (i == 1) {
        fin >> x[i].v;
        x[i].i = 0;
    }
    else if (i == 2)
        fin >> v;
    else {
        fin >> y[i - 2].v;
        y[i - 2].i = i - 2;
    }
    sort(y + 1, y + 1 + n - 2);
    for (int i = 2; i < n; i++) {
        int st = 1, dr = 0;
        for (int j = 1; j < i && x[j].v < v; j++) {
            while(dr < n - i && x[j].v + v + y[dr + 1].v <= s)
                dr++;
            while (st <= n - i && v >= y[st].v)
                st++;
            while (dr > 0 && x[j].v + v + y[dr].v > s)
                dr--;
            if (st <= dr)
                sol += dr - st + 1;
        }
        if (i <= n - 2) {
            int poz = i;
            for (int j = i - 1; j > 0 && v < x[j].v; j--) {
                poz = j;
                swap(x[j], x[j + 1]);
            }
            x[poz] = {v, 0};
            v = 0;
            for (int j = 1; j <= n - i; j++) {
                if (y[j].i == i - 1)
                    v = y[j].v;
                if (v != 0)
                    swap(y[j], y[j + 1]);
            }
        }
    }
    fout << sol;
    return 0;
}