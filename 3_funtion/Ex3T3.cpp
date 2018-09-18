#include <iostream>
#include <vector>
using namespace std;
class error{};
double index(vector<double> &x,vector<double> &y)throw(error){
    int i;double ans=0;
    if (x.size()<y.size()) throw error();
    for (i=0;i<y.size();i++) ans+=x[i]*y[i];
    return ans;
}
int main() {
    vector<double> price,weight;
    double x;

    while (cin>>x){
        if (x==-1) break;
        price.push_back(x);
    }
    while (cin>>x){
        if (x==-1) break;
        weight.push_back(x);
    }
    try{
        x=index(price,weight);
    }
    catch(error) {cout<<"The price vector is too small."<<endl;}
    cout<<x<<endl;
    return 0;
}