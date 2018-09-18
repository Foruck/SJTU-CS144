#include <iostream>
using namespace std;

class TooLowTem{};
class NotInt{};
double ktoc(double k) throw (TooLowTem) {
    if (k<0) throw TooLowTem();
    return k-273.15;
}

double ctok(double x) throw(TooLowTem) {
    if (x<-273.15) throw TooLowTem();
    return 273.15+double(x);
}

double ftok(double f) throw(TooLowTem){
    double ans=(f+459.67)/1.8;
    if (ans<0) throw TooLowTem();
    return ans;
}

double ktof(double k) throw(TooLowTem){
    if (k<0) throw TooLowTem();
    double ans=k*1.8-459.67;
    return ans;
}

int main() {
    double k,f,c;
    try{
        cout<<"Celsius to Kelvin:";
        cin>>c;
        k=ctok(c);
        cout<<k<<endl;
    }
    catch(TooLowTem) {cout<<"The input is TOO LOW.\n";}
    try{
        cout<<"Kevin to Celsius:";
        cin>>k;
        c=ktoc(k);
        cout<<c<<endl;
    }
    catch(TooLowTem) {cout<<"The input is TOO LOW.\n";}
    try{
        cout<<"Kevin to Fahrenheit:";
        cin>>k;
        f=ktof(k);
        cout<<f<<endl;
    }
    catch(TooLowTem) {cout<<"The input is TOO LOW.\n";}
    try{
        cout<<"Fahrenheit to Kelvin:";
        cin>>f;
        k=ftok(f);
        cout<<k<<endl;
    }
    catch(TooLowTem) {cout<<"The input is TOO LOW.\n";}
    return 0;
}