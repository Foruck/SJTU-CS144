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

int main() {
    int n,tot=0;
    bool *p;
    cin>>n;
    p=new bool[n+1];
    prime(n,p,tot);
    cout<<tot<<endl;
    for (int i=2;i<=n;i++) if (!p[i]) cout<<i<<' ';
    return 0;
}