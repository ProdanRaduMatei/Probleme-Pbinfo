#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sudoku.in");
ofstream fout("sudoku.out");

int a[10][10], n, k;
int st[3][100], as, ev, gasit;

void succesor() {
    if (a[st[1][k]][st[2][k]] < 9) {
        ++a[st[1][k]][st[2][k]];
        as = 1;
    }
    else
        as = 0;
}

void valid() {
    ev = 1;
    for (int j = 1; j <= 9; ++j)
        if (j != st[2][k] && a[st[1][k]][j] == a[st[1][k]][st[2][k]])
            ev = 0;
    for (int i = 1; i <= 9; ++i)
        if (i != st[1][k] && a[i][st[2][k]] == a[st[1][k]][st[2][k]])
            ev = 0;
    if (st[1][k] >= 1 && st[1][k] <= 3 && st[2][k] >= 1 && st[2][k] <= 3) {
        for (int i = 1; i <= 3; ++i)
            for (int j = 1; j <= 3; ++j)
                if (a[st[1][k]][st[2][k]] == a[i][j] && (i != st[1][k] || j != st[2][k]))
                    ev = 0;
    }
    else if (st[1][k] >= 1 && st[1][k] <= 3 && st[2][k] >= 4 && st[2][k] <= 6) {
            for (int i = 1; i <= 3; ++i)
                for (int j = 4; j <= 6; ++j)
                    if (a[st[1][k]][st[2][k]] == a[i][j] && (i != st[1][k] || j != st[2][k]))
                        ev = 0;
    }
    else if (st[1][k] >= 1 && st[1][k] <= 3 && st[2][k] >= 7 && st[2][k] <= 9) {
        for (int i = 1; i <= 3; ++i)
            for (int j = 7; j <= 9; ++j)
                if (a[st[1][k]][st[2][k]] == a[i][j] && (i != st[1][k] || j != st[2][k]))
                    ev = 0;
    }
    else if (st[1][k] >= 4 && st[1][k] <= 6 && st[2][k] >= 1 && st[2][k] <= 3) {
        for (int i = 4; i <= 6; ++i)
            for (int j = 1; j <= 3; ++j)
                if (a[st[1][k]][st[2][k]] == a[i][j] && (i != st[1][k] && j != st[2][k]))
                    ev = 0;
    }
    else if (st[1][k] >= 4 && st[1][k] <= 6 && st[2][k] >= 4 && st[2][k] <= 6) {
        for (int i = 4; i <= 6; ++i)
            for (int j = 4; j <= 6; ++j)
                if (a[st[1][k]][st[2][k]] == a[i][j] && (i != st[1][k] && j != st[2][k]))
                    ev = 0;
    }
    else if (st[1][k] >= 4 && st[1][k] <= 6 && st[2][k] >= 7 && st[2][k] <= 9) {
        for (int i = 4; i <= 6; ++i)
            for (int j = 7; j <= 9; ++j)
                if (a[st[1][k]][st[2][k]] == a[i][j] && (i != st[1][k] && j != st[2][k]))
                    ev = 0;
    }
    else if (st[1][k] >= 7 && st[1][k] <= 9 && st[2][k] >= 1 && st[2][k] <= 3) {
        for (int i = 7; i <= 9; ++i)
            for (int j = 1; j <= 3; ++j)
                if (a[st[1][k]][st[2][k]] == a[i][j] && (i != st[1][k] && j != st[2][k]))
                    ev = 0;
    }
    else if (st[1][k] >= 7 && st[1][k] <= 9 && st[2][k] >= 4 && st[2][k] <= 6) {
        for (int i = 7; i <= 9; ++i)
            for (int j = 4; j <= 6; ++j)
                if (a[st[1][k]][st[2][k]] == a[i][j] && (i != st[1][k] && j != st[2][k]))
                    ev = 0;
    }
    else if (st[1][k] >= 7 && st[1][k] <= 9 && st[2][k] >= 7 && st[2][k] <= 9) {
        for (int i = 7; i <= 9; ++i)
            for (int j = 7; j <= 9; ++j)
                if (a[st[1][k]][st[2][k]] == a[i][j] && (i != st[1][k] && j != st[2][k]))
                    ev = 0;
    }
}

void tipar() {
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j)
            fout << a[i][j] << " ";
        fout << endl;
    }
    gasit = 1;
}

int main()
{
    for (int i = 1; i <= 9; ++i)
        for (int j = 1; j <= 9; ++j) {
            fin >> a[i][j];
            if (a[i][j] == 0) {
                ++n;
                st[1][n] = i;
                st[2][n] = j;
            }
        }
    k = 1;
    while (k > 0 && !gasit) {
        do{
            succesor();
            if (as)
                valid();
        }while (as && !ev);
        if (as)
            if (k == n)
                tipar();
            else
                ++k;
        else {
            a[st[1][k]][st[2][k]] = 0;
            --k;
        }
    }
    return 0;
}
