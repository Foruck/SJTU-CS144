#include <iostream>
#include <cassert>
using namespace std;

class matrix{
    friend ostream &operator<<(ostream &os,const matrix &x){
        for (int i=0;i<x.m;i++){
            for (int j=0;j<x.n;j++){
                os<<x.a[i][j]<<' ';
            }
            cout<<'\n';
        }
        return os;
    }
    friend istream &operator>>(istream &is,matrix &x){
        if (x.a!=NULL) {
            for (int i=0;i<x.m;i++) delete[] x.a[i];
            delete[] x.a;
        }
        while (true){
            try{
                is>>x.m>>x.n;
                if (x.m<=0 || x.n<=0) throw 1;
                else throw 2;
            }
            catch(int x) {if (x==1) cout<<"Error!Again:";else break;}
        }
        x.a=new int* [x.m];
        for (int i=0;i<x.m;i++) x.a[i]=new int [x.n];
        for (int i=0;i<x.m;i++){
            for (int j=0;j<x.n;j++)
                is>>x.a[i][j];
        }
        return is;
    }

    friend matrix &operator+(const matrix &x,const matrix &y){
        if (x.n!=y.n || x.m!=y.m) {cout<<"Plus failed.";}
        matrix *ans;
        int i,j,**a;
        a=new int* [x.m];
        for (i=0;i<x.m;i++) a[i]=new int [x.n];
        for (i=0;i<x.m;i++)
            for (j=0;j<x.n;j++)
                a[i][j]=x.a[i][j]+y.a[i][j];
        ans=new matrix(x.m,x.n,a);
        for (i=0;i<x.m;i++) delete [] a[i];
        delete [] a;
        return *ans;
    }

    friend matrix &operator*(const matrix &x,const matrix &y){
        if (x.n!=y.m) {cout<<"Multiply failed."<<endl;matrix *ans=new matrix();return *ans;}
        matrix *ans;
        int i,j,**a,k;
        a=new int* [x.m];
        for (i=0;i<x.m;i++) a[i]=new int [x.n];
        for (i=0;i<x.m;i++)
            for (j=0;j<x.n;j++)
                a[i][j]=0;
        for (i=0;i<x.m;i++)
            for (j=0;j<y.n;j++)
                for (k=0;k<x.n;k++)
                    a[i][j]+=x.a[i][k]*y.a[k][j];
        ans=new matrix(x.m,y.n,a);
        for (i=0;i<x.m;i++) delete [] a[i];
        delete [] a;
        return *ans;
    }

    friend matrix &multiply(matrix &x,matrix &y);

private:
    int m,n;
    int **a;
public:
    matrix(){
        a=NULL;
    }
    matrix(int t1,int t2,int **v){
        if (t2<=0 || t1<=0) {cout<<"Construction failed."<<endl;return;}
        m=t1;n=t2;
        a=new int* [t1];
        for (int i=0;i<t1;i++) a[i]=new int [t2];
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                a[i][j]=v[i][j];
    }

    matrix &operator()(int x1,int y1,int x2,int y2){
        matrix *ans;
        int **v,i,j;
        v=new int* [x2-x1];
        for (i=x1;i<x2;i++) v[i-x1]=new int [y2-y1];
        for (i=x1;i<x2;i++)
            for (j=y1;j<y2;j++)
                v[i-x1][j-y1]=a[i][j];

        ans=new matrix(x2-x1,y2-y1,v);
        for (i=0;i<x2-x1;i++) delete [] v[i];
        delete [] v;
        return *ans;
    }

    matrix &operator=(const matrix &x){
        if (a!=NULL) {
            for (int i=0;i<m;i++) delete[] a[i];
            delete[] a;
        }
        int i,j;
        m=x.m;n=x.n;
        a=new int* [x.m];
        for (i=0;i<x.m;i++) a[i]=new int [x.n];
        for (i=0;i<x.m;i++)
            for (j=0;j<x.n;j++)
                a[i][j]=x.a[i][j];
        return *this;
    }

};

matrix &multiply(matrix &x,matrix &y){
    if (x.n!=y.m) {cout<<"Multiply failed.-multiply"<<endl;matrix *ans=new matrix();return *ans;}
    if (x.m<=2 && y.n<=2) return x*y;
    matrix *ans,x1,x2,x3,x4,y1,y2,y3,y4,a1,a2,a3,a4;
    int i,j,**a;

    a=new int* [x.m];
    for (i=0;i<x.m;i++) a[i]=new int [y.n];
    for (i=0;i<x.m;i++)
        for (j=0;j<y.n;j++)
            a[i][j]=0;

    x1=x(0,0,x.m/2,x.n/2);
    x2=x(0,x.n/2,x.m/2,x.n);
    x3=x(x.m/2,0,x.m,x.n/2);
    x4=x(x.m/2,x.n/2,x.m,x.n);

    y1=y(0,0,x.n/2,y.n/2);
    y2=y(x.n/2,0,x.n,y.n/2);
    y3=y(0,y.n/2,x.n/2,y.n);
    y4=y(x.n/2,y.n/2,x.n,y.n);

    a1=multiply(x1,y1)+multiply(x2,y2);
    a2=multiply(x1,y3)+multiply(x2,y4);
    a3=multiply(x3,y1)+multiply(x4,y2);
    a4=multiply(x3,y3)+multiply(x4,y4);

    for (i=0;i<x.m/2;i++)
        for (j=0;j<y.n/2;j++)
            a[i][j]=a1.a[i][j];
    for (i=0;i<a2.m;i++)
        for (j=0;j<a2.n;j++)
            a[i][j+y.n/2]=a2.a[i][j];
    for (i=0;i<a3.m;i++)
        for (j=0;j<a3.n;j++)
            a[i+x.m/2][j]=a3.a[i][j];
    for (i=0;i<a4.m;i++)
        for (j=0;j<a4.n;j++)
            a[i+x.m/2][j+y.n/2]=a4.a[i][j];

    ans=new matrix(x.m,y.n,a);

    for (i=0;i<x.m;i++) delete [] a[i];
    delete [] a;
    return *ans;
}

int main() {
    matrix x,y,z;
    cin>>x>>y;
    cout<<x<<endl;
    cout<<y<<endl;
    multiply(x,y);
    cout<<multiply(x,y)<<endl;
    return 0;
}