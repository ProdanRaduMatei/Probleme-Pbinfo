#include <stdio.h>
struct Frigider {
    char min;
    char max;
}f[10001], r[10001];
int Cate, i, j, N;
char min, max;
FILE* Fisier;

char Maxim(char x, char y) {
    if (x > y)
        return x;
    return y;
}

char Minim(char x, char y) {
    if (x < y)
        return x;
    return y;
}

int Cauta(char min, char max) {
    int i, Unde;
    for (i = 1; i <= Cate; i++) {
        if ((f[i].max >= min) && (f[i].max <= max))
            Unde = i;
        if ((f[i].min >= min) && (f[i].min <= max))
            Unde = i;
        if ((f[i].min <= min) && (f[i].max >= max))
            Unde = i;
        if ((f[i].max < min) || (f[i].min > max))
            Unde = -1;
    }
    return Unde;
}

void Intersectie(int j, char min, char max) {
    f[j].min = Maxim(min, f[j].min);
    f[j].max = Minim(max, f[j].max);
}

void Ordoneaza() {
    int i, j, ptmin;
    char tmax, tmin;
    for (i=1; i<=N-1; i++) {
        tmin = r[i].min;
        tmax = r[i].max;
        ptmin = i;
        for (j = i + 1; j <= N; j++)
            if (r[j].min < tmin) {
                tmax = r[j].max;
                tmin = r[j].min;
                ptmin = j;
            }
            else
                if (r[j].min == tmin)
                    if (r[j].max > tmax) {
                        tmax = r[j].max;
                        tmin = r[j].min;
                        ptmin = j;
                    }
        r[ptmin].min = r[i].min;
        r[ptmin].max = r[i].max;
        r[i].min = tmin;
        r[i].max = tmax;
    }
}

int main() {
    char x, y;
    Fisier = fopen("reactivi.in", "rt");
    fscanf(Fisier, "%d", &N);
    for (i = 1; i <= N; i++)
    fscanf(Fisier, "%d %d", &r[i].min, &r[i].max, &x, &y);
    Ordoneaza();
    f[1].min = r[1].min;
    f[1].max = r[1].max;
    Cate = 1;
    for (i = 2; i <= N; i++) {
        min = r[i].min;
        max = r[i].max;
        j = Cauta(min, max);
        if (j>0)
            Intersectie(j, min, max);
        else {
            Cate++;
            f[Cate].min = min;
            f[Cate].max = max;
        }
    }
    fclose(Fisier);
    Fisier = fopen("reactivi.out", "wt");
    fprintf(Fisier, "%d\n", Cate);
    fclose(Fisier);
    return 0;
}
