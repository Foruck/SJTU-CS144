#include <iostream>
#include <climits>
using namespace std;
class OutofRange{};
int main() {
    int f[233],i=3;unsigned delta;
    f[1]=1;f[2]=1;
    try{
        i=3;
        while (true){
            f[i]=f[i-1]+f[i-2];delta=unsigned(f[i-1])+unsigned(f[i-2]);
            if (delta>INT_MAX) throw OutofRange();
            i++;
        }
    }
    catch(...) {cout<<f[i-1];}
    return 0;
}