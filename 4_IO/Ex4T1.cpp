#include <fstream>
#include <iostream>
using namespace std;
int main() {
    char p[2333];
    ifstream is;

    cout<<"Path: ";
    cin>>p;is.open(p);
    while (!is){
        is.close();
        cout<<"Error! Path again: ";
        cin>>p;
        is.open(p);
    }

    int x,sum=0;
    try {
        while (is >> x)
            sum += x;
        cout << sum << endl;
    }
    catch(...) {cout<< "Wrong type!";}
    is.close();
    return 0;
}