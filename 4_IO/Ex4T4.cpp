#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<string> split(const string &s){
    ofstream tmp;ifstream is;
    vector<string> a;
    string x;

    tmp.open("D:\\4tmp.txt");
    tmp<<s;
    tmp.close();

    is.open("D:\\4tmp.txt");
    while (is>>x){
        a.push_back(x);
    }

    return a;
}

vector<string> new_split(const string &x,const string &y){
    int i;
    string tt=x;
    vector<string> ans;
    for (i=0;i<tt.size();i++) {
        if (y.find(tt[i])!=-1) tt[i]=' ';
    }
    ans=split(tt);
    return ans;
}

int main() {

    ifstream is("D:\\4.txt");
    char ch;
    string s,p;
    int i,j,k;
    vector<string> ans;
    while (is.get(ch)){
        s.push_back(ch);
    }
    ans=split(s);
    for (i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;

    s="";
    cout<<"The Original:";
    while (cin.get(ch)){
        if (ch=='\n') break;
        s.push_back(ch);
    }
    cout<<"The 'blank':";
    while (cin.get(ch)){
        if (ch=='\n') break;
        p.push_back(ch);
    }
    ans=new_split(s,p);
    for (i=0;i<ans.size();i++) cout<<ans[i]<<' ';

    return 0;
}