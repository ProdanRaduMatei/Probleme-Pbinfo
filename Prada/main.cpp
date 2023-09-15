#include <iostream>

using namespace std;

int main()

{
    int HA, HB, D, X;
    cin >> HA >> HB >> D;
    if (HA==HB) X=D/2;
    else {

        if (HA>HB) X=(D*D+HB*HB-HA*HA)/(2*D);

        else X=(D*D+HA*HA-HB*HB)/(2*D);
    }
    if (X<0) X=-X;
    cout << X;
    return 0;
}
