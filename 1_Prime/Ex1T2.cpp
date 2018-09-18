#include <iostream>
#include <cmath>
using namespace std;

void prime(int n){
    int i=2,tot=0,j;bool flag;
    while (true){
        flag=true;
        for (j=2;j<=sqrt(double(i));j++){
            if (i%j==0) {flag=false;break;}
        }
        if (flag) {
            cout<<i<<' ';
            tot++;
            if (tot==n) break;
        }
        i++;
    }
}

int main() {
    int n;
    cin>>n;
    prime(n);
    return 0;
}