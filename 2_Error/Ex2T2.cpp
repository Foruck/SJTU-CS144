#include <iostream>
#include <cmath>
using namespace std;
class NoneAns{};
void solve(double a,double b,double c,double &x1,double &x2) throw(NoneAns){
    double delta=b*b-4*a*c;
    if (delta<0) throw NoneAns();
    x1=(-b+sqrt(delta))/(2*a);
    x2=(-b-sqrt(delta))/(2*a);
    return;
}
int main() {
    double a,b,c,x1,x2;
    cin>>a>>b>>c;
    try{
        solve(a,b,c,x1,x2);
        cout<<x1<<' '<<x2;
    }
    catch(NoneAns) {cout<<"No answer for this equation.";}
    return 0;
}