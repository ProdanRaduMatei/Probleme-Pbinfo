#include <iostream>

using namespace std;

int esteVocala (char c) {
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return 1;
    return 0;
}

int main()
{
    char sir[261];
    cin.getline(sir, 260);
    int i = 1;
    int contor = 0;
    while (sir[i]) {
        if (esteVocala(sir[i-1]) && esteVocala(sir[i])) contor++;
        i++;
    }
    cout<<contor;
    return 0;
}
