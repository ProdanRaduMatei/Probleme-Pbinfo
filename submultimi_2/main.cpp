#include <iostream>

using namespace std;

int main()  {
    int n,k,r,line,sk, sr, primulk, ultimulk, cardpar, primulr,ultimulr;
    cin >> n >> k >> r;
    cardpar=n/2;
    if (k%2==0) primulk=(k/2)*(k-1);
    else primulk=((k-1)/2)*k;
    ultimulk=(k-1)+primulk;
    if (k%2==0)
        sk=(k/2)*(primulk+ultimulk);
    else
        sk=((primulk+ultimulk)/2)*k;
    if (r%2==0)
        primulr=(r/2)*(r-1);
    else
        primulr=((r-1)/2)*r;
    ultimulr=(r-1)+primulr;
    if (r%2==0)
        sr=(r/2)*(primulr+ultimulr);
    else
        sr=((primulr+ultimulr)/2)*r;
    cout << cardpar << endl;
    cout << (sk+sr)/(k+r) << endl;
    while (primulr<ultimulr) {
        cout << primulr << " ";
        ++primulr;
        if (primulr<ultimulr)
            cout << primulr << " ";
        cout << ultimulr << " ";
        ++primulr; --ultimulr;
    }
    if (primulr==ultimulr)
    cout << primulr;
    return 0;
}
