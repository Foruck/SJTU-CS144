#include <iostream>
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;
class error{};
class correct{};
class rational{
    friend rational operator+(const rational &x,const rational &y){
        rational ans;
        ans.down=x.down*y.down;
        ans.up=x.down*y.up+y.down*x.up;
        ans.reduct();
        return ans;
    }
    friend rational operator-(const rational &x,const rational &y){
        rational ans;
        ans.down=x.down*y.down;
        ans.up=y.down*x.up-x.down*y.up;
        ans.reduct();
        return ans;
    }
    friend rational operator*(const rational &x,const rational &y){
        rational ans;
        ans.down=x.down*y.down;
        ans.up=y.up*x.up;
        ans.reduct();
        return ans;
    }
    friend rational operator/(const rational &x,const rational &y){
        rational ans;
        ans.down=x.down*y.up;
        ans.up=x.up*y.down;
        ans.reduct();
        return ans;
    }

    friend ostream &operator<<(ostream &os,const rational &x){
        os<<x.up<<'/'<<x.down;
        return os;
    }
    friend istream &operator>>(istream &is,rational &x){
        while (true){
            try{
                is>>x.up>>x.down;
                if (x.down==0) throw error();
                else throw correct();
            }
            catch(error) {cout<<"Error! Again: ";}
            catch(correct) {break;}
        }
        return is;
    }

    friend bool operator==(const rational &x,const rational &y){
        return (x.down==y.down && x.up==y.up);
    }
    friend bool operator>=(const rational &x,const rational &y){
        return (x.up*y.down-x.down*y.up>=0);
    }
    friend bool operator>(const rational &x,const rational &y){
        return (x.up*y.down-x.down*y.up>0);
    }
    friend bool operator<=(const rational &x,const rational &y){
        return (x.up*y.down-x.down*y.up<=0);
    }
    friend bool operator<(const rational &x,const rational &y){
        return (x.up*y.down-x.down*y.up<0);
    }
    friend bool operator!=(const rational &x,const rational &y){
        return (x.up*y.down-x.down*y.up!=0);
    }

public:
    int up,down;
    rational()=default;
    rational(int x,int y) throw(error):up(x),down(y){
        if (y==0) throw error();
        if (x<0 && y<0) {up*=-1;down*=-1;}
        if (x>0 && y<0) {up*=-1;down*=-1;}
        reduct();
        return;
    }
    int gcd(int x,int y) const{
        if (y==0) return x;
        else return gcd(y,x%y);
    }
    void reduct(){
        if (up==0) {down=1;return;}
        int x=gcd(abs(up),abs(down));
        up/=x;
        down/=x;
        if (up<0 && down<0) {up*=-1;down*=-1;}
        if (up>0 && down<0) {up*=-1;down*=-1;}
        return;
    }

    operator double() const{
        return double(up)/down;
    }

    rational &operator=(const rational &x){
        up=x.up;down=x.down;
        return *this;
    }
};

int main() {
    rational x,y;
    cin>>x>>y;

    cout<<"x:"<<x<<" y:"<<y<<endl;
    cout<<"x="<<double(x)<<" y="<<double(y)<<endl;
    cout<<"x+y="<<x+y<<endl;
    cout<<"x-y="<<x-y<<endl;
    cout<<"x*y="<<x*y<<endl;
    cout<<"x/y="<<x/y<<endl;
    cout<<"x>y?"<<(x>y)<<endl;

    return 0;
}