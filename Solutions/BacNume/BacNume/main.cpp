#include <iostream>
#include <cstring>

using namespace std;

void FNume(char s[], char id[]) {
    char *p;
    p = strtok(s, " ");
        p = strtok(NULL, " ");
    strcpy(id, p);
    strcat(id, "2022");
}

int main() {
    char s[51], id[51] = "0";
    cin.getline(s, 51);
    FNume(s, id);
    cout << id;
    return 0;
}
