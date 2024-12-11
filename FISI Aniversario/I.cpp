#include <bits/stdc++.h>
using namespace std;
 
long long t,n,m,a[300005],ans;
#define mod 1000000007
 
long long solve(long long x,long long k){
	long long na=1;
	for(long long i=1;i<=k;i<<=1){
		if(i&k)
			na=na*x%mod;
		x=x*x%mod;
	}
	return na;
}
 
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(long long i=1;i<=n;i++)
				cin>>a[i];
		sort(a+1,a+n+1);
		ans=(m-1)*m%mod*(m+1)%mod*solve(6,mod-2)%mod;
		for(long long i=2;i<=n;i++){
			long long dd=a[i]-a[i-1];
			ans=(ans-(dd-1)*dd%mod*(dd+1)%mod*solve(6,mod-2)%mod+mod)%mod;
		}
		long long dd=a[1]+m-a[n];
		ans=(ans-(dd-1)*dd%mod*(dd+1)%mod*solve(6,mod-2)%mod+mod)%mod;
		cout<<ans*n%mod*solve(m,mod-2)%mod<<endl;
	}
}
