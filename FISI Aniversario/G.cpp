#include <bits/stdc++.h>
using namespace std;

double pi=acos(-1);
double ans=0.0;
vector<int> g[1010];
int vis[1010];
int n;



struct node{
    long long x,y,r;
    long long d1,d2,d3,d4;
    double s;
} c[1010];

long long check(node a,node b){
    if(a.d1<=b.d1&&a.d2>=b.d2&&a.d3>=b.d3&&a.d4<=b.d4){
        return 1;
    }
    return 0;
}

long long cmp(node a,node b){
    return a.r<b.r;
}

double dfs(long long now,long long f,long long deep){
    vis[now]=1;
    double tmp=0.0;
    for(long long i=0;i<g[now].size();i++){
        if(g[now][i]==f)
        	continue;
        tmp+=dfs(g[now][i],now,deep+1);
    }
    if(f==0)
    	return tmp;
   	if((deep&1))
   		return tmp+c[now].s;
   	else
   		return tmp-c[now].s;
}

int main(){
    cin >> n;
    for(long long i=1; i<=n; i++){
    	cin >> c[i].x >> c[i].y >> c[i].r;
        c[i].d1=c[i].y+c[i].r;
        c[i].d2=c[i].y-c[i].r;
        c[i].d3=c[i].x-c[i].r;
        c[i].d4=c[i].x+c[i].r;
        c[i].s=c[i].r*c[i].r*pi;
    }
    sort(c+1,c+n+1,cmp);
    for(long long i=1; i<=n; i++){
        for(long long j=i+1; j<=n; j++){
            if(check(c[i],c[j])){
                g[i].push_back(j);
                g[j].push_back(i);
                break;
            }
        }
    }
    for(long long i=n;i>=1;i--){
        if(!vis[i]){
            ans+=dfs(i,0,0)+c[i].s;
        }
    }
    printf("%.9lf\n",ans);
}
