#include <fstream>
#include <iostream>
using namespace std;
int main(){
    char p[233333];
    ifstream is;ofstream os;

    char ch;
    cout<<"Path: ";
    cin>>p;is.open(p);
    while (!is){
        is.close();
        cout<<"Error! Path again: ";
        cin>>p;
        is.open(p);
    }

    os.open("D:\\3tmp.txt");

    while (is.get(ch)){
        if (ch>='A' && ch<='Z') ch=char(int(ch)-int('A')+int('a'));
        os<<ch;
    }

    is.close();
    os.close();

}