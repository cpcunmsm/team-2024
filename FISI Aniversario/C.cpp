#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
char ln[130];

double dfs(int p,int cr,int tg) {
    if(!ln[p]) return cr==tg;
    if(ln[p]=='+') return dfs(p+1,cr+1,tg);
    if(ln[p]=='-') return dfs(p+1,cr-1,tg);
    return 0.5*(dfs(p+1,cr-1,tg)+dfs(p+1,cr+1,tg));
}

int main() {
    cin>>ln;
    int i,t=0;
    for(i=0;ln[i];i++) {
        if(ln[i]=='+') t++;
        else t--;
    }
    cin>>ln;
    printf("%.10lf\n",dfs(0,0,t));
    return 0;
}
