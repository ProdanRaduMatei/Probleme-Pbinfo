#include <iostream>
#include <string.h>

using namespace std;

char k[50];

int main() {
    cin >> k;
    for(int i=0; i<strlen(k); i++) {
        if(k[i] == '0') {
            cout<<"@@@@@"<<endl;
            cout<<"@"<<"   "<<"@"<<endl;
            cout<<"@"<<"   "<<"@"<<endl;
            cout<<"@"<<"   "<<"@"<<endl;
            cout<<"@@@@@"<<endl;
        }
        if(k[i]=='1') {
            cout <<" "<<" ";
            cout<<"@"<<endl;
            cout <<" ";
            cout<<"@@"<<endl;
            cout <<" "<<" ";
            cout<<"@"<<endl;
            cout <<" "<<" ";
            cout<<"@"<<endl;
            cout<<"@@@@@"<<endl;
        }
        if(k[i]=='2') {
            cout<<"@@@@"<<endl;
            cout <<"@" <<" "<<" "<<"@"<<endl;
            cout <<"  "<<"@"<<endl;
            cout<<" "<<"@"<<endl;
            cout<<"@@@@"<<endl;
        }
        if(k[i]=='3') {
            cout<<"@@@@@"<<endl;
            cout<<"    "<<"@"<<endl;
            cout<<"@@@@@"<<endl;
            cout<<"    "<<"@"<<endl;
            cout<<"@@@@@"<<endl;
        }
        if(k[i] == '4') {
            cout <<"@"<<"   "<<"@"<<endl;
            cout <<"@"<<"   "<<"@"<<endl;
            cout<<"@@@@@"<<endl;
            cout <<"    "<<"@"<<endl;
            cout <<"    "<<"@"<<endl;;
        }
        if(k[i] == '5') {
            cout<<"@@@@@"<<endl;
            cout<<"@"<<"    "<<endl;
            cout<<"@@@@@"<<endl;
            cout<<"    "<<"@"<<endl;
            cout<<"@@@@@"<<endl;
        }
        if(k[i] == '6') {
            cout<<"@@@@@"<<endl;
            cout<<"@"<<"    "<<endl;
            cout<<"@@@@@"<<endl;
            cout<<"@"<<"   "<<"@"<<endl;
            cout<<"@@@@@"<<endl;
        }
        if(k[i] == '7') {
            cout<<"@@@@"<<endl;
            cout<<"   "<<"@"<<endl;
            cout<<"  "<<"@@@"<<endl;
            cout<<"   "<<"@"<<endl;
            cout<<"   "<<"@"<<endl;
        }
        if(k[i] == '8') {
            cout<<"@@@@@"<<endl;
            cout<<"@"<<"   "<<"@"<<endl;
            cout<<"@@@@@"<<endl;
            cout<<"@"<<"   "<<"@"<<endl;
            cout<<"@@@@@"<<endl;
        }
        if(k[i] == '9') {
            cout<<"@@@@@"<<endl;
            cout<<"@"<<"   "<<"@"<<endl;
            cout<<"@@@@@"<<endl;
            cout<<"    "<<"@"<<endl;
            cout<<"    "<<"@"<<endl;
        }
    }
    return 0;
}
