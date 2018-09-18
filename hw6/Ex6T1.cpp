#include <iostream>
using namespace std;
class rectangle{
private:
    int l,w;
public:
    rectangle(int a,int b){
        if (a<=0 || a>20) {cout<<"Construction failed."<<endl;return;}
        if (b<=0 || b>20) {cout<<"Construction failed."<<endl;return;}
        l=a;w=b;
    }
    int area(){
        return l*w;
    }
    int perimeter(){
        return 2*l+2*w;
    }
    void setl(int x){
        if (x<=0 || x>20) {cout<<"Setl failed."<<endl;return;}
        l=x;
    }
    void setw(int x){
        if (x<=0 || x>20) {cout<<"Setl failed."<<endl;return;}
        w=x;
    }
    void draw(char ch){
        for (int i=0;i<l;i++) {
            for (int j = 0; j < w; j++) cout << ch;
            cout<<endl;
        }
    }
};
int main() {
    rectangle r(15,15);
    r.draw('r');
    int a,b;char ch;
    cout<<"Setl: ";cin>>a;
    r.setl(a);
    cout<<"Setw: ";cin>>b;
    r.setw(b);
    cout<<"Draw with: ";cin>>ch;
    r.draw(ch);
    return 0;
}