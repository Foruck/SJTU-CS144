#include <cassert>
#include <iostream>
using namespace std;
class polynomial{
    friend istream &operator>>(istream &is, polynomial &x){
        is>>x.deg;
        if (x.c!=NULL) delete[] x.c;
        x.c=new double[x.deg+1];
        for (int i=0;i<x.deg+1;i++) is>>x.c[i];
        return is;
    }
    friend ostream &operator<<(ostream &os, const polynomial &y){
        for (int i=y.deg;i>=0;i--){
            if (y.c[i]==0) continue;
            if (i<y.deg && i>0) os<<'+'<<y.c[i]<<"*x^"<<i;
            else if (i==y.deg) os<<y.c[i]<<"*x^"<<i;
            else if (i==0) os<<"+"<<y.c[i];
        }
        return os;
    }

    friend polynomial &operator+(const polynomial &x,const polynomial &y){
        polynomial *ans;
        double *a;
        int n,m,i;
        n=x.deg>y.deg?x.deg:y.deg;
        a=new double [n+1];
        for (i=0;i<n+1;i++) a[i]=0;
        for (i=0;i<n+1;i++) {
            if (i > x.deg) a[i] = y.c[i];
            else if (i > y.deg) a[i]=x.c[i];
            else a[i]=x.c[i]+y.c[i];
        }
        ans=new polynomial(n+1,a);
        return *ans;
    }

    friend polynomial &operator-(const polynomial &x,const polynomial &y){
        polynomial *ans;
        double *a;
        int n,m,i;
        n=x.deg>y.deg?x.deg:y.deg;
        a=new double [n+1];
        for (i=0;i<n+1;i++) a[i]=0;
        for (i=0;i<n+1;i++) {
            if (i > x.deg) a[i] =-y.c[i];
            else if (i > y.deg) a[i]=x.c[i];
            else a[i]=x.c[i]-y.c[i];
        }
        ans=new polynomial(n+1,a);
        return *ans;
    }

    friend polynomial &operator*(const polynomial &x,const polynomial &y){
        polynomial *ans;
        double *a;
        int n,m,i,j;
        n=x.deg+y.deg;
        a=new double [n+1];
        for (i=0;i<n+1;i++) a[i]=0;
        for (i=0;i<x.deg+1;i++)
            for (j=0;j<y.deg+1;j++)
            a[i+j]+=x.c[i]+y.c[j];
        ans=new polynomial(n+1,a);
        return *ans;
    }

private:
    int deg;
    double *c;
public:
    polynomial(){c=new double [1];c[0]=1;deg=0;}

    polynomial(const polynomial &other){
        deg=other.deg;
        c=new double [deg];
        for (int i=0;i<deg+1;i++){
            c[i]=other.c[i];
        }
    }

    polynomial(int n,double *a){
        deg=n-1;
        c=new double [n];
        for (int i=0;i<n;i++) c[i]=a[i];
    }

    polynomial &operator=(const polynomial &other){
        deg=other.deg;
        if (c!=NULL) delete[] c;
        c=new double [deg];
        for (int i=0;i<deg+1;i++) c[i]=other.c[i];
        return *this;
    }


};
int main() {
    polynomial x,y;
    cin>>x>>y;
    cout<<"x+y="<<x+y<<endl;
    cout<<"x-y="<<x-y<<endl;
    cout<<"x*y="<<x*y<<endl;
    return 0;
}