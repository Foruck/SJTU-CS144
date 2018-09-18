#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> reLen(vector<string> &x){
    vector<int> tmp;
    for (int i=0;i<x.size();i++) tmp.push_back(x[i].size());
    return tmp;
}
string &Longest(vector<string> &x)throw(int){
    int i,tmp=0,k=-1;
    for (i=0;i<x.size();i++) {
        if (x[i].size()>tmp) {tmp=x[i].size();k=i;}
    }
    if (k==-1) throw 1;
    return x[k];
}
string &Shortest(vector<string> &x)throw(int){
    int i,tmp=23333333,k=-1;
    for (i=0;i<x.size();i++) {
        if (x[i].size()<tmp) {tmp=x[i].size();k=i;}
    }
    if (k==-1) throw 1;
    return x[k];
}
string Smallest(vector<string> &x)throw(int){
    if (x.size()==0) throw 1;
    vector<string> b=x;
    sort(b.begin(),b.end(),less<string>());
    return b[0];
}
string Biggest(vector<string> &x)throw(int){
    if (x.size()==0) throw 1;
    vector<string> b=x;
    sort(b.begin(),b.end(),less<string>());
    return b[b.size()-1];
}

int main() {
    vector<string> a;
    vector<int> len;
    int n,i,j,k;
    string s;
    cin>>n;
    for (i=0;i<n;i++){
        cin>>s;a.push_back(s);
    }
    len=reLen(a);
    for (i=0;i<len.size();i++) cout<<len[i]<<' ';
    cout<<endl;
    try{
        cout<<Longest(a)<<endl;
        cout<<Shortest(a)<<endl;
        cout<<Biggest(a)<<endl;
        cout<<Smallest(a)<<endl;
    }
    catch(...) {cout<<"There is no item in the vector.";}
    return 0;
}