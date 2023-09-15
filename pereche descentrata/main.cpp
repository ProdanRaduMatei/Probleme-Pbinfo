#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char text[101], *p;
    char cuvinte[100][100];
    cin.get(text, 100);
    int nr_cuvinte = 0;
    p = strtok(text, " ");
    int i;
    while (p) {
        strcpy(cuvinte[nr_cuvinte++], p);
        p = strtok(NULL, " ");
    }
    for (i = 0; i < nr_cuvinte; ++i) {
        p = cuvinte[i];
        if (strlen(p) % 2 == 1) {
            char temp[100];
            strcpy(temp, p);
            temp[strlen(p) / 2 + 1] = temp[strlen(p) / 2];
            strcpy(temp + strlen(p) / 2 + 2, p + strlen(p) / 2 + 1);
            p = temp;
            int j;
            for (j = 0; j < nr_cuvinte; ++j) {
                if (strcmp(cuvinte[j], p) == 0) {
                    cout << "DA";
                    return 0;
                }
            }
        }
    }
    cout << "NU";
    return 0;
}
