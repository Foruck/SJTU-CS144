#include <iostream>
#include <vector>
using namespace std;
template <class T>
vector<T> reverse2(vector<T> &a){
    vector<T> tmp;
    int i;
    for (i=a.size()-1;i>=0;i--) tmp.push_back(a[i]);
    return tmp;
}

template <class T>
void reverse1(vector<T> &a){
    int i,tmp;
    for (i=1;i<=a.size()/2;i++) {tmp=a[i-1];a[i-1]=a[a.size()-i];a[a.size()-i]=tmp;}
    return;
}

int main() {
    vector<int> a,b;
    int x,i;
    try {
        while (cin >> x) {a.push_back(x);}
    }
    catch(...) {}
    b=reverse2<int>(a);
    reverse1<int>(a);
    for (i=0;i<b.size();i++) cout<<b[i]<<' ';
    cout<<endl;
    for (i=0;i<a.size();i++) cout<<a[i]<<' ';
    return 0;
}