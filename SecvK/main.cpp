#include <iostream>
#include <fstream>
using namespace std;

int sumaPartiala(int v[], int k, int start) {
    int s = 0;
    for (int i = start; i < start + k; i++)
        s += v[i];
    return s;
}

int main() {
    int n, k, v[100000];

    ifstream fin("secvk.in");
    ofstream fout("secvk.out");

    fin >> n >> k;
    for (int i = 0; i < n; i++)
        fin >> v[i];
    int start = 0, end = k, 
    	lastSum = sumaPartiala(v, k, 0),
        maxSum = lastSum;
    for (int i = 1; i < n - k; i++) {
        lastSum = lastSum - v[i - 1] + v[i + k - 1];
        if (lastSum > maxSum) {
            maxSum = lastSum;
            start = i;
            end = i + k;
        }
    }
    for (int i = start; i < end; i++)
        fout << v[i] << " ";
}