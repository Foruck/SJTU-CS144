#include <iostream>
#include <cstring>
using namespace std;

void prime(int n,bool *p,int &tot){
    int i,j,k;
    //for (i=1;i<=n;i++) p[i]=false;
    memset(p,sizeof(bool)*(n+1),0);
    for (i=2;i<=n/2;i++){
        if (!p[i]){
            for (j=i;j*i<=n;j++){
                for (k=j*i;k<=n;k*=i) p[k]=true;
            }
        }
    }
    for (i=2;i<=n;i++) if (!p[i]) tot++;
}

bool reverse(int x){
    if (x<10) return true;
    if (x<100 && x%10==x/10) return true;
    if (x<1000 && x/100==x%10) return true;
    if (x<10000 && x/1000==x%10 && (x/100)%10==(x%100)/10) return true;
    return false;
}

int main() {
    int n,tot=0;
    bool *p;
    p=new bool[10001];
    prime(10000,p,tot);
    for (int i=2;i<=10000;i++) if (!p[i] && reverse(i)) cout<<i<<' ';
    delete[] p;
    return 0;
}