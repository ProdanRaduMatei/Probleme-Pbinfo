#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream fin("vacantadevara.in");
    ofstream fout("vacantadevara.out");
    int N, i, j, x[1000], min;
    long cod_securitate;
    fin >> N;
    for(i = 0; i < N; i++)
        fin >> x[i];
    min = x[0];
    for(i = 0; i < N; i++)
        if(x[i] < min && x[i] != 0) {
            min = x[i];
            swap(x[0], x[i]); //se schimba locurile
        }
    for(i = 1; i < N; i++)
        for(j = 1; j < N; j++)
            if(x[i] < x[j])
                swap(x[i], x[j]);
    for(i = 0; i < N; i++)
        cod_securitate = cod_securitate * 10 + x[i];
    fout << cod_securitate;
    return 0;
}
