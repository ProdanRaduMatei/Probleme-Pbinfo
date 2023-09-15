#include <iostream>

using namespace std;

const int x = 4, y = 5;
int tabla[x][y] = {};
bool opreste = false;

void arata() {
    for(int r = 0; r < x; r++) {
        for(int c = 0; c < y; c++)
            cout << tabla[r][c] << " ";
        cout << endl;
    }
}

bool valideaza(int r, int c)  {
    if(tabla[r][c] == 0)
        return true;
    return false;
}
void backtrack(int stop, int r, int c) {
    if((stop == x * y + 1) && (!opreste)) {
        arata();
        opreste = true;
    }
    if((r - 1 >= 0) && (c - 2 >= 0))
        if(valideaza(r, c)) {
            tabla[r][c] = stop;
            backtrack(stop+1, r-1, c-2);
            tabla[r][c] = 0;
        }
    if((r - 2 >= 0) && (c - 1 >= 0))
        if(valideaza(r, c)) {
            tabla[r][c] = stop;
            backtrack(stop + 1, r - 2, c - 1);
            tabla[r][c] = 0;
        }
    if((r - 2 >= 0) && (c + 1 < y))
        if(valideaza(r, c)) {
            tabla[r][c] = stop;
            backtrack(stop+1, r-2, c+1);
            tabla[r][c] = 0;
        }
    if((r - 1 >= 0) && (c + 2 < y))
        if(valideaza(r, c)) {
            tabla[r][c] = stop;
            backtrack(stop+1, r-1, c+2);
            tabla[r][c] = 0;
        }
    if((r + 1 < x) && (c + 2 < y))
        if(valideaza(r, c)) {
            tabla[r][c] = stop;
            backtrack(stop+1, r+1, c+2);
            tabla[r][c] = 0;
        }
    if((r + 2 < x) && (c + 1 < y))
        if(valideaza(r, c)) {
            tabla[r][c] = stop;
            backtrack(stop+1, r+2, c+1);
            tabla[r][c] = 0;
        }
    if((r + 2 < x) && (c - 1 >= 0))
        if(valideaza(r, c)) {
            tabla[r][c] = stop;
            backtrack(stop+1, r+2, c-1);
            tabla[r][c] = 0;
        }
    if((r + 1 < 4) && (c - 2 >= 0))
        if(valideaza(r, c)) {
            tabla[r][c] = stop;
            backtrack(stop+1, r+1, c-2);
            tabla[r][c] = 0;
        }
}

int main() {
    backtrack(1, 0, 0);
    return 0;
}
